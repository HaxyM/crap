#ifndef CRAP_ALGORITHM_MERGESORTFORTYPE
#define CRAP_ALGORITHM_MERGESORTFORTYPE

#include "mergesort.h"
#include "../functional/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less> struct mergeSortForType
 {
  template <Type ... Values> using type = mergeSort<Type, Operator, Values...>;
  template <Type ... Values> using values = mergeSort<Type, Operator, Values...>;
 };
}
#endif

