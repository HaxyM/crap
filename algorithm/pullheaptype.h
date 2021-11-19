#ifndef CRAP_ALGORITHM_PULLHEAPTYPE
#define CRAP_ALGORITHM_PULLHEAPTYPE

#include "copytype.h"
#include "../utility/swapindicestype.h"
#include "../utility/typelist.h"
#include "../utility/typedemultiplexer.h"

#include <cstddef>

namespace crap
{
 template <template <class, class> class, class...> struct pullHeapType;

 template <template <class, class> class Operator> struct pullHeapType<Operator>
 {
  template <template <class...> class Container = typeList>
	  using type = Container<>;
 };

 template <template <class, class> class Operator, class Type>
	 struct pullHeapType<Operator, Type>
 {
  template <template <class...> class Container = typeList>
	  using type = Container<Type>;
 };

 template <template <class, class> class Operator, class ... Types> struct pullHeapType
 {
  private:
  template <std :: size_t ParentIndex, class ... SubTypes> struct Implementation;
  template <class ... SubTypes> using ImplementationContainer = Implementation<0u, SubTypes...>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename swapIndicesType <0u, (sizeof...(Types) - 1u), Types...> :: template
	  type <ImplementationContainer> :: template type<Container>;
 };

 template <template <class, class> class Operator, class ... Types>
	 template <std :: size_t ParentIndex, class ... SubTypes>
	 struct pullHeapType <Operator, Types...> :: Implementation
 {
  private:
  using subTypes = typeList<SubTypes...>;
  constexpr const static std :: size_t LeftChildIndex = (2u * ParentIndex) + 1u;
  constexpr const static std :: size_t RightChildIndex = (2u * ParentIndex) + 2u;
  constexpr const static bool hasLeftChild = (LeftChildIndex < (subTypes :: size - 1u));
  constexpr const static bool hasRightChild = (RightChildIndex < (subTypes :: size - 1u));
  using leftChild = typename subTypes :: template at<hasLeftChild ? LeftChildIndex : ParentIndex>;
  using rightChild = typename subTypes :: template at<hasRightChild ? RightChildIndex : ParentIndex>;
  constexpr const static std :: size_t ChildIndex =
	  ((hasRightChild && (Operator <leftChild, rightChild> :: value)) ? RightChildIndex : LeftChildIndex);
  using parent = typename subTypes :: template at<ParentIndex>;
  using child = typename subTypes :: template at<hasLeftChild ? ChildIndex : ParentIndex>;
  constexpr const static bool needSwap = hasLeftChild && (Operator <parent, child> :: value);
  template <class ... NewTypes> using NextStep = Implementation<ChildIndex, NewTypes...>;
  template <class ... NewTypes>
	  using goWithSwap = typename swapIndicesType <ParentIndex, ChildIndex, NewTypes...> :: template
	  type<NextStep>;
  template <template <template <class...> class> class Source>
	  using selector = typeDemultiplexer<needSwap, Source, goWithSwap, copyType>;
  template <template <class...> class Container> using Source = Container<SubTypes...>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename selector <Source> :: type :: template type<Container>;
 };
}
#endif
