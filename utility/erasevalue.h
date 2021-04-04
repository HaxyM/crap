#ifndef CRAP_UTILITY_ERASEVALUE
#define CRAP_UTILITY_ERASEVALUE

#include "concatenatefortype.h"
#include "valuelist.h"
#include "valuelistfortype.h"

namespace crap
{
 template <class Type, std :: size_t Begin, std :: size_t End, Type ... Values> struct eraseValue
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

