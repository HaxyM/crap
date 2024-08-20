#ifndef CRAP_ALGORITHM_NONEOFTYPE
#define CRAP_ALGORITHM_NONEOFTYPE

#include <type_traits>

#include "../functional.d/logicalnotvalue.h"
#include "../functional.d/logicalorvalue.h"
#include "../utility.d/commontype.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <template <class> class, class...> struct noneOfType;

 template <template <class> class Operator> struct noneOfType<Operator>
	 : std :: integral_constant<bool, true> {};

 template <template <class> class Operator, class ... Types> struct noneOfType
 {
  private:
  using resultType = typename commonType <decltype(Operator <Types> :: value)...> :: type;
  constexpr const static auto orValue =
	  logicalOrValue <resultType, static_cast<resultType>(Operator <Types> :: value)...> :: value;
  public:
  constexpr const static auto value = logicalNotValue <decltype(orValue), orValue> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };
}

template <template <class> class Operator, class ... Types>
        inline constexpr crap :: noneOfType <Operator, Types...> :: operator
	typename crap :: noneOfType <Operator, Types...> :: value_type () const noexcept
{
 return crap :: noneOfType <Operator, Types...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class> class Operator, class ... Types>
	inline constexpr typename crap :: noneOfType <Operator, Types...> :: value_type
	crap :: noneOfType <Operator, Types...> :: operator () () const noexcept
{
 return crap :: noneOfType <Operator, Types...> :: value;
}
#endif
#endif
