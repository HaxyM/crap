#include <cstdint>
#include <type_traits>

#include "dividestype.h"
#include "identity.h"
#include "ln2.h"
#include "minustype.h"
#include "multipliestype.h"
#include "plustype.h"
#include "sqrt2.h"
#include "sqrttype.h"
#include "valueratio.h"
#include "zero.h"
#include "../numbers.d/ln10.h"
#include "../functional.d/equaltovalue.h"

#ifndef CRAP_RATIO_LN10
#define CRAP_RATIO_LN10

namespace crap
{
#ifdef UINT8_C
 template <char Sign, typename std :: make_unsigned <std :: int8_t> :: type Numerator, typename std :: make_unsigned <std :: int8_t> :: type Denominator>
	 struct ln10<valueRatio<std :: int8_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: int8_t, '+', UINT8_C(255), UINT8_C(106)>;
 };

 template <char Sign, typename std :: make_unsigned <std :: uint8_t> :: type Numerator, typename std :: make_unsigned <std :: uint8_t> :: type Denominator>
	 struct ln10<valueRatio<std :: uint8_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint8_t, '+', UINT8_C(255), UINT8_C(106)>;
 };
#endif

#ifdef UINT16_C
 template <char Sign, typename std :: make_unsigned <std :: int16_t> :: type Numerator, typename std :: make_unsigned <std :: int16_t> :: type Denominator>
	 struct ln10<valueRatio<std :: int16_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: int16_t, '+', UINT16_C(13107), UINT16_C(5690)>;
 };

 template <char Sign, typename std :: make_unsigned <std :: uint16_t> :: type Numerator, typename std :: make_unsigned <std :: uint16_t> :: type Denominator>
	 struct ln10<valueRatio<std :: uint16_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint16_t, '+', UINT16_C(13107), UINT16_C(5690)>;
 };
#endif

#ifdef UINT32_C
 template <char Sign, typename std :: make_unsigned <std :: int32_t> :: type Numerator, typename std :: make_unsigned <std :: int32_t> :: type Denominator>
	 struct ln10<valueRatio<std :: int32_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: int32_t, '+', UINT32_C(4294967295), UINT32_C(1865280574)>;
 };

 template <char Sign, typename std :: make_unsigned <std :: uint32_t> :: type Numerator, typename std :: make_unsigned <std :: uint32_t> :: type Denominator>
	 struct ln10<valueRatio<std :: uint32_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint32_t, '+', UINT32_C(4294967295), UINT32_C(1865280574)>;
 };
#endif

#ifdef UINT64_C
 template <char Sign, typename std :: make_unsigned <std :: int64_t> :: type Numerator, typename std :: make_unsigned <std :: int64_t> :: type Denominator>
	 struct ln10<valueRatio<std :: int64_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: int64_t, '+', UINT64_C(9223372036854775807), UINT64_C(4005659580146785282)>;
 };

 template <char Sign, typename std :: make_unsigned <std :: uint64_t> :: type Numerator, typename std :: make_unsigned <std :: uint64_t> :: type Denominator>
	 struct ln10<valueRatio<std :: uint64_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint64_t, '+', UINT64_C(9223372036854775807), UINT64_C(4005659580146785282)>;
 };
#endif

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct ln10<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <passed> :: type;
  using const4 = typename plusType <const1, const1, const1, const1> :: type;
  using const5 = typename plusType <const1, const1, const1, const1, const1> :: type;
  using root = typename dividesType <const5, const4> :: type;
  using product = typename minusType <root, const1> :: type;
  template <class Product, class Root, bool isFinal> struct step;
  template <class Product, class Root> struct step<Product, Root, true>;
  public:
  using type = typename step <product, root, false> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 template <class Product, class Root, bool isFinal>
	 struct ln10<valueRatio<Type, Sign, Numerator, Denominator> > :: step
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
	 template <class Product, class Root>
	 struct ln10<valueRatio<Type, Sign, Numerator, Denominator> > :: template step<Product, Root, true>
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <passed> :: type;
  using const3 = typename plusType <const1, const1, const1> :: type;
  using shift = typename multipliesType <const3, typename ln2 <const1> :: type> :: type;
  public:
  using type = typename plusType <Product, shift> :: type;
 };
}
#endif

