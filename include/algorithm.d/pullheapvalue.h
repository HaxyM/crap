#ifndef CRAP_ALGORITHM_PULLHEAPVALUE
#define CRAP_ALGORITHM_PULLHEAPVALUE

#include "copyfortype.h"
#include "../utility.d/swapindicesvalue.h"
#include "../utility.d/valuelist.h"
#include "../utility.d/valuelistfortype.h"
#include "../utility.d/valuedemultiplexer.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct pullHeapValue;

 template <class Type, template <Type, Type> class Operator> struct pullHeapValue<Type, Operator>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<>;
 };

 template <class Type, template <Type, Type> class Operator, Type Value>
	 struct pullHeapValue<Type, Operator, Value>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<Value>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> struct pullHeapValue
 {
  private:
  template <std :: size_t ParentIndex, Type ... SubValues> struct Implementation;
  template <Type ... SubValues> using ImplementationContainer = Implementation<0u, SubValues...>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename swapIndicesValue <Type, 0u, (sizeof...(Values) - 1u), Values...> :: template
	  type <ImplementationContainer> :: template type<Container>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <std :: size_t ParentIndex, Type ... SubValues>
	 struct pullHeapValue <Type, Operator, Values...> :: Implementation
 {
  private:
  using subValues = valueList<Type, SubValues...>;
  constexpr const static std :: size_t LeftChildIndex = (2u * ParentIndex) + 1u;
  constexpr const static std :: size_t RightChildIndex = (2u * ParentIndex) + 2u;
  constexpr const static bool hasLeftChild = (LeftChildIndex < (subValues :: size - 1u));
  constexpr const static bool hasRightChild = (RightChildIndex < (subValues :: size - 1u));
  constexpr const static Type leftChild = subValues :: template At <hasLeftChild ? LeftChildIndex : ParentIndex> :: value;
  constexpr const static Type rightChild = subValues :: template At <hasRightChild ? RightChildIndex : ParentIndex> :: value;
  constexpr const static std :: size_t ChildIndex = ((hasRightChild && (Operator <leftChild, rightChild> :: value)) ? RightChildIndex : LeftChildIndex);
  constexpr const static Type parent = subValues :: template At <ParentIndex> :: value;
  constexpr const static Type child = subValues :: template At <hasLeftChild ? ChildIndex : ParentIndex> :: value;
  constexpr const static bool needSwap = hasLeftChild && (Operator <parent, child> :: value);
  template <Type ... NewValues> using NextStep = Implementation<ChildIndex, NewValues...>;
  template <Type ... NewValues>
	  using goWithSwap = typename swapIndicesValue <Type, ParentIndex, ChildIndex, NewValues...> :: template type<NextStep>;
  template <template <template <Type...> class> class Source>
	  using selector = valueDemultiplexer<Type, needSwap, Source, goWithSwap, copyForType <Type> :: template type>;
  template <template <Type...> class Container> using Source = Container<SubValues...>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename selector <Source> :: type :: template type<Container>;
 };
}
#endif
