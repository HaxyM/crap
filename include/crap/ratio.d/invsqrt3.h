#include <cstdint>
#include <type_traits>

#include "dividestype.h"
#include "identity.h"
#include "minustype.h"
#include "multipliestype.h"
#include "plustype.h"
#include "valueratio.h"
#include "zero.h"
#include "../numbers.d/invsqrt3.h"
#include "../functional.d/equaltovalue.h"

#ifndef CRAP_RATIO_INVSQRT3
#define CRAP_RATIO_INVSQRT3

namespace crap
{
#ifdef UINT8_C
 template <char Sign, std :: uint8_t Numerator, std :: uint8_t Denominator>
	 struct invSqrt3<valueRatio<std :: uint8_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint8_t, '+', UINT8_C(29), UINT8_C(51)>;
 };
#endif

#ifdef UINT16_C
 template <char Sign, std :: uint16_t Numerator, std :: uint16_t Denominator>
	 struct invSqrt3<valueRatio<std :: uint16_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint16_t, '+', UINT16_C(7567), UINT16_C(13107)>;
 };
#endif

#ifdef UINT32_C
 template <char Sign, std :: uint32_t Numerator, std :: uint32_t Denominator>
	 struct invSqrt3<valueRatio<std :: uint32_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint32_t, '+', UINT32_C(826566841), UINT32_C(1431655765)>;
 };
#endif

#ifdef UINT64_C
 template <char Sign, std :: uint64_t Numerator, std :: uint64_t Denominator>
	 struct invSqrt3<valueRatio<std :: uint64_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint64_t, '+', UINT64_C(3550077552209447801), UINT64_C(6148914691236517205)>;
 };
#endif

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct invSqrt3<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <passed> :: type;
  using const3 = typename plusType <const1, const1, const1> :: type;
  using initialA = typename dividesType <const1, const3> :: type;
  using initialC = typename minusType <initialA, const1> :: type;
  template <class A, class C, bool isFinal> struct step;
  template <class A, class C> struct step<A, C, true>;
  public:
  using type = typename step <initialA, initialC, false> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class A, class C, bool isFinal>
	 struct invSqrt3<valueRatio<Type, Sign, Numerator, Denominator> > :: step
 {
  private:
  using const1 = typename identity <A> :: type;
  using const2 = typename plusType <const1, const1> :: type;
  using halfC = typename dividesType <C, const2> :: type;
  using C1 = typename plusType <const1, C> :: type;
  using C2 = typename minusType <const1, halfC> :: type;
  using C3 = typename multipliesType <C1, C2, C2> :: type;
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
	 struct invSqrt3<valueRatio<Type, Sign, Numerator, Denominator> > :: template step<A, C, true>
 {
  using type = A;
 };
}
#endif

