#ifndef CRAP_ALGORITHM_ANYOFTYPE
#define CRAP_ALGORITHM_ANYOFTYPE

#include <type_traits>

#include "../functional.d/logicalorvalue.h"
#include "../utility.d/commontype.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <template <class> class, class...> struct anyOfType;

 template <template <class> class Operator> struct anyOfType<Operator>
	 : std :: integral_constant<bool, false> {};

 template <template <class> class Operator, class ... Types> struct anyOfType
 {
  private:
  using resultType = typename commonType <decltype(Operator <Types> :: value)...> :: type;
  public:
  constexpr const static auto value = logicalOrValue <resultType, static_cast<resultType>(Operator <Types> :: value)...> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };
}

template <template <class> class Operator, class ... Types>
        inline constexpr crap :: anyOfType <Operator, Types...> :: operator
	typename crap :: anyOfType <Operator, Types...> :: value_type () const noexcept
{
 return crap :: anyOfType <Operator, Types...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class> class Operator, class ... Types>
	inline constexpr typename crap :: anyOfType <Operator, Types...> :: value_type
	crap :: anyOfType <Operator, Types...> :: operator () () const noexcept
{
 return crap :: anyOfType <Operator, Types...> :: value;
}
#endif
#endif

