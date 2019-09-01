#ifndef CRAP_UTILITY_VALUELIST
#define CRAP_UTILITY_VALUELIST

#include <utility>

#include "language.h"

namespace crap
{
 template <class Type, Type ... Values> struct valueList
 {
  private:
  constexpr const static Type values[sizeof...(Values)] = {Values...};
  template <Type ... SubValues> using This = valueList<Type, SubValues...>;
  template <template <std :: size_t> class Gen, std :: size_t ... Indices>
struct Generator;
  public:
  constexpr const static std :: size_t size = sizeof...(Values);
  template <std :: size_t N> struct At;
  template <std :: size_t N> struct Till;
  template <std :: size_t N> struct Since;
  template <std :: size_t N> friend struct valueList <Type, Values...> :: At;
  template <std :: size_t N> friend struct valueList <Type, Values...> :: Till;
  template <std :: size_t N> friend struct valueList <Type, Values...> :: Since;
  #if CPP14
  template <std :: size_t N> constexpr const static Type at = At <N> :: value;
  #endif
  template <std :: size_t N, template <Type...> class Container = This> using till = typename Till <N> :: template type<Container>;
  template <std :: size_t N, template <Type...> class Container = This> using since = typename Since <N> :: template type<Container>;
 };
}

#include "makeindexsequence.h"

namespace crap
{
 template <class Type, Type ... Values> template <template <std :: size_t> class Gen, std :: size_t ... Indices>
 struct valueList <Type, Values...> :: Generator
 {
  template <template <Type...> class Container> using type = Container<(Gen <Indices> :: value)...>;
 };

 template <class Type, Type ... Values> template <std :: size_t N> struct valueList <Type, Values...> :: At
 {
  private:
  static_assert(N < valueList <Type, Values...> :: size, "Index out of range.");
  public:
  constexpr const static auto value = valueList <Type, Values...> :: values[N];
 };

 template <class Type, Type ... Values> template <std :: size_t N> struct valueList <Type, Values...> :: Till
 {
  private:
  static_assert(N <= valueList <Type, Values...> :: size, "Index out of range.");
  template <std :: size_t Index> using valueAt = std :: integral_constant<Type, valueList <Type, Values...> :: values[Index]>;
  template <Type ... SubValues> using This = typename valueList <Type, Values...> :: template This<SubValues...>;
  template <std :: size_t ... Indices> static typename valueList <Type, Values...> :: template Generator<valueAt, Indices...>
  //generate(std :: index_sequence<Indices...>);
  generate(indexSequence<Indices...>);
  //using generator = decltype(generate(std :: make_index_sequence<N>{}));
  using generator = decltype(generate(makeIndexSequence<N>{}));
  public:
  template <template <Type... > class Container = This> using type = typename generator :: template type<Container>;
 };

 template <class Type, Type ... Values> template <std :: size_t N> struct valueList <Type, Values...> :: Since
 {
  private:
  static_assert(N <= valueList <Type, Values...> :: size, "Index out of range.");
  template <std :: size_t Index> using valueAt = std :: integral_constant<Type, valueList <Type, Values...> :: values[N + Index]>;
  template <Type ... SubValues> using This = typename valueList <Type, Values...> :: template This<SubValues...>;
  template <std :: size_t ... Indices> static typename valueList <Type, Values...> :: template Generator<valueAt, Indices...>
  //generate(std :: index_sequence<Indices...>);
  generate(indexSequence<Indices...>);
  //using generator = decltype(generate(std :: make_index_sequence<valueList <Type, Values...> :: size - N>{}));
  using generator = decltype(generate(makeIndexSequence<valueList <Type, Values...> :: size - N>{}));
  public:
  template <template <Type...> class Container = This> using type = typename generator :: template type<Container>;
 };
}
#endif

