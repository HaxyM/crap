#ifndef CRAP_UTILITY_FRONTVALUE
#define CRAP_UTILITY_FRONTVALUE

namespace crap
{
 template <class Type, Type...> struct frontValue;

 template <class Type, Type First, Type ... Rest> struct frontValue<Type, First, Rest...>
 {
  constexpr const static Type value = First;
 };

 template <class Type, Type ... Values> struct frontValue
 {
  static_assert(sizeof...(Values) != 0u, "Collection must not be empty.");
 };
}
#endif

