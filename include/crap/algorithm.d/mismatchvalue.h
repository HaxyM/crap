#ifndef CRAP_ALGORITHM_MISMATCHVALUE
#define CRAP_ALGORITHM_MISMATCHVALUE

#include "../utility.d/valuelist.h"
#include "../version.d/variabletemplates.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct mismatchValue;

 template <class Type, template <Type, Type> class Operator> struct mismatchValue<Type, Operator>
 {
  template <Type ... Values2> struct with;
#if (crap_variable_templates >= 201304L)
  template <Type ... Values2> constexpr const static std :: size_t value = with <Values2...> :: value;
  template <Type ... Values2> constexpr const static std :: size_t npos = with <Values2...> :: npos;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type Value1> struct mismatchValue<Type, Operator, Value1>
 {
  template <Type ... Values2> struct with;
#if (crap_variable_templates >= 201304L)
  template <Type ... Values2> constexpr const static std :: size_t value = with <Values2...> :: value;
  template <Type ... Values2> constexpr const static std :: size_t npos = with <Values2...> :: npos;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1> struct mismatchValue
 {
  template <Type ... Values2> struct with;
#if (crap_variable_templates >= 201304L)
  template <Type ... Values2> constexpr const static std :: size_t value = with <Values2...> :: value;
  template <Type ... Values2> constexpr const static std :: size_t npos = with <Values2...> :: npos;
#endif
 };

 template <class Type, template <Type, Type> class Operator> template <Type ... Values2> struct mismatchValue <Type, Operator> :: with
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = sizeof...(Values2);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1> template <Type ... Values2>
 struct mismatchValue <Type, Operator, Value1> :: with
 {
  private:
  constexpr const static std :: size_t getValue();
  constexpr const static std :: size_t getValue(Type, ...);
  public:
  constexpr const static std :: size_t value = getValue(Values2...);
  constexpr const static std :: size_t npos = ((sizeof...(Values2) > 1u) ? sizeof...(Values2) : 1u);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1>
 template <Type ... Values2> struct mismatchValue <Type, Operator, Values1...> :: with
 {
  private:
  constexpr const static std :: size_t getValue();
  constexpr const static std :: size_t getValue(Type);
  constexpr const static std :: size_t getValue(Type, Type, ...);
  using values1 = valueList<Type, Values1...>;
  using values2 = valueList<Type, Values2...>;
  constexpr const static std :: size_t half = (((values1 :: size) < (values2 :: size)) ? (values1 :: size) : (values2 :: size)) / 2u;
  template <Type ... SubValues> using This = mismatchValue<Type, Operator, SubValues...>;
  template <Type ... SubValues> using lowerMismatch = typename values1 :: template till <half, This> :: template with<SubValues...>;
  template <Type ... SubValues> using upperMismatch = typename values1 :: template since <half, This> :: template with<SubValues...>;
  constexpr const static std :: size_t lower = values2 :: template till <half, lowerMismatch> :: value;
  constexpr const static std :: size_t upper = values2 :: template since <half, upperMismatch> :: value;
  public:
  constexpr const static std :: size_t value = getValue(Values2...);
  constexpr const static std :: size_t npos = ((sizeof...(Values1) < sizeof...(Values2)) ? sizeof...(Values2) : sizeof...(Values1));
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <class Type, template <Type, Type> class Operator> template <Type ... Values2>
        inline constexpr
	crap :: mismatchValue <Type, Operator> :: template with <Values2...> :: operator typename
	crap :: mismatchValue <Type, Operator> :: template with <Values2...> :: value_type ()
	const noexcept
{
 return crap :: mismatchValue <Type, Operator> :: template with <Values2...> :: value;
}

template <class Type, template <Type, Type> class Operator, Type Value1> template <Type ... Values2>
constexpr const std :: size_t crap :: mismatchValue <Type, Operator, Value1> :: template with <Values2...> :: getValue()
{
 return 0u;
}

template <class Type, template <Type, Type> class Operator, Type Value1> template <Type ... Values2>
constexpr const std :: size_t crap :: mismatchValue <Type, Operator, Value1> :: template with <Values2...> :: getValue(Type, ...)
{
 using values = crap :: valueList<Type, Values2...>;
 return ((Operator <Value1, values :: template At <0u> :: value> :: value) ? 1u : 0u);
}

template <class Type, template <Type, Type> class Operator, Type Value1> template <Type ... Values2>
        inline constexpr
	crap :: mismatchValue <Type, Operator, Value1> :: template with <Values2...> :: operator typename
	crap :: mismatchValue <Type, Operator, Value1> :: template with <Values2...> :: value_type ()
	const noexcept
{
 return crap :: mismatchValue <Type, Operator, Value1> :: template with <Values2...> :: value;
}

template <class Type, template <Type, Type> class Operator, Type ... Values1> template <Type ... Values2>
constexpr const std :: size_t crap :: mismatchValue <Type, Operator, Values1...> :: template with <Values2...> :: getValue()
{
 return 0u;
}

template <class Type, template <Type, Type> class Operator, Type ... Values1> template <Type ... Values2>
constexpr const std :: size_t crap :: mismatchValue <Type, Operator, Values1...> :: template with <Values2...> :: getValue(Type)
{
 return ((Operator <values1 :: template At <0u> :: value, values2 :: template At <0u> :: value> :: value) ? 1u : 0u);
}

template <class Type, template <Type, Type> class Operator, Type ... Values1> template <Type ... Values2>
constexpr const std :: size_t
crap :: mismatchValue <Type, Operator, Values1...> :: template with <Values2...> :: getValue(Type, Type, ...)
{
 return ((lower != half) ? lower : (half + upper));
}

template <class Type, template <Type, Type> class Operator, Type ... Values1> template <Type ... Values2>
        inline constexpr
	crap :: mismatchValue <Type, Operator, Values1...> :: template with <Values2...> :: operator typename
	crap :: mismatchValue <Type, Operator, Values1...> :: template with <Values2...> :: value_type ()
	const noexcept
{
 return crap :: mismatchValue <Type, Operator, Values1...> :: template with <Values2...> :: value;
}
#endif

