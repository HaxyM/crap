#ifndef CRAP_ALGORITHM_FINDIFVALUE
#define CRAP_ALGORITHM_FINDIFVALUE

#include "../utility/valuelist.h"

namespace crap
{
 template <class Type, template <Type> class, Type...> struct findIfValue;

 template <class Type, template <Type> class Operator> struct findIfValue<Type, Operator>
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
 };

 template <class Type, template <Type> class Operator, Type Value> struct findIfValue<Type, Operator, Value>
 {
  constexpr const static std :: size_t value = (Operator <Value> :: value ? 0u : 1u);
  constexpr const static std :: size_t npos = 1u;
 };

 template <class Type, template <Type> class Operator, Type ... Values> struct findIfValue
 {
  private:
  using values = valueList<Type, Values...>;
  constexpr const static std :: size_t half = values :: size / 2u;
  template <Type ... SubValues> using This = findIfValue<Type, Operator, SubValues...>;
  using lower = typename values :: template till<half, This>;
  using upper = typename values :: template since<half, This>;
  public:
  constexpr const static std :: size_t value = (((lower :: value) != (lower :: npos)) ? (lower :: value) : ((lower :: npos) + (upper :: value)));
  constexpr const static std :: size_t npos = lower :: npos + upper :: npos;
 };
}
#endif

