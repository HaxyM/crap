#ifndef CRAP_ALGORITHM_PARTITIONPOINTTYPE
#define CRAP_ALGORITHM_PARTITIONPOINTTYPE

#include "../utility/bisecttype.h"

#include <cstddef>

namespace crap
{
 template <template <class> class, class...> struct partitionPointType;

 template <template <class> class Operator> struct partitionPointType<Operator>
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
 };

 template <template <class> class Operator, class Type> struct partitionPointType<Operator, Type>
 {
  constexpr const static std :: size_t value = ((Operator <Type> :: value) ? 1u : 0u);
  constexpr const static std :: size_t npos = 1u;
 };

 template <template <class> class Operator, class ... Types> struct partitionPointType
 {
  private:
  using types = bisectType<Types...>;
  template <class ... SubTypes> using This = partitionPointType<Operator, SubTypes...>;
  template <std :: size_t LowerValue, std :: size_t LowerNpos> struct upper;
  template <std :: size_t LowerNpos> struct upper<LowerNpos, LowerNpos>;
  using lower = typename types :: template lower<This>;
  public:
  constexpr const static std :: size_t value = upper <lower :: value, lower :: npos> :: value;
  constexpr const static std :: size_t npos = sizeof...(Types);
 };

 template <template <class> class Operator, class ... Types>
	 template <std :: size_t LowerValue, std :: size_t LowerNpos>
	struct partitionPointType <Operator, Types...> :: upper
 {
  constexpr const static std :: size_t value = LowerValue;
 };

 template <template <class> class Operator, class ... Types>
	 template <std :: size_t LowerNpos>
	struct partitionPointType <Operator, Types...> :: template upper<LowerNpos, LowerNpos>
 {
  private:
  using types = bisectType<Types...>;
  template <class ... SubTypes> using This = partitionPointType<Operator, SubTypes...>;
  public:
  constexpr const static std :: size_t value = LowerNpos + (types :: template upper <This> :: value);
 };
}
#endif
