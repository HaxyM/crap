#ifndef CRAP_ALGORITHM_ISSORTEDUNTILTYPE
#define CRAP_ALGORITHM_ISSORTEDUNTILTYPE

#include "../utility.d/bisecttype.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <template <class, class> class, class...> struct isSortedUntilType;

 template <template <class, class> class Operator> struct isSortedUntilType<Operator>
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class Type> struct isSortedUntilType<Operator, Type>
 {
  private:
  template <template <class, class> class, class...> friend struct isSortedUntilType;
  using first = Type;
  using last = Type;
  public:
  constexpr const static std :: size_t value = 1u;
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
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
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
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
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };
}

template <template <class, class> class Operator>
        inline constexpr crap :: isSortedUntilType <Operator> :: operator
        typename crap :: isSortedUntilType <Operator> :: value_type () const noexcept
{
 return crap :: isSortedUntilType <Operator> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator>
        inline constexpr typename crap :: isSortedUntilType <Operator> :: value_type
        crap :: isSortedUntilType <Operator> :: operator () () const noexcept
{
 return crap :: isSortedUntilType <Operator> :: value;
}
#endif

template <template <class, class> class Operator, class Type>
        inline constexpr crap :: isSortedUntilType <Operator, Type> :: operator
        typename crap :: isSortedUntilType <Operator, Type> :: value_type () const noexcept
{
 return crap :: isSortedUntilType <Operator, Type> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class Type>
        inline constexpr typename crap :: isSortedUntilType <Operator, Type> :: value_type
        crap :: isSortedUntilType <Operator, Type> :: operator () () const noexcept
{
 return crap :: isSortedUntilType <Operator, Type> :: value;
}
#endif

template <template <class, class> class Operator, class Type1, class Type2>
        inline constexpr crap :: isSortedUntilType <Operator, Type1, Type2> :: operator
        typename crap :: isSortedUntilType <Operator, Type1, Type2> :: value_type () const noexcept
{
 return crap :: isSortedUntilType <Operator, Type1, Type2> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class Type1, class Type2>
        inline constexpr typename crap :: isSortedUntilType <Operator, Type1, Type2> :: value_type
        crap :: isSortedUntilType <Operator, Type1, Type2> :: operator () () const noexcept
{
 return crap :: isSortedUntilType <Operator, Type1, Type2> :: value;
}
#endif

template <template <class, class> class Operator, class ... Types>
        inline constexpr crap :: isSortedUntilType <Operator, Types...> :: operator
        typename crap :: isSortedUntilType <Operator, Types...> :: value_type () const noexcept
{
 return crap :: isSortedUntilType <Operator, Types...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class ... Types>
        inline constexpr typename crap :: isSortedUntilType <Operator, Types...> :: value_type
        crap :: isSortedUntilType <Operator, Types...> :: operator () () const noexcept
{
 return crap :: isSortedUntilType <Operator, Types...> :: value;
}
#endif
#endif
