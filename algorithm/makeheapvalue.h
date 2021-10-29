#ifndef CRAP_ALGORITHM_MAKEHEAPVALUE
#define CRAP_ALGORITHM_MAKEHEAPVALUE

#include "copyvalue.h"
#include "../utility/swapindicesvalue.h"
#include "../utility/valuedemultiplexer.h"
#include "../utility/valuelistfortype.h"

#include <cstddef>

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct makeHeapValue;

 template <class Type, template <Type, Type> class Operator> struct makeHeapValue<Type, Operator>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<>;
 };

 template <class Type, template <Type, Type> class Operator, Type Value> struct makeHeapValue<Type, Operator, Value>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<Value>;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2> struct makeHeapValue<Type, Operator, Value1, Value2>
 {
  private:
  constexpr const static bool unordered = Operator <Value1, Value2> :: value;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container <(unordered ? Value2 : Value1), (unordered ? Value1 : Value2)>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> struct makeHeapValue
 {
  private:
  constexpr const static std :: size_t lastNonLeaf = (sizeof...(Values) / 2u) - 1u;
  template <std :: size_t Node, std :: size_t Pass, Type ... SubValues> struct heapify;
  template <std :: size_t Node, Type ... SubValues> struct heapify<Node, 0u, SubValues...>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = typename heapify <lastNonLeaf, lastNonLeaf, Values...> :: template type<Container>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> template <std :: size_t Node, std :: size_t Pass, Type ... SubValues> struct makeHeapValue <Type, Operator, Values...> :: heapify
 {
  private:
  using values = valueList<Type, SubValues...>;
  constexpr const static std :: size_t leftChild = (2u * Node) + 1u;
  constexpr const static std :: size_t rightChild = (2u * Node) + 2u;
  constexpr const static std :: size_t leftToUse = ((leftChild < sizeof...(SubValues)) ? leftChild : 0u);
  constexpr const static std :: size_t rightToUse = ((rightChild < sizeof...(SubValues)) ? rightChild : 0u);
  constexpr const static Type leftValue = values :: template At <leftToUse> :: value;
  constexpr const static Type rightValue = values :: template At <rightToUse> :: value;
  constexpr const static Type largestCandidate1Value = values :: template At <Node> :: value;
  constexpr const static std :: size_t largestCandidate1 = ((leftChild < sizeof...(SubValues)) && Operator <largestCandidate1Value, leftValue> :: value) ? leftChild : Node;
  constexpr const static Type largestCandidate2Value = values :: template At <largestCandidate1> :: value;
  constexpr const static std :: size_t largest = ((rightChild < sizeof...(SubValues)) && Operator <largestCandidate2Value, rightValue> :: value) ? rightChild : largestCandidate1;
  template <Type ... Data> using swappingRecurse = heapify <largest, Pass, Data...>;
  template <Type ... Data> using swapping = typename swapIndicesValue <Type, Node, largest, Data...> :: template type<swappingRecurse>;
  template <Type ... Data> using noSwapping = heapify <Pass - 1u, Pass - 1u, Data...>;
  public:
  template <template <Type...> class Container> using type = typename valueDemultiplexer <Type, (largest == Node), copyValue <Type, SubValues...> :: template type, noSwapping, swapping> :: type :: template type<Container>;
 };
 
 template <class Type, template <Type, Type> class Operator, Type ... Values> template <std :: size_t Node, Type ... SubValues> struct makeHeapValue <Type, Operator, Values...> :: heapify<Node, 0u, SubValues...>
 {
  private:
  using values = valueList<Type, SubValues...>;
  constexpr const static std :: size_t leftChild = (2u * Node) + 1u;
  constexpr const static std :: size_t rightChild = (2u * Node) + 2u;
  constexpr const static std :: size_t leftToUse = ((leftChild < sizeof...(SubValues)) ? leftChild : 0u);
  constexpr const static std :: size_t rightToUse = ((rightChild < sizeof...(SubValues)) ? rightChild : 0u);
  constexpr const static Type leftValue = values :: template At <leftToUse> :: value;
  constexpr const static Type rightValue = values :: template At <rightToUse> :: value;
  constexpr const static Type largestCandidate1Value = values :: template At <Node> :: value;
  constexpr const static std :: size_t largestCandidate1 = ((leftChild < sizeof...(SubValues)) && Operator <largestCandidate1Value, leftValue> :: value) ? leftChild : Node;
  constexpr const static Type largestCandidate2Value = values :: template At <largestCandidate1> :: value;
  constexpr const static std :: size_t largest = ((rightChild < sizeof...(SubValues)) && Operator <largestCandidate2Value, rightValue> :: value) ? rightChild : largestCandidate1;
  template <Type ... Data> using swappingRecurse = heapify <largest, 0u, Data...>;
  template <Type ... Data> using swapping = typename swapIndicesValue <Type, Node, largest, Data...> :: template type<swappingRecurse>;
  template <Type ... Data> using noSwapping = copyValue<Type, Data...>;
  public:
  template <template <Type...> class Container> using type = typename valueDemultiplexer <Type, (largest == Node), copyValue <Type, SubValues...> :: template type, noSwapping, swapping> :: type :: template type<Container>;
 };
}
#endif

