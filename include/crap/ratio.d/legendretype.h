#include <type_traits>

#include "dividestype.h"
#include "identity.h"
#include "lesstype.h"
#include "multipliestype.h"
#include "negatetype.h"
#include "plustype.h"
#include "powtype.h"
#include "valueratio.h"
#include "../algorithm.d/sorttype.h"
#include "../cmath.d/legendretype.h"
#include "../numeric.d/accumulatetype.h"
#include "../numeric.d/iotavalue.h"
#include "../utility.d/concatenatetype.h"
#include "../utility.d/reproducetype.h"
#include "../utility.d/typecast.h"

#ifndef CRAP_RATIO_LEGENDRETYPE
#define CRAP_RATIO_LEGENDRETYPE

namespace crap
{
 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct legendreType<0u, valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  public:
  using type = typename identity <passed> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct legendreType<1u, valueRatio<Type, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<Type, Sign, Numerator, Denominator>;
 };

 template <unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 struct legendreType<Order, valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  template <class CommonIntegralType, unsigned int Index, bool lastEpmty> struct sumElement;
  template <class CommonIntegralType, unsigned int Index> struct sumElement<CommonIntegralType, Index, false>;
  template <class CommonIntegralType, unsigned int Index> struct sumElement<CommonIntegralType, Index, true>;
  template <class CommonIntegralType> struct sumElement<CommonIntegralType, 0u, false>;
  using common_t = typename std :: common_type <unsigned int, Type> :: type;
  template <unsigned int Index> using element = sumElement<common_t, Index, (Order - Index - Index) == 0u>;
  template <class ... Elements> using reduce = accumulateType<plusType, Elements...>;
  template <unsigned int ... Indices> using sum =
	  typename sortType<lessType, typename element <Indices> :: type...> :: template type<reduce>;
  constexpr const static unsigned int lastIndex = Order / 2u;
  using result =
	  typename iotaValue <lastIndex + 1u, unsigned int, 0u> :: template
	  type <sum> :: type;
  public:
  using type = typename typeCast <result> :: template
	  onto <valueRatio<Type, Sign, Numerator, Denominator> > :: type;
 };

 template <unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 template <class CommonIntegralType, unsigned int Index>
 struct legendreType <Order, valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 sumElement<CommonIntegralType, Index, false>
 {
  private:
  constexpr const static CommonIntegralType xNum = static_cast<CommonIntegralType>(Numerator);
  constexpr const static CommonIntegralType xDen = static_cast<CommonIntegralType>(Denominator);
  using x = valueRatio<CommonIntegralType, Sign, xNum, xDen>;
  using const1 = typename identity <x> :: type;
  using const2 = typename plusType <const1, const1> :: type;
  using constHalf = typename dividesType <const1, const2> :: type;
  constexpr const static CommonIntegralType nNum = static_cast<CommonIntegralType>(Order);
  constexpr const static CommonIntegralType kNum = static_cast<CommonIntegralType>(Index);
  template <CommonIntegralType SubIndex> using prod1elem1 =
	  valueRatio<CommonIntegralType, '+', (nNum - kNum + SubIndex), (SubIndex + SubIndex)>;
  template <CommonIntegralType SubIndex> using prod1elem =
	  typename multipliesType <constHalf, prod1elem1<SubIndex> > :: type;
  template <CommonIntegralType SubIndex> using prod2elem1 =
	  valueRatio<CommonIntegralType, '+', nNum, (SubIndex + SubIndex)>;
  template <CommonIntegralType SubIndex> using prod2elem2 =
	  typename plusType <constHalf, prod2elem1<SubIndex> > :: type;
  template <CommonIntegralType SubIndex> using prod2elem =
	  typename multipliesType <x, prod2elem2<SubIndex> > :: type;
  template <class ... Elements> using reduce = accumulateType<multipliesType, Elements...>;
  template <class ... Elements> using prodElements =
	  typename sortType <lessType, Elements...> :: template type <reduce> :: type;
  template <CommonIntegralType ... SubIndices> using prod1Elements = concatenateType<prod1elem<SubIndices>...>;
  template <CommonIntegralType ... SubIndices> using prod2Elements =
	  typename iotaValue<Index, CommonIntegralType, 1u> :: template
	  type <prod1Elements> :: template
	  with <prod2elem<SubIndices>...> :: template
	  type<prodElements>;
  using result = typename iotaValue <Order - Index - Index, CommonIntegralType, 1u> :: template
	  type<prod2Elements>;
  constexpr const static char resultSign =
	  (Index % 2u == 0u) ? result :: sign : (result :: sign == '+' ? '-' : '+'); 
  public:
  using type = valueRatio<CommonIntegralType, resultSign, result :: num, result :: den>;
 };

 template <unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 template <class CommonIntegralType, unsigned int Index>
 struct legendreType <Order, valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 sumElement<CommonIntegralType, Index, true>
 {
  private:
  constexpr const static CommonIntegralType xNum = static_cast<CommonIntegralType>(Numerator);
  constexpr const static CommonIntegralType xDen = static_cast<CommonIntegralType>(Denominator);
  using x = valueRatio<CommonIntegralType, Sign, xNum, xDen>;
  using const1 = typename identity <x> :: type;
  using const2 = typename plusType <const1, const1> :: type;
  using constHalf = typename dividesType <const1, const2> :: type;
  constexpr const static CommonIntegralType nNum = static_cast<CommonIntegralType>(Order);
  constexpr const static CommonIntegralType kNum = static_cast<CommonIntegralType>(Index);
  template <CommonIntegralType SubIndex> using elem1 =
	  valueRatio<CommonIntegralType, '+', (nNum - kNum + SubIndex), (SubIndex + SubIndex)>;
  template <CommonIntegralType SubIndex> using elem =
	  typename multipliesType <constHalf, elem1<SubIndex> > :: type;
  template <class ... Elements> using reduce = accumulateType<multipliesType, Elements...>;
  template <CommonIntegralType ... SubIndices> using prodElements =
	  typename sortType <lessType, elem<SubIndices>...> :: template type <reduce> :: type;
  using result = typename iotaValue <Index, CommonIntegralType, 1u> :: template type<prodElements>;
  constexpr const static char resultSign =
	  (Index % 2u == 0u) ? result :: sign : (result :: sign == '+' ? '-' : '+'); 
  public:
  using type = valueRatio<CommonIntegralType, resultSign, result :: num, result :: den>;
 };

 template <unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 template <class CommonIntegralType>
 struct legendreType <Order, valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 sumElement<CommonIntegralType, 0u, false>
 {
  private:
  constexpr const static CommonIntegralType xNum = static_cast<CommonIntegralType>(Numerator);
  constexpr const static CommonIntegralType xDen = static_cast<CommonIntegralType>(Denominator);
  using x = valueRatio<CommonIntegralType, Sign, xNum, xDen>;
  using const1 = typename identity <x> :: type;
  using const2 = typename plusType <const1, const1> :: type;
  using constHalf = typename dividesType <const1, const2> :: type;
  constexpr const static CommonIntegralType nNum = static_cast<CommonIntegralType>(Order);
  template <CommonIntegralType SubIndex> using elem1 =
	  valueRatio<CommonIntegralType, '+', nNum, (SubIndex + SubIndex)>;
  template <CommonIntegralType SubIndex> using elem2 = typename plusType <constHalf, elem1<SubIndex> > :: type;
  template <CommonIntegralType SubIndex> using elem = typename multipliesType <x, elem2<SubIndex> > :: type;
  template <class ... Elements> using reduce = accumulateType<multipliesType, Elements...>;
  template <CommonIntegralType ... SubIndices> using prodElements =
	  typename sortType <lessType, elem<SubIndices>...> :: template type <reduce> :: type;
  public:
  using type = typename iotaValue <Order, CommonIntegralType, 1u> :: template type<prodElements>;
 };

 template <unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 constexpr typename legendreType <Order, valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 legendre(std :: integral_constant<unsigned int, Order>, valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
inline constexpr typename crap :: legendreType <Order, crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: legendre(std :: integral_constant<unsigned int, Order>, crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

