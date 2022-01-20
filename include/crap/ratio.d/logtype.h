#ifndef CRAP_RATIO_LOGTYPE
#define CRAP_RATIO_LOGTYPE

#include "identity.h"
#include "dividestype.h"
#include "minustype.h"
#include "multipliestype.h"
#include "plustype.h"
#include "valueratio.h"
#include "../cmath.d/logtype.h"
#include "../functional.d/dividestype.h"
#include "../functional.d/minustype.h"
#include "../functional.d/multipliestype.h"
#include "../functional.d/plustype.h"
#include "../numeric.d/identity.h"
#include "../numeric.d/innerproducttype.h"
#include "../numeric.d/iotavalue.h"
#include "../utility.d/reproducetype.h"

#include <cstddef>
#include <type_traits>

namespace crap
{
 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator, std :: size_t Steps>
	 struct logType<valueRatio<Type, Sign, Numerator, Denominator>, Steps>
 {
  private:
  static_assert(Sign == '+', "Value must be positive.");
  using valueType = typename std :: make_unsigned <Type> :: type;
  using z = valueRatio<Type, Sign, Numerator, Denominator>;
  using argument = typename dividesType <typename minusType <z, typename identity <z> :: type> :: type,
	typename plusType <z, typename identity <z> :: type> :: type> :: type;
  template <valueType N> using constant = valueRatio<Type, '+', identity <valueType> :: value, N>;
  template <std :: size_t N>
	  using power = typename reproduceType<N, argument> :: template type<multipliesType> :: type;
  template <valueType ... N> using constants = innerProductType<plusType, multipliesType, constant<N>...>;
  template <std :: size_t ... N>
	  using odds = typename constants <static_cast<valueType>(2u * N + 1u)...> :: template
	  with <power<2u * N + 1u>...> :: type;
  using half = plusType<argument, typename iotaValue <Steps, std :: size_t, 1u> :: template type<odds> >;
  public:
  using type = typename plusType <typename half :: type, typename half :: type> :: type;
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
