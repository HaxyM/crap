#include <cstddef>
#include <cstdint>
#include <type_traits>

#include "abstype.h"
#include "dividestype.h"
#include "identity.h"
#include "lesstype.h"
#include "minustype.h"
#include "multipliestype.h"
#include "negatetype.h"
#include "plustype.h"
#include "sintype.h"
#include "sqrttype.h"
#include "valueratio.h"
#include "zero.h"
#include "../algorithm.d/maxtype.h"
#include "../cmath.d/ellint1type.h"
#include "../functional.d/lessvalue.h"
#include "../utility.d/typecast.h"

#ifndef CRAP_RATIO_ELLINT1TYPE
#define CRAP_RATIO_ELLINT1TYPE

namespace crap
{
 template <class Type, char SignK, Type NumeratorK, Type DenominatorK, char SignPhi, Type NumeratorPhi, Type DenominatorPhi>
	 struct ellint1Type<valueRatio<Type, SignK, NumeratorK, DenominatorK>, valueRatio<Type, SignPhi, NumeratorPhi, DenominatorPhi> >
 {
  private:
  using k = valueRatio<Type, SignK, NumeratorK, DenominatorK>;
  using phi = valueRatio<Type, SignPhi, NumeratorPhi, DenominatorPhi>;
  using s = typename sinType <phi> :: type;
  using s2 = typename multipliesType <s, s> :: type;
  using ms2 = typename multipliesType <k, k, s2> :: type;
  using const1 = typename identity <ms2> :: type;
  using initX = typename minusType <const1, s2> :: type;
  using initY = typename minusType <const1, ms2> :: type;
  using const1o10 = typename typeCast <std :: ratio<1, 10> > :: template onto <const1> :: type;
  using c1 = typename typeCast <std :: ratio<1, 24> > :: template onto <const1> :: type;
  using c2 = typename typeCast <std :: ratio<3, 44> > :: template onto <const1> :: type;
  using c3 = typename typeCast <std :: ratio<1, 14> > :: template onto <const1> :: type;
  using const2 = typename plusType <const1, const1> :: type;
  using const3 = typename plusType <const1, const1, const1> :: type;
  using mu = typename dividesType <typename plusType <initX, initY, const1> :: type, const3> :: type;
  using initXnDev =
          typename minusType <const2, typename dividesType <typename plusType <initX,mu> :: type,mu> :: type> :: type;
  using initYnDev =
          typename minusType <const2, typename dividesType <typename plusType <initY,mu> :: type,mu> :: type> :: type;
  using initZnDev =
          typename minusType <const2,typename dividesType <typename plusType <const1,mu> :: type,mu> :: type> :: type;
  using initEps = typename maxType <lessType, initXnDev, initYnDev, initZnDev> :: type;
  template <class nX, class nY, class nZ, class eps, bool isFinal> struct reduce;
  template <class nX, class nY, class nZ, class eps> struct reduce<nX, nY, nZ, eps, true>;
  template <class nX, class nY, class nZ, class eps> struct reduce<nX, nY, nZ, eps, false>;
  using reduced = reduce<initX, initY, const1, initEps, false>;
  using reducedX = typename reduced :: xnDev;
  using reducedY = typename reduced :: ynDev;
  using reducedZ = typename reduced :: znDev;
  using sqrtA = typename sqrtType <typename reduced :: A> :: type;
  using xy = typename multipliesType <reducedX, reducedY> :: type;
  using e2 = typename minusType <xy, typename multipliesType <reducedZ, reducedZ> :: type> :: type;
  using e3 = typename multipliesType <xy, reducedZ> :: type;
  using c1e2 = typename multipliesType <c1, e2> :: type;
  using c2e3 = typename multipliesType <c2, e3> :: type;
  using c3e3 = typename multipliesType <c3, e3> :: type;
  using p1 = typename multipliesType <typename minusType <c1e2, const1o10, c2e3> :: type, e2> :: type;
  using Rf = typename dividesType <typename plusType <const1, p1, c3e3> :: type, sqrtA> :: type;
  public:
  using type = typename multipliesType <s, Rf> :: type;
 };

 template <class Type, char SignK, Type NumeratorK, Type DenominatorK, char SignPhi, Type NumeratorPhi, Type DenominatorPhi>
	 template <class nX, class nY, class nZ, class eps>
 struct ellint1Type<valueRatio<Type, SignK, NumeratorK, DenominatorK>, valueRatio<Type, SignPhi, NumeratorPhi, DenominatorPhi> > :: template
	 reduce<nX, nY, nZ, eps, true>
 {
  private:
  using const1 = typename identity <nX> :: type;
  using const2 = typename plusType <const1, const1> :: type;
  using const3 = typename plusType <const1, const1, const1> :: type;
  public:
  using A = typename dividesType <typename plusType <nX, nY, nZ> :: type, const3> :: type;
  using xnDev =
	  typename minusType <const2, typename dividesType <typename plusType <A, nX> :: type, A> :: type> :: type;
  using ynDev =
	  typename minusType <const2, typename dividesType <typename plusType <A, nY> :: type, A> :: type> :: type;
  using znDev =
	  typename minusType <const2, typename dividesType <typename plusType <A, nZ> :: type, A> :: type> :: type;
 };

 template <class Type, char SignK, Type NumeratorK, Type DenominatorK, char SignPhi, Type NumeratorPhi, Type DenominatorPhi>
	 template <class nX, class nY, class nZ, class eps>
 struct ellint1Type<valueRatio<Type, SignK, NumeratorK, DenominatorK>, valueRatio<Type, SignPhi, NumeratorPhi, DenominatorPhi> > :: template
	 reduce<nX, nY, nZ, eps, false>
 {
  private:
  using const1 = typename identity <nX> :: type;
  using const2 = typename plusType <const1, const1> :: type;
  using const3 = typename plusType <const1, const1, const1> :: type;
  using const4 = typename plusType <const1, const1, const1, const1> :: type;
  using xnRoot = typename sqrtType <nX> :: type;
  using ynRoot = typename sqrtType <nY> :: type;
  using znRoot = typename sqrtType <nZ> :: type;
  using l1 = typename multipliesType <xnRoot, typename plusType <ynRoot, znRoot> :: type> :: type;
  using lambda = typename plusType <l1, typename multipliesType <ynRoot, znRoot> :: type> :: type;
  using nextXn = typename dividesType <typename plusType <nX, lambda> :: type, const4> :: type;
  using nextYn = typename dividesType <typename plusType <nY, lambda> :: type, const4> :: type;
  using nextZn = typename dividesType <typename plusType <nZ, lambda> :: type, const4> :: type;
  using mu = typename dividesType <typename plusType <nextXn, nextYn, nextZn> :: type, const3> :: type;
  using nextXnDev =
          typename minusType <const2,typename dividesType <typename plusType <nextXn,mu> :: type,mu> :: type> :: type;
  using nextYnDev =
          typename minusType <const2,typename dividesType <typename plusType <nextYn,mu> :: type,mu> :: type> :: type;
  using nextZnDev =
          typename minusType <const2,typename dividesType <typename plusType <nextZn,mu> :: type,mu> :: type> :: type;
  using nextEps = typename maxType <lessType, nextXnDev, nextYnDev, nextZnDev> :: type;
  using cond = typename minusType <eps, nextEps> :: type;
  constexpr const static bool nextFinal = //FIXME: Add check if is zero.
          equalToValue <decltype(cond :: num), cond :: num, zero <decltype(cond :: num)> :: value> :: value;
  using newXn = typename std :: conditional <nextFinal, nX, nextXn> :: type;
  using newYn = typename std :: conditional <nextFinal, nY, nextYn> :: type;
  using newZn = typename std :: conditional <nextFinal, nZ, nextZn> :: type;
  using next = reduce<newXn, newYn, newZn, nextEps, nextFinal>;
  public:
  using xnDev = typename next :: xnDev;
  using ynDev = typename next :: ynDev;
  using znDev = typename next :: znDev;
  using A = typename next :: A;
 };

 template <class Type, char SignK, Type NumeratorK, Type DenominatorK, char SignPhi, Type NumeratorPhi, Type DenominatorPhi>
	 constexpr typename ellint1Type <valueRatio<Type, SignK, NumeratorK, DenominatorK>, valueRatio<Type, SignPhi, NumeratorPhi, DenominatorPhi> > :: type
	 ellint_1(valueRatio<Type, SignK, NumeratorK, DenominatorK>, valueRatio<Type, SignPhi, NumeratorPhi, DenominatorPhi>) noexcept;
}

template <class Type, char SignK, Type NumeratorK, Type DenominatorK, char SignPhi, Type NumeratorPhi, Type DenominatorPhi>
inline constexpr typename crap :: ellint1Type <crap :: valueRatio<Type, SignK, NumeratorK, DenominatorK>, crap :: valueRatio<Type, SignPhi, NumeratorPhi, DenominatorPhi> > :: type
crap :: ellint_1(crap :: valueRatio<Type, SignK, NumeratorK, DenominatorK>, crap :: valueRatio<Type, SignPhi, NumeratorPhi, DenominatorPhi>) noexcept
{
 return {};
}
#endif

