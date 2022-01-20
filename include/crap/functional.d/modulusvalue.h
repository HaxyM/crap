#ifndef CRAP_FUNCTIONAL_MODULUSVALUE
#define CRAP_FUNCTIONAL_MODULUSVALUE

#include "../utility.d/language.h"

#if CPP17
#else
#include "../numeric.d/accumulatevalue.h"
#endif

namespace crap
{
 template <class Type, Type...> struct modulusValue;

 #if CPP17
 #else
 template <class Type, Type Value> struct modulusValue<Type, Value>
 {
  constexpr const static auto value = Value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type Value1, Type Value2> struct modulusValue<Type, Value1, Value2>
 {
  constexpr const static auto value = (Value1 % Value2);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
 #endif

 template <class Type, Type FirstValue, Type ... Rest> struct modulusValue<Type, FirstValue, Rest...>
 {
  #if CPP17
  constexpr const static auto value = (FirstValue % ... % Rest);
  #else
  private:
  template <Type ... SubValues> using This = modulusValue<Type, SubValues...>;
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
inline constexpr crap :: modulusValue <Type, Value> :: operator
typename crap :: modulusValue <Type, Value> :: value_type () const noexcept
{
 return crap :: modulusValue <Type, Value> :: value;
}

template <class Type, Type Value1, Type Value2>
inline constexpr crap :: modulusValue <Type, Value1, Value2> :: operator
typename crap :: modulusValue <Type, Value1, Value2> :: value_type () const noexcept
{
 return crap :: modulusValue <Type, Value1, Value2> :: value;
}
#endif

template <class Type, Type FirstValue, Type ... Rest>
inline constexpr crap :: modulusValue <Type, FirstValue, Rest...> :: operator
typename crap :: modulusValue <Type, FirstValue, Rest...> :: value_type () const noexcept
{
 return crap :: modulusValue <Type, FirstValue, Rest...> :: value;
}
#endif

