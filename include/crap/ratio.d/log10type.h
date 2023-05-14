#include <cstddef>
#include <type_traits>

#include "identity.h"
#include "logtype.h"
#include "log10e.h"
#include "multipliestype.h"
#include "../cmath.d/log10type.h"

#ifndef CRAP_RATIO_LOG10TYPE
#define CRAP_RATIO_LOG10TYPE

namespace crap
{
 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct log10Type<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  static_assert(Sign == '+', "Value must be positive.");
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <passed> :: type;
  using log = typename logType <passed> :: type;
  public:
  using type = typename multipliesType <log, typename log10e <const1> :: type> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 constexpr typename log10Type <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 log10(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, Type Numerator, Type Denominator>
inline constexpr typename crap :: log10Type <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: log10(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

