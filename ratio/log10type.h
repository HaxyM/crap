#ifndef CRAP_RATIO_LOG10TYPE
#define CRAP_RATIO_LOG10TYPE

#include "logtype.h"
#include "dividestype.h"
#include "valueratio.h"
#include "../cmath/log10type.h"
#include "../functional/dividestype.h"
#include "../numeric/identity.h"

#include <cstddef>
#include <type_traits>

namespace crap
{
 template <class Type, typename std :: make_signed <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator, std :: size_t Steps>
	 struct log10Type<valueRatio<Type, Numerator, Denominator>, Steps>
 {
  private:
  using numeratorType = typename std :: make_signed <Type> :: type;
  using denominatorType = typename std :: make_unsigned <Type> :: type;
  using base = typename logType <valueRatio<Type, static_cast<numeratorType>(10), identity <denominatorType> :: value>, Steps> :: type;
  using ln = typename logType <valueRatio<Type, Numerator, Denominator>, Steps> :: type;
  public:
  using type = typename dividesType <ln, base> :: type;
 };

 template <class Type, typename std :: make_signed <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 constexpr typename log10Type <valueRatio<Type, Numerator, Denominator> > :: type
	 log10(valueRatio<Type, Numerator, Denominator>) noexcept;
}

template <class Type, typename std :: make_signed <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
inline constexpr typename crap :: log10Type <crap :: valueRatio<Type, Numerator, Denominator> > :: type
crap :: log10(crap :: valueRatio<Type, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

