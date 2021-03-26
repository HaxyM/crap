#ifndef CRAP_ALGORITHM_UPPERBOUNDTYPE
#define CRAP_ALGORITHM_UPPERBOUNDTYPE

#include "../utility/bisecttype.h"

namespace crap
{
 template <class, template <class, class> class, class...> struct upperBoundType;

 template <class Type, template <class, class> class Operator> struct upperBoundType<Type, Operator>
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
 };

 template <class Type, template <class, class> class Operator, class Type1> struct upperBoundType<Type, Operator, Type1>
 {
  constexpr const static std :: size_t value = (Operator <Type, Type1> :: value ? 0u : 1u);
  constexpr const static std :: size_t npos = 1u;
 };

 template <class Type, template <class, class> class Operator, class ... Types> struct upperBoundType
 {
  private:
  using values = bisectType<Types...>;
  template <class ... SubTypes> using This = upperBoundType<Type, Operator, SubTypes...>;
  using lower = typename values :: template lower<This>;
  using upper = typename values :: template upper<This>;
  public:
  constexpr const static std :: size_t value = (((lower :: value) != (lower :: npos)) ? (lower :: value) : ((lower :: npos) + (upper :: value)));
  constexpr const static std :: size_t npos = (lower :: npos) + (upper :: npos);
 };
}
#endif
