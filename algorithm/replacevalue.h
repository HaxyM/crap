#ifndef CRAP_ALGORITHM_REPLACEVALUE
#define CRAP_ALGORITHM_REPLACEVALUE

#include "../utility/valuelistfortype.h"

#include <type_traits>

namespace crap
{
 template <class Type, Type Old, Type New, template <Type, Type> class Operator, Type ... Values>
	 struct replaceValue
 {
  private:
  template <Type Value> using value = std :: integral_constant<Type, ((Operator <Value, Old>) ? New : Value)>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<(value <Values> :: value)...>;
 };
}
#endif

