#ifndef CRAP_NUMERIC_EXCLUSIVESCANTYPE
#define CRAP_NUMERIC_EXCLUSIVESCANTYPE

#include "../utility.d/backtype.h"
#include "../utility.d/bisecttype.h"
#include "../utility.d/concatenatetype.h"
#include "../utility.d/typelist.h"

namespace crap
{
 template <class, template <class, class> class, class...> struct exclusiveScanType;

 template <class Init, template <class, class> class Operator>
	 struct exclusiveScanType<Init, Operator>
 {
  template <template <class...> class Container = typeList>
	  using type = Container<>;
 };

 template <class Init, template <class, class> class Operator, class Type>
	 struct exclusiveScanType<Init, Operator, Type>
 {
  template <template <class...> class Container = typeList>
	  using type = Container<Init>;
 };

 template <class Init, template <class, class> class Operator, class Type1, class Type2>
	 struct exclusiveScanType<Init, Operator, Type1, Type2>
 {
  template <template <class...> class Container = typeList>
	  using type = Container<Init, typename Operator <Init, Type1> :: type>;
 };

 template <class Init, template <class, class> class Operator, class ... Types>
	 struct exclusiveScanType
 {
  private:
  using types = bisectType<Types...>;
  template <class ... SubTypes> using lowerPass = exclusiveScanType<Init, Operator, SubTypes...>;
  template <template <class...> class Container>
	  using lower = typename types :: template lower <lowerPass> :: template type<Container>;
  using lowerEnd = typename types :: template lower <backType> :: type;
  using sumEnd = typename lower <backType> :: type;
  template <class ... SubTypes>
	  using upperPass = exclusiveScanType<typename Operator <sumEnd, lowerEnd> :: type, Operator, SubTypes...>;
  template <template <class...> class Container>
	  using upper = typename types :: template upper <upperPass> :: template type<Container>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename upper <lower <concatenateType> :: template with> :: template
	  type<Container>;
 };
}
#endif

