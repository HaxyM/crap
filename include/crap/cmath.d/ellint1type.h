#ifndef CRAP_CMATH_ELLINT1TYPE
#define CRAP_CMATH_ELLINT1TYPE

namespace crap
{
 template <class, class> struct ellint1Type;
}

#include <cstdint>
#include <ratio>
#include <type_traits>

#include "../numbers.d/identity.h"
#include "../ratio.d/ellint1type.h"
#include "../ratio.d/identity.h"
#include "../utility.d/typecast.h"

namespace crap
{
 template <intmax_t NumeratorK, intmax_t DenominatorK, intmax_t NumeratorPhi, intmax_t DenominatorPhi>
	 struct ellint1Type<std :: ratio<NumeratorK, DenominatorK>, std :: ratio<NumeratorPhi, DenominatorPhi> >
 {
  private:
  using origK = std :: ratio<NumeratorK, DenominatorK>;
  using origPhi = std :: ratio<NumeratorPhi, DenominatorPhi>;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr static valueType int_1 = identity <valueType> :: value;
  using const1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using K = typename typeCast <origK> :: template onto <const1> :: type;
  using Phi = typename typeCast <origPhi> :: template onto <const1> :: type;
  using value = typename ellint1Type <K, Phi> :: type;
  public:
  using type = typename typeCast <value> :: template onto <origK> :: type;
 };

 template <intmax_t NumeratorK, intmax_t DenominatorK, intmax_t NumeratorPhi, intmax_t DenominatorPhi>
	 constexpr typename ellint1Type <std :: ratio<NumeratorK, DenominatorK>, std :: ratio<NumeratorPhi, DenominatorPhi> > :: type
	 ellint_1(std :: ratio<NumeratorK, DenominatorK>, std :: ratio<NumeratorPhi, DenominatorPhi>) noexcept;
}

template <intmax_t NumeratorK, intmax_t DenominatorK, intmax_t NumeratorPhi, intmax_t DenominatorPhi>
inline constexpr typename crap :: ellint1Type <std :: ratio<NumeratorK, DenominatorK>, std :: ratio<NumeratorPhi, DenominatorPhi> > :: type
crap :: ellint_1(std :: ratio<NumeratorK, DenominatorK>, std :: ratio<NumeratorPhi, DenominatorPhi>) noexcept
{
 return {};
}
#endif

