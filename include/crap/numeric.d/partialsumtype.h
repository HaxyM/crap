#ifndef CRAP_NUMERIC_PARTIALSUMTYPE
#define CRAP_NUMERIC_PARTIALSUMTYPE

#include "../algorithm.d/copytype.h"
#include "../utility.d/bisecttype.h"
#include "../utility.d/concatenatetype.h"
#include "../utility.d/typelist.h"

namespace crap
{
 template <template <class...> class, class...> struct partialSumType;

 template <template <class...> class Operator> struct partialSumType<Operator>
	 : copyType<> {};

 template <template <class...> class Operator, class Type> struct partialSumType<Operator, Type>
	 : copyType<Type>
 {
  private:
  template <template <class...> class SomeOperator,class ... SomeTypes>
	  friend struct partialSumType;
  using last = Type;
 };

 template <template <class...> class Operator, class ... Types> struct partialSumType
 {
  private:
  using values = bisectType<Types...>;
  template <template <class...> class SomeOperator, class ... SomeTypes>
	  friend struct partialSumType;
  template <class ... SubTypes> using This = partialSumType<Operator, SubTypes...>;
  using lower = typename values :: template lower <This>;
  template <class Element> using upperOperator = typename Operator <typename lower :: last, Element> :: type;
  template <class ... SubTypes> using transformUpper = copyType<upperOperator<SubTypes>...>;
  using upper = typename values :: template upper <This> :: template type<transformUpper>;
  using last = upperOperator<typename values :: template upper <This> :: last>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename upper :: template
	  type <lower :: template type <concatenateType> :: template with> :: template
	  type<Container>;
 };
}
#endif

