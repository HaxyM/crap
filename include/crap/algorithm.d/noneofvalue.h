#ifndef CRAP_ALGORITHM_NONEOFVALUE
#define CRAP_ALGORITHM_NONEOFVALUE

#include <type_traits>

#include "../functional.d/logicalnotvalue.h"
#include "../functional.d/logicalorvalue.h"
#include "../utility.d/commontype.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <class Type, template <Type> class, Type...> struct noneOfValue;

 template <class Type, template <Type> class Operator> struct noneOfValue<Type, Operator>
	 : std :: integral_constant<bool, true> {};

 template <class Type, template <Type> class Operator, Type ... Values> struct noneOfValue
 {
  private:
  using resultType = typename commonType <decltype(Operator <Values> :: value)...> :: type;
  constexpr const static auto orValue =
	  logicalOrValue <resultType, static_cast<resultType>(Operator <Values> :: value)...> :: value;
  public:
  constexpr const static auto value = logicalNotValue <decltype(orValue), orValue> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };
}

template <class Type, template <Type> class Operator, Type ... Values>
        inline constexpr crap :: noneOfValue <Type, Operator, Values...> :: operator
	typename crap :: noneOfValue <Type, Operator, Values...> :: value_type () const noexcept
{
 return crap :: noneOfValue <Type, Operator, Values...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type> class Operator, Type ... Values>
	inline constexpr typename crap :: noneOfValue <Type, Operator, Values...> :: value_type
	crap :: noneOfValue <Type, Operator, Values...> :: operator () () const noexcept
{
 return crap :: noneOfValue <Type, Operator, Values...> :: value;
}
#endif
#endif
