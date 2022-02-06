#ifndef CRAP_ALGORITHM_EXTREMAOPERATORSFORTYPE
#define CRAP_ALGORITHM_EXTREMAOPERATORSFORTYPE

#include "maxvalue.h"
#include "minvalue.h"
#include "../functional.d/comparatorsfortype.h"
#include "../utility.d/language.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less>
	 struct extremaOperatorsForType
 {
  template <Type ... Values> using Maximum = maxValue<Type, Operator, Values...>;
  template <Type ... Values> using Minimum = minValue<Type, Operator, Values...>;
  #if CPP14
  template <Type ... Values> constexpr const static auto maximum = maxValue <Type, Operator, Values...> :: value;
  template <Type ... Values> constexpr const static auto minimum = minValue <Type, Operator, Values...> :: value;
  #endif
 };
}
#endif

