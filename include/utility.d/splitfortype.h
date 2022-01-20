#ifndef CRAP_UTILITY_SPLITFORTYPE
#define CRAP_UTILITY_SPLITFORTYPE

#include "splitvalue.h"

namespace crap
{
 template <class Type, std :: size_t At> struct splitForType
 {
  template <Type ... Values> using type = splitValue<At, Type, Values...>;
  template <Type ... Values> using values = splitValue<At, Type, Values...>;
 };
}
#endif

