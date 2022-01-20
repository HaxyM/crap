#ifndef CRAP_FUNCTIONAL_DIVIDESVALUE
#define CRAP_FUNCTIONAL_DIVIDESVALUE

#include "../utility.d/language.h"

#if CPP17
#else
#include "../numeric.d/accumulatevalue.h"
#endif

namespace crap
{
 template <class Type, Type...> struct dividesValue;

 #if CPP17
 #else
 template <class Type, Type Value> struct dividesValue<Type, Value>
 {
  constexpr const static auto value = Value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type Value1, Type Value2> struct dividesValue<Type, Value1, Value2>
 {
  constexpr const static auto value = (Value1 / Value2);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
 #endif

 template <class Type, Type FirstValue, Type ... Rest> struct dividesValue<Type, FirstValue, Rest...>
 {
  #if CPP17
  constexpr const static auto value = (FirstValue / ... / Rest);
  #else
  private:
  template <Type ... SubValues> using This = dividesValue<Type, SubValues...>;
  public:
  constexpr const static auto value = accumulateValue <Type, This, FirstValue, Rest...> :: value;
  #endif
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

#if CPP17
#else
template <class Type, Type Value>
inline constexpr crap :: dividesValue <Type, Value> :: operator
typename crap :: dividesValue <Type, Value> :: value_type () const noexcept
{
 return crap :: dividesValue <Type, Value> :: value;
}

template <class Type, Type Value1, Type Value2>
inline constexpr crap :: dividesValue <Type, Value1, Value2> :: operator
typename crap :: dividesValue <Type, Value1, Value2> :: value_type () const noexcept
{
 return crap :: dividesValue <Type, Value1, Value2> :: value;
}
#endif

template <class Type, Type FirstValue, Type ... Rest>
inline constexpr crap :: dividesValue <Type, FirstValue, Rest...> :: operator
typename crap :: dividesValue <Type, FirstValue, Rest...> :: value_type () const noexcept
{
 return crap :: dividesValue <Type, FirstValue, Rest...> :: value;
}
#endif

