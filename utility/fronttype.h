#ifndef CRAP_UTILITY_FRONTTYPE
#define CRAP_UTILITY_FRONTTYPE

namespace crap
{
 template <class...> struct frontType;

 template <class First, class ... Rest> struct frontType<First, Rest...>
 {
  using type = First;
 };

 template <class ... Types> struct frontType
 {
  static_assert(sizeof...(Types) != 0u, "Collection must not be empty.");
 };
}
#endif
