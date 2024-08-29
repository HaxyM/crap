#ifndef CRAP_ALGORITHM_EQUALVALUE
#define CRAP_ALGORITHM_EQUALVALUE

#include "../utility.d/valuelist.h"
#include "../version.d/variabletemplates.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct equalValue;

 template <class Type, template <Type, Type> class Operator> struct equalValue<Type, Operator>
 {
  template <Type ... Values2> struct with;
#if (crap_variable_templates >= 201304L)
  template <Type ... Values2> constexpr const static bool value = with <Values2...> :: value;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type Value1> struct equalValue<Type, Operator, Value1>
 {
  template <Type ... Values2> struct with;
#if (crap_variable_templates >= 201304L)
  template <Type ... Values2> constexpr const static bool value = with <Values2...> :: value;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1> struct equalValue
 {
  template <Type ... Values2> struct with;
#if (crap_variable_templates >= 201304L)
  template <Type ... Values2> constexpr const static bool value = with <Values2...> :: value;
#endif
 };

 template <class Type, template <Type, Type> class Operator> template <Type ... Values2> struct equalValue <Type, Operator> :: with
 {
  constexpr const static bool value = (sizeof...(Values2) == 0u);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type Value1> template <Type ... Values2> struct equalValue <Type, Operator, Value1> :: with
 {
  private:
  constexpr const static bool getValue(...);
  constexpr const static bool getValue(Type);
  public:
  constexpr const static bool value = getValue(Values2...);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1>
 template <Type ... Values2> struct equalValue <Type, Operator, Values1...> :: with
 { //TODO: add disarding if sizes missmatch;
  private:
  using values1 = valueList<Type, Values1...>;
  using values2 = valueList<Type, Values2...>;
  constexpr const static std :: size_t half1 = (values1 :: size) / 2u;
  constexpr const static std :: size_t half2 = (values2 :: size) / 2u;
  template <Type ... SubValues> using This = equalValue<Type, Operator, SubValues...>;
  template <Type ... SubValues> using lower = typename values1 :: template till <half1, This> :: template with<SubValues...>;
  template <Type ... SubValues> using upper = typename values1 :: template since <half1, This> :: template with<SubValues...>;
  constexpr const static bool lowerEqual = values2 :: template till <half2, lower> :: value;
  constexpr const static bool upperEqual = values2 :: template since <half2, upper> :: value;
  public:
  constexpr const static bool value = (lowerEqual && upperEqual);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };
}

template <class Type, template <Type, Type> class Operator> template <Type ... Values2>
inline constexpr crap :: equalValue <Type, Operator> :: with <Values2...> :: operator
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
typename crap :: equalValue <Type, Operator> :: template with <Values2...> :: value_type () const noexcept
#else
typename crap :: equalValue <Type, Operator> :: with <Values2...> :: value_type () const noexcept
#endif
{
 return crap :: equalValue <Type, Operator> :: with <Values2...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator> template <Type ... Values2>
inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
crap :: equalValue <Type, Operator> :: template with <Values2...> :: value_type
#else
crap :: equalValue <Type, Operator> :: with <Values2...> :: value_type
#endif
crap :: equalValue <Type, Operator> :: with <Values2...> :: operator () () const noexcept
{
 return crap :: equalValue <Type, Operator> :: with <Values2...> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type Value1>
template <Type ... Values2> constexpr const bool crap :: equalValue <Type, Operator, Value1> :: template with <Values2...> :: getValue(...)
{
 return false;
}

template <class Type, template <Type, Type> class Operator, Type Value1>
template <Type ... Values2> constexpr const bool crap :: equalValue <Type, Operator, Value1> :: template with <Values2...> :: getValue(Type)
{
 using values = crap :: valueList<Type, Values2...>;
 return Operator <Value1, values :: template At <0u> :: value> :: value;
}

template <class Type, template <Type, Type> class Operator, Type Value1> template <Type ... Values2>
inline constexpr crap :: equalValue <Type, Operator, Value1> :: with <Values2...> :: operator
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
typename crap :: equalValue <Type, Operator, Value1> :: template with <Values2...> :: value_type () const noexcept
#else
typename crap :: equalValue <Type, Operator, Value1> :: with <Values2...> :: value_type () const noexcept
#endif
{
 return crap :: equalValue <Type, Operator, Value1> :: with <Values2...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type Value1> template <Type ... Values2>
inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
crap :: equalValue <Type, Operator, Value1> :: template with <Values2...> :: value_type
#else
crap :: equalValue <Type, Operator, Value1> :: with <Values2...> :: value_type
#endif
crap :: equalValue <Type, Operator, Value1> :: with <Values2...> :: operator () () const noexcept
{
 return crap :: equalValue <Type, Operator, Value1> :: with <Values2...> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type ... Values1> template <Type ... Values2>
inline constexpr crap :: equalValue <Type, Operator, Values1...> :: with <Values2...> :: operator
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
typename crap :: equalValue <Type, Operator, Values1...> :: template with <Values2...> :: value_type () const noexcept
#else
typename crap :: equalValue <Type, Operator, Values1...> :: with <Values2...> :: value_type () const noexcept
#endif
{
 return crap :: equalValue <Type, Operator, Values1...> :: with <Values2...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type ... Values1> template <Type ... Values2>
inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
crap :: equalValue <Type, Operator, Values1...> :: template with <Values2...> :: value_type
#else
crap :: equalValue <Type, Operator, Values1...> :: with <Values2...> :: value_type
#endif
crap :: equalValue <Type, Operator, Values1...> :: with <Values2...> :: operator () () const noexcept
{
 return crap :: equalValue <Type, Operator, Values1...> :: with <Values2...> :: value;
}
#endif
#endif

