#ifndef CRAP_ALGORITHM_FINDFIRSTOFTYPE
#define CRAP_ALGORITHM_FINDFIRSTOFTYPE

#include <cstddef>

#include "anyoftype.h"
#include "findiftype.h"

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
 };

 template <template <class, class> class Operator, class ... Keys>
	 template <class ... Types>
	 template <class Element>
 struct findFirstOfType <Operator, Keys...> :: template with <Types...> :: searchCondition
 {
  private:
  template <class KeyElement> using condition = Operator<Element, KeyElement>;
  public:
  constexpr const static bool value = anyOfType <condition, Keys...> :: value;
 };
}

template <template <class, class> class Operator, class ... Keys> template <class ... Types>
	inline constexpr
	crap :: findFirstOfType <Operator, Keys...> :: template with <Types...> :: operator typename
	crap :: findFirstOfType <Operator, Keys...> :: template with <Types...> :: value_type ()
	const noexcept
{
 return crap :: findFirstOfType <Operator, Keys...> :: template with <Types...> :: value;
};
#endif

