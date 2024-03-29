#ifndef CRAP_ALGORITHM_FINDIFTYPE
#define CRAP_ALGORITHM_FINDIFTYPE

#include "../utility.d/bisecttype.h"
#include "../utility.d/typemultiplexer.h"

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
  using values = bisectType<Types...>;
  template <class ... SubTypes> using This = findIfType<Operator, SubTypes...>;
  template <template <class...> class Container> using empty = Container<>;
  using lower = typename values :: template lower<This>;
  constexpr const static bool inLower = (lower :: value) != (lower :: npos);
  using upper = typename typeMultiplexer <inLower, This, empty, values :: template upper> :: type;
  public:
  constexpr const static std :: size_t value = (inLower ? (lower :: value) : ((lower :: npos) + (upper :: value)));
  constexpr const static std :: size_t npos = sizeof...(Types);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
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

