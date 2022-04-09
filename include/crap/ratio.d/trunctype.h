#ifndef CRAP_RATIO_TRUNCTYPE
#define CRAP_RATIO_TRUNCTYPE

#include <type_traits>

#include "contracttype.h"
#include "valueratio.h"
#include "../cmath.d/trunctype.h"
#include "../numeric.d/identity.h"

namespace crap
{
 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct truncType<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using value = typename contractType <valueRatio<Type, Sign, Numerator, Denominator> > :: type;
  public:
  using type = valueRatio<Type, Sign, (value :: num / value :: den), identity <typename value :: denominatorType> :: value>;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 constexpr typename truncType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 trunc(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
inline constexpr typename crap :: truncType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: trunc(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif
