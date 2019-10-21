#ifndef CRAP_UTILITY_VALUECONTAINERLIST
#define CRAP_UTILITY_VALUECONTAINERLIST

#include <utility>

#include "makeindexsequence.h"

namespace crap
{
 template <class Type, template <Type...> class ... StoredContainers> struct valueContainerList
 {
  private:
  struct ignore;
  template <template <Type...> class Container> struct identity;
  template <template <Type...> class ... SubContainers> struct Generator;
  template <std :: size_t ... Indices> struct Impl;
  template <std :: size_t ... Indices> friend struct valueContainerList <Type, StoredContainers...> :: Impl;
  template <template <Type...> class ... Subcontainers> using This = valueContainerList<Type, Subcontainers...>;
  public:
  template <std :: size_t N> struct At;
  template <std :: size_t N> struct Till;
  template <std :: size_t N> struct Since;
  template <std :: size_t N> friend struct valueContainerList <Type, StoredContainers...> :: At;
  template <std :: size_t N> friend struct valueContainerList <Type, StoredContainers...> :: Till;
  template <std :: size_t N> friend struct valueContainerList <Type, StoredContainers...> :: Since;
  constexpr const static std :: size_t size = sizeof...(StoredContainers);
  template <std :: size_t N, template <template <Type...> class...> class Container = This>
	  using till = typename Till <N> :: template type<Container>;
  template <std :: size_t N, template <template <Type...> class...> class Container = This>
	  using since = typename Since <N> :: template type<Container>;
 };
 
 template <class Type, template <Type...> class ... StoredContainers>
 struct valueContainerList <Type, StoredContainers...> :: ignore
 {
  ignore(...){}
 };
 
 template <class Type, template <Type...> class ... StoredContainers> template <template <Type...> class Container>
	 struct valueContainerList <Type, StoredContainers...> :: identity
 {
  template <Type ... Values> using type = Container<Values...>;
 };
 
 template <class Type, template <Type...> class ... StoredContainers> template <template <Type...> class ... SubContainers>
	 struct valueContainerList <Type, StoredContainers...> :: Generator
 {
  template <template <template <Type...> class...> class Container> using type = Container<SubContainers...>;
 };
 
 template <class Type, template <Type...> class ... StoredContainers> template <std :: size_t ... Indices>
	 struct valueContainerList <Type, StoredContainers...> :: Impl
 {
  using ignore = valueContainerList <Type, StoredContainers...> :: ignore;
  template <template <Type...> class SubContainer>
 	 using identity = typename valueContainerList <Type, StoredContainers...> :: template identity<SubContainer>;
  template <template <Type...> class NthContainer> static identity<NthContainer>
	  generateAt(decltype(ignore{Indices})..., identity<NthContainer>,...);
  template <template <Type...> class ... SubContainers> static
	  typename valueContainerList <Type, StoredContainers...> :: template Generator<SubContainers...>
	  generateSince(decltype(ignore{Indices})..., identity<SubContainers>...);
 };
 
 template <class Type, template <Type...> class ... StoredContainers> template <std :: size_t N>
	 struct valueContainerList <Type, StoredContainers...> :: At
 {
  private:
  static_assert(N < valueContainerList <Type, StoredContainers...> :: size, "Index out of range.");
  template <std :: size_t ... Indices> static
	  typename valueContainerList <Type, StoredContainers...> :: template Impl<Indices...>
	  generate(indexSequence <Indices...>);
  using impl = decltype(generate(makeIndexSequence<N>{}));
  public:
  template <Type ... Values>
	  using type = typename decltype(impl :: generateAt(typename impl :: template identity<StoredContainers>{}...)) :: template type<Values...>;
 };
 
 template <class Type, template <Type...> class ... StoredContainers> template <std :: size_t N>
	 struct valueContainerList <Type, StoredContainers...> :: Till
 {
  private:
  template <template <Type...> class ... SubContainers>
	  using This = typename valueContainerList <Type, StoredContainers...> :: template This<SubContainers...>;
  template <std :: size_t Index> using containerAt = typename valueContainerList <Type, StoredContainers...> :: template At<Index>;
  template <std :: size_t ... Indices> static
	  typename valueContainerList <Type, StoredContainers...> :: template Generator<containerAt <Indices> :: template type...>
	  generate(indexSequence<Indices...>);
  static_assert(N <= valueContainerList <Type, StoredContainers...> :: size, "Index out of range.");
  public:
  template <template <template <Type...> class...> class Container = This>
	  using type = typename decltype(generate(makeIndexSequence<N>{})) :: template type<Container>;
 };
 
 template <class Type, template <Type...> class ... StoredContainers> template <std :: size_t N>
	 struct valueContainerList <Type, StoredContainers...> :: Since
 {
  private:
  static_assert(N <= valueContainerList <Type, StoredContainers...> :: size, "Index out of range.");
  template <template <Type...> class ... SubContainers>
	  using This = typename valueContainerList <Type, StoredContainers...> :: template This<SubContainers...>;
  template <std :: size_t ... Indices> static 
	  typename valueContainerList <Type, StoredContainers...> :: template Impl<Indices...>
	  generate(indexSequence<Indices...>);
  using impl = decltype(generate(makeIndexSequence<N>{}));
  public:
  template <template <template <Type...> class...> class Container = This>
	  using type = typename decltype(impl :: generateSince(typename impl :: template identity<StoredContainers>{}...)) :: template type<Container>;
 };
}
#endif

