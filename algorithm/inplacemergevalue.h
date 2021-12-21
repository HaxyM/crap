#ifndef CRAP_ALGORITHM_INPLACEMERGEVALUE
#define CRAP_ALGORITHM_INPLACEMERGEVALUE

#include <cstddef>

#include "mergevalue.h"
#include "../utility/splitvalue.h"
#include "../utility/valuelistfortype.h"

namespace crap
{
 template <class Type, std :: size_t Middle, template <Type, Type> class Operator, Type ... Values>
	 struct inplaceMergeValue
 {
  private:
  template <Type ... SubValues> using merge = mergeValue<Type, Operator, SubValues...>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename splitValue <Middle, Type, Values...> :: template
	  upper<splitValue <Middle, Type, Values...> :: template lower <merge> :: template with> :: template
	  type<Container>;
 };
}
#endif

