#ifndef CRAP_RATIO_EXPTYPE
#define CRAP_RATIO_EXPTYPE

#include "identity.h"
#include "multipliestype.h"
#include "plustype.h"
#include "valueratio.h"
#include "../cmath/exptype.h"
#include "../numeric/identity.h"
#include "../numeric/innerproducttype.h"
#include "../numeric/iotavalue.h"
#include "../utility/reproducetype.h"

#include <cstddef>
#include <ratio>
#include <type_traits>

namespace crap
{
 template <class Type, typename std :: make_signed <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator, std :: size_t Steps>
	 struct expType<valueRatio<Type, Numerator, Denominator>, Steps>
 {
  private:
  using numeratorType = typename std :: make_signed <Type> :: type;
  using denominatorType = typename std :: make_unsigned <Type> :: type;
  template <denominatorType N> using constant = valueRatio<Type, identity <numeratorType> :: value, N>;
  template <std :: size_t N> using reproduce = reproduceType<N, valueRatio<Type, Numerator, Denominator> >;
  template <denominatorType ... N>
	  using constants = innerProductType<multipliesType, multipliesType, constant<N>...>;
  template <std :: size_t N> using at = typename reproduce <N> :: template
	  type <iotaValue <N, denominatorType, 1u> :: template type <constants> :: template with> :: type;
  template <std :: size_t ... N>
	  using sum = typename plusType <typename identity<valueRatio<Type, Numerator, Denominator> > :: type, at<N>...> :: type;
  public:
  using type = typename iotaValue <Steps, std :: size_t, 1u> :: template type<sum>;
 };
}
#endif

