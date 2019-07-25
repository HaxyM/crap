#ifndef CRAP_UTILITY_VALUELIST
#define CRAP_UTILITY_VALUELIST

#include <utility>

namespace crap
{
 template <class Type, Type ... Values> struct valueList
 {
  private:
  constexpr const static Type values[] = {Values...};
  template <std :: size_t N> struct At;
  template <std :: size_t N, template <Type...> class Container> struct Till;
  template <std :: size_t N, template <Type...> class Container> struct Since;
  template <std :: size_t N> friend struct valueList <Type, Values...> :: At;
  template <std :: size_t N, template <Type...> class Container> friend struct valueList <Type, Values...> :: Till;
  template <std :: size_t N, template <Type...> class Container> friend struct valueList <Type, Values...> :: Since;
  template <Type ... SubValues> using This = valueList<Type, SubValues...>;
  public:
  constexpr const static std :: size_t size = sizeof...(Values);
  template <std :: size_t N> constexpr const static Type at = At <N> :: value;
  template <std :: size_t N, template <Type...> class Container = This> using till = typename Till <N, Container> :: type;
  template <std :: size_t N, template <Type...> class Container = This> using since = typename Since <N, Container> :: type;
 };

 template <class Type, Type ... Values> template <std :: size_t N> struct valueList <Type, Values...> :: At
 {
  private:
  static_assert(N < valueList <Type, Values...> :: size, "Index out of range.");
  public:
  constexpr const static Type value = valueList <Type, Values...> :: values[N];
 };

 template <class Type, Type ... Values> template <std :: size_t N, template <Type...> class Container> struct valueList <Type, Values...> :: Till
 {
  private:
  static_assert(N <= valueList <Type, Values...> :: size, "Index out of range.");
  template <std :: size_t Index> constexpr const static Type valueAt = valueList <Type, Values...> :: values[Index];
  template <std :: size_t ... Indices> static Container<valueAt<Indices>...> generate(std :: index_sequence<Indices...>);
  public:
  using type = decltype(generate(std :: make_index_sequence<N>{}));
 };

 template <class Type, Type ... Values> template <std :: size_t N, template <Type...> class Container> struct valueList <Type, Values...> :: Since
 {
  private:
  static_assert(N <= valueList <Type, Values...> :: size, "Index out of range.");
  template <std :: size_t Index> constexpr const static Type valueAt = valueList <Type, Values...> :: values[N + Index];
  template <std :: size_t ... Indices> static Container<valueAt<Indices>...> generate(std :: index_sequence<Indices...>);
  public:
  using type = decltype(generate(std :: make_index_sequence<valueList <Type, Values...> :: size - N>{}));
 };
}
#endif

