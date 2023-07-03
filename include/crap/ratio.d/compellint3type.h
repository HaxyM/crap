#include <cstddef>
#include <cstdint>
#include <type_traits>

#include "dividestype.h"
#include "compellint1type.h"
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
#include "../cmath.d/compellint3type.h"
#include "../functional.d/lessvalue.h"
#include "../utility.d/typecast.h"

#ifndef CRAP_RATIO_COMPELLINT3TYPE
#define CRAP_RATIO_COMPELLINT3TYPE

namespace crap
{
 template <class Type, char SignK, Type NumeratorK, Type DenominatorK, char SignNu, Type NumeratorNu, Type DenominatorNu>
	 struct compEllint3Type<valueRatio<Type, SignK, NumeratorK, DenominatorK>, valueRatio<Type, SignNu, NumeratorNu, DenominatorNu> >
 {
  private:
  using k = valueRatio<Type, SignK, NumeratorK, DenominatorK>;
  using nu = valueRatio<Type, SignNu, NumeratorNu, DenominatorNu>;
  using k2 = typename multipliesType <k, k> :: type;
  using const0 = typename zero <k2> :: type;
  using const1 = typename identity <const0> :: type;
  using const5 = typename plusType <const1, const1, const1, const1, const1> :: type;
  using constM1 = typename typeCast <std :: ratio<-1, 1> > :: template onto <const1> :: type;
  using const1o2 = typename typeCast <std :: ratio<1, 2> > :: template onto <const1> :: type;
  using const1o3 = typename typeCast <std :: ratio<1, 3> > :: template onto <const1> :: type;
  using const3o4 = typename typeCast <std :: ratio<3, 4> > :: template onto <const1> :: type;
  using const3o2 = typename typeCast <std :: ratio<3, 2> > :: template onto <const1> :: type;
  using initY = typename minusType <const1, k2> :: type;
  using initP = typename minusType <const1, nu> :: type;
  using c1 = typename typeCast <std :: ratio<3, 14> > :: template onto <const1> :: type;
  using c2 = typename typeCast <std :: ratio<1, 3> > :: template onto <const1> :: type;
  using c3 = typename typeCast <std :: ratio<3, 22> > :: template onto <const1> :: type;
  using c4 = typename typeCast <std :: ratio<3, 26> > :: template onto <const1> :: type;
  using mu = typename dividesType <typename plusType <initY, const1, initP, initP> :: type, const5> :: type;
  using initYnDev = typename dividesType <typename minusType <initY, mu> :: type, mu> :: type;
  using initZnDev = typename dividesType <typename minusType <const1, mu> :: type, mu> :: type;
  using initPnDev = typename dividesType <typename minusType <initP, mu> :: type, mu> :: type;
  using initEps = typename maxType <lessType, constM1, initYnDev, initZnDev, initPnDev> :: type;
  template <class nX, class nY, class nZ, class nP, class Sigma, class p4, class eps, bool isFinal> struct reduce;
  template <class nX, class nY, class nZ, class nP, class Sigma, class p4, class eps>
	  struct reduce<nX, nY, nZ, nP, Sigma, p4, eps, true>;
  template <class nX, class nY, class nZ, class nP, class Sigma, class p4, class eps>
	  struct reduce<nX, nY, nZ, nP, Sigma, p4, eps, false>;
  using reduced = reduce<const0, initY, const1, initP, const0, const1, initEps, false>;
  using reducedX = typename reduced :: xnDev;
  using reducedY = typename reduced :: ynDev;
  using reducedZ = typename reduced :: znDev;
  using reducedP = typename reduced :: pnDev;
  using reducedA = typename reduced :: A;
  using reducedS = typename reduced :: sigma;
  using reducedP4 = typename reduced :: power4;
  using Ap3o2 = typename multipliesType <reducedA, typename sqrtType <reducedA> :: type> :: type;
  using eap1 = typename plusType <reducedY, reducedZ> :: type;
  using eap2 = typename multipliesType <reducedY, reducedZ> :: type;
  using ea = typename plusType <typename multipliesType <reducedX, eap1> :: type, eap2> :: type;
  using eb = typename multipliesType <reducedX, reducedY, reducedZ> :: type;
  using ec = typename multipliesType <reducedP, reducedP> :: type;
  using e2 = typename minusType <ea, ec, ec, ec> :: type;
  using e3p1 = typename multipliesType <reducedP, typename minusType <ea, ec> :: type> :: type;
  using e3 = typename plusType <eb, e3p1, e3p1> :: type;
  using s1p1 = typename multipliesType <const3o2, c4, e3> :: type;
  using s1p2 = typename multipliesType <const3o4, c3, e2> :: type;
  using s1p3 = typename multipliesType <e2, typename minusType <s1p2, c1, s1p1> :: type> :: type;
  using s1 = typename plusType <const1, s1p3> :: type;
  using s2p1 = typename minusType <typename multipliesType <reducedP, c4> :: type, c3, c3> :: type;
  using s2p2 = typename multipliesType <reducedP, s2p1> :: type;
  using s2p3 = typename multipliesType <const1o2, c2> :: type;
  using s2 = typename multipliesType <eb, typename plusType <s2p3, s2p2> :: type> :: type;
  using s3p1 = typename multipliesType <c2, reducedP, ec> :: type;
  using s3p2 = typename minusType <c2, typename multipliesType <reducedP, c3> :: type> :: type;
  using s3 = typename minusType <typename multipliesType <reducedP, ea, s3p2> :: type, s3p1> :: type;
  using Rjp1 = typename dividesType <reducedP4, Ap3o2> :: type;
  using Rjp2 = typename multipliesType<Rjp1, typename plusType <s1, s2, s3> :: type> :: type;
  using Rj = typename plusType <reducedS, reducedS, reducedS, Rjp2> :: type;
  using K = typename compEllint1Type <k> :: type;
  public:
  using type = typename plusType <K, typename multipliesType <const1o3, nu, Rj> :: type> :: type;
 };

 template <class Type, char SignK, Type NumeratorK, Type DenominatorK, char SignNu, Type NumeratorNu, Type DenominatorNu>
	 template <class nX, class nY, class nZ, class nP, class Sigma, class p4, class eps>
 struct compEllint3Type<valueRatio<Type, SignK, NumeratorK, DenominatorK>, valueRatio<Type, SignNu, NumeratorNu, DenominatorNu> > :: template
	 reduce<nX, nY, nZ, nP, Sigma, p4, eps, true>
 {
  private:
  using const1 = typename identity <nX> :: type;
  using const5 = typename plusType <const1, const1, const1, const1, const1> :: type;
  public:
  using sigma = Sigma;
  using power4 = p4;
  using A = typename dividesType <typename plusType <nX, nY, nZ, nP, nP> :: type, const5> :: type;
  using xnDev = typename dividesType <typename minusType <A, nX> :: type, A> :: type;
  using ynDev = typename dividesType <typename minusType <A, nY> :: type, A> :: type;
  using znDev = typename dividesType <typename minusType <A, nZ> :: type, A> :: type;
  using pnDev = typename dividesType <typename minusType <A, nP> :: type, A> :: type;
 };

 template <class Type, char SignK, Type NumeratorK, Type DenominatorK, char SignNu, Type NumeratorNu, Type DenominatorNu>
	 template <class nX, class nY, class nZ, class nP, class Sigma, class p4, class eps>
 struct compEllint3Type<valueRatio<Type, SignK, NumeratorK, DenominatorK>, valueRatio<Type, SignNu, NumeratorNu, DenominatorNu> > :: template
	 reduce<nX, nY, nZ, nP, Sigma, p4, eps, false>
 {
  private:
  using const1 = typename identity <nX> :: type;
  using const2 = typename plusType <const1, const1> :: type;
  using const3 = typename plusType <const1, const1, const1> :: type;
  using const4 = typename plusType <const1, const1, const1, const1> :: type;
  using const5 = typename plusType <const1, const1, const1, const1, const1> :: type;
  using xnRoot = typename sqrtType <nX> :: type;
  using ynRoot = typename sqrtType <nY> :: type;
  using znRoot = typename sqrtType <nZ> :: type;
  using l1 = typename multipliesType <xnRoot, typename plusType <ynRoot, znRoot> :: type> :: type;
  using lambda = typename plusType <l1, typename multipliesType <ynRoot, znRoot> :: type> :: type;
  using dp1 = typename multipliesType<nP, typename plusType <xnRoot, ynRoot, znRoot> :: type> :: type;
  using d = typename plusType <dp1, typename multipliesType <xnRoot, ynRoot, znRoot> :: type> :: type;
  using b1 = typename plusType <nP, lambda> :: type;
  using alpha = typename multipliesType <d, d> :: type;
  using beta = typename multipliesType <nP, b1, b1> :: type;
  using initRcA = typename dividesType <typename plusType <alpha, beta, beta> :: type, const3> :: type;
  using initRcEps1 = typename plusType <beta, initRcA> :: type;
  using initRcEps = typename minusType <typename dividesType <initRcEps1, initRcA> :: type, const2> :: type;
  template <class RcX, class RcY, class RcEps, bool RcFinal> struct Rc;
  template <class RcX, class RcY, class RcEps> struct Rc<RcX, RcY, RcEps, true>;
  template <class RcX, class RcY, class RcEps> struct Rc<RcX, RcY, RcEps, false>;
  using nextSigmaP1 = typename multipliesType <p4, typename Rc <alpha, beta, initRcEps, false> :: type> :: type;
  using nextSigma = typename plusType <Sigma, nextSigmaP1> :: type;
  using nextP4 = typename dividesType <p4, const4> :: type;
  using nextXn = typename dividesType <typename plusType <nX, lambda> :: type, const4> :: type;
  using nextYn = typename dividesType <typename plusType <nY, lambda> :: type, const4> :: type;
  using nextZn = typename dividesType <typename plusType <nZ, lambda> :: type, const4> :: type;
  using nextPn = typename dividesType <typename plusType <nP, lambda> :: type, const4> :: type;

  using mu =
	  typename dividesType <typename plusType <nextXn, nextYn, nextZn, nextPn, nextPn> :: type, const5> :: type;
  using nextXnDev = typename dividesType <typename minusType <nextXn, mu> :: type, mu> :: type;
  using nextYnDev = typename dividesType <typename minusType <nextYn, mu> :: type, mu> :: type;
  using nextZnDev = typename dividesType <typename minusType <nextZn, mu> :: type, mu> :: type;
  using nextPnDev = typename dividesType <typename minusType <nextPn, mu> :: type, mu> :: type;
  using nextEps = typename maxType <lessType, nextXnDev, nextYnDev, nextZnDev, nextPnDev> :: type;
  using cond = typename minusType <eps, nextEps> :: type;
  constexpr const static bool nextFinal = //FIXME: Add check if is zero.
          equalToValue <decltype(cond :: num), cond :: num, zero <decltype(cond :: num)> :: value> :: value;
  using newXn = typename std :: conditional <nextFinal, nX, nextXn> :: type;
  using newYn = typename std :: conditional <nextFinal, nY, nextYn> :: type;
  using newZn = typename std :: conditional <nextFinal, nZ, nextZn> :: type;
  using newPn = typename std :: conditional <nextFinal, nP, nextPn> :: type;
  using newSigma = typename std :: conditional <nextFinal, Sigma, nextSigma> :: type;
  using newP4 = typename std :: conditional <nextFinal, p4, nextP4> :: type;
  using next = reduce<newXn, newYn, newZn, newPn, newSigma, newP4, nextEps, nextFinal>;
  public:
  using xnDev = typename next :: xnDev;
  using ynDev = typename next :: ynDev;
  using znDev = typename next :: znDev;
  using pnDev = typename next :: pnDev;
  using A = typename next :: A;
  using power4 = typename next :: power4;
  using sigma = typename next :: sigma;
 };

 template <class Type, char SignK, Type NumeratorK, Type DenominatorK, char SignNu, Type NumeratorNu, Type DenominatorNu>
	 template <class nX, class nY, class nZ, class nP, class Sigma, class p4, class eps>
	 template <class RcX, class RcY, class RcEps>
 struct compEllint3Type<valueRatio<Type, SignK, NumeratorK, DenominatorK>, valueRatio<Type, SignNu, NumeratorNu, DenominatorNu> > :: template
	 reduce <nX, nY, nZ, nP, Sigma, p4, eps, false> :: template
	 Rc<RcX, RcY, RcEps, true>
 {
  private:
  using const1 = typename identity <RcX> :: type;
  using const3 = typename plusType <const1, const1, const1> :: type;
  using c1Rc = typename typeCast <std :: ratio<1, 7> > :: template onto <const1> :: type; 
  using c2Rc = typename typeCast <std :: ratio<9, 22> > :: template onto <const1> :: type; 
  using c3Rc = typename typeCast <std :: ratio<3, 8> > :: template onto <const1> :: type; 
  using c4Rc = typename typeCast <std :: ratio<3, 10> > :: template onto <const1> :: type; 
  using ARc = typename dividesType <typename plusType <RcX, RcY, RcY> :: type, const3> :: type;
  using resP1 = typename plusType <c3Rc, typename multipliesType <RcEps, c2Rc> :: type> :: type;
  using resP2 = typename plusType <c1Rc, typename multipliesType <RcEps, resP1> :: type> :: type;
  using resP3 = typename plusType <c4Rc, typename multipliesType <RcEps, resP2> :: type> :: type;
  using resP4 = typename plusType <const1, typename multipliesType <RcEps, RcEps, resP3> :: type> :: type;
  public:
  using type = typename dividesType <resP4, typename sqrtType <ARc> :: type> :: type;
 };

 template <class Type, char SignK, Type NumeratorK, Type DenominatorK, char SignNu, Type NumeratorNu, Type DenominatorNu>
	 template <class nX, class nY, class nZ, class nP, class Sigma, class p4, class eps>
	 template <class RcX, class RcY, class RcEps>
 struct compEllint3Type<valueRatio<Type, SignK, NumeratorK, DenominatorK>, valueRatio<Type, SignNu, NumeratorNu, DenominatorNu> > :: template
	 reduce <nX, nY, nZ, nP, Sigma, p4, eps, false> :: template
	 Rc<RcX, RcY, RcEps, false>
 {
  private:
  using const1 = typename identity <RcX> :: type;
  using const2 = typename plusType <const1, const1> :: type;
  using const3 = typename plusType <const1, const1, const1> :: type;
  using const4 = typename plusType <const1, const1, const1, const1> :: type;
  using ARc = typename dividesType <typename plusType <RcX, RcY, RcY> :: type, const3> :: type;
  using snp1Rc = typename dividesType <typename plusType <RcY, ARc> :: type, ARc> :: type;
  using nextEpsRc = typename minusType <snp1Rc, const2> :: type;
  using condRc = typename minusType <RcEps, nextEpsRc> :: type;
  constexpr const static bool nextFinalRc = //FIXME: Add check if is zero.
          equalToValue <decltype(condRc :: num), condRc :: num, zero <decltype(condRc :: num)> :: value> :: value;
  using xnRootRc = typename sqrtType <RcX> :: type;
  using ynRootRc = typename sqrtType <RcY> :: type;
  using lambdaRc = typename plusType <typename multipliesType <const2, xnRootRc, ynRootRc> :: type, RcY> :: type;
  using nextXnRc = typename dividesType <typename plusType <RcX, lambda> :: type, const4> :: type;
  using nextYnRc = typename dividesType <typename plusType <RcY, lambda> :: type, const4> :: type;
  using newXnRc = typename std :: conditional <nextFinalRc, RcX, nextXnRc> :: type;
  using newYnRc = typename std :: conditional <nextFinalRc, RcY, nextYnRc> :: type;
  public:
  using type = typename Rc <newXnRc, newYnRc, nextEpsRc, nextFinalRc> :: type;
 };

 template <class Type, char SignK, Type NumeratorK, Type DenominatorK, char SignNu, Type NumeratorNu, Type DenominatorNu>
	 constexpr typename compEllint3Type <valueRatio<Type, SignK, NumeratorK, DenominatorK>, valueRatio<Type, SignNu, NumeratorNu, DenominatorNu> > :: type
	 comp_ellint_3(valueRatio<Type, SignK, NumeratorK, DenominatorK>, valueRatio<Type, SignNu, NumeratorNu, DenominatorNu>) noexcept;
}

template <class Type, char SignK, Type NumeratorK, Type DenominatorK, char SignNu, Type NumeratorNu, Type DenominatorNu>
inline constexpr typename crap :: compEllint3Type <crap :: valueRatio<Type, SignK, NumeratorK, DenominatorK>, crap :: valueRatio<Type, SignNu, NumeratorNu, DenominatorNu> > :: type
crap :: comp_ellint_3(crap :: valueRatio<Type, SignK, NumeratorK, DenominatorK>, crap :: valueRatio<Type, SignNu, NumeratorNu, DenominatorNu>) noexcept
{
 return {};
}
#endif

