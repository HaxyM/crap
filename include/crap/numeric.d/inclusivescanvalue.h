#ifndef CRAP_NUMERIC_INCLUSIVESCANVALUE
#define CRAP_NUMERIC_INCLUSIVESCANVALUE

#include "../algorithm.d/transformfortype.h"
#include "../utility.d/backfortype.h"
#include "../utility.d/bisectvalue.h"
#include "../utility.d/concatenatefortype.h"
#include "../utility.d/valuelistfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct inclusiveScanValue;

 template <class Type, template <Type, Type> class Operator>
	 struct inclusiveScanValue<Type, Operator>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<>;
 };

 template <class Type, template <Type, Type> class Operator, Type Value>
	 struct inclusiveScanValue<Type, Operator, Value>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<Value>;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
	 struct inclusiveScanValue<Type, Operator, Value1, Value2>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<Value1, Operator <Value1, Value2> :: value>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> struct inclusiveScanValue
 {
  private:
  template <Type ... SubValues> using This = inclusiveScanValue<Type, Operator, SubValues...>;
  using values = bisectValue<Type, Values...>;
  template <template <Type...> class Container>
	  using lower = typename values :: template lower <This> :: template type<Container>;
  template <Type SubValue>
	  using UpperAdd = Operator<lower <backForType <Type> :: template type> :: value, SubValue>;
  template <template <Type...> class Container>
	  using upper = typename values :: template
	  upper <This> :: template
	  type <transformForType <Type, UpperAdd> :: template type> :: template
	  type<Container>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename upper <lower <concatenateForType <Type> :: template type> :: template with> :: template
	  type<Container>;
 };
}
#endif
