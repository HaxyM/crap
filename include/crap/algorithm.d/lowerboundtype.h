#ifndef CRAP_ALGORITHM_LOWERBOUNDTYPE
#define CRAP_ALGORITHM_LOWERBOUNDTYPE

#include "../utility.d/bisecttype.h"

namespace crap
{
 template <class, template <class, class> class, class...> struct lowerBoundType;

 template <class Type, template <class, class> class Operator> struct lowerBoundType<Type, Operator>
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <class, class> class Operator, class Type1> struct lowerBoundType<Type, Operator, Type1>
 {
  constexpr const static std :: size_t value = (Operator <Type1, Type> :: value ? 1u : 0u);
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <class, class> class Operator, class ... Types> struct lowerBoundType
 {
  private:
  using values = bisectType<Types...>;
  template <class ... SubTypes> using This = lowerBoundType<Type, Operator, SubTypes...>;
  using lower = typename values :: template lower<This>;
  using upper = typename values :: template upper<This>;
  public:
  constexpr const static std :: size_t value = (((lower :: value) != (lower :: npos)) ? (lower :: value) : ((lower :: npos) + (upper :: value)));
  constexpr const static std :: size_t npos = (lower :: npos) + (upper :: npos);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <class Type, template <class, class> class Operator>
        inline constexpr crap :: lowerBoundType <Type, Operator> :: operator
        typename crap :: lowerBoundType <Type, Operator> :: value_type () const noexcept
{
 return crap :: lowerBoundType <Type, Operator> :: value;
}

template <class Type, template <class, class> class Operator, class Type1>
        inline constexpr crap :: lowerBoundType <Type, Operator, Type1> :: operator
        typename crap :: lowerBoundType <Type, Operator, Type1> :: value_type () const noexcept
{
 return crap :: lowerBoundType <Type, Operator, Type1> :: value;
}

template <class Type, template <class, class> class Operator, class ... Types>
        inline constexpr crap :: lowerBoundType <Type, Operator, Types...> :: operator
        typename crap :: lowerBoundType <Type, Operator, Types...> :: value_type () const noexcept
{
 return crap :: lowerBoundType <Type, Operator, Types...> :: value;
}
#endif
