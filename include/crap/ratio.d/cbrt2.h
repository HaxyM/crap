#include <cstdint>
#include <type_traits>

#include "dividestype.h"
#include "identity.h"
#include "minustype.h"
#include "multipliestype.h"
#include "plustype.h"
#include "valueratio.h"
#include "zero.h"
#include "../numbers.d/cbrt2.h"
#include "../functional.d/equaltovalue.h"

#ifndef CRAP_RATIO_CBRT2
#define CRAP_RATIO_CBRT2

namespace crap
{
#ifdef UINT8_C
 template <char Sign, std :: uint8_t Numerator, std :: uint8_t Denominator>
	 struct cbrt2<valueRatio<std :: uint8_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint8_t, '+', UINT8_C(85), UINT8_C(67)>;
 };
#endif

#ifdef UINT16_C
 template <char Sign, std :: uint16_t Numerator, std :: uint16_t Denominator>
	 struct cbrt2<valueRatio<std :: uint16_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint16_t, '+', UINT16_C(65534), UINT16_C(52013)>;
 };
#endif

#ifdef UINT32_C
 template <char Sign, std :: uint32_t Numerator, std :: uint32_t Denominator>
	 struct cbrt2<valueRatio<std :: uint32_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint32_t, '+', UINT32_C(858993459), UINT32_C(681783560)>;
 };
#endif

#ifdef UINT64_C
 template <char Sign, std :: uint64_t Numerator, std :: uint64_t Denominator>
	 struct cbrt2<valueRatio<std :: uint64_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint64_t, '+', UINT64_C(18446744073709551615), UINT64_C(14641190473997345813)>;
 };
#endif

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct cbrt2<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <passed> :: type;
  using initialA = typename dividesType <const1, typename plusType <const1, const1> :: type> :: type;
  using initialC = typename minusType <typename multipliesType <initialA, initialA> :: type, const1> :: type;
  template <class A, class C, bool isFinal> struct step;
  template <class A, class C> struct step<A, C, true>;
  public:
  using type = typename step <initialA, initialC, false> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class A, class C, bool isFinal>
	 struct cbrt2<valueRatio<Type, Sign, Numerator, Denominator> > :: step
 {
  private:
  using const1 = typename identity <A> :: type;
  using const3 = typename plusType <const1, const1, const1> :: type;
  using thirdC = typename dividesType <C, const3> :: type;
  using C1 = typename plusType <const1, C> :: type;
  using C2 = typename minusType <const1, thirdC> :: type;
  using C3 = typename multipliesType <C1, C2, C2, C2> :: type;
  using nextC = typename minusType <C3, const1> :: type;
  using nextA = typename multipliesType <A, C2> :: type;
  using cond = typename minusType <A, nextA> :: type;
  constexpr const static bool nextFinal = //FIXME: Add check if is zero.
	  equalToValue <decltype(cond :: num), cond :: num, zero <decltype(cond :: num)> :: value> :: value;
  public:
  using type = typename step <nextA, nextC, nextFinal> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class A, class C>
	 struct cbrt2<valueRatio<Type, Sign, Numerator, Denominator> > :: template step<A, C, true>
 {
  using type = valueRatio<Type, A :: sign, A :: den, A :: num>;
 };
}
#endif

