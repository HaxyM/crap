#ifndef CRAP_NUMERIC_EXCLUSIVESCANVALUE
#define CRAP_NUMERIC_EXCLUSIVESCANVALUE

#include "../utility.d/backfortype.h"
#include "../utility.d/bisectvalue.h"
#include "../utility.d/concatenatefortype.h"
#include "../utility.d/valuelistfortype.h"

namespace crap
{
 template <class Type, Type, template <Type, Type> class, Type...> struct exclusiveScanValue;

 template <class Type, Type Init, template <Type, Type> class Operator>
	 struct exclusiveScanValue<Type, Init, Operator>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<>;
 };

 template <class Type, Type Init, template <Type, Type> class Operator, Type Value>
	 struct exclusiveScanValue<Type, Init, Operator, Value>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<Init>;
 };

 template <class Type, Type Init, template <Type, Type> class Operator, Type Value1, Type Value2>
	 struct exclusiveScanValue<Type, Init, Operator, Value1, Value2>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<Init, Operator <Init, Value1> :: value>;
 };

 template <class Type, Type Init, template <Type, Type> class Operator, Type ... Values>
	 struct exclusiveScanValue
 {
  private:
  using values = bisectValue<Type, Values...>;
  template <Type ... SubValues> using lowerPass = exclusiveScanValue<Type, Init, Operator, SubValues...>;
  template <template <Type...> class Container>
	  using lower = typename values :: template lower <lowerPass> :: template type<Container>;
  constexpr const static Type lowerEnd = values :: template lower <backForType <Type> :: template type> :: value;
  constexpr const static Type sumEnd = lower <backForType <Type> :: template type> :: value;
  template <Type ... SubValues>
	  using upperPass = exclusiveScanValue<Type, Operator <sumEnd, lowerEnd> :: value, Operator, SubValues...>;
  template <template <Type...> class Container>
	  using upper = typename values :: template upper <upperPass> :: template type<Container>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename upper <lower <concatenateForType <Type> :: template type> :: template with> :: template
	  type<Container>;
 };
}
#endif

