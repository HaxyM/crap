#include <type_traits>

#include "identity.h"
#include "lesstype.h"
#include "multipliestype.h"
#include "negatetype.h"
#include "plustype.h"
#include "powtype.h"
#include "valueratio.h"
#include "../algorithm.d/sorttype.h"
#include "../cmath.d/hermitetype.h"
#include "../numeric.d/accumulatetype.h"
#include "../numeric.d/iotavalue.h"
#include "../utility.d/concatenatetype.h"
#include "../utility.d/reproducetype.h"
#include "../utility.d/typecast.h"

#ifndef CRAP_RATIO_HERMITETYPE
#define CRAP_RATIO_HERMITETYPE

namespace crap
{
 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct hermiteType<0u, valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  public:
  using type = typename identity <passed> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct hermiteType<1u, valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using x = valueRatio<Type, Sign, Numerator, Denominator>;
  public:
  using type = typename plusType <x, x> :: type;
 };

 template <unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 struct hermiteType<Order, valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  template <class CommonIntegralType, unsigned int Index> struct sumElement;
  template <class CommonIntegralType> struct sumElement<CommonIntegralType, 0u>;
  template <class CommonIntegralType> struct sumElement<CommonIntegralType, 1u>;
  using common_t = typename std :: common_type <unsigned int, Type> :: type;
  template <unsigned int ... Indices> using elements =
	  sortType<lessType, typename sumElement <common_t, Indices> :: type...>;
  template <class ... Elements> using reduce = accumulateType<plusType, Elements...>;
  template <unsigned int ... Indices> using combine =
	  typename elements <Indices...> :: template type<reduce>;
  constexpr const static unsigned int lastIndex = Order / 2u;
  using result =
	  typename iotaValue <lastIndex + 1u, unsigned int, 0u> :: template
	  type <combine> :: type;
  public:
  using type = typename typeCast <result> :: template
	  onto <valueRatio<Type, Sign, Numerator, Denominator> > :: type;
 };

 template <unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 template <class CommonIntegralType, unsigned int Index>
 struct hermiteType <Order, valueRatio<Type, Sign, Numerator, Denominator> > :: sumElement
 {
  private:
  constexpr const static CommonIntegralType xNum = static_cast<CommonIntegralType>(Numerator);
  constexpr const static CommonIntegralType xDen = static_cast<CommonIntegralType>(Denominator);
  using x = valueRatio<CommonIntegralType, Sign, xNum, xDen>;
  using x2 = typename plusType <x, x> :: type;
  constexpr const static CommonIntegralType n = static_cast<CommonIntegralType>(Order);
  constexpr const static CommonIntegralType i = static_cast<CommonIntegralType>(Index);
  constexpr const static CommonIntegralType const1 = identity <CommonIntegralType> :: value;
  template <CommonIntegralType SubIndex> using prod1Element =
	  valueRatio<CommonIntegralType, '+', n - SubIndex + const1, SubIndex>;
  template <CommonIntegralType SubIndex> using prod2Element =
	  valueRatio<CommonIntegralType, '+', n - i - SubIndex + const1, const1>;
  template <CommonIntegralType ... SubIndices> using prod1and2Elements =
	  typename concatenateType <prod1Element<SubIndices>...> :: template
	  with <prod2Element<SubIndices>...>;
  template <class ... Elements> using reduce = accumulateType<multipliesType, Elements...>;
  template <class ... Elements> using prodResult =
	  typename sortType <lessType, Elements...> :: template type <reduce> :: type;
  template <class ... x2s> using prodElements =
	  typename iotaValue <i, CommonIntegralType, const1> :: template
	  type <prod1and2Elements> :: template with <x2s...> :: template type<prodResult>;
  using result = typename reproduceType <n - i - i, x2> :: template type<prodElements>;
  constexpr const static char resultSign =
	  ((Index % 2u) == 0u) ? (result :: sign) : ((result :: sign == '+') ? '-' : '+');
  public:
  using type = valueRatio<CommonIntegralType, resultSign, result :: num, result :: den>;
 };

 template <unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 template <class CommonIntegralType>
 struct hermiteType <Order, valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 sumElement<CommonIntegralType, 0u>
 {
  private:
  constexpr const static CommonIntegralType xNum = static_cast<CommonIntegralType>(Numerator);
  constexpr const static CommonIntegralType xDen = static_cast<CommonIntegralType>(Denominator);
  using x = valueRatio<CommonIntegralType, Sign, xNum, xDen>;
  using x2 = typename plusType <x, x> :: type;
  constexpr const static CommonIntegralType nNum = static_cast<CommonIntegralType>(Order);
  using n = valueRatio<CommonIntegralType, '+', nNum, identity <CommonIntegralType> :: value>;
  public:
  using type = typename powType <x2, n> :: type;
 };

 template <unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 template <class CommonIntegralType>
 struct hermiteType <Order, valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 sumElement<CommonIntegralType, 1u>
 {
  private:
  constexpr const static CommonIntegralType xNum = static_cast<CommonIntegralType>(Numerator);
  constexpr const static CommonIntegralType xDen = static_cast<CommonIntegralType>(Denominator);
  using x = valueRatio<CommonIntegralType, Sign, xNum, xDen>;
  using x2 = typename plusType <x, x> :: type;
  constexpr const static CommonIntegralType n = static_cast<CommonIntegralType>(Order);
  constexpr const static CommonIntegralType const1 = identity <CommonIntegralType> :: value;
  using prod1 = valueRatio<CommonIntegralType, '+', n, const1>;
  using prod2 = valueRatio<CommonIntegralType, '+', n - const1, const1>;
  template <class ... Elements> using reduce = accumulateType<multipliesType, Elements...>;
  template <class ... x2s> using prodElements =
	  typename sortType <lessType, prod1, prod2, x2s...> :: template type <reduce> :: type;
  using result = typename reproduceType <n - const1 - const1, x2> :: template type<prodElements>;
  public:
  using type = typename negateType <result> :: type;
 };

 template <unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 constexpr typename hermiteType <Order, valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 hermite(std :: integral_constant<unsigned int, Order>, valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
inline constexpr typename crap :: hermiteType <Order, crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: hermite(std :: integral_constant<unsigned int, Order>, crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

