#include <cstdint>
#include <type_traits>

#include "dividestype.h"
#include "identity.h"
#include "minustype.h"
#include "multipliestype.h"
#include "plustype.h"
#include "sqrt2.h"
#include "sqrttype.h"
#include "valueratio.h"
#include "zero.h"
#include "../numbers.d/pi.h"
#include "../functional.d/equaltovalue.h"

#ifndef CRAP_RATIO_PI
#define CRAP_RATIO_PI

namespace crap
{
#ifdef UINT8_C
 template <char Sign, std :: uint8_t Numerator, std :: uint8_t Denominator>
	 struct pi<valueRatio<std :: uint8_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint8_t, '+', UINT8_C(85), UINT8_C(27)>;
 };
#endif

#ifdef UINT16_C
 template <char Sign, std :: uint16_t Numerator, std :: uint16_t Denominator>
	 struct pi<valueRatio<std :: uint16_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint16_t, '+', UINT16_C(23513), UINT16_C(7487)>;
 };
#endif

#ifdef UINT32_C
 template <char Sign, std :: uint32_t Numerator, std :: uint32_t Denominator>
	 struct pi<valueRatio<std :: uint32_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint32_t, '+', UINT32_C(3082798721), UINT32_C(981285313)>;
 };
#endif

#ifdef UINT64_C
 template <char Sign, std :: uint64_t Numerator, std :: uint64_t Denominator>
	 struct pi<valueRatio<std :: uint64_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint64_t, '+', UINT64_C(18446744073709551615), UINT64_C(5871781006564002461)>;
 };
#endif

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct pi<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <passed> :: type;
  using const4 = typename plusType <const1, const1, const1, const1> :: type;
  using initialA = typename identity <const1> :: type;
  using initialB = typename dividesType <const1, typename sqrt2 <const1> :: type> :: type;
  using initialT = typename dividesType <const1, const4> :: type;
  using initialP = typename identity <const1> :: type;
  using numSum = typename plusType <initialA, initialB> :: type;
  using num = typename multipliesType <numSum, numSum> :: type;
  using initialResult = typename dividesType <num, const4, initialT> :: type;
  template <class A, class B, class T, class P, class prevResult, bool isFinal> struct step;
  template <class A, class B, class T, class P, class prevResult> struct step<A, B, T, P, prevResult, true>;
  public:
  using type = typename step <initialA, initialB, initialT, initialP, initialResult, false> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class A, class B, class T, class P, class prevResult, bool isFinal>
	 struct pi<valueRatio<Type, Sign, Numerator, Denominator> > :: step
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <passed> :: type;
  using const2 = typename plusType <const1, const1> :: type;
  using const4 = typename plusType <const1, const1, const1, const1> :: type;
  using nextA = typename dividesType <typename plusType <A, B> :: type, const2> :: type;
  using nextB = typename sqrtType <typename multipliesType <A, B> :: type> :: type;
  using aDiff = typename minusType <A, nextA> :: type;
  using nextT = typename minusType <T, typename multipliesType <P, aDiff, aDiff> :: type> :: type;
  using nextP = typename plusType <P, P> :: type;
  using numSum = typename plusType <nextA, nextB> :: type;
  using num = typename multipliesType <numSum, numSum> :: type;
  using nextResult = typename dividesType <num, const4, nextT> :: type;
  using cond = typename minusType <prevResult, nextResult> :: type;
  constexpr const static bool nextFinal = //FIXME: Add check if is zero.
	  equalToValue <decltype(cond :: num), cond :: num, zero <decltype(cond :: num)> :: value> :: value;
  public:
  using type = typename step <nextA, nextB, nextT, nextP, nextResult, nextFinal> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class A, class B, class T, class P, class prevResult>
 struct pi<valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 step<A, B, T, P, prevResult, true>
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <passed> :: type;
  using const4 = typename plusType <const1, const1, const1, const1> :: type;
  using numSum = typename plusType <A, B> :: type;
  using num = typename multipliesType <numSum, numSum> :: type;
  public:
  using type = typename dividesType <num, const4, T> :: type;
 };
}
#endif

