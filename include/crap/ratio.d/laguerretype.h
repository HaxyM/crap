#include <cstddef>
#include <cstdint>
#include <type_traits>

#include "dividestype.h"
#include "identity.h"
#include "minustype.h"
#include "multipliestype.h"
#include "plustype.h"
#include "valueratio.h"
#include "../cmath.d/laguerretype.h"
#include "../utility.d/typecast.h"

#ifndef CRAP_RATIO_LAGUERRETYPE
#define CRAP_RATIO_LAGUERRETYPE

namespace crap
{
 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct laguerreType<0u, valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  public:
  using type = typename identity <passed> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct laguerreType<1u, valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using x = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <x> :: type;
  public:
  using type = typename minusType <const1, x> :: type;
 };

 template <unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 struct laguerreType<Order, valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using x = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <x> :: type;
  using kConst = typename typeCast <valueRatio<unsigned int, '+', (Order - 1u), 1u> > :: template onto <x> :: type;
  using arg1Part1 = typename plusType <kConst, kConst, const1> :: type;
  using arg1Part2 = typename minusType <arg1Part1, x> :: type;
  using arg1 = typename multipliesType <arg1Part1, typename laguerreType <(Order - 1u), x> :: type> :: type;
  using arg2 = typename multipliesType <kConst, typename laguerreType <(Order - 2u), x> :: type> :: type;
  using num = typename minusType <arg1, arg2> :: type;
  using den = typename plusType <kConst, const1> :: type;
  public:
  using type = typename dividesType <num, den> :: type;
 };

 template <unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 constexpr typename laguerreType <Order, valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 laguerre(std :: integral_constant<unsigned int, Order>, valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
inline constexpr typename crap :: laguerreType <Order, crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: laguerre(std :: integral_constant<unsigned int, Order>, crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

