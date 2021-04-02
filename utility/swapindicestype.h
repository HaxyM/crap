#ifndef CRAP_UTILITY_SWAPINDICESTYPE
#define CRAP_UTILITY_SWAPINDICESTYPE

#include "typelist.h"

#include <cstddef>

namespace crap
{
 template <std :: size_t, std :: size_t, class...> struct swapIndicesType;

 template <std :: size_t Index, class ... Types> struct swapIndicesType<Index, Index, Types...>
 {
  private:
  static_assert(Index < sizeof...(Types), "Index out of range.");
  public:
  template <template <class...> class Container = typeList>
	  using type = Container<Types...>;
 };

 template <std :: size_t Index1, std :: size_t Index2, class ... Types> struct swapIndicesType
 {
  private:
  static_assert(Index1 < sizeof...(Types), "Index out of range.");
  static_assert(Index2 < sizeof...(Types), "Index out of range.");
  template <class ... Ancestors> struct withAncestors;
  constexpr const static std :: size_t index1 = ((Index1 < Index2) ? Index1 : Index2);
  public:
  template <template <class...> class Container = typeList>
	  using type = typename typeList <Types...> :: template
	  till<index1, withAncestors> :: template type<Container>;
 };

 template <std :: size_t Index1, std :: size_t Index2, class ... Types>
	 template <class ... Ancestors>
 struct swapIndicesType <Index1, Index2, Types...> :: withAncestors
 {
  private:
  template <class ... Sibblings> struct withSibblings;
  constexpr const static std :: size_t index1 = ((Index1 < Index2) ? Index1 : Index2);
  constexpr const static std :: size_t index2 = ((Index1 < Index2) ? Index2 : Index1);
  public:
  template <template <class...> class Container>
	  using type = typename typeList <Types...> :: template
	  subRange <index1 + 1u, index2, withSibblings> :: template type<Container>;
 };

 template <std :: size_t Index1, std :: size_t Index2, class ... Types>
	 template <class ... Ancestors>
	 template <class ... Sibblings>
 struct swapIndicesType <Index1, Index2, Types...> :: template
 	withAncestors <Ancestors...> :: withSibblings
 {
   private:
   template <class ... Offsprings> struct withOffsprings;
   constexpr const static std :: size_t index2 = ((Index1 < Index2) ? Index2 : Index1);
   public:
   template <template <class...> class Container>
	   using type = typename typeList <Types...> :: template
	   since <index2 + 1u, withOffsprings> :: template type<Container>;
 };

 template <std :: size_t Index1, std :: size_t Index2, class ... Types>
	  template <class ... Ancestors>
	  template <class ... Sibblings>
	  template <class ... Offsprings>
 struct swapIndicesType <Index1, Index2, Types...> :: template
  	withAncestors <Ancestors...> :: template
	withSibblings <Sibblings...> :: withOffsprings
 {
  private:
  template <std :: size_t Index> using valueAt = typename typeList <Types...> :: template at<Index>;
  constexpr const static std :: size_t index1 = ((Index1 < Index2) ? Index1 : Index2);
  constexpr const static std :: size_t index2 = ((Index1 < Index2) ? Index2 : Index1);
  public:
  template <template <class...> class Container>
	  using type = Container<Ancestors..., valueAt <index2> :: value, Sibblings..., valueAt <index1> :: value, Offsprings...>;
 };
}
#endif
