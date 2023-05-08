#ifndef CRAP_RATIO_TRUNCTYPE
#define CRAP_RATIO_TRUNCTYPE

#include <type_traits>

#include "contracttype.h"
#include "valueratio.h"
#include "../cmath.d/trunctype.h"
#include "../numbers.d/identity.h"

namespace crap
{
 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct truncType<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using value = typename contractType <valueRatio<Type, Sign, Numerator, Denominator> > :: type;
  public:
  using type = valueRatio<Type, Sign, (value :: num / value :: den), identity <typename value :: valueType> :: value>;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 constexpr typename truncType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 trunc(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, Type Numerator, Type Denominator>
inline constexpr typename crap :: truncType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: trunc(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif
