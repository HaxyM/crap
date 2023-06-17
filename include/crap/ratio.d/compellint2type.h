#include "abstype.h"
#include "dividestype.h"
#include "identity.h"
#include "lesstype.h"
#include "minustype.h"
#include "multipliestype.h"
#include "pi.h"
#include "plustype.h"
#include "sqrttype.h"
#include "valueratio.h"
#include "../cmath.d/compellint2type.h"
#include "../functional.d/equaltovalue.h"

#ifndef CRAP_RATIO_COMPELLINT2TYPE
#define CRAP_RATIO_COMPELLINT2TYPE

namespace crap
{
 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct compEllint2Type<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using k = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <k> :: type;
  using const2 = typename plusType <const1, const1> :: type;
  static_assert(!lessType <const1, typename absType <k> :: type> :: value, "Value out of range!");
  using a0 = const1;
  using g0 = typename sqrtType <typename minusType <const1, typename multipliesType <k, k> :: type> :: type> :: type;
  using c0 = k;
  using p0 = typename dividesType <const1, const2> :: type;
  using r0 = const1;
  template <class Aritm, class Geom, class C, class P, class Result, bool isFinal> struct step;
  template <class Aritm, class Geom, class C, class P, class Result> struct step<Aritm, Geom, C, P, Result, true>;
  template <class Aritm, class Geom, class C, class P, class Result> struct step<Aritm, Geom, C, P, Result, false>;
  public:
  using type = typename step <a0, g0, c0, p0, r0, false> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class Aritm, class Geom, class C, class P, class Result>
 struct compEllint2Type <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 step<Aritm, Geom, C, P, Result, true>
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using num = typename multipliesType <typename pi <typename identity <passed> :: type> :: type, Result> :: type;
  public:
  using type = typename dividesType <num, typename plusType <Aritm, Aritm> :: type> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class Aritm, class Geom, class C, class P, class Result>
 struct compEllint2Type <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 step<Aritm, Geom, C, P, Result, false>
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <passed> :: type;
  using const2 = typename plusType <const1, const1> :: type;
  using const4 = typename plusType <const1, const1, const1, const1> :: type;
  using nextAritm = typename dividesType <typename plusType <Aritm, Geom> :: type, const2> :: type;
  using nextGeom = typename sqrtType <typename multipliesType <Aritm, Geom> :: type> :: type;
  using sqrC = typename multipliesType <C, C> :: type;
  using nextC = typename dividesType <sqrC, typename multipliesType <const4, nextAritm> :: type> :: type;
  using nextP = typename plusType <P, P> :: type;
  using nextResult = typename minusType <Result, typename multipliesType <P, C, C> :: type> :: type;
  using diff1 = typename absType <typename minusType <Aritm, Geom> :: type> :: type;
  using diff2 = typename absType <typename minusType <nextAritm, nextGeom> :: type> :: type;
  constexpr const static bool continueSteps = lessType <diff2, diff1> :: value;
  public:
  using type = typename step <nextAritm, nextGeom, nextC, nextP, nextResult, !continueSteps> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 constexpr typename compEllint2Type <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 comp_ellint_2(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, Type Numerator, Type Denominator>
inline constexpr typename crap :: compEllint2Type <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: comp_ellint_2(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

