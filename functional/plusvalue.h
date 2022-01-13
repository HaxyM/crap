#ifndef CRAP_FUNCTIONAL_PLUSVALUE
#define CRAP_FUNCTIONAL_PLUSVALUE

#include "../numeric/zero.h"
#include "../utility/language.h"

#if CPP17
#else
#include "../numeric/reducevalue.h"
#endif

namespace crap
{
 template <class Type, Type...> struct plusValue;

 template <class Type> struct plusValue<Type>
 {
  constexpr const static auto value = zero <Type> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type Value> struct plusValue<Type, Value>
 {
  constexpr const static auto value = Value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
 
 template <class Type, Type Value1, Type Value2> struct plusValue<Type, Value1, Value2>
 {
  constexpr const static auto value = (Value1 + Value2);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type ... Values> struct plusValue
 {
  #if CPP17
  constexpr const static auto value = (Values + ...);
  #else
  private:
  template <Type ... SubValues> using This = plusValue<Type, SubValues...>;
  public:
  constexpr const static auto value = reduceValue <Type, This, Values...> :: value;
  #endif
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <class Type>
inline constexpr crap :: plusValue <Type> :: operator
typename crap :: plusValue <Type> :: value_type () const noexcept
{
 return crap :: plusValue <Type> :: value;
}

template <class Type, Type Value>
inline constexpr crap :: plusValue <Type, Value> :: operator
typename crap :: plusValue <Type, Value> :: value_type () const noexcept
{
 return crap :: plusValue <Type, Value> :: value;
}

template <class Type, Type Value1, Type Value2>
inline constexpr crap :: plusValue <Type, Value1, Value2> :: operator
typename crap :: plusValue <Type, Value1, Value2> :: value_type () const noexcept
{
 return crap :: plusValue <Type, Value1, Value2> :: value;
}

template <class Type, Type ... Values>
inline constexpr crap :: plusValue <Type, Values...> :: operator
typename crap :: plusValue <Type, Values...> :: value_type () const noexcept
{
 return crap :: plusValue <Type, Values...> :: value;
}
#endif

