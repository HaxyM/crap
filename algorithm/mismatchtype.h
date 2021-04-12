#ifndef CRAP_ALGORITHM_MISMATCHTYPE
#define CRAP_ALGORITHM_MISMATCHTYPE

#include "../utility/typelist.h"

#include <cstddef>

namespace crap
{
 template <template <class, class> class, class...> struct mismatchType;

 template <template <class, class> class Operator> struct mismatchType<Operator>
 {
  template <class ... Types2> struct with;
 };

 template <template <class, class> class Operator, class Only1> struct mismatchType<Operator, Only1>
 {
  template <class...> struct with;
  template <class Only2> struct with<Only2>;
  template <class First2, class ... Rest2> struct with<First2, Rest2...>;
 };

 template <template <class, class> class Operator, class First1, class ... Rest1>
	 struct mismatchType<Operator, First1, Rest1...>
 {
  template <class...> struct with;
  template <class Only2> struct with<Only2>;
  template <class First2, class ... Rest2> struct with<First2, Rest2...>;
 };

 template <template <class, class> class Operator> template <class ... Types2>
	 struct mismatchType <Operator> :: with
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = sizeof...(Types2);
 };

 template <template <class, class> class Operator, class Only1> template <class...>
	 struct mismatchType <Operator, Only1> :: with
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 1u;
 };

 template <template <class, class> class Operator, class Only1> template <class Only2>
	 struct mismatchType <Operator, Only1> :: template with<Only2>
 {
  constexpr const static std :: size_t value = ((Operator <Only1, Only2> :: value) ? 1u : 0u);
  constexpr const static std :: size_t npos = 1u;
 };

 template <template <class, class> class Operator, class Only1> template <class First2, class ... Rest2>
	 struct mismatchType <Operator, Only1> :: template with<First2, Rest2...>
 {
  constexpr const static std :: size_t value = ((Operator <Only1, First2> :: value) ? 1u : 0u);
  constexpr const static std :: size_t npos = sizeof...(Rest2) + 1u;
 };

 template <template <class, class> class Operator, class First1, class ... Rest1> template <class...>
	 struct mismatchType <Operator, First1, Rest1...> :: with
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = sizeof...(Rest1) + 1u;
 };

 template <template <class, class> class Operator, class First1, class ... Rest1> template <class Only2>
	 struct mismatchType <Operator, First1, Rest1...> :: template with<Only2>
 {
  constexpr const static std :: size_t value = ((Operator <First1, Only2> :: value) ? 1u : 0u);
  constexpr const static std :: size_t npos = sizeof...(Rest1) + 1u;
 };

 template <template <class, class> class Operator, class First1, class ... Rest1>
	 template <class First2, class ... Rest2>
	 struct mismatchType <Operator, First1, Rest1...> :: template with<First2, Rest2...>
 {
  private:
  using types1 = typeList<First1, Rest1...>;
  using types2 = typeList<First2, Rest2...>;
  constexpr const static std :: size_t half =
	  ((types1 :: size > types2 :: size) ? (types1 :: size) : (types2 :: size)) / 2u;
  template <class ... SubTypes> using This = mismatchType<Operator, SubTypes...>;
  using lower = typename types2 :: template till<half, types1 :: template till <half, This> :: template with>;
  template <std :: size_t LowerValue, std :: size_t LowerNpos> struct upper;
  template <std :: size_t LowerNpos> struct upper<LowerNpos, LowerNpos>;
  public:
  constexpr const static std :: size_t value = upper <lower :: value, lower :: npos> :: value;
  constexpr const static std :: size_t npos =
	  ((types1 :: size > types2 :: size) ? (types1 :: size) : (types2 :: size));
 };

 template <template <class, class> class Operator, class First1, class ... Rest1>
	 template <class First2, class ... Rest2>
	 template <std :: size_t LowerValue, std :: size_t LowerNpos>
	 struct mismatchType <Operator, First1, Rest1...> :: template with <First2, Rest2...> :: upper
 {
  constexpr const static std :: size_t value = LowerValue;
 };

 template <template <class, class> class Operator, class First1, class ... Rest1>
	 template <class First2, class ... Rest2>
	 template <std :: size_t LowerNpos>
 struct mismatchType <Operator, First1, Rest1...> :: template
	 with <First2, Rest2...> :: template upper<LowerNpos, LowerNpos>
 {
  private:
  using types1 = typeList<First1, Rest1...>;
  using types2 = typeList<First2, Rest2...>;
  template <class ... SubTypes> using This = mismatchType<Operator, SubTypes...>;
  using result = typename types2 :: template
	  since<LowerNpos, types1 :: template since <LowerNpos, This> :: template with>;
  public:
  constexpr const static std :: size_t value = LowerNpos + (result :: value);
 }; 
}
#endif

