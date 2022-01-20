#ifndef CRAP_ALGORITHM_MINMAXTYPE
#define CRAP_ALGORITHM_MINMAXTYPE

#include <type_traits>

#include "../utility.d/bisecttype.h"

namespace crap
{
 template <template <class, class> class, class...> struct minMaxType;

 template <template <class, class> class Operator, class Type> struct minMaxType<Operator, Type>
 {
  using minimum = Type;
  using maximum = Type;
 };

 template <template <class, class> class Operator, class Type1, class Type2>
	 struct minMaxType<Operator, Type1, Type2>
 {
  using minimum = typename std :: conditional<(Operator <Type2, Type1> :: value), Type2, Type1> :: type;
  using maximum = typename std :: conditional<(Operator <Type2, Type1> :: value), Type1, Type2> :: type;
 };

 template <template <class, class> class Operator, class ... Types> struct minMaxType
 {
  private:
  static_assert(sizeof...(Types) > 0u, "Extremum of empty set is not defined.");
  template <class ... SubTypes> using This = minMaxType<Operator, SubTypes...>;
  using lower = typename bisectType <Types...> :: template lower<This>;
  using upper = typename bisectType <Types...> :: template upper<This>;
  public:
  using minimum = typename std :: conditional
	  <Operator <typename upper :: minimum, typename lower :: minimum> :: value,
	  typename upper :: minimum, typename lower :: minimum> :: type;
  using maximum = typename std :: conditional
	  <Operator <typename upper :: maximum, typename lower :: maximum> :: value,
	  typename lower :: maximum, typename upper :: maximum> :: type;
 };
}
#endif

