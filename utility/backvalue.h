#ifndef CRAP_UTILITY_BACKVALUE
#define CRAP_UTILITY_BACKVALUE

#include "makeindexsequence.h"

namespace crap
{
 template <class Type, Type...> struct backValue;

 template <class Type, Type First, Type ... Rest> struct backValue<Type, First, Rest...>
 {
  private:
  template <std :: size_t ... Indices> struct Implementation;
  template <std :: size_t ... Indices> static Implementation<Indices...> getImplementation(indexSequence<Indices...>);
  public:
  constexpr const static Type value = decltype(getImplementation(makeIndexSequence<sizeof...(Rest)>())) :: value;
 };

 template <class Type, Type ... Values> struct backValue
 {
  static_assert(sizeof...(Values) != 0u, "Collection must not be empty.");
 };

 template <class Type, Type First, Type ... Rest> template <std :: size_t ... Indices> struct backValue <Type, First, Rest...> :: Implementation
 {
  private:
  struct ignore;
  template <Type Value> static std :: integral_constant<Type, Value> getValue(decltype(ignore(Indices))..., std :: integral_constant<Type, Value>);
  public:
  constexpr const static Type value = decltype(getValue(std :: integral_constant<Type, First>{}, std :: integral_constant<Type, Rest>{}...)) :: value;
 };

 template <class Type, Type First, Type ... Rest> template <std :: size_t ... Indices> struct backValue <Type, First, Rest...> :: template Implementation <Indices...> :: ignore
 {
  ignore(...){}
 };
}
#endif

