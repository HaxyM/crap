#ifndef CRAP_ALGORITHM_PUSHHEAPTYPE
#define CRAP_ALGORITHM_PUSHHEAPTYPE

#include "copytype.h"
#include "../utility.d/swapindicestype.h"
#include "../utility.d/typelist.h"
#include "../utility.d/typedemultiplexer.h"

#include <cstddef>

namespace crap
{
 template <template <class, class> class, class...> struct pushHeapType;

 template <template <class, class> class Operator> struct pushHeapType<Operator>
 {
  template <template <class...> class Container = typeList>
	  using type = Container<>;
 };

 template <template <class, class> class Operator, class Type>
	 struct pushHeapType<Operator, Type>
 {
  template <template <class...> class Container = typeList>
	  using type = Container<Type>;
 };

 template <template <class, class> class Operator, class ... Types> struct pushHeapType
 {
  private:
  template <std :: size_t ChildIndex, class ... SubTypes> struct Implementation;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename Implementation <sizeof...(Types) - 1u, Types...> :: template type<Container>;
 };

 template <template <class, class> class Operator, class ... Types>
	 template <std :: size_t ChildIndex, class ... SubTypes>
	 struct pushHeapType <Operator, Types...> :: Implementation
 {
  private:
  constexpr const static std :: size_t ParentIndex = ((ChildIndex == 0u) ? 0u : ((ChildIndex - 1u) / 2u));
  using parent = typename typeList <SubTypes...> :: template at<ParentIndex>;
  using child = typename typeList <SubTypes...> :: template at<ChildIndex>;
  constexpr const static bool needSwap = Operator <parent, child> :: value;
  template <class ... NewTypes> using NextStep = Implementation<ParentIndex, NewTypes...>;
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

