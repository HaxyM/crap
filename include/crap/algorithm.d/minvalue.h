#ifndef CRAP_ALGORITHM_MINVALUE
#define CRAP_ALGORITHM_MINVALUE

#include <type_traits>

#include "../numeric.d/reducevalue.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct minValue;

 template <class Type, template <Type, Type> class Operator, Type Value>
	 struct minValue<Type, Operator, Value>
	 : std :: integral_constant<Type, Value> {};

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
	 struct minValue<Type, Operator, Value1, Value2>
	 : std :: integral_constant<Type, ((Operator <Value1, Value2> :: value) ? Value1 : Value2)> {};

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 struct minValue
 {
  private:
  static_assert(sizeof...(Values) > 0u, "Extremum of empty set is not defined.");
  template <Type ... SubValues> using This = minValue<Type, Operator, SubValues...>;
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
        inline constexpr crap :: minValue <Type, Operator, Values...> :: operator
        typename crap :: minValue <Type, Operator, Values...> :: value_type () const noexcept
{
 return crap :: minValue <Type, Operator, Values...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type ... Values>
	inline constexpr typename crap :: minValue <Type, Operator, Values...> :: value_type
	crap :: minValue <Type, Operator, Values...> :: operator () () const noexcept
{
 return crap :: minValue <Type, Operator, Values...> :: value;
}
#endif
#endif
