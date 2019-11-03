#ifndef CRAP_NUMERIC_OUTERPRODUCTVALUE
#define CRAP_NUMERIC_OUTERPRODUCTVALUE

#include "../utility/concatenatefortype.h"
#include "../utility/valuelistfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct outerProductValue;

 template <class Type, template <Type, Type> class Operator> struct outerProductValue<Type, Operator>
 {
  template <Type ... Values2> struct with;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1>
 struct outerProductValue<Type, Operator, Value1>
 {
  template <Type ... Values2> struct with;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1> struct outerProductValue
 {
  template <Type ... Values2> struct with;
 };

 template <class Type, template <Type, Type> class Operator> template <Type ... Values2>
	 struct outerProductValue <Type, Operator> :: with
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<>;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1> template <Type ... Values2>
	 struct outerProductValue <Type, Operator, Value1> :: with
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<(Operator <Value1, Values2> :: value)...>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1> template <Type ... Values2>
	 struct outerProductValue <Type, Operator, Values1...> :: with
 {
  private:
  using values = valueList<Type, Values1...>;
  constexpr const static std :: size_t half = (values :: size) / 2u;
  template <Type ... SubValues> using This = outerProductValue<Type, Operator, SubValues...>;
  using lower = typename values :: template till <half, This> :: template with <Values2...> :: template type<concatenateForType <Type> :: template type>;
  using upper = typename values :: template since <half, This> :: template with <Values2...> :: template type<lower :: template with>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename upper :: template type<Container>;
 };
}
#endif

