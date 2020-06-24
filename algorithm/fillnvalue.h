#ifndef CRAP_ALGORITHM_FILLNVALUE
#define CRAP_ALGORITHM_FILLNVALUE

#include "../algorithm/fillfortype.h"
#include "../utility/concatenatefortype.h"
#include "../utility/splitvalue.h"
#include "../utility/valuelistfortype.h"

namespace crap
{
 template <std :: size_t N, class Type, Type Value, Type ... Values> struct fillNValue
 {
  private:
  constexpr const static std :: size_t pivot = (((sizeof...(Values)) < N) ? sizeof...(Values) : N);
  using split = splitValue<pivot, Type, Values...>;
  template <template <Type...> class Container>
	  using lower = typename split :: template
	  lower <fillForType <Type, Value> :: template type> :: template type<Container>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename split :: template
	  upper<lower <concatenateForType <Type> :: template type> :: template with> :: template
	  type<Container>;
 };
}
#endif

