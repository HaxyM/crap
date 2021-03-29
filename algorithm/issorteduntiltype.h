#ifndef CRAP_ALGORITHM_ISSORTEDUNTILTYPE
#define CRAP_ALGORITHM_ISSORTEDUNTILTYPE

#include "../utility/bisecttype.h"

namespace crap
{
 template <template <class, class> class, class...> struct isSortedUntilType;

 template <template <class, class> class Operator> struct isSortedUntilType<Operator>
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
 };

 template <template <class, class> class Operator, class Type> struct isSortedUntilType<Operator, Type>
 {
  private:
  template <template <class, class> class, class...> friend struct isSortesUntilType;
  using first = Type;
  using last = Type;
  public:
  constexpr const static std :: size_t value = 1u;
  constexpr const static std :: size_t npos = 1u;
 };

 template <template <class, class> class Operator, class Type1, class Type2> struct isSortedUntilType<Operator, Type1, Type2>
 {
  private:
  template <template <class, class> class, class...> friend struct isSortedUntilType;
  using first = Type1;
  using last = Type2;
  public:
  constexpr const static std :: size_t value = ((Operator <Type2, Type1> :: value) ? 1u : 2u);
  constexpr const static std :: size_t npos = 2u;
 };

 template <template <class, class> class Operator, class ... Types> struct isSortedUntilType
 {
  private:
  using values = bisectType<Types...>;
  template <template <class, class> class, class...> friend struct isSortedUntilType;
  template <class ... SubTypes> using This = isSortedUntilType<Operator, SubTypes...>;
  using lower = typename values :: template lower<This>;
  using upper = typename values :: template upper<This>;
  constexpr const static bool borderUnsorted = Operator <typename upper :: first, typename lower :: last> :: value;
  constexpr const static bool lowerUnsorted = ((lower :: value) != (lower :: npos));
  constexpr const static std :: size_t upperValue = (borderUnsorted ? 0u : (upper :: value));
  using first = typename lower :: first;
  using last = typename upper :: last;
  public:
  constexpr const static std :: size_t value = (lowerUnsorted ? (lower :: value) : ((lower :: value) + upperValue));
  constexpr const static std :: size_t npos = sizeof...(Types);
 };
}
#endif
