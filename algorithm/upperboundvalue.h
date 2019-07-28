#ifndef CRAP_ALGORITHM_UPPERBOUNDVALUE
#define CRAP_ALGORITHM_UPPERBOUNDVALUE

#include "../utility/valuelist.h"

namespace crap
{
 template <class Type, Type, template <Type, Type> class, Type...> struct upperBoundValue;

 template <class Type, Type Value, template <Type, Type> class Operator> struct upperBoundValue<Type, Value, Operator>
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
 };

 template <class Type, Type Value, template <Type, Type> class Operator, Type Value1> struct upperBoundValue<Type, Value, Operator, Value1>
 {
  constexpr const static std :: size_t value = (Operator <Value, Value1> :: value ? 0u : 1u);
  constexpr const static std :: size_t npos = 1u;
 };

 template <class Type, Type Value, template <Type, Type> class Operator, Type ... Values> struct upperBoundValue
 {
  private:
  using values = valueList<Type, Values...>;
  constexpr const static std :: size_t half = (values :: size) / 2u;
  template <Type ... SubValues> using This = upperBoundValue<Type, Value, Operator, SubValues...>;
  using lower = typename values :: template till<half, This>;
  using upper = typename values :: template since<half, This>;
  public:
  constexpr const static std :: size_t value = (((lower :: value) != (lower :: npos)) ? (lower :: value) : ((lower :: npos) + (upper :: value)));
  constexpr const static std :: size_t npos = (lower :: npos) + (upper :: npos);
 };
}
#endif

