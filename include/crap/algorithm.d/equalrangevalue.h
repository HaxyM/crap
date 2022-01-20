#ifndef CRAP_ALGORITHM_EQUALRANGEVALUE
#define CRAP_ALGORITHM_EQUALRANGEVALUE

#include "copyvalue.h"
#include "../utility.d/valuelist.h"
#include "../utility.d/valuemultiplexer.h"

namespace crap
{
 template <class Type, Type, template <Type, Type> class, Type...> struct equalRangeValue;

 template <class Type, Type Value, template <Type, Type> class Operator> struct equalRangeValue<Type, Value, Operator>
 {
  constexpr const static std :: size_t begin = 0u;
  constexpr const static std :: size_t end = 0u;
  constexpr const static std :: size_t npos = 0u;
 };

 template <class Type, Type Value, template <Type, Type> class Operator, Type Value1> struct equalRangeValue<Type, Value, Operator, Value1>
 {
  constexpr const static std :: size_t begin = (Operator <Value1, Value> :: value ? 1u : 0u);
  constexpr const static std :: size_t end = (Operator <Value, Value1> :: value ? 0u : 1u);
  constexpr const static std :: size_t npos = 1u;
 };

 template <class Type, Type Value, template <Type, Type> class Operator, Type ... Values> struct equalRangeValue
 {
  private:
  using values = valueList<Type, Values...>;
  constexpr const static std :: size_t half = (values :: size) / 2u;
  template <template <Type...> class Container> using lowerSource = typename values :: template till<half, Container>;
  template <template <Type...> class Container> using upperSource = typename values :: template since<half, Container>;
  template <template <Type...> class Container> using emptySource = typename copyValue <Type> :: template type<Container>;
  template <Type ... SubValues> using This = equalRangeValue<Type, Value, Operator, SubValues...>;
  constexpr const static Type midVal = values :: template At <half> :: value;
  constexpr const static bool notInLower = Operator <midVal, Value> :: value;
  constexpr const static bool notInUpper = Operator <Value, midVal> :: value;
  using lower = typename valueMultiplexer <Type, notInLower, This, emptySource, lowerSource> :: type;
  using upper = typename valueMultiplexer <Type, notInUpper, This, emptySource, upperSource> :: type;
  public:
  constexpr const static std :: size_t begin = (notInLower ? (half + (upper :: begin)) : (lower :: begin));
  constexpr const static std :: size_t end = (notInUpper ? (lower :: end) : (half + (upper :: end)));
  constexpr const static std :: size_t npos = values :: size;
 };
}
#endif

