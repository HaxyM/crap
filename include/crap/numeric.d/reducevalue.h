#ifndef CRAP_NUMERIC_REDUCEVALUE
#define CRAP_NUMERIC_REDUCEVALUE

#include <type_traits>

#include "../version.d/libintegralconstantcallable.h"
#include "../utility.d/bisectvalue.h"

namespace crap
{
 template <class Type, template <Type...> class, Type...> struct reduceValue;

 template <class Type, template <Type...> class Operator>
	 struct reduceValue<Type, Operator>
	 : std :: integral_constant<decltype(Operator <> :: value), Operator <> :: value> {};

 template <class Type, template <Type...> class Operator, Type Value>
	 struct reduceValue<Type, Operator, Value>
	 : std :: integral_constant<decltype(Operator <Value> :: value), Operator <Value> :: value> {};

 template <class Type, template <Type...> class Operator, Type Value1, Type Value2>
	 struct reduceValue<Type, Operator, Value1, Value2>
	 : std :: integral_constant<decltype(Operator <Value1, Value2> :: value), Operator <Value1, Value2> :: value> {};

 template <class Type, template <Type...> class Operator, Type ... Values> struct reduceValue
 {
  private:
  using values = bisectValue<Type, Values...>;
  template <Type ... SubValues> using This = reduceValue<Type, Operator, SubValues...>;
  constexpr const static Type lower = values :: template lower <This> :: value;
  constexpr const static Type upper = values :: template upper <This> :: value;
  public:
  constexpr const static auto value = Operator <lower, upper> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };
}

template <class Type, template <Type...> class Operator, Type ... Values>
	inline constexpr crap :: reduceValue <Type, Operator, Values...> :: operator
	typename crap :: reduceValue <Type, Operator, Values...> :: value_type () const noexcept
{
 return crap :: reduceValue <Type, Operator, Values...> :: value;
};
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type...> class Operator, Type ... Values>
inline constexpr typename crap :: reduceValue <Type, Operator, Values...> :: value_type
crap :: reduceValue <Type, Operator, Values...> :: operator () () const noexcept
{
 return crap :: reduceValue <Type, Operator, Values...> :: value;
}
#endif
#endif

