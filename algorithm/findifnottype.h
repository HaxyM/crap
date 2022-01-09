#ifndef CRAP_ALGORITHM_FINDIFNOTTYPE
#define CRAP_ALGORITHM_FINDIFNOTTYPE

#include <cstddef>

#include "../utility/bisecttype.h"

namespace crap
{
 template <template <class> class, class...> struct findIfNotType;

 template <template <class> class Operator> struct findIfNotType<Operator>
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <template <class> class Operator, class Type> struct findIfNotType<Operator, Type>
 {
  constexpr const static std :: size_t value = (Operator <Type> :: value ? 1u : 0u);
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <template <class> class Operator, class ... Types> struct findIfNotType
 {
  private:
  using types = bisectType<Types...>;
  template <class ... SubTypes> using This = findIfNotType<Operator, SubTypes...>;
  using lower = typename types :: template lower<This>;
  template <std :: size_t LowerIndex, std :: size_t, class...> struct upperCheck;
  template <std :: size_t LowerNpos, class ... SubTypes> struct upperCheck<LowerNpos, LowerNpos, SubTypes...>;
  template <class ... SubTypes> using upperCheckThis = upperCheck<lower :: value, lower :: npos, SubTypes...>;
  using upper = typename types :: template upper<upperCheckThis>;
  public:
  constexpr const static std :: size_t value = upper :: value;
  constexpr const static std :: size_t npos = sizeof...(Types);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <template <class> class Operator, class ... Types>
	 template <std :: size_t LowerIndex, std :: size_t, class...>
 struct findIfNotType <Operator, Types...> :: upperCheck
 {
  constexpr const static std :: size_t value = LowerIndex;
 };

 template <template <class> class Operator, class ... Types>
	 template <std :: size_t LowerNpos, class ... SubTypes>
 struct findIfNotType <Operator, Types...> :: template upperCheck<LowerNpos, LowerNpos, SubTypes...>
 {
  constexpr const static std :: size_t value = LowerNpos + (findIfNotType <Operator, SubTypes...> :: value);
 };
}

template <template <class> class Operator>
inline constexpr crap :: findIfNotType <Operator> :: operator
typename crap :: findIfNotType <Operator> :: value_type () const noexcept
{
 return crap :: findIfNotType <Operator> :: value;
}

template <template <class> class Operator, class Type>
inline constexpr crap :: findIfNotType <Operator, Type> :: operator
typename crap :: findIfNotType <Operator, Type> :: value_type () const noexcept
{
 return crap :: findIfNotType <Operator, Type> :: value;
}

template <template <class> class Operator, class ... Types>
inline constexpr crap :: findIfNotType <Operator, Types...> :: operator
typename crap :: findIfNotType <Operator, Types...> :: value_type () const noexcept
{
 return crap :: findIfNotType <Operator, Types...> :: value;
}
#endif

