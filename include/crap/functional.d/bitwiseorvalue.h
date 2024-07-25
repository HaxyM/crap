#ifndef CRAP_FUNCTIONAL_BITWISEORVALUE
#define CRAP_FUNCTIONAL_BITWISEORVALUE

#include "../numbers.d/zero.h"
#include "../version.d/foldexpressions.h"

#if (crap_fold_expressions >= 201603L)
#else
#include "../numeric.d/reducevalue.h"
#endif

namespace crap
{
 template <class Type, Type...> struct bitwiseOrValue;

 template <class Type> struct bitwiseOrValue<Type>
 {
  constexpr const static auto value = (zero <Type> :: value ^ zero <Type> :: value);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type Value> struct bitwiseOrValue<Type, Value>
 {
  constexpr const static auto value = Value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type Value1, Type Value2> struct bitwiseOrValue<Type, Value1, Value2>
 {
  constexpr const static auto value = (Value1 | Value2);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type ... Values> struct bitwiseOrValue
 {
#if (crap_fold_expressions >= 201603L)
  constexpr const static auto value = (Values | ...);
#else
  private:
  template <Type ... SubValues> using This = bitwiseOrValue<Type, SubValues...>;
  public:
  constexpr const static auto value = reduceValue <Type, This, Values...> :: value;
#endif
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <class Type>
inline constexpr crap :: bitwiseOrValue <Type> :: operator
typename crap :: bitwiseOrValue <Type> :: value_type () const noexcept
{
 return crap :: bitwiseOrValue <Type> :: value;
}

template <class Type, Type Value>
inline constexpr crap :: bitwiseOrValue <Type, Value> :: operator
typename crap :: bitwiseOrValue <Type, Value> :: value_type () const noexcept
{
 return crap :: bitwiseOrValue <Type, Value> :: value;
}

template <class Type, Type Value1, Type Value2>
inline constexpr crap :: bitwiseOrValue <Type, Value1, Value2> :: operator
typename crap :: bitwiseOrValue <Type, Value1, Value2> :: value_type () const noexcept
{
 return crap :: bitwiseOrValue <Type, Value1, Value2> :: value;
}

template <class Type, Type ... Values>
inline constexpr crap :: bitwiseOrValue <Type, Values...> :: operator
typename crap :: bitwiseOrValue <Type, Values...> :: value_type () const noexcept
{
 return crap :: bitwiseOrValue <Type, Values...> :: value;
}
#endif

