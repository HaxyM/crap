#ifndef CRAP_ALGORITHM_REMOVEVALUE
#define CRAP_ALGORITHM_REMOVEVALUE

#include "removeifvalue.h"
#include "../utility.d/valuelistfortype.h"

namespace crap
{
 template <class Type, Type Value, template <Type, Type> class Operator, Type ... Values>
	 struct removeValue
 {
  private:
  template <Type SomeValue> using condition = Operator<Value, SomeValue>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename removeIfValue <Type, condition, Values...> :: template type<Container>;
 };
}
#endif

