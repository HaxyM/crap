#ifndef CRAP_ALGORITHM_PUSHHEAPVALUE
#define CRAP_ALGORITHM_PUSHHEAPVALUE

#include "../utility/valuelist.h"
#include "../utility/valuelistfortype.h"
#include "../utility/valuemultiplexer.h"

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
  template <std :: size_t Index>
	  using parentOf = std :: integral_constant<std :: size_t, (Index == 0u) ? 0u : ((Index - 1u) / 2u)>;
  template <std :: size_t Index, template <std :: size_t> class ParentIndexer, Type ... SubValues>
	  struct Implementation;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename Implementation<sizeof...(Values) - 1u, parentOf, Values...> :: template type<Container>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <std :: size_t Index, template <std :: size_t> class ParentIndexer, Type ... SubValues>
 struct pushHeapValue <Type, Operator, Values...> :: Implementation
 {
  private:
  constexpr const static std :: size_t parentIndex = ParentIndexer <Index> :: value;
  using subValues = valueList<Type, SubValues...>;
  constexpr const static Type parent = subValues :: template At <parentIndex> :: value;
  constexpr const static Type child = subValues :: template At <Index> :: value;
  constexpr const static bool needSwap = Operator <parent, child> :: value;
  template <Type ... NewValues>
	  using Next = typename pushHeapValue <Type, Operator, Values...> :: template
	  Implementation<parentIndex, ParentIndexer, NewValues...>;
  template <std :: size_t ParentIndex, Type Parent, Type Child> struct makeSwap;
  template <template <Type...> class Container> using nonSwappingSource = Container<SubValues...>;
  template <Type Parent, Type Child, template <std :: size_t, Type, Type> class Swapper, template <Type...> class ContinueWith, template <Type...> class Container> 
	  struct swappingSourceConstructor;
  template <template <Type...> class Container>
	  using swappingSource = typename swappingSourceConstructor <parent, child, makeSwap, Next, Container> :: type;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename valueMultiplexer <Type, needSwap, Container, swappingSource, nonSwappingSource> :: type;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <std :: size_t Index, template <std :: size_t> class ParentIndexer, Type ... SubValues>
	 template <std :: size_t ParentIndex, Type Parent, Type Child>
 struct pushHeapValue <Type, Operator, Values...> :: template
	 Implementation <Index, ParentIndexer, SubValues...> ::
	 makeSwap
 {
  private:
  using subValues = valueList<Type, SubValues...>;
  template <Type ... Ancestors> struct swap;
  template <Type ... Sibblings>
	  using ancestors = typename subValues :: template
	  till <ParentIndex, swap> :: template withSibblings<Sibblings...>;
  template <Type ... Offsprings>
	  using sibblings = typename subValues :: template
	  subRange<ParentIndex + 1u, Index, ancestors> :: template withOffsprings<Offsprings...>;
  public:
  template <template <Type...> class Container>
	  using type = typename subValues :: template since <Index + 1u, sibblings> :: template type<Container>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <std :: size_t Index, template <std :: size_t> class ParentIndexer, Type ... SubValues>
	 template <Type Parent, Type Child, template <std :: size_t, Type, Type> class Swapper, template <Type...> class ContinueWith, template <Type...> class Container>
 struct pushHeapValue <Type, Operator, Values...> :: template
	 Implementation <Index, ParentIndexer, SubValues...> ::
	 swappingSourceConstructor
 {
  using type = typename Swapper <parentIndex, Parent, Child> :: template type <ContinueWith> :: template type<Container>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <std :: size_t Index, template <std :: size_t> class ParentIndexer, Type ... SubValues>
	 template <std :: size_t ParentIndex, Type Parent, Type Child>
	 template <Type ... Ancestors>
 struct pushHeapValue <Type, Operator, Values...> :: template
	 Implementation <Index, ParentIndexer, SubValues...> :: template
	 makeSwap <ParentIndex, Parent, Child> ::
	 swap
 {
  template <Type ... Sibblings> struct withSibblings;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <std :: size_t Index, template <std :: size_t> class ParentIndexer, Type ... SubValues>
	 template <std :: size_t ParentIndex, Type Parent, Type Child>
	 template <Type ... Ancestors> template <Type ... Sibblings>
 struct pushHeapValue <Type, Operator, Values...> :: template
	 Implementation <Index, ParentIndexer, SubValues...> :: template
	 makeSwap <ParentIndex, Parent, Child> :: template
	 swap <Ancestors...> ::
	 withSibblings
 {
  template <Type ... Offsprings> struct withOffsprings;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <std :: size_t Index, template <std :: size_t> class ParentIndexer, Type ... SubValues>
	 template <std :: size_t ParentIndex, Type Parent, Type Child>
	 template <Type ... Ancestors>
	 template <Type ... Sibblings>
	 template <Type ... Offsprings>
 struct pushHeapValue <Type, Operator, Values...> :: template
	 Implementation <Index, ParentIndexer, SubValues...> :: template
	 makeSwap <ParentIndex, Parent, Child> :: template
	 swap <Ancestors...> :: template
	 withSibblings <Sibblings...> ::
	 withOffsprings
 {
  template <template <Type...> class Container>
	  using type = Container<Ancestors..., Child, Sibblings..., Parent, Offsprings...>;
 };
}
#endif

