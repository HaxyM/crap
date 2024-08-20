#ifndef CRAP_ALGORITHM_ANYOFVALUE
#define CRAP_ALGORITHM_ANYOFVALUE

#include <type_traits>

#include "../functional.d/logicalorvalue.h"
#include "../utility.d/commontype.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <class Type, template <Type> class, Type...> struct anyOfValue;

 template <class Type, template <Type> class Operator> struct anyOfValue<Type, Operator>
	 : std :: integral_constant<bool, false> {};

 template <class Type, template <Type> class Operator, Type ... Values> struct anyOfValue
 {
  private:
  using resultType = typename commonType <decltype(Operator <Values> :: value)...> :: type;
  public:
  constexpr const static auto value =
	  logicalOrValue <resultType, static_cast<resultType>(Operator <Values> :: value)...> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };
}

template <class Type, template <Type> class Operator, Type ... Values>
	inline constexpr crap :: anyOfValue <Type, Operator, Values...> :: operator
	typename crap :: anyOfValue <Type, Operator, Values...> :: value_type () const noexcept
{
 return crap :: anyOfValue <Type, Operator, Values...> :: value;
};
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type> class Operator, Type ... Values>
	inline constexpr typename crap :: anyOfValue <Type, Operator, Values...> :: value_type
	crap :: anyOfValue <Type, Operator, Values...> :: operator () () const noexcept
{
 return crap :: anyOfValue <Type, Operator, Values...> :: value;
}
#endif
#endif

