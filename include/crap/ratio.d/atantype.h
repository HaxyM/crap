#include <cstdint>
#include <type_traits>

#include "dividestype.h"
#include "identity.h"
#include "minustype.h"
#include "multipliestype.h"
#include "plustype.h"
#include "sqrttype.h"
#include "valueratio.h"
#include "zero.h"
#include "../cmath.d/atantype.h"
#include "../functional.d/equaltovalue.h"

#ifndef CRAP_RATIO_ATANTYPE
#define CRAP_RATIO_ATANTYPE

namespace crap
{
 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct atanType<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using x = valueRatio<Type, Sign, Numerator, Denominator>;
  using sqrX = typename multipliesType <x, x> :: type;
  using const1 = typename identity <x> :: type;
  using elem1 = typename plusType <const1, sqrX> :: type;
  using elem2 = typename sqrtType <elem1> :: type;
  using initialA = valueRatio<Type, elem2 :: sign, elem2 :: den, elem2 :: num>;
  template <class A, class B, bool isFinal> struct step;
  template <class A, class B> struct step<A, B, true>;
  public:
  using type = typename step <initialA, const1, false> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 template <class A, class B, bool isFinal>
	 struct atanType<valueRatio<Type, Sign, Numerator, Denominator> > :: step
 {
  private:
  using const2 = typename plusType <typename identity <A> :: type, typename identity <A> :: type> :: type;
  using nextA = typename dividesType <typename plusType <A, B> :: type, const2> :: type;
  using nextB = typename sqrtType <typename multipliesType <nextA, B> :: type> :: type;
  using cond = typename minusType <nextA, A> :: type;
  constexpr const static bool nextFinal = //FIXME: Add check if is zero.
	  equalToValue <decltype(cond :: num), cond :: num, zero <decltype(cond :: num)> :: value> :: value;
  public:
  using type = typename step <nextA, nextB, nextFinal> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 template <class A, class B>
	 struct atanType<valueRatio<Type, Sign, Numerator, Denominator> > :: template step<A, B, true>
 {
  private:
  using x = valueRatio<Type, Sign, Numerator, Denominator>;
  using sqrX = typename multipliesType <x, x> :: type;
  using const1 = typename identity <x> :: type;
  using denominator = typename sqrtType <typename plusType <const1, sqrX> :: type> :: type;
  public:
  using type = typename dividesType <x, denominator, A> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 constexpr typename atanType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 atan(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
inline constexpr typename crap :: atanType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: atan(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif
