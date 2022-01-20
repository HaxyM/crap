#ifndef CRAP_ALGORITHM_MAKEHEAPTYPE
#define CRAP_ALGORITHM_MAKEHEAPTYPE

#include "copytype.h"
#include "../utility.d/swapindicestype.h"
#include "../utility.d/typedemultiplexer.h"
#include "../utility.d/typelist.h"

#include <cstddef>
#include <type_traits>

namespace crap
{
 template <template <class, class> class, class...> struct makeHeapType;

 template <template <class, class> class Operator> struct makeHeapType<Operator>
 {
  template <template <class...> class Container = typeList> using type = Container<>;
 };

 template <template <class, class> class Operator, class Type> struct makeHeapType<Operator, Type>
 {
  template <template <class...> class Container = typeList> using type = Container<Type>;
 };

 template <template <class, class> class Operator, class Type1, class Type2> struct makeHeapType<Operator, Type1, Type2>
 {
  private:
  constexpr const static bool unordered = Operator <Type1, Type2> :: value;
  public:
  template <template <class...> class Container = typeList>
	  using type = Container<typename std :: conditional <unordered, Type2, Type1> :: type, typename std :: conditional <unordered, Type1, Type2> :: type>;
 };

 template <template <class, class> class Operator, class ... Types> struct makeHeapType
 {
  private:
  constexpr const static std :: size_t lastNonLeaf = (sizeof...(Types) / 2u) - 1u;
  template <std :: size_t Node, std :: size_t Pass, class ... SubTypes> struct heapify;
  template <std :: size_t Node, class ... SubTypes> struct heapify<Node, 0u, SubTypes...>;
  public:
  template <template <class...> class Container = typeList> using type = typename heapify <lastNonLeaf, lastNonLeaf, Types...> :: template type<Container>;
 };

 template <template <class, class> class Operator, class ... Types>
	 template <std :: size_t Node, std :: size_t Pass, class ... SubTypes>
 struct makeHeapType <Operator, Types...> :: heapify
 {
  private:
  using types = typeList<SubTypes...>;
  constexpr const static std :: size_t leftChild = (2u * Node) + 1u;
  constexpr const static std :: size_t rightChild = (2u * Node) + 2u;
  constexpr const static std :: size_t leftToUse = ((leftChild < sizeof...(SubTypes)) ? leftChild : 0u);
  constexpr const static std :: size_t rightToUse = ((rightChild < sizeof...(SubTypes)) ? rightChild : 0u);
  using leftType = typename types :: template at<leftToUse>;
  using rightType = typename types :: template at<rightToUse>;
  using largestCandidate1Type = typename types :: template at<Node>;
  constexpr const static std :: size_t largestCandidate1 = ((leftChild < sizeof...(SubTypes)) && Operator <largestCandidate1Type, leftType> :: value) ? leftChild : Node;
  using largestCandidate2Type = typename types :: template at<largestCandidate1>;
  constexpr const static std :: size_t largest = ((rightChild < sizeof...(SubTypes)) && Operator <largestCandidate2Type, rightType> :: value) ? rightChild : largestCandidate1;
  template <class ... Data> using swappingRecurse = heapify <largest, Pass, Data...>;
  template <class ... Data> using swapping = typename swapIndicesType <Node, largest, Data...> :: template type<swappingRecurse>;
  template <class ... Data> using noSwapping = heapify <Pass - 1u, Pass - 1u, Data...>;
  public:
  template <template <class...> class Container>
	  using type = typename typeDemultiplexer <(largest == Node), copyType <SubTypes...> :: template type, noSwapping, swapping> :: type :: template type<Container>;
 };
 
 template <template <class, class> class Operator, class ... Types>
	 template <std :: size_t Node, class ... SubTypes>
 struct makeHeapType <Operator, Types...> :: template heapify<Node, 0u, SubTypes...>
 {
  private:
  using types = typeList<SubTypes...>;
  constexpr const static std :: size_t leftChild = (2u * Node) + 1u;
  constexpr const static std :: size_t rightChild = (2u * Node) + 2u;
  constexpr const static std :: size_t leftToUse = ((leftChild < sizeof...(SubTypes)) ? leftChild : 0u);
  constexpr const static std :: size_t rightToUse = ((rightChild < sizeof...(SubTypes)) ? rightChild : 0u);
  using leftType = typename types :: template at<leftToUse>;
  using rightType = typename types :: template at<rightToUse>;
  using largestCandidate1Type = typename types :: template at<Node>;
  constexpr const static std :: size_t largestCandidate1 = ((leftChild < sizeof...(SubTypes)) && Operator <largestCandidate1Type, leftType> :: value) ? leftChild : Node;
  using largestCandidate2Type = typename types :: template at<largestCandidate1>;
  constexpr const static std :: size_t largest = ((rightChild < sizeof...(SubTypes)) && Operator <largestCandidate2Type, rightType> :: value) ? rightChild : largestCandidate1;
  template <class ... Data> using swappingRecurse = heapify <largest, 0u, Data...>;
  template <class ... Data> using swapping = typename swapIndicesType <Node, largest, Data...> :: template type<swappingRecurse>;
  template <class ... Data> using noSwapping = copyType<Data...>;
  public:
  template <template <class...> class Container>
	  using type = typename typeDemultiplexer <(largest == Node), copyType <SubTypes...> :: template type, noSwapping, swapping> :: type :: template type<Container>;
 };
}
#endif

