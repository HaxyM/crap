#ifndef CRAP_ALGORITHM_REMOVEFORTYPE
#define CRAP_ALGORITHM_REMOVEFORTYPE

#include "removevalue.h"

namespace crap
{
 template <class Type, std :: size_t Begin, std :: size_t End> struct removeForType
 {
  template <Type ... Values> using type = removeValue<Type, Begin, End, Values...>;
  template <Type ... Values> using values = removeValue<Type, Begin, End, Values...>;
 };
}
#endif

