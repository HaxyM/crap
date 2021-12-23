#ifndef CRAP_ALGORITHM_FINDFIRSTOFVALUE
#define CRAP_ALGORITHM_FINDFIRSTOFVALUE

#include <cstddef>

#include "anyofvalue.h"
#include "findifvalue.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator, Type ... Keys> struct findFirstOfValue
 {
  template <Type ... Values> struct with;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Keys> template <Type ... Values>
	 struct findFirstOfValue <Type, Operator, Keys...> :: with
 {
  private:
  template <Type Element> struct searchCondition;
  public:
  constexpr const static std :: size_t value = findIfValue <Type, searchCondition, Values...> :: value;
  constexpr const static std :: size_t npos = findIfValue <Type, searchCondition, Values...> :: npos;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Keys>
	 template <Type ... Values>
	 template <Type Element>
 struct findFirstOfValue <Type, Operator, Keys...> :: template with <Values...> :: searchCondition
 {
  private:
  template <Type KeyElement> using condition = Operator<Element, KeyElement>;
  public:
  constexpr const static bool value = anyOfValue <Type, condition, Keys...> :: value;
 };
}

template <class Type, template <Type, Type> class Operator, Type ... Keys> template <Type ... Values>
	inline constexpr
	crap :: findFirstOfValue <Type, Operator, Keys...> :: template with <Values...> :: operator typename
	crap :: findFirstOfValue <Type, Operator, Keys...> :: template with <Values...> :: value_type ()
	const noexcept
{
 return crap :: findFirstOfValue <Type, Operator, Keys...> :: template with <Values...> :: value;
};
#endif

