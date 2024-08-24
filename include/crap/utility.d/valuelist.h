#ifndef CRAP_UTILITY_VALUELIST
#define CRAP_UTILITY_VALUELIST

#include <cstddef>
#include <utility>

#include "../version.d/variabletemplates.h"

namespace crap
{
 template <class Type, Type...> struct valueList;

 template <class Type> struct valueList<Type>
 {
  private:
  template <Type ... SubValues> using This = valueList<Type, SubValues...>;
  public:
  constexpr const static std :: size_t size = 0u;
  constexpr const static std :: size_t begin = 0u;
  constexpr const static std :: size_t end = 0u;
  template <std :: size_t N> struct At;
  template <std :: size_t N> struct Till;
  template <std :: size_t N> struct Since;
  template <std :: size_t Begin, std :: size_t End> struct SubRange;

#if (crap_variable_templates >= 201304L)
  template <std :: size_t N> constexpr const static Type at = At <N> :: value;
#endif
  constexpr static std :: nullptr_t data() noexcept;
  template <template <Type...> class Container = This> using copy = Container<>;
  template <std :: size_t N, template <Type...> class Container = This>
	  using till = typename Till <N> :: template type<Container>;
  template <std :: size_t N, template <Type...> class Container = This>
	  using since = typename Since <N> :: template type<Container>;
  template <std :: size_t Begin, std :: size_t End, template <Type...> class Container = This>
	  using subRange = typename SubRange <Begin, End> :: template type<Container>;
 };

 template <class Type, Type ... Values> struct valueList
 {
  private:
  constexpr const static Type values[sizeof...(Values)] = {Values...};
  template <Type ... SubValues> using This = valueList<Type, SubValues...>;
  template <template <std :: size_t> class Gen, std :: size_t ... Indices>
	  struct Generator;
  public:
  constexpr const static std :: size_t size = sizeof...(Values);
  constexpr const static std :: size_t begin = 0u;
  constexpr const static std :: size_t end = size;
  template <std :: size_t N> struct At;
  template <std :: size_t N> struct Till;
  template <std :: size_t N> struct Since;
  template <std :: size_t Begin, std :: size_t End> struct SubRange;
#ifndef _MSC_VER //Possibly issue with cl compiler or my misunderstanding of standard.
  template <std :: size_t N> friend struct valueList <Type, Values...> :: At;
  template <std :: size_t N> friend struct valueList <Type, Values...> :: Till;
  template <std :: size_t N> friend struct valueList <Type, Values...> :: Since;
  template <std :: size_t Begin, std :: size_t End> friend struct valueList <Type, Values...> :: SubRange;
#endif
 
#if (crap_variable_templates >= 201304L)
  template <std :: size_t N> constexpr const static Type at = At <N> :: value;
#endif
  constexpr const static Type (& data() noexcept)[sizeof...(Values)];
  template <template <Type...> class Container = This> using copy = Container<Values...>;
  template <std :: size_t N, template <Type...> class Container = This>
	  using till = typename Till <N> :: template type<Container>;
  template <std :: size_t N, template <Type...> class Container = This>
	  using since = typename Since <N> :: template type<Container>;
  template <std :: size_t Begin, std :: size_t End, template <Type...> class Container = This>
	  using subRange = typename SubRange <Begin, End> :: template type<Container>;
 };

 template <class Type> template <std :: size_t N> struct valueList <Type> :: At
 {
  static_assert(N < 0u, "Index out of range.");
 };

 template <class Type> template <std :: size_t N> struct valueList <Type> :: Till
 {
  static_assert(N <= 0u, "Index out of range.");
  template <template <Type... > class Container = This> using type = Container<>;
 };

 template <class Type> template <std :: size_t N> struct valueList <Type> :: Since
 {
  static_assert(N <= 0u, "Index out of range.");
  template <template <Type... > class Container = This> using type = Container<>;
 };

 template <class Type> template <std :: size_t Begin, std :: size_t End> struct valueList <Type> :: SubRange
 {
  static_assert(End <= 0u, "Index out of range.");
  static_assert(Begin <= End, "Negative range.");
  template <template <Type... > class Container = This> using type = Container<>;
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
  generate(indexSequence<Indices...>);
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
  generate(indexSequence<Indices...>);
  using generator = decltype(generate(makeIndexSequence<valueList <Type, Values...> :: size - N>{}));
  public:
  template <template <Type...> class Container = This> using type = typename generator :: template type<Container>;
 };

 template <class Type, Type ... Values> template <std :: size_t Begin, std :: size_t End> struct valueList <Type, Values...> :: SubRange
 {
  private:
  static_assert(End <= (valueList <Type, Values...> :: size), "Index out of range.");
  static_assert(Begin <= End, "Negative range.");
  template <std :: size_t Index> using valueAt = std :: integral_constant<Type, valueList <Type, Values...> :: values[Begin + Index]>;
  template <Type ... SubValues> using This = typename valueList <Type, Values...> :: template This<SubValues...>;
  template <std :: size_t ... Indices> static typename valueList <Type, Values...> :: template Generator<valueAt, Indices...>
  generate(indexSequence<Indices...>);
  using generator = decltype(generate(makeIndexSequence<End - Begin>{}));
  public:
  template <template <Type...> class Container = This> using type = typename generator :: template type<Container>;
 };
}

template <class Type>
inline constexpr std :: nullptr_t crap :: valueList <Type> :: data() noexcept
{
 return nullptr;
}

template <class Type, Type ... Values>
constexpr const Type crap :: valueList <Type, Values...> :: values[sizeof...(Values)];

template <class Type, Type ... Values>
inline constexpr const Type (& crap :: valueList <Type, Values...> :: data() noexcept)[sizeof...(Values)]
{
 return crap :: valueList <Type, Values...> :: values;
}
#endif

