#ifndef CRAP_NUMERIC_OUTERPRODUCTTYPE
#define CRAP_NUMERIC_OUTERPRODUCTTYPE

#include "../utility.d/bisecttype.h"
#include "../utility.d/concatenatetype.h"
#include "../utility.d/typelist.h"

namespace crap
{
 template <template <class, class> class, class...> struct outerProductType;

 template <template <class, class> class Operator> struct outerProductType<Operator>
 {
  template <class ... Types2> struct with;
 };

 template <template <class, class> class Operator, class Type1>
 struct outerProductType<Operator, Type1>
 {
  template <class ... Types2> struct with;
 };

 template <template <class, class> class Operator, class ... Types1> struct outerProductType
 {
  template <class ... Types2> struct with;
 };

 template <template <class, class> class Operator> template <class ... Types2>
	 struct outerProductType <Operator> :: with
 {
  template <template <class...> class Container = typeList> using type = Container<>;
 };

 template <template <class, class> class Operator, class Type1> template <class ... Types2>
	 struct outerProductType <Operator, Type1> :: with
 {
  private:
  template <class SubType> using element = typename Operator <Type1, SubType> :: type;
  public:
  template <template <class...> class Container = typeList>
	  using type = Container<element<Types2>...>;
 };

 template <template <class, class> class Operator, class ... Types1> template <class ... Types2>
	 struct outerProductType <Operator, Types1...> :: with
 {
  private:
  using types = bisectType<Types1...>;
  template <class ... SubTypes> using This = outerProductType<Operator, SubTypes...>;
  using lower = typename types :: template lower <This> :: template with <Types2...> :: template type<concatenateType>;
  using upper = typename types :: template upper <This> :: template with <Types2...> :: template type<lower :: template with>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename upper :: template type<Container>;
 };
}
#endif

