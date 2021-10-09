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
 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator, std :: size_t Steps>
	 struct log10Type<valueRatio<Type, Sign, Numerator, Denominator>, Steps>
 {
  private:
  using valueType = typename std :: make_unsigned <Type> :: type;
  using base = typename logType <valueRatio<Type, '+', static_cast<valueType>(10), identity <valueType> :: value>, Steps> :: type;
  using ln = typename logType <valueRatio<Type, Sign, Numerator, Denominator>, Steps> :: type;
  public:
  using type = typename dividesType <ln, base> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 constexpr typename log10Type <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 log10(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
inline constexpr typename crap :: log10Type <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: log10(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif
