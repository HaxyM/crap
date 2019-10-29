#ifndef CRAP_UTILITY_CONCATENATEFORTYPE
#define CRAP_UTILITY_CONCATENATEFORTYPE

#include "concatenatevalue.h"

namespace crap
{
 template <class Type> struct concatenateForType
 {
  template <Type ... Values> using type = concatenateValue<Type, Values...>;
  template <Type ... Values> using values = concatenateValue<Type, Values...>;
 };
}
#endif

