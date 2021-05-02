#ifndef CRAP_ALGORITHM_ISSORTEDTYPE
#define CRAP_ALGORITHM_ISSORTEDTYPE

#include "../utility/bisecttype.h"

#include <type_traits>

namespace crap
{
 template <template <class, class> class, class...> struct isSortedType;

 template <template <class, class> class Operator> struct isSortedType<Operator>
	 : std :: integral_constant<bool, true> {};

 template <template <class, class> class Operator, class Type> struct isSortedType<Operator, Type>
	 : std :: integral_constant<bool, true>
 {
  private:
  template <template <class, class> class SomeOperator,class ... SomeTypes>
	  friend struct isSortedType;
  using first = Type;
  using last = Type;
 };

 template <template <class, class> class Operator, class ... Types> struct isSortedType
 {
  private:
  using values = bisectType<Types...>;
  template <template <class, class> class SomeOperator, class ... SomeTypes>
	  friend struct isSortedType;
  template <class ... SubTypes> using This = isSortedType<Operator, SubTypes...>;
  using lower = typename values :: template lower <This>;
  using upper = typename values :: template upper <This>;
  using first = typename lower :: first;
  using last = typename upper :: last;
  public:
  constexpr const static auto value = (lower :: value) && (upper :: value) && (Operator <typename lower :: last, typename upper :: first> :: value);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <template <class, class> class Operator, class ... Types>
        inline constexpr crap :: isSortedType <Operator, Types...> :: operator
        typename crap :: isSortedType <Operator, Types...> :: value_type () const noexcept
{
 return crap :: isSortedType <Operator, Types...> :: value;
}
#endif
