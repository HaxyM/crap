#ifndef CRAP_UTILITY_ERASEFORTYPE
#define CRAP_UTILITY_ERASEFORTYPE

#include "erasevalue.h"

namespace crap
{
 template <class Type, std :: size_t Begin, std :: size_t End> struct eraseForType
 {
  template <Type ... Values> using type = eraseValue<Type, Begin, End, Values...>;
  template <Type ... Values> using values = eraseValue<Type, Begin, End, Values...>;
 };
}
#endif

