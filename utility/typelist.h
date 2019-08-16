#ifndef CRAP_UTILITY_TYPELIST
#define CRAP_UTILITY_TYPELIST

#include <utility>

namespace crap
{
 template <class ... Types> struct typeList
 {
  private:
  struct ignore;
  template <class ... SubTypes> using This = typeList<SubTypes...>;
  template <class Type> struct identity;
  template <std :: size_t N> struct At;
  template <std :: size_t N, template <class...> class Container> struct Since;
  template <std :: size_t N, template <class...> class Container> struct Till;
  public:
  constexpr const static std :: size_t size = sizeof...(Types);
  template <std :: size_t N> using at = typename At <N> :: type;
  template <std :: size_t N, template <class...> class Container = This> using since = typename Since <N, Container> :: type;
  template <std :: size_t N, template <class...> class Container = This> using till = typename Till <N, Container> :: type;
 };

 template <class ... Types> struct typeList <Types...> :: ignore
 {
  ignore(...);
 };

 template <class ... Types> template <class Type> struct typeList <Types...> :: identity{};

 template <class ... Types> template <std :: size_t N> struct typeList <Types...> :: At
 {
  private:
  static_assert(N < (typeList <Types...> :: size), "Index out of range.");
  template <std :: size_t ... Indices> struct Implementation;
  template <std :: size_t ... Indices> static Implementation<Indices...> generate(std :: index_sequence<Indices...>);
  using implementation = decltype(generate(std :: make_index_sequence<N>{}));
  template <class Type> using identity = typename typeList <Types...> :: template identity<Type>;
  public:
  using type = decltype(implementation :: generate(identity<Types>{}...));
 };

 template <class ... Types> template <std :: size_t N, template <class ...> class Container>
 struct typeList <Types...> :: Since
 {
  private:
  static_assert(N <= (typeList <Types...> :: size), "Index out of range.");
  template <std :: size_t ... Indices> struct Implementation;
  template <std :: size_t ... Indices> static Implementation<Indices...> generate(std :: index_sequence<Indices...>);
  using implementation = decltype(generate(std :: make_index_sequence<N>{}));
  template <class Type> using identity = typename typeList <Types...> :: template identity<Type>;
  public:
  using type = decltype(implementation :: generate(identity<Types>{}...));
 };

 template <class ... Types> template <std :: size_t N, template <class...> class Container>
 struct typeList <Types...> :: Till
 {//TODO: Find some better solution.
  private:
  static_assert(N <= (typeList <Types...> :: size), "Index out of range.");
  template <std :: size_t Index> using at = typename typeList <Types...> :: template at<Index>;
  template <std :: size_t ... Indices> static Container<at<Indices>...> generate(std :: index_sequence<Indices...>);
  public:
  using type = decltype(generate(std :: make_index_sequence<N>{}));
 };

 template <class ... Types> template <std :: size_t N> template <std :: size_t ... Indices>
 struct typeList <Types...> :: template At <N> :: Implementation
 {
  template <class Type> using identity = typename typeList <Types...> :: template identity<Type>;
  template <class NthType> static NthType
  generate(decltype(typename typeList <Types...> :: ignore(Indices))..., identity<NthType>, ...);
 };

 template <class ... Types> template <std :: size_t N, template <class...> class Container>
 template <std :: size_t ... Indices>
 struct typeList <Types...> :: template Since <N, Container> :: Implementation
 {
  template <class Type> using identity = typename typeList <Types...> :: template identity<Type>;
  template <class ... SubTypes> static Container<SubTypes...>
  generate(decltype(typename typeList <Types...> :: ignore(Indices))..., identity<SubTypes>...);
 };
}
#endif
