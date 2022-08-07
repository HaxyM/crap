#ifndef CRAP_FUNCTIONAL_LOGICALANDVALUE
#define CRAP_FUNCTIONAL_LOGICALANDVALUE

#include "../numbers.d/identity.h"
#include "../utility.d/language.h"

#if CPP17
#else
#include "../numeric.d/reducevalue.h"
#endif

namespace crap
{
 template <class Type, Type...> struct logicalAndValue;

 template <class Type> struct logicalAndValue<Type>
 {
  constexpr const static auto value = identity <Type> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type Value> struct logicalAndValue<Type, Value>
 {
  constexpr const static auto value = Value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type Value1, Type Value2> struct logicalAndValue<Type, Value1, Value2>
 {
  constexpr const static auto value = (Value1 && Value2);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type ... Values> struct logicalAndValue
 {
  #if CPP17
  constexpr const static auto value = (Values && ...);
  #else
  private:
  template <Type ... SubValues> using This = logicalAndValue<Type, SubValues...>;
  public:
  constexpr const static auto value = reduceValue <Type, This, Values...> :: value;
  #endif
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <class Type>
inline constexpr crap :: logicalAndValue <Type> :: operator
typename crap :: logicalAndValue <Type> :: value_type () const noexcept
{
 return crap :: logicalAndValue <Type> :: value;
}

template <class Type, Type Value>
inline constexpr crap :: logicalAndValue <Type, Value> :: operator
typename crap :: logicalAndValue <Type, Value> :: value_type () const noexcept
{
 return crap :: logicalAndValue <Type, Value> :: value;
}

template <class Type, Type Value1, Type Value2>
inline constexpr crap :: logicalAndValue <Type, Value1, Value2> :: operator
typename crap :: logicalAndValue <Type, Value1, Value2> :: value_type () const noexcept
{
 return crap :: logicalAndValue <Type, Value1, Value2> :: value;
}

template <class Type, Type ... Values>
inline constexpr crap :: logicalAndValue <Type, Values...> :: operator
typename crap :: logicalAndValue <Type, Values...> :: value_type () const noexcept
{
 return crap :: logicalAndValue <Type, Values...> :: value;
}
#endif

