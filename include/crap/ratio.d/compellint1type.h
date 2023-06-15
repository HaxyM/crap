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
#include "../cmath.d/compellint1type.h"
#include "../functional.d/equaltovalue.h"

#ifndef CRAP_RATIO_COMPELLINT1TYPE
#define CRAP_RATIO_COMPELLINT1TYPE

namespace crap
{
 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct compEllint1Type<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using k = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <k> :: type;
  static_assert(lessType <typename absType <k> :: type, const1> :: value, "Value out of range!");
  using a0 = const1;
  using g0 = typename sqrtType <typename minusType <const1, typename multipliesType <k, k> :: type> :: type> :: type;
  template <class Aritm, class Geom, bool isFinal> struct step;
  template <class Aritm, class Geom> struct step<Aritm, Geom, true>;
  template <class Aritm, class Geom> struct step<Aritm, Geom, false>;
  public:
  using type = typename step <a0, g0, false> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class Aritm, class Geom>
 struct compEllint1Type <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 step<Aritm, Geom, true>
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using constPi = typename pi <typename identity <passed> :: type> :: type;
  public:
  using type = typename dividesType <constPi, typename plusType <Aritm, Aritm> :: type> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class Aritm, class Geom>
 struct compEllint1Type <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 step<Aritm, Geom, false>
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <passed> :: type;
  using const2 = typename plusType <const1, const1> :: type;
  using nextAritm = typename dividesType <typename plusType <Aritm, Geom> :: type, const2> :: type;
  using nextGeom = typename sqrtType <typename multipliesType <Aritm, Geom> :: type> :: type;
  using diff1 = typename absType <typename minusType <Aritm, Geom> :: type> :: type;
  using diff2 = typename absType <typename minusType <nextAritm, nextGeom> :: type> :: type;
  constexpr const static bool continueSteps = lessType <diff2, diff1> :: value;
  public:
  using type = typename step <nextAritm, nextGeom, !continueSteps> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 constexpr typename compEllint1Type <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 comp_ellint_1(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, Type Numerator, Type Denominator>
inline constexpr typename crap :: compEllint1Type <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: comp_ellint_1(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

