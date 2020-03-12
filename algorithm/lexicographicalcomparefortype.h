#ifndef CRAP_ALGORITHM_LEXICOGRAPHICALCOMPAREFORTYPE
#define CRAP_ALGORITHM_LEXICOGRAPHICALCOMPAREFORTYPE

#include "lexicographicalcomparevalue.h"
#include "../functional/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less>
	 struct lexicographicalCompareForType
 {
  using detailedResult_t = typename lexicographicalCompareValue <Type, Operator> :: detailedResult_t;
  template <Type ... Values> using type = lexicographicalCompareValue<Type, Operator, Values...>;
  template <Type ... Values> using values = lexicographicalCompareValue<Type, Operator, Values...>;
 };
}
#endif

