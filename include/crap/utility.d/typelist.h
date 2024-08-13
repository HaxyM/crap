#ifndef CRAP_UTILITY_TYPELIST
#define CRAP_UTILITY_TYPELIST

#include <utility>

#include "makeindexsequence.h"

#include "../version.d/packindexing.h"

#if (crap_pack_indexing >= 202311L)
#include "typeidentity.h"
#else
#endif

namespace crap
{
 template <class ... Types> struct typeList
 {
  private:
  struct ignore;
  template <class ... SubTypes> using This = typeList<SubTypes...>;
  template <class Type> struct identity;
#if (crap_pack_indexing >= 202311L)
  template <std :: size_t N> using At = typeIdentity<Types...[N]>;
#else
  template <std :: size_t N> struct At;
#endif
  template <std :: size_t N, template <class...> class Container> struct Since;
  template <std :: size_t N, template <class...> class Container> struct Till;
  template <std :: size_t Begin, std :: size_t End, template <class...> class Container> struct SubRange;
  public:
  constexpr const static std :: size_t size = sizeof...(Types);
#if (crap_pack_indexing >= 202311L)
  template <std :: size_t N> using at = Types...[N];
#else
  template <std :: size_t N> using at = typename At <N> :: type;
#endif
  template <std :: size_t N, template <class...> class Container = This> using since = typename Since <N, Container> :: type;
  template <std :: size_t N, template <class...> class Container = This> using till = typename Till <N, Container> :: type;
  template <std :: size_t Begin, std :: size_t End, template <class...> class Container = This> using subRange = typename SubRange <Begin, End, Container> :: type;
 };

 template <class ... Types> struct typeList <Types...> :: ignore
 {
  ignore(...);
 };

 template <class ... Types> template <class Type> struct typeList <Types...> :: identity{};

#if (crap_pack_indexing >= 202311L)
#else
 template <class ... Types> template <std :: size_t N> struct typeList <Types...> :: At
 {
  private:
  static_assert(N < (typeList <Types...> :: size), "Index out of range.");
  template <std :: size_t ... Indices> struct Implementation;
  template <std :: size_t ... Indices> static Implementation<Indices...> generate(indexSequence<Indices...>);
  using implementation = decltype(generate(makeIndexSequence<N>{}));
  template <class Type> using identity = typename typeList <Types...> :: template identity<Type>;
  public:
  using type = decltype(implementation :: generate(identity<Types>{}...));
 };
#endif

 template <class ... Types> template <std :: size_t N, template <class ...> class Container>
 struct typeList <Types...> :: Since
 {//TODO: Check if using pack indexing can be better.
  private:
  static_assert(N <= (typeList <Types...> :: size), "Index out of range.");
  template <std :: size_t ... Indices> struct Implementation;
  template <std :: size_t ... Indices> static Implementation<Indices...> generate(indexSequence<Indices...>);
  using implementation = decltype(generate(makeIndexSequence<N>{}));
  template <class Type> using identity = typename typeList <Types...> :: template identity<Type>;
  public:
  using type = decltype(implementation :: generate(identity<Types>{}...));
 };

 template <class ... Types> template <std :: size_t N, template <class...> class Container>
 struct typeList <Types...> :: Till
 {
  private:
  static_assert(N <= (typeList <Types...> :: size), "Index out of range.");
  template <std :: size_t Index> using at = typename typeList <Types...> :: template at<Index>;
  template <std :: size_t ... Indices> static Container<at<Indices>...> generate(indexSequence<Indices...>);
  public:
  using type = decltype(generate(makeIndexSequence<N>{}));
 };
 
 template <class ... Types> template <std :: size_t Begin, std :: size_t End, template <class...> class Container>
 struct typeList <Types...> :: SubRange
 {//TODO: Check if using pack indexing can be better.
  private:
  template <class ... SubTypes> using Since = typename typeList <SubTypes...> :: template since <Begin, Container>;
  public:
  using type = typename typeList <Types...> :: template till<End, Since>;
 };

#if (crap_pack_indexing >= 202311L)
#else
 template <class ... Types> template <std :: size_t N> template <std :: size_t ... Indices>
 struct typeList <Types...> :: At <N> :: Implementation
 {
  template <class Type> using identity = typename typeList <Types...> :: template identity<Type>;
  using ignore_t = typename typeList <Types...> :: ignore;
  template <class NthType> static NthType
  generate(decltype(static_cast<ignore_t>(Indices))..., identity<NthType>, ...);
 };
#endif

 template <class ... Types> template <std :: size_t N, template <class...> class Container>
 template <std :: size_t ... Indices>
 struct typeList <Types...> :: Since <N, Container> :: Implementation
 {
  template <class Type> using identity = typename typeList <Types...> :: template identity<Type>;
  using ignore_t = typename typeList <Types...> :: ignore;
  template <class ... SubTypes> static Container<SubTypes...>
  generate(decltype(static_cast<ignore_t>(Indices))..., identity<SubTypes>...);
 };
}
#endif
