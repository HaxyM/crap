#ifndef CRAP_RATIO_EXPTYPE
#define CRAP_RATIO_EXPTYPE

#include "identity.h"
#include "multipliestype.h"
#include "plustype.h"
#include "valueratio.h"
#include "../cmath.d/exptype.h"
#include "../numbers.d/identity.h"
#include "../numeric.d/innerproducttype.h"
#include "../numeric.d/iotavalue.h"
#include "../utility.d/reproducetype.h"

#include <cstddef>
#include <ratio>
#include <type_traits>

namespace crap
{
 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator, std :: size_t Steps>
	 struct expType<valueRatio<Type, Sign, Numerator, Denominator>, Steps>
 {
  private:
  using valueType = typename std :: make_unsigned <Type> :: type;
  template <valueType N> using constant = valueRatio<Type, '+', identity <valueType> :: value, N>;
  template <std :: size_t N> using reproduce = reproduceType<N, valueRatio<Type, Sign, Numerator, Denominator> >;
  template <valueType ... N>
	  using constants = innerProductType<multipliesType, multipliesType, constant<N>...>;
  template <std :: size_t N> using at = typename reproduce <N> :: template
	  type <iotaValue <N, valueType, 1u> :: template type <constants> :: template with> :: type;
  template <std :: size_t ... N>
	  using sum = typename plusType <typename identity<valueRatio<Type, Sign, Numerator, Denominator> > :: type, at<N>...> :: type;
  public:
  using type = typename iotaValue <Steps, std :: size_t, 1u> :: template type<sum>;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 constexpr typename expType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 exp(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
inline constexpr typename crap :: expType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: exp(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif
