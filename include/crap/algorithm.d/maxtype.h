#ifndef CRAP_ALGORITHM_MAXTYPE
#define CRAP_ALGORITHM_MAXTYPE

#include "../numeric.d/reducetype.h"

#include <type_traits>

namespace crap
{
 template <template <class, class> class, class...> struct maxType;

 template <template <class, class> class Operator, class Type> struct maxType<Operator, Type>
 {
  using type = Type;
 };

 template <template <class, class> class Operator, class Type1, class Type2>
	 struct maxType<Operator, Type1, Type2>
 {
  using type = typename std :: conditional <Operator <Type2, Type1> :: value, Type1, Type2> :: type;
 };

 template <template <class, class> class Operator, class ... Types> struct maxType
 {
  private:
  static_assert(sizeof...(Types) > 0u, "Extremum of empty set is not defined.");
  template <class ... SubTypes> using This = maxType<Operator, SubTypes...>;
  public:
  using  type = typename reduceType <This, Types...> :: type;
 };
}
#endif

