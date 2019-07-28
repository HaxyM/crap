#ifndef CRAP_ALGORITHM_LOWERBOUNDVALUE
#define CRAP_ALGORITHM_LOWERBOUNDVALUE

#include "../utility/valuelist.h"

namespace crap
{
 template <class Type, Type, template <Type, Type> class, Type...> struct lowerBoundValue;

 template <class Type, Type Value, template <Type, Type> class Operator> struct lowerBoundValue<Type, Value, Operator>
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
 };

 template <class Type, Type Value, template <Type, Type> class Operator, Type Value1> struct lowerBoundValue<Type, Value, Operator, Value1>
 {
  constexpr const static std :: size_t value = (Operator <Value1, Value> :: value ? 1u : 0u);
  constexpr const static std :: size_t npos = 1u;
 };

 template <class Type, Type Value, template <Type, Type> class Operator, Type ... Values> struct lowerBoundValue
 {
  private:
  using values = valueList<Type, Values...>;
  constexpr const static std :: size_t half = (values :: size) / 2u;
  template <Type ... SubValues> using This = lowerBoundValue<Type, Value, Operator, SubValues...>;
  using lower = typename values :: template till<half, This>;
  using upper = typename values :: template since<half, This>;
  public:
  constexpr const static std :: size_t value = (((lower :: value) != (lower :: npos)) ? (lower :: value) : ((lower :: npos) + (upper :: value)));
  constexpr const static std :: size_t npos = (lower :: npos) + (upper :: npos);
 };
}
#endif

