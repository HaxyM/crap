#ifndef CRAP_CMATH_COMPELLINT3TYPE
#define CRAP_CMATH_COMPELLINT3TYPE

namespace crap
{
 template <class, class> struct compEllint3Type;
}

#include <cstdint>
#include <ratio>
#include <type_traits>

#include "../numbers.d/identity.h"
#include "../ratio.d/compellint3type.h"
#include "../ratio.d/identity.h"
#include "../utility.d/typecast.h"

namespace crap
{
 template <intmax_t NumeratorK, intmax_t DenominatorK, intmax_t NumeratorNu, intmax_t DenominatorNu>
	 struct compEllint3Type<std :: ratio<NumeratorK, DenominatorK>, std :: ratio<NumeratorNu, DenominatorNu> >
 {
  private:
  using origK = std :: ratio<NumeratorK, DenominatorK>;
  using origNu = std :: ratio<NumeratorNu, DenominatorNu>;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr static valueType int_1 = identity <valueType> :: value;
  using const1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using K = typename typeCast <origK> :: template onto <const1> :: type;
  using Nu = typename typeCast <origNu> :: template onto <const1> :: type;
  using value = typename compEllint3Type <K, Nu> :: type;
  public:
  using type = typename typeCast <value> :: template onto <origK> :: type;
 };

 template <intmax_t NumeratorK, intmax_t DenominatorK, intmax_t NumeratorNu, intmax_t DenominatorNu>
	 constexpr typename compEllint3Type <std :: ratio<NumeratorK, DenominatorK>, std :: ratio<NumeratorNu, DenominatorNu> > :: type
	 comp_ellint_3(std :: ratio<NumeratorK, DenominatorK>, std :: ratio<NumeratorNu, DenominatorNu>) noexcept;
}

template <intmax_t NumeratorK, intmax_t DenominatorK, intmax_t NumeratorNu, intmax_t DenominatorNu>
inline constexpr typename crap :: compEllint3Type <std :: ratio<NumeratorK, DenominatorK>, std :: ratio<NumeratorNu, DenominatorNu> > :: type
crap :: comp_ellint_3(std :: ratio<NumeratorK, DenominatorK>, std :: ratio<NumeratorNu, DenominatorNu>) noexcept
{
 return {};
}
#endif

