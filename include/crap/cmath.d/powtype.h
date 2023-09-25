#ifndef CRAP_CMATH_POWTYPE
#define CRAP_CMATH_POWTYPE

namespace crap
{
 template <class, class> struct powType;
}

#include <cstdint>
#include <ratio>
#include <type_traits>

#include "../numbers.d/identity.h"
#include "../ratio.d/powtype.h"
#include "../ratio.d/identity.h"
#include "../utility.d/typecast.h"

namespace crap
{
 template <intmax_t NumeratorX, intmax_t DenominatorX, intmax_t NumeratorY, intmax_t DenominatorY>
	 struct powType<std :: ratio<NumeratorX, DenominatorX>, std :: ratio<NumeratorY, DenominatorY> >
 {
  private:
  using origX = typename contractType <std :: ratio<NumeratorX, DenominatorX> > :: type;
  using origY = typename contractType <std :: ratio<NumeratorY, DenominatorY> > :: type;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr static valueType int_1 = identity <valueType> :: value;
  using const1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using x = typename typeCast <origX> :: template onto <const1> :: type;
  using y = typename typeCast <origY> :: template onto <const1> :: type;
  using value = typename powType <x, y> :: type;
  public:
  using type = typename typeCast <value> :: template onto <origX> :: type;
 };

 template <intmax_t NumeratorX, intmax_t DenominatorX, class TypeY, TypeY Y>
	 struct powType<std :: ratio<NumeratorX, DenominatorX>, std :: integral_constant<TypeY, Y> >
 {
  private:
  using origX = typename contractType <std :: ratio<NumeratorX, DenominatorX> > :: type;
  using origY = std :: integral_constant<TypeY, Y>;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr static valueType int_1 = identity <valueType> :: value;
  using const1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using x = typename typeCast <origX> :: template onto <const1> :: type;
  using value = typename powType <x, origY> :: type;
  public:
  using type = typename typeCast <value> :: template onto <origX> :: type;
 };
 template <intmax_t NumeratorX, intmax_t DenominatorX, intmax_t NumeratorY, intmax_t DenominatorY>
	 constexpr typename powType <std :: ratio<NumeratorX, DenominatorX>, std :: ratio<NumeratorY, DenominatorY> > :: type
	 pow(std :: ratio<NumeratorX, DenominatorX>, std :: ratio<NumeratorY, DenominatorY>) noexcept;
}

template <intmax_t NumeratorX, intmax_t DenominatorX, intmax_t NumeratorY, intmax_t DenominatorY>
inline constexpr typename crap :: powType <std :: ratio<NumeratorX, DenominatorX>, std :: ratio<NumeratorY, DenominatorY> > :: type
crap :: pow(std :: ratio<NumeratorX, DenominatorX>, std :: ratio<NumeratorY, DenominatorY>) noexcept
{
 return {};
}
#endif

