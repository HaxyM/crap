#ifndef CRAP_ALGORITHM_FINDENDVALUE
#define CRAP_ALGORITHM_FINDENDVALUE

#include <cstddef>

#include "searchvalue.h"
#include "reversevalue.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator, Type ... Values> struct findEndValue
 {
  template <Type ... Pattern> struct with;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> template <Type ... Pattern>
	 struct findEndValue <Type, Operator, Values...> :: with
 {
  private:
  template <Type ... SubValues> using search = searchValue<Type, Operator, SubValues...>;
  constexpr const static std :: size_t sinceEnd = reverseValue <Type, Pattern...> :: template
	  type <reverseValue <Type, Values...> :: template type <search> :: template with> :: value;
  public:
  constexpr const static std :: size_t value =
	  (sizeof...(Values) == sinceEnd) ? sizeof...(Values) : (sizeof...(Values) - sizeof...(Pattern) - sinceEnd); 
  constexpr const static std :: size_t npos = sizeof...(Values);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <class Type, template <Type, Type> class Operator, Type ... Values> template <Type ... Pattern>
	inline constexpr
	crap :: findEndValue <Type, Operator, Values...> :: template with <Pattern...> :: operator typename
	crap :: findEndValue <Type, Operator, Values...> :: template with <Pattern...> :: value_type()
	const noexcept
{
 return crap :: findEndValue <Type, Operator, Values...> :: template with <Pattern...> :: value;
}
#endif

