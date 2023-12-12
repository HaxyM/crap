#include <type_traits>

#include "identity.h"
#include "lesstype.h"
#include "minustype.h"
#include "multipliestype.h"
#include "plustype.h"
#include "valueratio.h"
#include "../algorithm.d/sorttype.h"
#include "../cmath.d/assoclaguerretype.h"
#include "../numeric.d/accumulatetype.h"
#include "../numeric.d/iotavalue.h"
#include "../utility.d/concatenatetype.h"
#include "../utility.d/typecast.h"

#ifndef CRAP_RATIO_ASSOCLAGUERRETYPE
#define CRAP_RATIO_ASSOCLAGUERRETYPE

namespace crap
{
 template <unsigned int Alpha, class Type, char Sign, Type Numerator, Type Denominator>
	 struct assocLaguerreType<0u, Alpha, valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  public:
  using type = typename identity <passed> :: type;
 };

 template <unsigned int Alpha, class Type, char Sign, Type Numerator, Type Denominator>
	 struct assocLaguerreType<1u, Alpha, valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using common_t = typename std :: common_type <unsigned int, Type> :: type;
  using const1 = valueRatio<common_t, '+', identity <common_t> :: value, identity <common_t> :: value>;
  using x = typename typeCast <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	  onto <const1> :: type;
  using mAlpha = valueRatio<common_t, '-', static_cast<common_t>(Alpha), static_cast<common_t>(1u)>;
  using result = typename minusType <const1, mAlpha, x> :: type;
  public:
  using type = typename typeCast <result> :: template
	  onto <valueRatio<Type, Sign, Numerator, Denominator> > :: type;
 };

 template <unsigned int Order, unsigned int Alpha, class Type, char Sign, Type Numerator, Type Denominator>
	 struct assocLaguerreType<Order, Alpha, valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  template <class CommonIntegralType, unsigned int Index> struct sumElement;
  template <class CommonIntegralType> struct sumElement<CommonIntegralType, 0u>;
  template <class CommonIntegralType> struct sumElement<CommonIntegralType, Order>;
  using common_t = typename std :: common_type <unsigned int, Type> :: type;
  template <unsigned int Index> using element = sumElement<common_t, Index>;
  template <class ... Elements> using reduce = accumulateType<plusType, Elements...>;
  template <unsigned int ... Indices> using sum =
	  typename sortType<lessType, typename element <Indices> :: type...> :: template type<reduce>;
  using result =
	  typename iotaValue <Order + 1u, unsigned int, 0u> :: template
	  type <sum> :: type;
  public:
  using type = typename typeCast <result> :: template
	  onto <valueRatio<Type, Sign, Numerator, Denominator> > :: type;
 };

 template <unsigned int Order, unsigned int Alpha, class Type, char Sign, Type Numerator, Type Denominator>
	 template <class CommonIntegralType, unsigned int Index>
 struct assocLaguerreType <Order, Alpha, valueRatio<Type, Sign, Numerator, Denominator> > :: sumElement
 {
  private:
  constexpr const static CommonIntegralType xNum = static_cast<CommonIntegralType>(Numerator);
  constexpr const static CommonIntegralType xDen = static_cast<CommonIntegralType>(Denominator);
  constexpr const static CommonIntegralType nNum = static_cast<CommonIntegralType>(Order);
  constexpr const static CommonIntegralType aNum = static_cast<CommonIntegralType>(Alpha);
  constexpr const static CommonIntegralType const1 = identity <CommonIntegralType> :: value;
  using x = valueRatio<CommonIntegralType, Sign, xNum, xDen>;
  template <CommonIntegralType SubIndex> using prod1elem1 =
	  valueRatio<CommonIntegralType, '+', const1, SubIndex>;
  template <CommonIntegralType SubIndex> using prod1elem =
	  typename multipliesType <x, prod1elem1<SubIndex> > :: type;
  template <CommonIntegralType SubIndex> using prod2elem1 =
	  valueRatio<CommonIntegralType, '+', aNum, SubIndex>;
  template <CommonIntegralType SubIndex> using prod2elem2 =
	  valueRatio<CommonIntegralType, '+', nNum - SubIndex + const1, SubIndex>;
  template <CommonIntegralType SubIndex> using prod2elem =
	  typename plusType <prod2elem1<SubIndex>, prod2elem2<SubIndex> > :: type;
  template <class ... Elements> using reduce = accumulateType<multipliesType, Elements...>;
  template <class ... Elements> using prodElements =
	  typename sortType <lessType, Elements...> :: template type <reduce> :: type;
  template <CommonIntegralType ... SubIndices> using prod1Elements =
	  concatenateType<prod1elem<SubIndices>...>;
  template <CommonIntegralType ... SubIndices> using prod2Elements =
	  typename iotaValue<Order - Index, CommonIntegralType, 1u> :: template
	  type <prod1Elements> :: template
	  with <prod2elem<SubIndices>...> :: template
	  type<prodElements>;
  using result = typename iotaValue <Index, CommonIntegralType, 1u> :: template
	  type<prod2Elements>;
  constexpr const static char resultSign =
	  (Index % 2u == 0u) ? result :: sign : (result :: sign == '+' ? '-' : '+'); 
  public:
  using type = valueRatio<CommonIntegralType, resultSign, result :: num, result :: den>;
 };

 template <unsigned int Order, unsigned int Alpha, class Type, char Sign, Type Numerator, Type Denominator>
	 template <class CommonIntegralType>
 struct assocLaguerreType <Order, Alpha, valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 sumElement<CommonIntegralType, 0u>
 {
  private:
  constexpr const static CommonIntegralType xNum = static_cast<CommonIntegralType>(Numerator);
  constexpr const static CommonIntegralType xDen = static_cast<CommonIntegralType>(Denominator);
  using x = valueRatio<CommonIntegralType, Sign, xNum, xDen>;
  template <CommonIntegralType SubIndex> using elem1 =
	  valueRatio<CommonIntegralType, '+', identity <CommonIntegralType> :: value, SubIndex>;
  template <CommonIntegralType SubIndex> using elem =
	  typename multipliesType <x, elem1<SubIndex> > :: type;
  template <class ... Elements> using reduce = accumulateType<multipliesType, Elements...>;
  template <CommonIntegralType ... SubIndices> using prodElements =
	  typename sortType <lessType, elem<SubIndices>...> :: template type <reduce> :: type;
  public:
  using type = typename iotaValue <Order, CommonIntegralType, 1u> :: template type<prodElements>;
 };

 template <unsigned int Order, unsigned int Alpha, class Type, char Sign, Type Numerator, Type Denominator>
	 template <class CommonIntegralType>
 struct assocLaguerreType <Order, Alpha, valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 sumElement<CommonIntegralType, Order>
 {
  private:
  constexpr const static CommonIntegralType nNum = static_cast<CommonIntegralType>(Order);
  constexpr const static CommonIntegralType aNum = static_cast<CommonIntegralType>(Alpha);
  constexpr const static CommonIntegralType const1 = identity <CommonIntegralType> :: value;
  template <CommonIntegralType SubIndex> using elem1 =
	  valueRatio<CommonIntegralType, '+', aNum, SubIndex>;
  template <CommonIntegralType SubIndex> using elem2 =
	  valueRatio<CommonIntegralType, '+', nNum - SubIndex + const1, SubIndex>;
  template <CommonIntegralType SubIndex> using elem =
	  typename plusType <elem1<SubIndex>, elem2<SubIndex> > :: type;
  template <class ... Elements> using reduce = accumulateType<multipliesType, Elements...>;
  template <CommonIntegralType ... SubIndices> using prodElements =
	  typename sortType <lessType, elem<SubIndices>...> :: template type <reduce> :: type;
  using result = typename iotaValue <Order, CommonIntegralType, 1u> :: template type<prodElements>;
  constexpr const static char resultSign =
	  (Order % 2u == 0u) ? result :: sign : (result :: sign == '+' ? '-' : '+'); 
  public:
  using type = typename iotaValue <Order, CommonIntegralType, 1u> :: template type<prodElements>;
 };

 template <unsigned int Order, unsigned int Alpha, class Type, char Sign, Type Numerator, Type Denominator>
	 constexpr typename assocLaguerreType <Order, Alpha, valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 assoc_laguerre(std :: integral_constant<unsigned int, Order>, std :: integral_constant<unsigned int, Alpha>, valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <unsigned int Order, unsigned int Alpha, class Type, char Sign, Type Numerator, Type Denominator>
inline constexpr typename crap :: assocLaguerreType <Order, Alpha, crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: assoc_laguerre(std :: integral_constant<unsigned int, Order>, std :: integral_constant<unsigned int, Alpha>, crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

