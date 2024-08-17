#ifndef CRAP_NUMERIC_ACCUMULATEVALUE
#define CRAP_NUMERIC_ACCUMULATEVALUE

#include <type_traits>

#include "../utility.d/bisectvalue.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <class Type, template <Type...> class, Type...> struct accumulateValue;

 template <class Type, template <Type...> class Operator> struct accumulateValue<Type, Operator>
	 : std :: integral_constant<decltype(Operator <> :: value), Operator <> :: value> {};

 template <class Type, template <Type...> class Operator, Type Value>
	 struct accumulateValue<Type, Operator, Value>
	 : std :: integral_constant<decltype(Operator <Value> :: value), Operator <Value> :: value> {};

 template <class Type, template <Type...> class Operator, Type Value1, Type Value2>
	 struct accumulateValue<Type, Operator, Value1, Value2>
	 : std :: integral_constant<decltype(Operator <Value1, Value2> :: value), Operator <Value1, Value2> :: value> {};

 template <class Type, template <Type...> class Operator, Type Value1, Type Value2, Type Value3>
	 struct accumulateValue<Type, Operator, Value1, Value2, Value3>
 {
  private:
  constexpr const static Type subResult = Operator <Value1, Value2> :: value;
  public:
  constexpr const static Type value = Operator <subResult, Value3> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type...> class Operator, Type ... Values> struct accumulateValue
 {
  private:
  using values = bisectValue<Type, Values...>;
  template <Type ... SubValues> using firstHalf = accumulateValue<Type, Operator, SubValues...>;
  constexpr const static Type firstHalfValue = values :: template lower <firstHalf> :: value;
  template <Type ... SubValues> using secondHalf = accumulateValue<Type, Operator, firstHalfValue, SubValues...>;
  public:
  constexpr const static Type value = values :: template upper <secondHalf> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };
}

template <class Type, template <Type...> class Operator, Type Value1, Type Value2, Type Value3>
	inline constexpr crap :: accumulateValue <Type, Operator, Value1, Value2, Value3> :: operator
	typename crap :: accumulateValue <Type, Operator, Value1, Value2, Value3> :: value_type () const noexcept
{
 return crap :: accumulateValue <Type, Operator, Value1, Value2, Value3> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type...> class Operator, Type Value1, Type Value2, Type Value3>
inline constexpr typename crap :: accumulateValue <Type, Operator, Value1, Value2, Value3> :: value_type
crap :: accumulateValue <Type, Operator, Value1, Value2, Value3> :: operator () () const noexcept
{
 return crap :: accumulateValue <Type, Operator, Value1, Value2, Value3> :: value;
}
#endif

template <class Type, template <Type...> class Operator, Type ... Values>
	inline constexpr crap :: accumulateValue <Type, Operator, Values...> :: operator
	typename crap :: accumulateValue <Type, Operator, Values...> :: value_type () const noexcept
{
 return crap :: accumulateValue <Type, Operator, Values...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type...> class Operator, Type ... Values>
inline constexpr typename crap :: accumulateValue <Type, Operator, Values...> :: value_type
crap :: accumulateValue <Type, Operator, Values...> :: operator () () const noexcept
{
 return crap :: accumulateValue <Type, Operator, Values...> :: value;
}
#endif
#endif

