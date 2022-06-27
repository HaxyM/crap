#ifndef CRAP_ALGORITHM_MINTYPE
#define CRAP_ALGORITHM_MINTYPE

#include "../numeric.d/reducetype.h"

#include <type_traits>

namespace crap
{
 template <template <class, class> class, class...> struct minType;

 template <template <class, class> class Operator, class Type> struct minType<Operator, Type>
 {
  using type = Type;
 };

 template <template <class, class> class Operator, class Type1, class Type2>
	 struct minType<Operator, Type1, Type2>
 {
  using type = typename std :: conditional <Operator <Type1, Type2> :: value, Type1, Type2> :: type;
 };

 template <template <class, class> class Operator, class ... Types> struct minType
 {
  private:
  static_assert(sizeof...(Types) > 0u, "Extremum of empty set is not defined.");
  template <class ... SubTypes> using This = minType<Operator, SubTypes...>;
  public:
  using  type = typename reduceType <This, Types...> :: type;
 };
 template <template <class, clas> class Operator, class ... Types> using minType_t = typename minType <Operator, Types...> :: type;
}
#endif

