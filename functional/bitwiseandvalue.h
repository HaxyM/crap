#ifndef CRAP_FUNCTIONAL_BITWISEANDVALUE
#define CRAP_FUNCTIONAL_BITWISEANDVALUE

#include "../numeric/zero.h"
#include "../utility/language.h"

#if CPP17
#else
#include "../numeric/reducevalue.h"
#endif

namespace crap
{
 template <class Type, Type...> struct bitwiseAndValue;

 template <class Type> struct bitwiseAndValue<Type>
 {
  constexpr const static auto value = ~(zero <Type> :: value ^ zero <Type> :: value);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type Value> struct bitwiseAndValue<Type, Value>
 {
  constexpr const static auto value = Value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type Value1, Type Value2> struct bitwiseAndValue<Type, Value1, Value2>
 {
  constexpr const static auto value = (Value1 & Value2);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type ... Values> struct bitwiseAndValue
 {
  #if CPP17
  constexpr const static auto value = (Values & ...);
  #else
  private:
  template <Type ... SubValues> using This = bitwiseAndValue<Type, SubValues...>;
  public:
  constexpr const static auto value = reduceValue <Type, This, Values...> :: value;
  #endif
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <class Type>
inline constexpr crap :: bitwiseAndValue <Type> :: operator
typename crap :: bitwiseAndValue <Type> :: value_type () const noexcept
{
 return crap :: bitwiseAndValue <Type> :: value;
}

template <class Type, Type Value>
inline constexpr crap :: bitwiseAndValue <Type, Value> :: operator
typename crap :: bitwiseAndValue <Type, Value> :: value_type () const noexcept
{
 return crap :: bitwiseAndValue <Type, Value> :: value;
}

template <class Type, Type Value1, Type Value2>
inline constexpr crap :: bitwiseAndValue <Type, Value1, Value2> :: operator
typename crap :: bitwiseAndValue <Type, Value1, Value2> :: value_type () const noexcept
{
 return crap :: bitwiseAndValue <Type, Value1, Value2> :: value;
}

template <class Type, Type ... Values>
inline constexpr crap :: bitwiseAndValue <Type, Values...> :: operator
typename crap :: bitwiseAndValue <Type, Values...> :: value_type () const noexcept
{
 return crap :: bitwiseAndValue <Type, Values...> :: value;
}
#endif

