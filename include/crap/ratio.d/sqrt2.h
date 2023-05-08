#include <cstdint>
#include <type_traits>

#include "dividestype.h"
#include "identity.h"
#include "minustype.h"
#include "multipliestype.h"
#include "plustype.h"
#include "valueratio.h"
#include "zero.h"
#include "../numbers.d/sqrt2.h"
#include "../functional.d/equaltovalue.h"

#ifndef CRAP_RATIO_SQRT2
#define CRAP_RATIO_SQRT2

namespace crap
{
#ifdef UINT8_C
 template <char Sign, std :: uint8_t Numerator, std :: uint8_t Denominator>
	 struct sqrt2<valueRatio<std :: uint8_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint8_t, '+', UINT8_C(255), UINT8_C(181)>;
 };
#endif

#ifdef UINT16_C
 template <char Sign, std :: uint16_t Numerator, std :: uint16_t Denominator>
	 struct sqrt2<valueRatio<std :: uint16_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint16_t, '+', UINT16_C(65534), UINT16_C(46339)>;
 };
#endif

#ifdef UINT32_C
 template <char Sign, std :: uint32_t Numerator, std :: uint32_t Denominator>
	 struct sqrt2<valueRatio<std :: uint32_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint32_t, '+', UINT32_C(4294967295), UINT32_C(3037000498)>;
 };
#endif

#ifdef UINT64_C
 template <char Sign, std :: uint64_t Numerator, std :: uint64_t Denominator>
	 struct sqrt2<valueRatio<std :: uint64_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint64_t, '+', UINT64_C(18446744073709551615), UINT64_C(13043817825332782214)>;
 };
#endif

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct sqrt2<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using initialA =
	  typename plusType <typename identity <passed> :: type, typename identity <passed> :: type> :: type;
  using initialC = typename identity <passed> :: type;
  template <class A, class C, bool isFinal> struct step;
  template <class A, class C> struct step<A, C, true>;
  public:
  using type = typename step <initialA, initialC, false> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class A, class C, bool isFinal>
	 struct sqrt2<valueRatio<Type, Sign, Numerator, Denominator> > :: step
 {
  private:
  using const2 = typename plusType <typename identity <A> :: type, typename identity <A> :: type> :: type;
  using const3 = typename plusType <const2, typename identity <A> :: type> :: type;
  using const4 = typename plusType <const2, const2> :: type;
  using AC = typename multipliesType <A, C> :: type;
  using halfAC = typename dividesType <AC, const2> :: type;
  using nextA = typename minusType <A, halfAC> :: type;
  using Cless3 = typename minusType <C, const3> :: type;
  using Cs = typename multipliesType <C, C, Cless3> :: type;
  using nextC = typename dividesType <Cs, const4> :: type;
  constexpr const static bool nextFinal = //FIXME: Add check if is zero.
	  equalToValue <decltype(nextC :: num), nextC :: num, zero <decltype(nextC :: num)> :: value> :: value;
  public:
  using type = typename step <nextA, nextC, nextFinal> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class A, class C>
	 struct sqrt2<valueRatio<Type, Sign, Numerator, Denominator> > :: template step<A, C, true>
 {
  using type = A;
 };
}
#endif

