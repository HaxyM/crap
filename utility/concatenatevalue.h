#ifndef CRAP_UTILITY_CONCATENATEVALUE
#define CRAP_UTILITY_CONCATENATEVALUE

#include "valuelistfortype.h"

namespace crap
{
 template <class Type, Type ... Values1> struct concatenateValues
 {
  template <Type ... Values2> struct with;
 };

 template <class Type, Type ... Values1> template <Type ... Values2>
	 struct concatenateValues <Type, Values1...> :: with
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<Values1..., Values2...>;
 };
}
#endif

