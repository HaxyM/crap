#include <cstddef>
#include <type_traits>

#include "ceiltype.h"
#include "dividestype.h"
#include "equaltotype.h"
#include "identity.h"
#include "ln2.h"
#include "minustype.h"
#include "multipliestype.h"
#include "plustype.h"
#include "valueratio.h"
#include "zero.h"
#include "../bit.d/bitfloorvalue.h"
#include "../bit.d/bitwidthvalue.h"
#include "../cmath.d/logtype.h"
#include "../functional.d/dividestype.h"
#include "../functional.d/minustype.h"
#include "../functional.d/multipliestype.h"
#include "../functional.d/plustype.h"
#include "../numbers.d/identity.h"
#include "../numbers.d/ln2.h"
#include "../numbers.d/zero.h"

#ifndef CRAP_RATIO_LOGTYPE
#define CRAP_RATIO_LOGTYPE

namespace crap
{
 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct logType<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  static_assert(Sign == '+', "Value must be positive.");
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using inversed = valueRatio<Type, Sign, Denominator, Numerator>;
  using ceilRegular = typename ceilType <passed> :: type;
  using ceilInversed = typename ceilType <inversed> :: type;
  constexpr const static std :: size_t bitWidthRegular =
	  bitWidthValue <decltype(ceilRegular :: num), ceilRegular :: num> :: value;
  constexpr const static std :: size_t bitWidthInversed =
	  bitWidthValue <decltype(ceilInversed :: num), ceilInversed :: num> :: value;
  constexpr const static bool useInversed = (bitWidthInversed > bitWidthRegular);
  using valueToBeUsed = typename std :: conditional <useInversed, inversed, passed> :: type;
  using rounded = typename std :: conditional <useInversed, ceilInversed, ceilRegular> :: type;
  using scale =
	  valueRatio<Type, '+', bitFloorValue <decltype(rounded :: num), rounded :: num> :: value, rounded :: den>;
  using x = typename dividesType <valueToBeUsed, scale> :: type;
  using const1 = typename identity <passed> :: type;
  using initialX = typename minusType <x, const1> :: type;
  using initialPower = typename multipliesType <initialX, initialX> :: type;
  using valueType = typename std :: make_unsigned <Type> :: type;
  constexpr const static valueType constK1 = identity <valueType> :: value;
  constexpr const static valueType initialK = constK1 + constK1;
  template <class Sum, class Power, class X, typename std :: make_unsigned <Type> :: type K, bool isFinal> struct step;
  template <class Sum, class Power, class X, typename std :: make_unsigned <Type> :: type K> struct step<Sum, Power, X, K, false>;
  public:
  using type = typename step <initialX, initialPower, initialX, initialK, false> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 template <class Sum, class Power, class X, typename std :: make_unsigned <Type> :: type K, bool isFinal>
	 struct logType<valueRatio<Type, Sign, Numerator, Denominator> > :: step
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using inversed = valueRatio<Type, Sign, Denominator, Numerator>;
  using ceilRegular = typename ceilType <passed> :: type;
  using ceilInversed = typename ceilType <inversed> :: type;
  constexpr const static std :: size_t bitWidthRegular =
	  bitWidthValue <decltype(ceilRegular :: num), ceilRegular :: num> :: value;
  constexpr const static std :: size_t bitWidthInversed =
	  bitWidthValue <decltype(ceilInversed :: num), ceilInversed :: num> :: value;
  constexpr const static bool useInversed = (bitWidthInversed > bitWidthRegular);
  constexpr const static std :: size_t bitWidth = (useInversed ? bitWidthInversed : bitWidthRegular);
  using scale = valueRatio<Type, '+', (bitWidth - 1u), identity <decltype(bitWidth - 1u)> :: value>;
  template <class Scale, bool useInversed> struct scaleUp;
  template <class Scale> struct scaleUp<Scale, false>;
  public:
  using type = typename scaleUp <scale, useInversed> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 template <class Sum, class Power, class X, typename std :: make_unsigned <Type> :: type K>
	 struct logType<valueRatio<Type, Sign, Numerator, Denominator> > :: template step<Sum, Power, X, K, false>
 {
  private:
  using valueType = typename std :: make_unsigned <Type> :: type;
  constexpr const static valueType const0 = zero <valueType> :: value;
  constexpr const static valueType const1 = identity <valueType> :: value;
  constexpr const static valueType const2 = const1 + const1;
  constexpr const static bool kOverflow = (K > std :: numeric_limits <valueType> :: max() - const1);
  constexpr const static valueType nextK = kOverflow ? K : (K + const1);
  constexpr const static char sign = ((K % const2) == const0) ? '-' : '+';
  using frac = valueRatio<Type, sign, identity <valueType> :: value, K>;
  using element = typename multipliesType <frac, Power> :: type;
  using nextPower = typename multipliesType <Power, X> :: type;
  using nextSum = typename plusType <Sum, element> :: type;
  using cond = typename minusType <nextSum, Sum> :: type;
  constexpr const static bool nextFinal = //FIXME: Add check if is zero.
	  equalToValue <decltype(cond :: num), cond :: num, zero <decltype(cond :: num)> :: value> :: value;
  public:
  using type = typename step <nextSum, nextPower, X, nextK, nextFinal || kOverflow> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 template <class Sum, class Power, class X, typename std :: make_unsigned <Type> :: type K, bool isFinal>
	 template <class Scale, bool useInversed>
 struct logType<valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 step<Sum, Power, X, K, isFinal> :: scaleUp
 {
  private:
  using constant = typename ln2 <typename identity <Sum> :: type> :: type;
  using shift = typename multipliesType <Scale, constant> :: type;
  using result = typename plusType <Sum, shift> :: type;
  constexpr const static char resultSign = (result :: sign == '+') ? '-' : '+';
  public:
  using type = valueRatio<Type, resultSign, result :: num, result :: den>;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 template <class Sum, class Power, class X, typename std :: make_unsigned <Type> :: type K, bool isFinal>
	 template <class Scale>
 struct logType<valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 step<Sum, Power, X, K, isFinal> :: template scaleUp<Scale, false>
 {
  private:
  using constant = typename ln2 <typename identity <Sum> :: type> :: type;
  using shift = typename multipliesType <Scale, constant> :: type;
  public:
  using type = typename plusType <Sum, shift> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 constexpr typename logType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 log(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
inline constexpr typename crap :: logType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: log(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif
