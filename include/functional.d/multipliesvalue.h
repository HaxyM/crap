#ifndef CRAP_FUNCTIONAL_MULTIPLIESVALUE
#define CRAP_FUNCTIONAL_MULTIPLIESVALUE

#include "../numeric.d/identity.h"
#include "../utility.d/language.h"

#if CPP17
#else
#include "../numeric.d/reducevalue.h"
#endif

namespace crap
{
 template <class Type, Type...> struct multipliesValue;

 template <class Type> struct multipliesValue<Type>
 {
  constexpr const static auto value = identity <Type> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type Value> struct multipliesValue<Type, Value>
 {
  constexpr const static auto value = Value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type Value1, Type Value2> struct multipliesValue<Type, Value1, Value2>
 {
  constexpr const static auto value = (Value1 * Value2);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type ... Values> struct multipliesValue
 {
  #if CPP17
  constexpr const static auto value = (Values * ...);
  #else
  private:
  template <Type ... SubValues> using This = multipliesValue<Type, SubValues...>;
  public:
  constexpr const static auto value = reduceValue <Type, This, Values...> :: value;
  #endif
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <class Type>
inline constexpr crap :: multipliesValue <Type> :: operator
typename crap :: multipliesValue <Type> :: value_type () const noexcept
{
 return crap :: multipliesValue <Type> :: value;
}

template <class Type, Type Value>
inline constexpr crap :: multipliesValue <Type, Value> :: operator
typename crap :: multipliesValue <Type, Value> :: value_type () const noexcept
{
 return crap :: multipliesValue <Type, Value> :: value;
}

template <class Type, Type Value1, Type Value2>
inline constexpr crap :: multipliesValue <Type, Value1, Value2> :: operator
typename crap :: multipliesValue <Type, Value1, Value2> :: value_type () const noexcept
{
 return crap :: multipliesValue <Type, Value1, Value2> :: value;
}

template <class Type, Type ... Values>
inline constexpr crap :: multipliesValue <Type, Values...> :: operator
typename crap :: multipliesValue <Type, Values...> :: value_type () const noexcept
{
 return crap :: multipliesValue <Type, Values...> :: value;
}
#endif

