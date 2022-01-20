#ifndef CRAP_ALGORITHM_SORTHEAPVALUE
#define CRAP_ALGORITHM_SORTHEAPVALUE

#include "copyvalue.h"
#include "pullheapvalue.h"
#include "../utility.d/valuelist.h"
#include "../utility.d/valuelistfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct sortHeapValue;

 template <class Type, template <Type, Type> class Operator> struct sortHeapValue<Type, Operator>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<>;
 };

 template <class Type, template <Type, Type> class Operator, Type Value>
	 struct sortHeapValue<Type, Operator, Value>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<Value>;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
	 struct sortHeapValue<Type, Operator, Value1, Value2>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<Value2, Value1>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> struct sortHeapValue
 {
  private:
  template <Type ... SubValues> struct back;
  template <Type ... SubValues> using This = sortHeapValue<Type, Operator, SubValues...>;
  using pop = typename pullHeapValue <Type, Operator, Values...> :: template type<back>;
  template <Type ... SubValues> using merge = copyValue <Type, SubValues..., pop :: value>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename pop :: template rest <This> :: template type <merge> :: template type<Container>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <Type ... SubValues>
 struct sortHeapValue <Type, Operator, Values...> :: back
 {
  private:
  using values = valueList<Type, SubValues...>;
  public:
  constexpr const static Type value = values :: template At <sizeof...(SubValues) - 1u> :: value;
  template <template <Type...> class Container>
	  using rest = typename values :: template till<sizeof...(SubValues) - 1u, Container>;
 };
}
#endif

