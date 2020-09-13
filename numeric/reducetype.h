#ifndef CRAP_NUMERIC_REDUCETYPE
#define CRAP_NUMERIC_REDUCETYPE

#include "../utility/typelist.h"

namespace crap
{
 template <template <class...> class, class...> struct reduceType;

 template <template <class...> class Operator> struct reduceType<Operator>
 {
  using type = typename Operator <> :: type;
 };

 template <template <class...> class Operator, class Type> struct reduceType<Operator, Type>
 {
  using type = typename Operator <Type> :: type;
 };

 template <template <class...> class Operator, class Type1, class Type2> struct reduceType<Operator, Type1, Type2>
 {
  using type = typename Operator <Type1, Type2> :: type;
 };

 template <template <class...> class Operator, class ... Types> struct reduceType
 {
  private:
  using types = typeList<Types...>;
  constexpr const static std :: size_t half = types :: size / 2u;
  template <class ... SubTypes> using This = reduceType<Operator, SubTypes...>;
  using lower = typename types :: template till<half, This>;
  using upper = typename types :: template since<half, This>;
  public:
  using type = typename Operator <typename lower :: type, typename upper :: type> :: type;
 };
}
#endif

