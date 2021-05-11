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
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <class, class> class Operator, class Type1> struct upperBoundType<Type, Operator, Type1>
 {
  constexpr const static std :: size_t value = (Operator <Type, Type1> :: value ? 0u : 1u);
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
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
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <class Type, template <class, class> class Operator>
        inline constexpr crap :: upperBoundType <Type, Operator> :: operator
        typename crap :: upperBoundType <Type, Operator> :: value_type () const noexcept
{
 return crap :: upperBoundType <Type, Operator> :: value;
}

template <class Type, template <class, class> class Operator, class Type1>
        inline constexpr crap :: upperBoundType <Type, Operator, Type1> :: operator
        typename crap :: upperBoundType <Type, Operator, Type1> :: value_type () const noexcept
{
 return crap :: upperBoundType <Type, Operator, Type1> :: value;
}

template <class Type, template <class, class> class Operator, class ... Types>
        inline constexpr crap :: upperBoundType <Type, Operator, Types...> :: operator
        typename crap :: upperBoundType <Type, Operator, Types...> :: value_type () const noexcept
{
 return crap :: upperBoundType <Type, Operator, Types...> :: value;
}
#endif
