#ifndef CRAP_UTILITY_SWAPVALUE
#define CRAP_UTILITY_SWAPVALUE

#include "valuelist.h"
#include "valuelistfortype.h"

namespace crap
{
 template <class Type, std :: size_t, std :: size_t, Type...> struct swapIndicesValue;

 template <class Type, std :: size_t Index, Type ... Values> struct swapIndicesValue<Type, Index, Index, Values...>
 {
  private:
  static_assert(Index < sizeof...(Values), "Index out of range.");
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<Values...>;
 };

 template <class Type, std :: size_t Index1, std :: size_t Index2, Type ... Values> struct swapIndicesValue
 {
  private:
  static_assert(Index1 < sizeof...(Values), "Index out of range.");
  static_assert(Index2 < sizeof...(Values), "Index out of range.");
  template <Type ... Ancestors> struct withAncestors;
  constexpr const static std :: size_t index1 = ((Index1 < Index2) ? Index1 : Index2);
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename valueList <Type, Values...> :: template
	  Till<index1> :: template type <withAncestors> :: template type<Container>;
 };

 template <class Type, std :: size_t Index1, std :: size_t Index2, Type ... Values>
	 template <Type ... Ancestors>
 struct swapIndicesValue <Type, Index1, Index2, Values...> :: withAncestors
 {
  private:
  template <Type ... Sibblings> struct withSibblings;
  constexpr const static std :: size_t index1 = ((Index1 < Index2) ? Index1 : Index2);
  constexpr const static std :: size_t index2 = ((Index1 < Index2) ? Index2 : Index1);
  public:
  template <template <Type...> class Container>
	  using type = typename valueList <Type, Values...> :: template
	  SubRange <index1 + 1u, index2> :: template type <withSibblings> :: template type<Container>;
 };

 template <class Type, std :: size_t Index1, std :: size_t Index2, Type ... Values>
	 template <Type ... Ancestors>
	 template <Type ... Sibblings>
 struct swapIndicesValue <Type, Index1, Index2, Values...> :: template
 	withAncestors <Ancestors...> :: withSibblings
 {
   private:
   template <Type ... Offsprings> struct withOffsprings;
   constexpr const static std :: size_t index2 = ((Index1 < Index2) ? Index2 : Index1);
   public:
   template <template <Type...> class Container>
	   using type = typename valueList <Type, Values...> :: template
	   Since <index2 + 1u> :: template type <withOffsprings> :: template type<Container>;
 };

 template <class Type, std :: size_t Index1, std :: size_t Index2, Type ... Values>
	  template <Type ... Ancestors>
	  template <Type ... Sibblings>
	  template <Type ... Offsprings>
 struct swapIndicesValue <Type, Index1, Index2, Values...> :: template
  	withAncestors <Ancestors...> :: template
	withSibblings <Sibblings...> :: withOffsprings
 {
  private:
  template <std :: size_t Index> using valueAt = typename valueList <Type, Values...> :: template At<Index>;
  constexpr const static std :: size_t index1 = ((Index1 < Index2) ? Index1 : Index2);
  constexpr const static std :: size_t index2 = ((Index1 < Index2) ? Index2 : Index1);
  public:
  template <template <Type...> class Container>
	  using type = Container<Ancestors..., valueAt <index2> :: value, Sibblings..., valueAt <index1> :: value, Offsprings...>;
 };
}
#endif

