#ifndef CRAP_FUNCTIONAL_LOGICALORVALUE
#define CRAP_FUNCTIONAL_LOGICALORVALUE

#include "../numeric/zero.h"
#include "../utility/language.h"

#if CPP17
#else
#include "../numeric/reducevalue.h"
#endif

namespace crap
{
 template <class Type, Type...> struct logicalOrValue;

 template <class Type> struct logicalOrValue<Type>
 {
  constexpr const static auto value = zero <Type> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type Value> struct logicalOrValue<Type, Value>
 {
  constexpr const static auto value = Value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type Value1, Type Value2> struct logicalOrValue<Type, Value1, Value2>
 {
  constexpr const static auto value = (Value1 || Value2);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type ... Values> struct logicalOrValue
 {
  #if CPP17
  constexpr const static auto value = (Values || ...);
  #else
  private:
  template <Type ... SubValues> using This = logicalOrValue<Type, SubValues...>;
  public:
  constexpr const static auto value = reduceValue <Type, This, Values...> :: value;
  #endif
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <class Type>
inline constexpr crap :: logicalOrValue <Type> :: operator
typename crap :: logicalOrValue <Type> :: value_type () const noexcept
{
 return crap :: logicalOrValue <Type> :: value;
}

template <class Type, Type Value>
inline constexpr crap :: logicalOrValue <Type, Value> :: operator
typename crap :: logicalOrValue <Type, Value> :: value_type () const noexcept
{
 return crap :: logicalOrValue <Type, Value> :: value;
}

template <class Type, Type Value1, Type Value2>
inline constexpr crap :: logicalOrValue <Type, Value1, Value2> :: operator
typename crap :: logicalOrValue <Type, Value1, Value2> :: value_type () const noexcept
{
 return crap :: logicalOrValue <Type, Value1, Value2> :: value;
}

template <class Type, Type ... Values>
inline constexpr crap :: logicalOrValue <Type, Values...> :: operator
typename crap :: logicalOrValue <Type, Values...> :: value_type () const noexcept
{
 return crap :: logicalOrValue <Type, Values...> :: value;
}
#endif

