#ifndef CRAP_STRING_STRINGFORTYPE
#define CRAP_STRING_STRINGFORTYPE

#include "string.h"

namespace crap
{
 template <class Type> struct stringForType
 {
  template <Type ... Values> using type = string<Type, Values...>;
  template <Type ... Values> using values = string<Type, Values...>;
 };
}
#endif

