#ifndef CRAP_ALGORITHM_PUSHHEAPVALUE
#define CRAP_ALGORITHM_PUSHHEAPVALUE

#include "copyfortype.h"
#include "../utility/swapindicesvalue.h"
#include "../utility/valuelist.h"
#include "../utility/valuelistfortype.h"
#include "../utility/valuedemultiplexer.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct pushHeapValue;

 template <class Type, template <Type, Type> class Operator> struct pushHeapValue<Type, Operator>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<>;
 };

 template <class Type, template <Type, Type> class Operator, Type Value>
	 struct pushHeapValue<Type, Operator, Value>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<Value>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> struct pushHeapValue
 {
  private:
  template <std :: size_t ChildIndex, Type ... SubValues> struct Implementation;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename Implementation <sizeof...(Values) - 1u, Values...> :: template type<Container>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <std :: size_t ChildIndex, Type ... SubValues>
	 struct pushHeapValue <Type, Operator, Values...> :: Implementation
 {
  private:
  using subValues = valueList<Type, SubValues...>;
  constexpr const static std :: size_t ParentIndex = ((ChildIndex == 0u) ? 0u : ((ChildIndex - 1u) / 2u));
  constexpr const static Type parent = subValues :: template At <ParentIndex> :: value;
  constexpr const static Type child = subValues :: template At <ChildIndex> :: value;
  constexpr const static bool needSwap = Operator <parent, child> :: value;
  template <Type ... NewValues> using NextStep = Implementation<ParentIndex, NewValues...>;
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

