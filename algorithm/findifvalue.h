#ifndef CRAP_ALGORITHM_FINDIFVALUE
#define CRAP_ALGORITHM_FINDIFVALUE

#include "../utility/bisectvalue.h"
#include "../utility/valuemultiplexer.h"

namespace crap
{
 template <class Type, template <Type> class, Type...> struct findIfValue;

 template <class Type, template <Type> class Operator> struct findIfValue<Type, Operator>
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type> class Operator, Type Value> struct findIfValue<Type, Operator, Value>
 {
  constexpr const static std :: size_t value = (Operator <Value> :: value ? 0u : 1u);
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type> class Operator, Type ... Values> struct findIfValue
 {
  private:
  using values = bisectValue<Type, Values...>;
  template <Type ... SubValues> using This = findIfValue<Type, Operator, SubValues...>;
  template <template <Type...> class Container> using empty = Container<>;
  using lower = typename values :: template lower<This>;
  constexpr const static bool inLower = (lower :: value) != (lower :: npos);
  using upper = typename valueMultiplexer <Type, inLower, This, empty, values :: template upper> :: type;
  public:
  constexpr const static std :: size_t value = (inLower ? (lower :: value) : ((lower :: npos) + (upper :: value)));
  constexpr const static std :: size_t npos = sizeof...(Values);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <class Type, template <Type> class Operator>
inline constexpr crap :: findIfValue <Type, Operator> :: operator
typename crap :: findIfValue <Type, Operator> :: value_type () const noexcept
{
 return crap :: findIfValue <Type, Operator> :: value;
}

template <class Type, template <Type> class Operator, Type Value>
inline constexpr crap :: findIfValue <Type, Operator, Value> :: operator
typename crap :: findIfValue <Type, Operator, Value> :: value_type () const noexcept
{
 return crap :: findIfValue <Type, Operator, Value> :: value;
}

template <class Type, template <Type> class Operator, Type ... Values>
inline constexpr crap :: findIfValue <Type, Operator, Values...> :: operator
typename crap :: findIfValue <Type, Operator, Values...> :: value_type () const noexcept
{
 return crap :: findIfValue <Type, Operator, Values...> :: value;
}
#endif

