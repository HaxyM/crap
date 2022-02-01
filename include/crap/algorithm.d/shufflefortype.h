#ifndef CRAP_ALGORITHM_SHUFFLEFORTYPE
#define CRAP_ALGORITHM_SHUFFLEFORTYPE

#include "shufflevalue.h"

namespace crap
{
 template <class Type> struct shuffleForType
 {
  template <Type ... Values> using type = shuffleValue<Type, Values...>;
  template <Type ... Values> using values = shuffleValue<Type, Values...>;
 };
}
#endif

