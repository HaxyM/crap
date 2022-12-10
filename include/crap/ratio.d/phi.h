#include <cstdint>
#include <type_traits>

#include "dividestype.h"
#include "identity.h"
#include "minustype.h"
#include "multipliestype.h"
#include "plustype.h"
#include "valueratio.h"
#include "zero.h"
#include "../numbers.d/phi.h"
#include "../functional.d/equaltovalue.h"

#ifndef CRAP_RATIO_PHI
#define CRAP_RATIO_PHI

namespace crap
{
#ifdef UINT8_C
 template <char Sign, typename std :: make_unsigned <std :: int8_t> :: type Numerator, typename std :: make_unsigned <std :: int8_t> :: type Denominator>
	 struct phi<valueRatio<std :: int8_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: int8_t, '+', UINT8_C(123), UINT8_C(76)>;
 };

 template <char Sign, typename std :: make_unsigned <std :: uint8_t> :: type Numerator, typename std :: make_unsigned <std :: uint8_t> :: type Denominator>
	 struct phi<valueRatio<std :: uint8_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint8_t, '+', UINT8_C(123), UINT8_C(76)>;
 };
#endif

#ifdef UINT16_C
 template <char Sign, typename std :: make_unsigned <std :: int16_t> :: type Numerator, typename std :: make_unsigned <std :: int16_t> :: type Denominator>
	 struct phi<valueRatio<std :: int16_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: int16_t, '+', UINT16_C(5579), UINT16_C(3448)>;
 };

 template <char Sign, typename std :: make_unsigned <std :: uint16_t> :: type Numerator, typename std :: make_unsigned <std :: uint16_t> :: type Denominator>
	 struct phi<valueRatio<std :: uint16_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint16_t, '+', UINT16_C(5579), UINT16_C(3448)>;
 };
#endif

#ifdef UINT32_C
 template <char Sign, typename std :: make_unsigned <std :: int32_t> :: type Numerator, typename std :: make_unsigned <std :: int32_t> :: type Denominator>
	 struct phi<valueRatio<std :: int32_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: int32_t, '+', UINT32_C(4143826441), UINT32_C(2561025584)>;
 };

 template <char Sign, typename std :: make_unsigned <std :: uint32_t> :: type Numerator, typename std :: make_unsigned <std :: uint32_t> :: type Denominator>
	 struct phi<valueRatio<std :: uint32_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint32_t, '+', UINT32_C(4143826441), UINT32_C(2561025584)>;
 };
#endif

#ifdef UINT64_C
 template <char Sign, typename std :: make_unsigned <std :: int64_t> :: type Numerator, typename std :: make_unsigned <std :: int64_t> :: type Denominator>
	 struct phi<valueRatio<std :: int64_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: int64_t, '+', UINT64_C(3559517175490765511), UINT64_C(2199902597992317258)>;
 };

 template <char Sign, typename std :: make_unsigned <std :: uint64_t> :: type Numerator, typename std :: make_unsigned <std :: uint64_t> :: type Denominator>
	 struct phi<valueRatio<std :: uint64_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint64_t, '+', UINT64_C(3559517175490765511), UINT64_C(2199902597992317258)>;
 };
#endif

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct phi<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <passed> :: type;
  using const4 = typename plusType <const1, const1, const1, const1> :: type;
  using initialC = typename dividesType <const1, const4> :: type;
  using initialA =
	  typename plusType <const1, initialC> :: type;
  template <class A, class C, bool isFinal> struct step;
  template <class A, class C> struct step<A, C, true>;
  public:
  using type = typename step <initialA, initialC, false> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 template <class A, class C, bool isFinal>
	 struct phi<valueRatio<Type, Sign, Numerator, Denominator> > :: step
 {
  private:
  using const1 = typename identity <A> :: type;
  using const2 = typename plusType <typename identity <A> :: type, typename identity <A> :: type> :: type;
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

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 template <class A, class C>
	 struct phi<valueRatio<Type, Sign, Numerator, Denominator> > :: template step<A, C, true>
 {
  private:
  using const1 = typename identity <A> :: type;
  using const2 = typename plusType <const1, const1> :: type;
  using half = typename dividesType <const1, const2> :: type;
  public:
  using type = typename plusType <half, A> :: type;
 };
}
#endif

