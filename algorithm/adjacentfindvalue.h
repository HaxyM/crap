#ifndef CRAP_ALGORITHM_ADJACENTFINDVALUE
#define CRAP_ALGORITHM_ADJACENTFINDVALUE

#include "../utility/valuelist.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct adjacentFindValue;

 template <class Type, template <Type, Type> class Operator> struct adjacentFindValue<Type, Operator>
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
 };

 template <class Type, template <Type, Type> class Operator, Type Value> struct adjacentFindValue<Type, Operator, Value>
 {
  constexpr const static std :: size_t value = 1u;
  constexpr const static std :: size_t npos = 1u;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> struct adjacentFindValue
 {
  private:
  using values = valueList<Type, Values...>;
  constexpr const static std :: size_t half = values :: size / 2u;
  template <Type ... SubValues> using This = adjacentFindValue<Type, Operator, SubValues...>;
  using lower = typename values :: template till<half, This>;
  using upper = typename values :: template since<half,  This>;
  constexpr const static Type lowerLast = values :: template At <half - 1u> :: value;
  constexpr const static Type upperFirst = values :: template At <half> :: value;
  constexpr const static bool foundInLower = ((lower :: value) != (lower :: npos));
  constexpr const static bool foundOnEdge = Operator <lowerLast, upperFirst> :: value;
  public:
  constexpr const static std :: size_t value = (foundInLower ? (lower :: value) : (foundOnEdge ? (half - 1u) : ((lower :: npos) + (upper :: value))));
  constexpr const static std :: size_t npos = (lower :: npos) + (upper :: npos);
 };
}
#endif

