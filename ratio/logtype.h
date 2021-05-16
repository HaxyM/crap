#ifndef CRAP_RATIO_LOGTYPE
#define CRAP_RATIO_LOGTYPE

#include "identity.h"
#include "dividestype.h"
#include "minustype.h"
#include "multipliestype.h"
#include "plustype.h"
#include "valueratio.h"
#include "../cmath/logtype.h"
#include "../functional/dividestype.h"
#include "../functional/minustype.h"
#include "../functional/multipliestype.h"
#include "../functional/plustype.h"
#include "../numeric/identity.h"
#include "../numeric/innerproducttype.h"
#include "../numeric/iotavalue.h"
#include "../utility/reproducetype.h"

#include <cstddef>
#include <type_traits>

namespace crap
{
 template <class Type, typename std :: make_signed <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator, std :: size_t Steps>
	 struct logType<valueRatio<Type, Numerator, Denominator>, Steps>
 {
  private:
  using numeratorType = typename std :: make_signed <Type> :: type;
  using denominatorType = typename std :: make_unsigned <Type> :: type;
  using z = valueRatio<Type, Numerator, Denominator>;
  using argument = typename dividesType <typename minusType <z, typename identity <z> :: type> :: type,
	typename plusType <z, typename identity <z> :: type> :: type> :: type;
  template <denominatorType N> using constant = valueRatio<Type, identity <numeratorType> :: value, N>;
  template <std :: size_t N>
	  using power = typename reproduceType<N, argument> :: template type<multipliesType> :: type;
  template <denominatorType ... N> using constants = innerProductType<plusType, multipliesType, constant<N>...>;
  template <std :: size_t ... N>
	  using odds = typename constants <static_cast<denominatorType>(2u * N + 1u)...> :: template
	  with <power<2u * N + 1u>...> :: type;
  using half = plusType<argument, typename iotaValue <Steps, std :: size_t, 1u> :: template type<odds> >;
  public:
  using type = typename plusType <typename half :: type, typename half :: type> :: type;
 };

 template <class Type, typename std :: make_signed <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 constexpr typename logType <valueRatio<Type, Numerator, Denominator> > :: type
	 log(valueRatio<Type, Numerator, Denominator>) noexcept;
}

template <class Type, typename std :: make_signed <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
inline constexpr typename crap :: logType <crap :: valueRatio<Type, Numerator, Denominator> > :: type
crap :: log(crap :: valueRatio<Type, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

