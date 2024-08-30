#ifndef CRAP_ALGORITHM_FINDFIRSTOFTYPE
#define CRAP_ALGORITHM_FINDFIRSTOFTYPE

#include <cstddef>

#include "anyoftype.h"
#include "findiftype.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <template <class, class> class Operator, class ... Keys> struct findFirstOfType
 {
  template <class ... Types> struct with;
 };

 template <template <class, class> class Operator, class ... Keys> template <class ... Types>
	 struct findFirstOfType <Operator, Keys...> :: with
 {
  private:
  template <class Element> struct searchCondition;
  public:
  constexpr const static std :: size_t value = findIfType <searchCondition, Types...> :: value;
  constexpr const static std :: size_t npos = findIfType <searchCondition, Types...> :: npos;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class ... Keys>
	 template <class ... Types>
	 template <class Element>
 struct findFirstOfType <Operator, Keys...> :: with <Types...> :: searchCondition
 {
  private:
  template <class KeyElement> using condition = Operator<Element, KeyElement>;
  public:
  constexpr const static bool value = anyOfType <condition, Keys...> :: value;
 };
}

template <template <class, class> class Operator, class ... Keys> template <class ... Types>
	inline constexpr
	crap :: findFirstOfType <Operator, Keys...> :: with <Types...> :: operator typename
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: findFirstOfType <Operator, Keys...> :: template with <Types...> :: value_type ()
#else
	crap :: findFirstOfType <Operator, Keys...> :: with <Types...> :: value_type ()
#endif
	const noexcept
{
 return crap :: findFirstOfType <Operator, Keys...> :: with <Types...> :: value;
};
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class ... Keys> template <class ... Types>
        inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
        crap :: findFirstOfType <Operator, Keys...> :: template with <Types...> :: value_type
#else
        crap :: findFirstOfType <Operator, Keys...> :: with <Types...> :: value_type
#endif
        crap :: findFirstOfType <Operator, Keys...> :: with <Types...> :: operator () ()
	const noexcept
{
 return crap :: findFirstOfType <Operator, Keys...> :: with <Types...> :: value;
}
#endif
#endif

