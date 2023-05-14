#include <cstddef>
#include <type_traits>

#include "identity.h"
#include "logtype.h"
#include "log2e.h"
#include "multipliestype.h"
#include "../cmath.d/log2type.h"

#ifndef CRAP_RATIO_LOG2TYPE
#define CRAP_RATIO_LOG2TYPE

namespace crap
{
 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct log2Type<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  static_assert(Sign == '+', "Value must be positive.");
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <passed> :: type;
  using log = typename logType <passed> :: type;
  public:
  using type = typename multipliesType <log, typename log2e <const1> :: type> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 constexpr typename log2Type <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 log2(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, Type Numerator, Type Denominator>
inline constexpr typename crap :: log2Type <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: log2(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

