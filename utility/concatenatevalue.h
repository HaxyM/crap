#ifndef CRAP_UTILITY_CONCATENATEVALUE
#define CRAP_UTILITY_CONCATENATEVALUE

#include "valuelistfortype.h"

namespace crap
{
 template <class Type, Type ... Values1> struct concatenateValue
 {
  template <Type ... Values2> using with = concatenateValue<Type, Values1..., Values2...>;
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<Values1...>;
 };
}
#endif

