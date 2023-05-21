#include <cstdint>
#include <type_traits>

#include "dividestype.h"
#include "identity.h"
#include "ln2.h"
#include "logtype.h"
#include "minustype.h"
#include "multipliestype.h"
#include "plustype.h"
#include "valueratio.h"
#include "zero.h"
#include "../bit.d/bitwidthvalue.h"
#include "../functional.d/equaltovalue.h"
#include "../numbers.d/egamma.h"
#include "../numeric.d/iotavalue.h"

#ifndef CRAP_RATIO_EGAMMA
#define CRAP_RATIO_EGAMMA

namespace crap
{
#ifdef UINT8_C
 template <char Sign, std :: uint8_t Numerator, std :: uint8_t Denominator>
	 struct egamma<valueRatio<std :: uint8_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint8_t, '+', UINT8_C(149), UINT8_C(254)>;
 };
#endif

#ifdef UINT16_C
 template <char Sign, std :: uint16_t Numerator, std :: uint16_t Denominator>
	 struct egamma<valueRatio<std :: uint16_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint16_t, '+', UINT16_C(37846), UINT16_C(65535)>;
 };
#endif

#ifdef UINT32_C
 template <char Sign, std :: uint32_t Numerator, std :: uint32_t Denominator>
	 struct egamma<valueRatio<std :: uint32_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint32_t, '+', UINT32_C(2479122442), UINT32_C(4294967295)>;
 };
#endif

#ifdef UINT64_C
 template <char Sign, std :: uint64_t Numerator, std :: uint64_t Denominator>
	 struct egamma<valueRatio<std :: uint64_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint64_t, '+', UINT64_C(10647749645774670032), UINT64_C(18446744073709551615)>;
 };
#endif

 //Adell, J. A.; Lekuona A. "Monotone and fast computation of Euler's constant." https://europepmc.org/article/MED/28983179
 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct egamma<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  //Common part
  using valueType = typename std :: add_const <Type> :: type;
  template <class X, std :: uintmax_t y, bool isEven> struct naturalPower;
  template <class X> struct naturalPower <X, UINTMAX_C(0), true>;
  template <class X> struct naturalPower <X, UINTMAX_C(1), false>;
  template <class X> struct naturalPower <X, UINTMAX_C(2), true>;
  template <class X> struct naturalPower <X, UINTMAX_C(3), false>;
  template <class X, std :: uintmax_t y> struct naturalPower <X, y, true>;
  template <class X, std :: uintmax_t y> struct naturalPower <X, y, false>;
  using const1 = typename identity <valueRatio<Type, Sign, Numerator, Denominator> > :: type;
  using const2 = typename plusType <const1, const1> :: type;
  using constHalf = typename dividesType <const1, const2> :: type;
  template <std :: uintmax_t y> using powerOfHalf = typename naturalPower <constHalf, y, (y % UINTMAX_C(2)) == UINTMAX_C(0)> :: type;
  template <std :: uintmax_t biN, std :: uintmax_t K> struct binomial;
  template <std :: uintmax_t biN> struct binomial<biN, UINTMAX_C(0)>;
  template <std :: uintmax_t bi> struct binomial<bi, bi>;
  //N coeficient part
  constexpr const static std :: uintmax_t N =
	  bitWidthValue <valueType, std :: numeric_limits <valueType> :: max()> :: value - UINTMAX_C(2);
  //A coeficient part
  template <std :: uintmax_t J, template <std :: uintmax_t, std :: uintmax_t> class biC, template <std :: uintmax_t> class pow> struct An;
  template <std :: uintmax_t J> using elementA = typename An <J, binomial, powerOfHalf> :: type;
  //L coeficient part
  template <std :: uintmax_t J>
	  using lJ = valueRatio<Type, '+', static_cast<valueType>(J + UINTMAX_C(2)), identity <valueType> :: value>;
  template <std :: uintmax_t J>
	  using lJfrac = valueRatio<Type, ((J % UINTMAX_C(2)) == UINTMAX_C(0)) ? '+' : '-', lJ <J> :: den, lJ <J> :: num>; 
  template <std :: uintmax_t J> using lJlog = typename logType <lJ<J> > :: type;
  template <std :: uintmax_t J>
	  using elementL = typename multipliesType <elementA<J>, lJfrac<J>, lJlog<J> > :: type;
  template <std :: uintmax_t ... Js>
	  using sumL = typename plusType <elementL<Js>...> :: type;
  using L = typename iotaValue <N + UINTMAX_C(1), std :: uintmax_t> :: template type<sumL>;
  //U coeficient part
  template <std :: uintmax_t J>
	  using uJ = valueRatio<Type, '+', static_cast<valueType>(J + UINTMAX_C(1)), identity <valueType> :: value>;
  template <std :: uintmax_t J>
	  using uJfrac1 = valueRatio<Type, ((J % UINTMAX_C(2)) == UINTMAX_C(0)) ? '+' : '-', uJ <J> :: den, uJ <J> :: num>;
  template <std :: uintmax_t J>
	  using uJfrac2 = valueRatio<Type, '+', identity <valueType> :: value, static_cast<valueType>(J)>;
  template <std :: uintmax_t J> using uJlog = typename logType <uJ<J> > :: type;
  template <std :: uintmax_t J> using uJbin = typename binomial <N + UINTMAX_C(1), J> :: type;
  template <std :: uintmax_t J>
	  using elementU = typename multipliesType <uJbin<J>, uJfrac1<J>, uJfrac2<J>, uJlog<J> > :: type;
  template <std :: uintmax_t ... Js> using sumU = typename plusType <const1, elementU<Js>...> :: type;
  using sumPartU = typename iotaValue <N + UINTMAX_C(1), std :: uintmax_t, UINTMAX_C(1)> :: template type<sumU>;
  using scale1U = valueRatio<Type, '+', static_cast<valueType>(N + UINTMAX_C(1)), identity <valueType> :: value>;
  using scale2U = powerOfHalf<N + UINTMAX_C(2)>;
  using shiftU = typename multipliesType <scale1U, scale2U, sumPartU> :: type;
  using U = typename plusType <L, shiftU> :: type;
  //Linear part
  using sum = typename plusType <L, U> :: type;
  using constLn2 = typename ln2 <const1> :: type;
  using avr = typename dividesType <sum, const2, constLn2> :: type;
  using shift = typename dividesType <constLn2, const2> :: type;
  public:
  using type = typename plusType <shift, avr> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class X>
 struct egamma <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 naturalPower<X, UINTMAX_C(0), true>
 {
  using type = typename identity <X> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class X>
 struct egamma <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 naturalPower<X, UINTMAX_C(1), false>
 {
  using type = X;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class X>
 struct egamma <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 naturalPower<X, UINTMAX_C(2), true>
 {
  using type = typename multipliesType <X, X> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class X>
 struct egamma <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 naturalPower<X, UINTMAX_C(3), false>
 {
  using type = typename multipliesType <X, X, X> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class X, std :: uintmax_t y>
 struct egamma <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 naturalPower<X, y, true>
 {
  private:
  constexpr const static std :: uintmax_t nextY = y / UINTMAX_C(2);
  constexpr const static bool nextEven = ((nextY % UINTMAX_C(2)) == UINTMAX_C(0));
  using ans = typename naturalPower <X, nextY, nextEven> :: type;
  public:
  using type = typename multipliesType <ans, ans> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class X, std :: uintmax_t y>
 struct egamma <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 naturalPower<X, y, false>
 {
  private:
  constexpr const static std :: uintmax_t nextY = (y - UINTMAX_C(1)) / UINTMAX_C(2);
  constexpr const static bool nextEven = ((nextY % UINTMAX_C(2)) == UINTMAX_C(0));
  using ans = typename naturalPower <X, nextY, nextEven> :: type;
  public:
  using type = typename multipliesType <X, ans, ans> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <std :: uintmax_t biN, std :: uintmax_t K>
 struct egamma <valueRatio<Type, Sign, Numerator, Denominator> > :: binomial
 {
  private:
  using valueType = typename std :: add_const <Type> :: type;
  template <std :: uintmax_t J>
	  using element = valueRatio<Type, '+', static_cast<valueType>(biN + UINTMAX_C(1) - J), static_cast<valueType>(J)>;
  template <std :: uintmax_t ... Js> using product = typename multipliesType <element<Js>...> :: type;
  public:
  using type = typename iotaValue <K, std :: uintmax_t, UINTMAX_C(1)> :: template type<product>;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <std :: uintmax_t biN>
 struct egamma <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 binomial<biN, UINTMAX_C(0)>
 {
  using type = typename identity <valueRatio<Type, Sign, Numerator, Denominator> > :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <std :: uintmax_t bi>
 struct egamma <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 binomial<bi, bi>
 {
  using type = typename identity <valueRatio<Type, Sign, Numerator, Denominator> > :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <std :: uintmax_t J, template <std :: uintmax_t, std :: uintmax_t> class biC, template <std :: uintmax_t> class pow>
 struct egamma <valueRatio<Type, Sign, Numerator, Denominator> > :: An
 {
  private:
  template <std :: uintmax_t K> using elementC = typename biC <K + UINTMAX_C(1), J + UINTMAX_C(1)> :: type;
  template <std :: uintmax_t K> using elementP = typename pow <K + UINTMAX_C(2)> :: type;
  template <std :: uintmax_t K> using element = typename multipliesType <elementC<K>, elementP<K> > :: type;
  template <std :: uintmax_t ... Ks> using sum = typename plusType <element<Ks>...> :: type;
  constexpr const static std :: size_t steps = static_cast<std :: size_t>(N + UINTMAX_C(1) - J);
  public:
  using type = typename iotaValue <steps, std :: uintmax_t, J> :: template type<sum>;
 };
}
#endif

