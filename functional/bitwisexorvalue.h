#ifndef CRAP_FUNCTIONAL_BITWISEXORVALUE
#define CRAP_FUNCTIONAL_BITWISEXORVALUE

#include "../numeric/zero.h"
#include "../utility/language.h"

#if CPP17
#else
#include "../numeric/reducevalue.h"
#endif

namespace crap
{
 template <class Type, Type...> struct bitwiseXorValue;

 template <class Type> struct bitwiseXorValue<Type>
 {
  constexpr const static auto value = (zero <Type> :: value ^ zero <Type> :: value);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type Value> struct bitwiseXorValue<Type, Value>
 {
  constexpr const static auto value = Value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type Value1, Type Value2> struct bitwiseXorValue<Type, Value1, Value2>
 {
  constexpr const static auto value = (Value1 ^ Value2);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type ... Values> struct bitwiseXorValue
 {
  #if CPP17
  constexpr const static auto value = (Values ^ ...);
  #else
  private:
  template <Type ... SubValues> using This = bitwiseXorValue<Type, SubValues...>;
  public:
  constexpr const static auto value = reduceValue <Type, This, Values...> :: value;
  #endif
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <class Type>
inline constexpr crap :: bitwiseXorValue <Type> :: operator
typename crap :: bitwiseXorValue <Type> :: value_type () const noexcept
{
 return crap :: bitwiseXorValue <Type> :: value;
}

template <class Type, Type Value>
inline constexpr crap :: bitwiseXorValue <Type, Value> :: operator
typename crap :: bitwiseXorValue <Type, Value> :: value_type () const noexcept
{
 return crap :: bitwiseXorValue <Type, Value> :: value;
}

template <class Type, Type Value1, Type Value2>
inline constexpr crap :: bitwiseXorValue <Type, Value1, Value2> :: operator
typename crap :: bitwiseXorValue <Type, Value1, Value2> :: value_type () const noexcept
{
 return crap :: bitwiseXorValue <Type, Value1, Value2> :: value;
}

template <class Type, Type ... Values>
inline constexpr crap :: bitwiseXorValue <Type, Values...> :: operator
typename crap :: bitwiseXorValue <Type, Values...> :: value_type () const noexcept
{
 return crap :: bitwiseXorValue <Type, Values...> :: value;
}
#endif

