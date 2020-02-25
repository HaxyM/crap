#ifndef CRAP_ALGORITHM_REMOVEVALUE
#define CRAP_ALGORITHM_REMOVEVALUE

#include "../utility/concatenatefortype.h"
#include "../utility/valuelist.h"
#include "../utility/valuelistfortype.h"

namespace crap
{
 template <class Type, std :: size_t Begin, std :: size_t End, Type ... Values> struct removeValue
 {
  private:
  using values = valueList<Type, Values...>;
  static_assert(Begin <= End, "Negative range not supported.");
  static_assert(End <= (values :: size), "Index out of range.");
  static_assert(Begin <= (values :: size), "Index out of range.");
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename values :: template
	  since <End, values :: template till <Begin, concatenateForType <Type> :: template type> :: template with> :: template
	  type<Container>;
 };
}
#endif

