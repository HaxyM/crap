#ifndef CRAP_NUMERIC_IOTAVALUE
#define CRAP_NUMERIC_IOTAVALUE

#include <limits>

namespace crap
{
 template <std :: size_t N, class Type, Type Since = static_cast<Type>(0)> struct iotaValue;
}

#include "../utility.d/concatenatefortype.h"
#include "../utility.d/valuelistfortype.h"

namespace crap
{
 template <class Type, Type Since> struct iotaValue<0u, Type, Since>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<>;
 };

 template <class Type, Type Since> struct iotaValue<1u, Type, Since>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<Since>;
 };

 template <std :: size_t N, class Type, Type Since> struct iotaValue
 {
  private:
  static_assert(N < (std :: numeric_limits <Type> :: max() - Since), "Overflow.");
  constexpr const static std :: size_t half = (N / 2u);
  using lower = typename iotaValue <half, Type, Since> :: template type<concatenateForType <Type> :: template values>;
  using upper = typename iotaValue <N - half, Type, Since + static_cast<Type>(half)> :: template type<lower :: template with>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = typename upper :: template type<Container>;
 };
}
#endif

