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
#include "sqrttype.h"
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
  using Root = typename dividesType <valueToBeUsed, scale> :: type;
  using const1 = typename identity <passed> :: type;
  using initArg1 = typename std :: conditional <useInversed, const1, Root> :: type;
  using initArg2 = typename std :: conditional <useInversed, Root, const1> :: type;
  using Product = typename minusType <initArg1, initArg2> :: type;
  template <class Product, class Root, bool isFinal> struct step;
  template <class Product, class Root> struct step<Product, Root, false>;
  public:
  using type = typename step <Product, Root, false> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 template <class Product, class Root, bool isFinal>
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
	 template <class Product, class Root>
	 struct logType<valueRatio<Type, Sign, Numerator, Denominator> > :: template step<Product, Root, false>
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using root = typename sqrtType <Root> :: type;
  using const1 = typename identity <passed> :: type;
  using const2 = typename plusType <const1, const1> :: type;
  using element = typename dividesType <const2, typename plusType <const1, root> :: type> :: type;
  using product = typename multipliesType <Product, element> :: type;
  using cond = typename minusType <product, Product> :: type;
  constexpr const static bool nextFinal = //FIXME: Add check if is zero.
	  equalToValue <decltype(cond :: num), cond :: num, zero <decltype(cond :: num)> :: value> :: value;
  public:
  using type = typename step <product, root, nextFinal> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 template <class Product, class Root, bool isFinal>
	 template <class Scale, bool useInversed>
 struct logType<valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 step<Product, Root, isFinal> :: scaleUp
 {
  private:
  using constant = typename ln2 <typename identity <Product> :: type> :: type;
  using shift = typename multipliesType <Scale, constant> :: type;
  public:
  using type = typename minusType <Product, shift> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 template <class Product, class Root, bool isFinal>
	 template <class Scale>
 struct logType<valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 step<Product, Root, isFinal> :: template scaleUp<Scale, false>
 {
  private:
  using constant = typename ln2 <typename identity <Product> :: type> :: type;
  using shift = typename multipliesType <Scale, constant> :: type;
  public:
  using type = typename plusType <Product, shift> :: type;
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

