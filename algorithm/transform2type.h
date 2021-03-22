#ifndef CRAP_ALGORITHM_TRANSFORM2TYPE
#define CRAP_ALGORITHM_TRANSFORM2TYPE

#include "copytype.h"

namespace crap
{
 template <template <class, class> class Operator, class ... Types1> struct transform2Type
 {
  template <class ... Types2> using with = copyType<Operator <Types1, Types2> :: type...>;
 };
}
#endif

