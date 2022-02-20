#ifndef CRAP_ALGORITHM_FINDENDTYPE
#define CRAP_ALGORITHM_FINDENDTYPE

#include <cstddef>

#include "searchtype.h"
#include "reversetype.h"

namespace crap
{
 template <template <class, class> class Operator, class ... Types> struct findEndType
 {
  template <class ... Pattern> struct with;
 };

 template <template <class, class> class Operator, class ... Types> template <class ... Pattern>
	 struct findEndType <Operator, Types...> :: with
 {
  private:
  template <class ... SubTypes> using search = searchType<Operator, SubTypes...>;
  constexpr const static std :: size_t sinceEnd = reverseType <Pattern...> :: template
	  type <reverseType <Types...> :: template type <search> :: template with> :: value;
  public:
  constexpr const static std :: size_t value =
	  (sizeof...(Types) == sinceEnd) ? sizeof...(Types) : (sizeof...(Types) - sizeof...(Pattern) - sinceEnd); 
  constexpr const static std :: size_t npos = sizeof...(Types);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <template <class, class> class Operator, class ... Types> template <class ... Pattern>
	inline constexpr
	crap :: findEndType <Operator, Types...> :: template with <Pattern...> :: operator typename
	crap :: findEndType <Operator, Types...> :: template with <Pattern...> :: value_type()
	const noexcept
{
 return crap :: findEndType <Operator, Types...> :: template with <Pattern...> :: value;
}
#endif

