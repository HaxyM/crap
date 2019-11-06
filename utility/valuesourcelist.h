#ifndef CRAP_UTILITY_VALUESOURCELIST
#define CRAP_UTILITY_VALUESOURCELIST

#include "makeindexsequence.h"

#include <utility>

namespace crap
{
 template <class Type, template <template <Type...> class> class ... StoredSources> struct valueSourceList
 {
  private:
  struct ignore;
  template <template <template <Type...> class> class Source> struct identity;
  template <template <template <Type...> class> class ... SubSources> struct Generator;
  template <std :: size_t ... Indices> struct Impl;
  template <std :: size_t ... Indices> friend struct valueSourceList <Type, StoredSources...> :: Impl;
  template <template <template <Type...> class> class ... SubSources> using This = valueSourceList<Type, SubSources...>;
  public:
  template <std :: size_t N> struct At;
  template <std :: size_t N> struct Till;
  template <std :: size_t N> struct Since;
  template <std :: size_t N> friend struct valueSourceList <Type, StoredSources...> :: At;
  template <std :: size_t N> friend struct valueSourceList <Type, StoredSources...> :: Till;
  template <std :: size_t N> friend struct valueSourceList <Type, StoredSources...> :: Since;
  constexpr const static std :: size_t size = sizeof...(StoredSources);
  template <std :: size_t N, template <template <template <Type...> class> class...> class SourcesContainer = This>
	  using till = typename Till <N> :: template type<SourcesContainer>;
  template <std :: size_t N, template <template <template <Type...> class> class...> class SourcesContainer = This>
	  using since = typename Since <N> :: template type<SourcesContainer>;
 };
 
 template <class Type, template <template <Type...> class> class ... StoredSources>
 struct valueSourceList <Type, StoredSources...> :: ignore
 {
  ignore(...){}
 };
 
 template <class Type, template <template <Type...> class> class ... StoredSources> template <template <template <Type...> class> class Source>
	 struct valueSourceList <Type, StoredSources...> :: identity
 {
  template <template <Type...> class Container> using type = Source<Container>;
 };
 
 template <class Type, template <template <Type...> class> class ... StoredSources>
	 template <template <template <Type...> class> class ... SubSources>
	 struct valueSourceList <Type, StoredSources...> :: Generator
 {
  template <template <template <template <Type...> class> class...> class SourceContainer> using type = SourceContainer<SubSources...>;
 };
 
 template <class Type, template <template <Type...> class> class ... StoredSources> template <std :: size_t ... Indices>
	 struct valueSourceList <Type, StoredSources...> :: Impl
 {
  using ignore = valueSourceList <Type, StoredSources...> :: ignore;
  template <template <template <Type...> class> class SubSource>
 	 using identity = typename valueSourceList <Type, StoredSources...> :: template identity<SubSource>;
  template <template <template <Type...> class> class NthSource> static identity<NthSource>
	  generateAt(decltype(ignore{Indices})..., identity<NthSource>,...);
  template <template <template <Type...> class> class ... SubSources> static
	  typename valueSourceList <Type, StoredSources...> :: template Generator<SubSources...>
	  generateSince(decltype(ignore{Indices})..., identity<SubSources>...);
 };
 
 template <class Type, template <template <Type...> class> class ... StoredSources> template <std :: size_t N>
	 struct valueSourceList <Type, StoredSources...> :: At
 {
  private:
  static_assert(N < valueSourceList <Type, StoredSources...> :: size, "Index out of range.");
  template <std :: size_t ... Indices> static
	  typename valueSourceList <Type, StoredSources...> :: template Impl<Indices...>
	  generate(indexSequence <Indices...>);
  using impl = decltype(generate(makeIndexSequence<N>{}));
  public:
  template <template <Type...> class Container>
	  using type = typename decltype(impl :: generateAt(typename impl :: template identity<StoredSources>{}...)) :: template type<Container>;
 };
 
 template <class Type, template <template <Type...> class> class ... StoredSources> template <std :: size_t N>
	 struct valueSourceList <Type, StoredSources...> :: Till
 {
  private:
  template <template <template <Type...> class> class ... SubSources>
	  using This = typename valueSourceList <Type, StoredSources...> :: template This<SubSources...>;
  template <std :: size_t Index> using sourceAt = typename valueSourceList <Type, StoredSources...> :: template At<Index>;
  template <std :: size_t ... Indices> static
	  typename valueSourceList <Type, StoredSources...> :: template Generator<sourceAt <Indices> :: template type...>
	  generate(indexSequence<Indices...>);
  static_assert(N <= valueSourceList <Type, StoredSources...> :: size, "Index out of range.");
  public:
  template <template <template <template <Type...> class> class...> class SourceContainer = This>
	  using type = typename decltype(generate(makeIndexSequence<N>{})) :: template type<SourceContainer>;
 };
 
 template <class Type, template <template <Type...> class> class ... StoredSources> template <std :: size_t N>
	 struct valueSourceList <Type, StoredSources...> :: Since
 {
  private:
  static_assert(N <= valueSourceList <Type, StoredSources...> :: size, "Index out of range.");
  template <template <template <Type...> class> class ... SubSources>
	  using This = typename valueSourceList <Type, StoredSources...> :: template This<SubSources...>;
  template <std :: size_t ... Indices> static 
	  typename valueSourceList <Type, StoredSources...> :: template Impl<Indices...>
	  generate(indexSequence<Indices...>);
  using impl = decltype(generate(makeIndexSequence<N>{}));
  public:
  template <template <template <template <Type...> class> class...> class SourceContainer = This>
	  using type = typename decltype(impl :: generateSince(typename impl :: template identity<StoredSources>{}...)) :: template type<SourceContainer>;
 };
}
#endif

