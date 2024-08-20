#ifndef CRAP_ALGORITHM_MAXVALUE
#define CRAP_ALGORITHM_MAXVALUE

#include <type_traits>

#include "../numeric.d/reducevalue.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct maxValue;

 template <class Type, template <Type, Type> class Operator, Type Value>
	 struct maxValue<Type, Operator, Value>
	 : std :: integral_constant<Type, Value> {};

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
	 struct maxValue<Type, Operator, Value1, Value2>
	 : std :: integral_constant<Type, ((Operator <Value2, Value1> :: value) ? Value1 : Value2)> {};

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 struct maxValue
 {
  private:
  static_assert(sizeof...(Values) > 0u, "Extremum of empty set is not defined.");
  template <Type ... SubValues> using This = maxValue<Type, Operator, SubValues...>;
  public:
  constexpr const static Type value = reduceValue <Type, This, Values...> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };
}

template <class Type, template <Type, Type> class Operator, Type ... Values>
        inline constexpr crap :: maxValue <Type, Operator, Values...> :: operator
        typename crap :: maxValue <Type, Operator, Values...> :: value_type () const noexcept
{
 return crap :: maxValue <Type, Operator, Values...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type ... Values>
	inline constexpr typename crap :: maxValue <Type, Operator, Values...> :: value_type
	crap :: maxValue <Type, Operator, Values...> :: operator () () const noexcept
{
 return crap :: maxValue <Type, Operator, Values...> :: value;
}
#endif
#endif
