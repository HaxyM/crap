#include <cstddef>
#include <cstdint>
#include <type_traits>

#include "abstype.h"
#include "dividestype.h"
#include "ellint1type.h"
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
#include "../cmath.d/ellint2type.h"
#include "../functional.d/lessvalue.h"
#include "../utility.d/typecast.h"

#ifndef CRAP_RATIO_ELLINT2TYPE
#define CRAP_RATIO_ELLINT2TYPE

namespace crap
{
 template <class Type, char SignK, Type NumeratorK, Type DenominatorK, char SignPhi, Type NumeratorPhi, Type DenominatorPhi>
	 struct ellint2Type<valueRatio<Type, SignK, NumeratorK, DenominatorK>, valueRatio<Type, SignPhi, NumeratorPhi, DenominatorPhi> >
 {
  private:
  using k = valueRatio<Type, SignK, NumeratorK, DenominatorK>;
  using phi = valueRatio<Type, SignPhi, NumeratorPhi, DenominatorPhi>;
  using s = typename sinType <phi> :: type;
  using s2 = typename multipliesType <s, s> :: type;
  using ms2 = typename multipliesType <k, k, s2> :: type;
  using const0 = typename zero <ms2> :: type;
  using const1 = typename identity <const0> :: type;
  using const2 = typename plusType <const1, const1> :: type;
  using const3 = typename plusType <const1, const1, const1> :: type;
  using const5 = typename plusType <const1, const1, const1, const1, const1> :: type;
  using const6 = typename plusType <const1, const1, const1, const1, const1, const1> :: type;
  using const1o3 = typename typeCast <std :: ratio<1, 3> > :: template onto <const1> :: type;
  using const1o4 = typename typeCast <std :: ratio<1, 4> > :: template onto <const1> :: type;
  using const3o2 = typename typeCast <std :: ratio<3, 2> > :: template onto <const1> :: type;
  using initX = typename minusType <const1, s2> :: type;
  using initY = typename minusType <const1, ms2> :: type;
  using c1 = typename typeCast <std :: ratio<3, 14> > :: template onto <const1> :: type;
  using c2 = typename typeCast <std :: ratio<1, 6> > :: template onto <const1> :: type;
  using c3 = typename typeCast <std :: ratio<9, 22> > :: template onto <const1> :: type;
  using c4 = typename typeCast <std :: ratio<3, 26> > :: template onto <const1> :: type;
  using mu = typename dividesType <typename plusType <initX, initY, const3> :: type, const5> :: type;
  using initXnDev = typename dividesType <typename minusType <initX, mu> :: type, mu> :: type;
  using initYnDev = typename dividesType <typename minusType <initY, mu> :: type, mu> :: type;
  using initZnDev = typename dividesType <typename minusType <const1, mu> :: type, mu> :: type;
  using initEps = typename maxType <lessType, initXnDev, initYnDev, initZnDev> :: type;
  template <class nX, class nY, class nZ, class Sigma, class p4, class eps, bool isFinal> struct reduce;
  template <class nX, class nY, class nZ, class Sigma, class p4, class eps>
	  struct reduce<nX, nY, nZ, Sigma, p4, eps, true>;
  template <class nX, class nY, class nZ, class Sigma, class p4, class eps>
	  struct reduce<nX, nY, nZ, Sigma, p4, eps, false>;
  using reduced = reduce<initX, initY, const1, const0, const1, initEps, false>;
  using reducedX = typename reduced :: xnDev;
  using reducedY = typename reduced :: ynDev;
  using reducedZ = typename reduced :: znDev;
  using reducedA = typename reduced :: A;
  using reducedS = typename reduced :: sigma;
  using reducedP = typename reduced :: power4;
  using Ap3o2 = typename multipliesType <reducedA, typename sqrtType <reducedA> :: type> :: type;
  using ea = typename multipliesType <reducedX, reducedY> :: type;
  using eb = typename multipliesType <reducedZ, reducedZ> :: type;
  using ec = typename minusType <ea, eb> :: type;
  using ed = typename minusType <ea, typename multipliesType <const6, eb> :: type> :: type;
  using ef = typename plusType <ed, ec, ec> :: type;
  using s1p1 = typename multipliesType <const1o4, c3, ed> :: type;
  using s1p2 = typename multipliesType <const3o2, c4, reducedZ, ef> :: type;
  using S1 = typename multipliesType <ed, typename minusType <s1p1, s1p2, c1> :: type> :: type;
  using s2p1 = typename multipliesType <reducedZ, c4, ea> :: type;
  using s2p2 = typename minusType <s2p1, typename multipliesType <c3, ec> :: type> :: type;
  using s2p3 = typename multipliesType <c2, ef> :: type;
  using s2p4 = typename plusType <s2p3, typename multipliesType <reducedZ, s2p2> :: type> :: type;
  using S2 = typename multipliesType <reducedZ, s2p4> :: type;
  using RdP1 = typename plusType <const1, S1, S2> :: type;
  using RdP2 = typename multipliesType <RdP1, typename dividesType <reducedP, Ap3o2> :: type> :: type;
  using Rd = typename plusType <reducedS, reducedS, reducedS, RdP2> :: type;
  using K = typename ellint1Type <k, phi> :: type;
  public:
  using type = typename minusType <K, typename multipliesType <const1o3, ms2, s, Rd> :: type> :: type;
 };

 template <class Type, char SignK, Type NumeratorK, Type DenominatorK, char SignPhi, Type NumeratorPhi, Type DenominatorPhi>
	 template <class nX, class nY, class nZ, class Sigma, class p4, class eps>
 struct ellint2Type<valueRatio<Type, SignK, NumeratorK, DenominatorK>, valueRatio<Type, SignPhi, NumeratorPhi, DenominatorPhi> > :: template
	 reduce<nX, nY, nZ, Sigma, p4, eps, true>
 {
  private:
  using const1 = typename identity <nX> :: type;
  using const5 = typename plusType <const1, const1, const1, const1, const1> :: type;
  public:
  using sigma = Sigma;
  using power4 = p4;
  using A = typename dividesType <typename plusType <nX, nY, nZ, nZ, nZ> :: type, const5> :: type;
  using xnDev = typename dividesType <typename minusType <A, nX> :: type, A> :: type;
  using ynDev = typename dividesType <typename minusType <A, nY> :: type, A> :: type;
  using znDev = typename dividesType <typename minusType <A, nZ> :: type, A> :: type;
 };

 template <class Type, char SignK, Type NumeratorK, Type DenominatorK, char SignPhi, Type NumeratorPhi, Type DenominatorPhi>
	 template <class nX, class nY, class nZ, class Sigma, class p4, class eps>
 struct ellint2Type<valueRatio<Type, SignK, NumeratorK, DenominatorK>, valueRatio<Type, SignPhi, NumeratorPhi, DenominatorPhi> > :: template
	 reduce<nX, nY, nZ, Sigma, p4, eps, false>
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
  using nextSigmaP1 = typename multipliesType <znRoot, typename plusType <nZ, lambda> :: type> :: type;
  using nextSigma = typename plusType <Sigma, typename dividesType <p4, nextSigmaP1> :: type> :: type;
  using nextP4 = typename dividesType <p4, const4> :: type;
  using nextXn = typename dividesType <typename plusType <nX, lambda> :: type, const4> :: type;
  using nextYn = typename dividesType <typename plusType <nY, lambda> :: type, const4> :: type;
  using nextZn = typename dividesType <typename plusType <nZ, lambda> :: type, const4> :: type;
  using mu = typename dividesType <typename plusType <nextXn, nextYn, nextZn> :: type, const3> :: type;
  using nextXnDev = typename dividesType <typename minusType <nextXn, mu> :: type, mu> :: type;
  using nextYnDev = typename dividesType <typename minusType <nextYn, mu> :: type, mu> :: type;
  using nextZnDev = typename dividesType <typename minusType <nextZn, mu> :: type, mu> :: type;
  using nextEps = typename maxType <lessType, nextXnDev, nextYnDev, nextZnDev> :: type;
  using cond = typename minusType <eps, nextEps> :: type;
  constexpr const static bool nextFinal = //FIXME: Add check if is zero.
          equalToValue <decltype(cond :: num), cond :: num, zero <decltype(cond :: num)> :: value> :: value;
  using newXn = typename std :: conditional <nextFinal, nX, nextXn> :: type;
  using newYn = typename std :: conditional <nextFinal, nY, nextYn> :: type;
  using newZn = typename std :: conditional <nextFinal, nZ, nextZn> :: type;
  using newSigma = typename std :: conditional <nextFinal, Sigma, nextSigma> :: type;
  using newP4 = typename std :: conditional <nextFinal, p4, nextP4> :: type;
  using next = reduce<newXn, newYn, newZn, newSigma, newP4, nextEps, nextFinal>;
  public:
  using xnDev = typename next :: xnDev;
  using ynDev = typename next :: ynDev;
  using znDev = typename next :: znDev;
  using A = typename next :: A;
  using power4 = typename next :: power4;
  using sigma = typename next :: sigma;
 };

 template <class Type, char SignK, Type NumeratorK, Type DenominatorK, char SignPhi, Type NumeratorPhi, Type DenominatorPhi>
	 constexpr typename ellint2Type <valueRatio<Type, SignK, NumeratorK, DenominatorK>, valueRatio<Type, SignPhi, NumeratorPhi, DenominatorPhi> > :: type
	 ellint_2(valueRatio<Type, SignK, NumeratorK, DenominatorK>, valueRatio<Type, SignPhi, NumeratorPhi, DenominatorPhi>) noexcept;
}

template <class Type, char SignK, Type NumeratorK, Type DenominatorK, char SignPhi, Type NumeratorPhi, Type DenominatorPhi>
inline constexpr typename crap :: ellint2Type <crap :: valueRatio<Type, SignK, NumeratorK, DenominatorK>, crap :: valueRatio<Type, SignPhi, NumeratorPhi, DenominatorPhi> > :: type
crap :: ellint_2(crap :: valueRatio<Type, SignK, NumeratorK, DenominatorK>, crap :: valueRatio<Type, SignPhi, NumeratorPhi, DenominatorPhi>) noexcept
{
 return {};
}
#endif

