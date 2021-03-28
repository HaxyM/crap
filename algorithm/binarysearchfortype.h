#ifndef CRAP_ALGORITHM_BINARYSEARCHFORTYPE
#define CRAP_ALGORITHM_BINARYSEARCHFORTYPE

#include "binarysearchvalue.h"
#include "../functional/comparatorsfortype.h"

namespace crap
{
 template <class Type, Type Value, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less> struct binarySearchForType
 {
  template <Type ... Values> using type = binarySearchValue<Type, Value, Operator, Values...>;
  template <Type ... Values> using values = binarySearchValue<Type, Value, Operator, Values...>;
 };
}
#endif
