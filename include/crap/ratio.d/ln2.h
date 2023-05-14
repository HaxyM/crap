#include <cstdint>
#include <type_traits>

#include "dividestype.h"
#include "identity.h"
#include "minustype.h"
#include "multipliestype.h"
#include "plustype.h"
#include "sqrt2.h"
#include "sqrttype.h"
#include "valueratio.h"
#include "zero.h"
#include "../numbers.d/ln2.h"
#include "../functional.d/equaltovalue.h"

#ifndef CRAP_RATIO_LN2
#define CRAP_RATIO_LN2

namespace crap
{
#ifdef UINT8_C
 template <char Sign, std :: uint8_t Numerator, std :: uint8_t Denominator>
	 struct ln2<valueRatio<std :: uint8_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint8_t, '+', UINT8_C(91), UINT8_C(127)>;
 };
#endif

#ifdef UINT16_C
 template <char Sign, std :: uint16_t Numerator, std :: uint16_t Denominator>
	 struct ln2<valueRatio<std :: uint16_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint16_t, '+', UINT16_C(3246), UINT16_C(4681)>;
 };
#endif

#ifdef UINT32_C
 template <char Sign, std :: uint32_t Numerator, std :: uint32_t Denominator>
	 struct ln2<valueRatio<std :: uint32_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint32_t, '+', UINT32_C(992348169), UINT32_C(1431655765)>;
 };
#endif

#ifdef UINT64_C
 template <char Sign, std :: uint64_t Numerator, std :: uint64_t Denominator>
	 struct ln2<valueRatio<std :: uint64_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint64_t, '+', UINT64_C(12786308645202655981), UINT64_C(18446744073709551615)>;
 };
#endif

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct ln2<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using initial = typename sqrt2 <passed> :: type;
  using const1 = typename identity <passed> :: type;
  using const2 = typename plusType <const1, const1> :: type;
  using product = typename dividesType <const2, typename plusType <const1, initial> :: type> :: type;
  using cond = typename minusType <initial, const1> :: type;
  constexpr const static bool nextFinal = //FIXME: Add check if is zero.
	  equalToValue <decltype(cond :: num), cond :: num, zero <decltype(cond :: num)> :: value> :: value;
  template <class Product, class Root, bool isFinal> struct step;
  template <class Product, class Root> struct step<Product, Root, true>;
  public:
  using type = typename step <product, initial, nextFinal> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class Product, class Root, bool isFinal>
	 struct ln2<valueRatio<Type, Sign, Numerator, Denominator> > :: step
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

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class Product, class Root>
	 struct ln2<valueRatio<Type, Sign, Numerator, Denominator> > :: template step<Product, Root, true>
 {
  using type = Product;
 };
}
#endif

