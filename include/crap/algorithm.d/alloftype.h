#ifndef CRAP_ALGORITHM_ALLOFTYPE
#define CRAP_ALGORITHM_ALLOFTYPE

#include <type_traits>

#include "../functional.d/logicalandvalue.h"
#include "../utility.d/commontype.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <template <class> class, class...> struct allOfType;

 template <template <class> class Operator> struct allOfType<Operator>
	 : std :: integral_constant<bool, true> {};

 template <template <class> class Operator, class ... Types> struct allOfType
 {
  private:
  using resultType = typename commonType <decltype(Operator <Types> :: value)...> :: type;
  public:
  constexpr const static auto value = logicalAndValue <resultType, static_cast<resultType>(Operator <Types> :: value)...> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };
}

template <template <class> class Operator, class ... Types>
        inline constexpr crap :: allOfType <Operator, Types...> :: operator
	typename crap :: allOfType <Operator, Types...> :: value_type () const noexcept
{
 return crap :: allOfType <Operator, Types...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class> class Operator, class ... Types>
	inline constexpr typename crap :: allOfType <Operator, Types...> :: value_type
	crap :: allOfType <Operator, Types...> :: operator () () const noexcept
{
 return crap :: allOfType <Operator, Types...> :: value;
}
#endif
#endif

