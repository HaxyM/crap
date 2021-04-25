#ifndef CRAP_ALGORITHM_ADJACENTFINDTYPE
#define CRAP_ALGORITHM_ADJACENTFINDTYPE

#include "../utility/typelist.h"

#include <cstddef>

namespace crap
{
 template <template <class, class> class, class...> struct adjacentFindType;

 template <template <class, class> class Operator> struct adjacentFindType<Operator>
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
 };

 template <template <class, class> class Operator, class Type> struct adjacentFindType<Operator, Type>
 {
  constexpr const static std :: size_t value = 1u;
  constexpr const static std :: size_t npos = 1u;
 };

 template <template <class, class> class Operator, class Type1, class Type2>
	 struct adjacentFindType<Operator, Type1, Type2>
 {
  constexpr const static std :: size_t value = ((Operator <Type1, Type2> :: value) ? 0u : 2u);
  constexpr const static std :: size_t npos = 2u;
 };

 template <template <class, class> class Operator, class ... Types> struct adjacentFindType
 {
  private:
  using types = typeList<Types...>;
  constexpr const static std :: size_t half = types :: size / 2u;
  template <class ... SubTypes> using This = adjacentFindType<Operator, SubTypes...>;
  using lower = typename types :: template till<half, This>;
  template <std :: size_t LowerValue, std :: size_t LowerNpos> struct checkMiddle;
  template <std :: size_t LowerNpos> struct checkMiddle<LowerNpos, LowerNpos>;
  public:
  constexpr const static std :: size_t value = checkMiddle <lower :: value, lower :: npos> :: value;
  constexpr const static std :: size_t npos = sizeof...(Types);
 };

 template <template <class, class> class Operator, class ... Types>
	 template <std :: size_t LowerValue, std :: size_t LowerNpos>
	struct adjacentFindType <Operator, Types...> :: checkMiddle
 {
  constexpr const static std :: size_t value = LowerValue;
 };

 template <template <class, class> class Operator, class ... Types>
	 template <std :: size_t LowerNpos>
	struct adjacentFindType <Operator, Types...> :: template checkMiddle<LowerNpos, LowerNpos>
 {
  private:
  using types = typeList<Types...>;
  constexpr const static std :: size_t half = types :: size / 2u;
  using type1 = typename types :: template at<half - 1u>;
  using type2 = typename types :: template at<half>;
  template <bool, class...> struct checkUpper;
  template <class ... Empty> struct checkUpper<false, Empty...>;
  public:
  constexpr const static std :: size_t value = checkUpper <Operator <type1, type2> :: value> :: value;
 };

 template <template <class, class> class Operator, class ... Types>
	 template <std :: size_t LowerNpos>
	 template <bool, class...>
 struct adjacentFindType <Operator, Types...> :: template
	checkMiddle <LowerNpos, LowerNpos> :: checkUpper
 {
  constexpr const static std :: size_t value = LowerNpos - 1u;
 };

 template <template <class, class> class Operator, class ... Types>
	 template <std :: size_t LowerNpos>
	 template <class ... Empty>
 struct adjacentFindType <Operator, Types...> :: template
	checkMiddle <LowerNpos, LowerNpos> :: template
	checkUpper<false, Empty...>
 {
  private:
  using types = typeList<Types...>;
  constexpr const static std :: size_t half = types :: size / 2u;
  template <class ... SubTypes> using This = adjacentFindType<Operator, SubTypes...>;
  using upper = typename types :: template since<half, This>;
  public:
  constexpr const static std :: size_t value = LowerNpos + (upper :: value);
 };
}
#endif

