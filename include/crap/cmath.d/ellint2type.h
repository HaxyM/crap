#ifndef CRAP_CMATH_ELLINT2TYPE
#define CRAP_CMATH_ELLINT2TYPE

namespace crap
{
 template <class, class> struct ellint2Type;
}

#include <cstdint>
#include <ratio>
#include <type_traits>

#include "../numbers.d/identity.h"
#include "../ratio.d/ellint2type.h"
#include "../ratio.d/identity.h"
#include "../utility.d/typecast.h"

namespace crap
{
 template <intmax_t NumeratorK, intmax_t DenominatorK, intmax_t NumeratorPhi, intmax_t DenominatorPhi>
	 struct ellint2Type<std :: ratio<NumeratorK, DenominatorK>, std :: ratio<NumeratorPhi, DenominatorPhi> >
 {
  private:
  using origK = std :: ratio<NumeratorK, DenominatorK>;
  using origPhi = std :: ratio<NumeratorPhi, DenominatorPhi>;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr static valueType int_1 = identity <valueType> :: value;
  using const1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using K = typename typeCast <origK> :: template onto <const1> :: type;
  using Phi = typename typeCast <origPhi> :: template onto <const1> :: type;
  using value = typename ellint2Type <K, Phi> :: type;
  public:
  using type = typename typeCast <value> :: template onto <origK> :: type;
 };

 template <intmax_t NumeratorK, intmax_t DenominatorK, intmax_t NumeratorPhi, intmax_t DenominatorPhi>
	 constexpr typename ellint2Type <std :: ratio<NumeratorK, DenominatorK>, std :: ratio<NumeratorPhi, DenominatorPhi> > :: type
	 ellint_2(std :: ratio<NumeratorK, DenominatorK>, std :: ratio<NumeratorPhi, DenominatorPhi>) noexcept;
}

template <intmax_t NumeratorK, intmax_t DenominatorK, intmax_t NumeratorPhi, intmax_t DenominatorPhi>
inline constexpr typename crap :: ellint2Type <std :: ratio<NumeratorK, DenominatorK>, std :: ratio<NumeratorPhi, DenominatorPhi> > :: type
crap :: ellint_2(std :: ratio<NumeratorK, DenominatorK>, std :: ratio<NumeratorPhi, DenominatorPhi>) noexcept
{
 return {};
}
#endif

