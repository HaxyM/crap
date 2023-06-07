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
#include "../numeric.d/iotavalue.h"
#include "../numeric.d/partialsumtype.h"
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
  template <std :: size_t K> struct element;
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <passed> :: type;
  template <std :: size_t ... Ks> using combine =
	  typename partialSumType <multipliesType, const1, typename element <Ks> :: type...> :: template
	  type <plusType> :: type;
  public:
  using type = typename iotaValue <Order, std :: size_t, 1u> :: template type <combine> :: type;
 };

 template <unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 template <std :: size_t K>
 struct laguerreType <Order, valueRatio<Type, Sign, Numerator, Denominator> > :: element
 {
  private:
  using x = valueRatio<Type, Sign, Numerator, Denominator>;
  using kConst = typename typeCast <valueRatio<std :: size_t, '-', K, 1u> > :: template onto <x> :: type;
  using nConst = typename typeCast <valueRatio<unsigned int, '-', Order, 1u> > :: template onto <x> :: type;
  using const1 = typename identity <x> :: type;
  using arg1 = typename minusType <nConst, const1, kConst> :: type;
  using arg2 = typename dividesType <x, kConst, kConst> :: type;
  public:
  using type = typename multipliesType <arg1, arg2> :: type;
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

