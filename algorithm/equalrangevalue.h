#ifndef CRAP_ALGORITHM_EQUALRANGEVALUE
#define CRAP_ALGORITHM_EQUALRANGEVALUE

#include "../utility/valuelist.h"

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
  template <Type ... SubValues> using This = equalRangeValue<Type, Value, Operator, SubValues...>;
  using lower = typename values :: template till<half, This>;
  using upper = typename values :: template since<half, This>;
  public:
  constexpr const static std :: size_t begin = (((lower :: begin) != (lower :: npos)) ? (lower :: begin) : ((lower :: npos) + (upper :: begin)));
  constexpr const static std :: size_t end = (((lower :: end) != (lower :: npos)) ? (lower :: end) : ((lower :: npos) + (upper :: end)));
  constexpr const static std :: size_t npos = (lower :: npos) + (upper :: npos);
 };
}
#endif

