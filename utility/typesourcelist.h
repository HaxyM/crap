#ifndef CRAP_UTILITY_TYPESOURCELIST
#define CRAP_UTILITY_TYPESOURCELIST

#include "makeindexsequence.h"

#include <utility>

namespace crap
{
 template <template <template <class...> class> class ... StoredSources> struct typeSourceList
 {
  private:
  struct ignore;
  template <template <template <class...> class> class Source> struct identity;
  template <template <template <class...> class> class ... SubSources> struct Generator;
  template <std :: size_t ... Indices> struct Impl;
  template <std :: size_t ... Indices> friend struct typeSourceList <StoredSources...> :: Impl;
  template <template <template <class...> class> class ... SubSources> using This = typeSourceList<SubSources...>;
  public:
  template <std :: size_t N> struct At;
  template <std :: size_t N> struct Till;
  template <std :: size_t N> struct Since;
  template <std :: size_t N> friend struct typeSourceList <StoredSources...> :: At;
  template <std :: size_t N> friend struct typeSourceList <StoredSources...> :: Till;
  template <std :: size_t N> friend struct typeSourceList <StoredSources...> :: Since;
  constexpr const static std :: size_t size = sizeof...(StoredSources);
  template <std :: size_t N, template <template <template <class...> class> class...> class SourcesContainer = This>
	  using till = typename Till <N> :: template type<SourcesContainer>;
  template <std :: size_t N, template <template <template <class...> class> class...> class SourcesContainer = This>
	  using since = typename Since <N> :: template type<SourcesContainer>;
 };
 
 template <template <template <class...> class> class ... StoredSources>
 struct typeSourceList <StoredSources...> :: ignore
 {
  ignore(...){}
 };
 
 template <template <template <class...> class> class ... StoredSources> template <template <template <class...> class> class Source>
	 struct typeSourceList <StoredSources...> :: identity
 {
  template <template <class...> class Container> using type = Source<Container>;
 };
 
 template <template <template <class...> class> class ... StoredSources>
	 template <template <template <class...> class> class ... SubSources>
	 struct typeSourceList <StoredSources...> :: Generator
 {
  template <template <template <template <class...> class> class...> class SourceContainer> using type = SourceContainer<SubSources...>;
 };
 
 template <template <template <class...> class> class ... StoredSources> template <std :: size_t ... Indices>
	 struct typeSourceList <StoredSources...> :: Impl
 {
  using ignore = typeSourceList <StoredSources...> :: ignore;
  template <template <template <class...> class> class SubSource>
 	 using identity = typename typeSourceList <StoredSources...> :: template identity<SubSource>;
  template <template <template <class...> class> class NthSource> static identity<NthSource>
	  generateAt(decltype(ignore{Indices})..., identity<NthSource>,...);
  template <template <template <class...> class> class ... SubSources> static
	  typename typeSourceList <StoredSources...> :: template Generator<SubSources...>
	  generateSince(decltype(ignore{Indices})..., identity<SubSources>...);
 };
 
 template <template <template <class...> class> class ... StoredSources> template <std :: size_t N>
	 struct typeSourceList <StoredSources...> :: At
 {
  private:
  static_assert(N < typeSourceList <StoredSources...> :: size, "Index out of range.");
  template <std :: size_t ... Indices> static
	  typename typeSourceList <StoredSources...> :: template Impl<Indices...>
	  generate(indexSequence <Indices...>);
  using impl = decltype(generate(makeIndexSequence<N>{}));
  public:
  template <template <class...> class Container>
	  using type = typename decltype(impl :: generateAt(typename impl :: template identity<StoredSources>{}...)) :: template type<Container>;
 };
 
 template <template <template <class...> class> class ... StoredSources> template <std :: size_t N>
	 struct typeSourceList <StoredSources...> :: Till
 {
  private:
  template <template <template <class...> class> class ... SubSources>
	  using This = typename typeSourceList <StoredSources...> :: template This<SubSources...>;
  template <std :: size_t Index> using sourceAt = typename typeSourceList <StoredSources...> :: template At<Index>;
  template <std :: size_t ... Indices> static
	  typename typeSourceList <StoredSources...> :: template Generator<sourceAt <Indices> :: template type...>
	  generate(indexSequence<Indices...>);
  static_assert(N <= typeSourceList <StoredSources...> :: size, "Index out of range.");
  public:
  template <template <template <template <class...> class> class...> class SourceContainer = This>
	  using type = typename decltype(generate(makeIndexSequence<N>{})) :: template type<SourceContainer>;
 };
 
 template <template <template <class...> class> class ... StoredSources> template <std :: size_t N>
	 struct typeSourceList <StoredSources...> :: Since
 {
  private:
  static_assert(N <= typeSourceList <StoredSources...> :: size, "Index out of range.");
  template <template <template <class...> class> class ... SubSources>
	  using This = typename typeSourceList <StoredSources...> :: template This<SubSources...>;
  template <std :: size_t ... Indices> static 
	  typename typeSourceList < StoredSources...> :: template Impl<Indices...>
	  generate(indexSequence<Indices...>);
  using impl = decltype(generate(makeIndexSequence<N>{}));
  public:
  template <template <template <template <class...> class> class...> class SourceContainer = This>
	  using type = typename decltype(impl :: generateSince(typename impl :: template identity<StoredSources>{}...)) :: template type<SourceContainer>;
 };
}
#endif

