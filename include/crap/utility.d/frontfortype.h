#ifndef CRAP_UTILITY_FRONTFORTYPE
#define CRAP_UTILITY_FRONTFORTYPE

#include "frontvalue.h"

namespace crap
{
 template <class Type> struct frontForType
 {
  template <Type ... Values> using type = frontValue<Type, Values...>;
  template <Type ... Values> using values = frontValue<Type, Values...>;
 };
}
#endif

