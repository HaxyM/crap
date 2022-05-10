#ifndef CRAP_NUMERIC_INCLUSIVESCANTYPE
#define CRAP_NUMERIC_INCLUSIVESCANTYPE

#include "../algorithm.d/transformtype.h"
#include "../utility.d/backtype.h"
#include "../utility.d/bisecttype.h"
#include "../utility.d/concatenatetype.h"
#include "../utility.d/typelist.h"

namespace crap
{
 template <template <class, class> class, class...> struct inclusiveScanType;

 template <template <class, class> class Operator>
	 struct inclusiveScanType<Operator>
 {
  template <template <class...> class Container = typeList>
	  using type = Container<>;
 };

 template <template <class, class> class Operator, class Type>
	 struct inclusiveScanType<Operator, Type>
 {
  template <template <class...> class Container = typeList>
	  using type = Container<Type>;
 };

 template <template <class, class> class Operator, class Type1, class Type2>
	 struct inclusiveScanType<Operator, Type1, Type2>
 {
  template <template <class...> class Container = typeList>
	  using type = Container<Type1, typename Operator <Type1, Type2> :: type>;
 };

 template <template <class, class> class Operator, class ... Types> struct inclusiveScanType
 {
  private:
  template <class ... SubTypes> using This = inclusiveScanType<Operator, SubTypes...>;
  using types = bisectType<Types...>;
  template <template <class...> class Container>
	  using lower = typename types :: template lower <This> :: template type<Container>;
  template <class SubType>
	  using UpperAdd = Operator<typename lower <backType> :: type, SubType>;
  template <class ... SubTypes>
	  using transform = transformType<UpperAdd, SubTypes...>;
  template <template <class...> class Container>
	  using upper = typename types :: template
	  upper <This> :: template
	  type <transform> :: template
	  type<Container>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename upper <lower <concatenateType> :: template with> :: template
	  type<Container>;
 };
}
#endif
