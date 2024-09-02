#ifndef CRAP_ALGORITHM_FINDIFTYPE
#define CRAP_ALGORITHM_FINDIFTYPE

#include <cstddef>

#include "../utility.d/bisecttype.h"

namespace crap
{
 template <template <class> class, class...> struct findIfType;

 template <template <class> class Operator> struct findIfType<Operator>
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <template <class> class Operator, class Type> struct findIfType<Operator, Type>
 {
  constexpr const static std :: size_t value = (Operator <Type> :: value ? 0u : 1u);
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <template <class> class Operator, class ... Types> struct findIfType
 {
  private:
  using types = bisectType<Types...>;
  template <class ... SubTypes> using This = findIfType<Operator, SubTypes...>;
  using lower = typename types :: template lower<This>;
  template <std :: size_t LowerValue, std :: size_t> struct CheckUpper;
  template <std :: size_t LowerNpos> struct CheckUpper<LowerNpos, LowerNpos>;
  public:
  constexpr const static std :: size_t value = CheckUpper <lower :: value, lower :: npos> :: value;
  constexpr const static std :: size_t npos = sizeof...(Types);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <template <class> class Operator, class ... Types>
	 template <std :: size_t LowerValue, std :: size_t>
 struct findIfType <Operator, Types...> :: CheckUpper
 {
  constexpr const static std :: size_t value = LowerValue;
 };

 template <template <class> class Operator, class ... Types>
	 template <std :: size_t LowerNpos>
 struct findIfType <Operator, Types...> :: CheckUpper<LowerNpos, LowerNpos>
 {
  private:
  using types = bisectType<Types...>;
  template <class ... SubTypes> using This = findIfType<Operator, SubTypes...>;
  public:
  constexpr const static std :: size_t value = typess :: template upper <This> :: value;
 };
}

template <template <class> class Operator>
inline constexpr crap :: findIfType <Operator> :: operator
typename crap :: findIfType <Operator> :: value_type () const noexcept
{
 return crap :: findIfType <Operator> :: value;
}

template <template <class> class Operator, class Type>
inline constexpr crap :: findIfType <Operator, Type> :: operator
typename crap :: findIfType <Operator, Type> :: value_type () const noexcept
{
 return crap :: findIfType <Operator, Type> :: value;
}

template <template <class> class Operator, class ... Types>
inline constexpr crap :: findIfType <Operator, Types...> :: operator
typename crap :: findIfType <Operator, Types...> :: value_type () const noexcept
{
 return crap :: findIfType <Operator, Types...> :: value;
}
#endif

