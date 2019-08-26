#ifndef CRAP_UTILITY_MERGEVALUES
#define CRAP_UTILITY_MERGEVALUES

#include "valuelistfortype.h"

namespace crap
{
 template <class Type, Type ... Values1> struct mergeValue
 {
  template <Type ... Values2> struct with;
 };

 template <class Type, Type ... Values1> template <Type ... Values2> struct mergeValue <Type, Values1...> :: with
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<Values1..., Values2...>;
 };
}
#endif

