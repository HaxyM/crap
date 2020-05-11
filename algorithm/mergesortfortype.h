#ifndef CRAP_ALGORITHM_MERGESORTFORTYPE
#define CRAP_ALGORITHM_MERGESORTFORTYPE

#include "mergesortvalue.h"
#include "../functional/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less> struct mergeSortForType
 {
  template <Type ... Values> using type = mergeSortValue<Type, Operator, Values...>;
  template <Type ... Values> using values = mergeSortValue<Type, Operator, Values...>;
 };
}
#endif

