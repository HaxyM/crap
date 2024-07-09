#include <type_traits>

#include "dividestype.h"
#include "identity.h"
#include "lesstype.h"
#include "minustype.h"
#include "multipliestype.h"
#include "plustype.h"
#include "powtype.h"
#include "sqrttype.h"
#include "valueratio.h"
#include "../algorithm.d/sorttype.h"
#include "../cmath.d/assoclegendretype.h"
#include "../numeric.d/accumulatetype.h"
#include "../numeric.d/iotavalue.h"
#include "../utility.d/concatenatetype.h"
#include "../utility.d/typecast.h"

#ifndef CRAP_RATIO_ASSOCLEGENDRETYPE
#define CRAP_RATIO_ASSOCLEGENDRETYPE

namespace crap
{
 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct assocLegendreType<0u, 0u, valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  public:
  using type = typename identity <passed> :: type;
 };

 template <unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 struct assocLegendreType<0u, Order, valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  static_assert(Order > 0u, "Case for Order greater than Degree.");
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  public:
  using type = typename zero <passed> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct assocLegendreType<1u, 0u, valueRatio<Type, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<Type, Sign, Numerator, Denominator>;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct assocLegendreType<1u, 1u, valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  //Check if passed |x| <= 1. 
  static_assert((Numerator <= Denominator), "Argument outside range. Function would generate complex result.");
  using x = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <x> :: type;
  using x2 = typename multipliesType <x, x> :: type;
  public:
  using type = typename sqrtType <typename minusType <const1, x2> :: type> :: type;
 };

 template <unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 struct assocLegendreType<1u, Order, valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  static_assert(Order > 1u, "Case for Order greater than Degree.");
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  public:
  using type = typename zero <passed> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct assocLegendreType<2u, 0u, valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using x = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <x> :: type;
  using const2 = typename plusType <const1, const1> :: type;
  using const3 = typename plusType <const1, const1, const1> :: type;
  using p3x2 = typename multipliesType <const3, x, x> :: type;
  public:
  using type = typename dividesType <typename minusType <p3x2, const1> :: type, const2> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct assocLegendreType<2u, 1u, valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using x = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <x> :: type;
  using const3 = typename plusType <const1, const1, const1> :: type;
  public:
  using type = typename multipliesType <const3, x, typename assocLegendreType <1u, 1u, x> :: type> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct assocLegendreType<2u, 2u, valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using x = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <x> :: type;
  using const3 = typename plusType <const1, const1, const1> :: type;
  using x2 = typename multipliesType <x, x> :: type;
  public:
  using type = typename multipliesType <typename minusType <const1, x2> :: type, const3> :: type;
 };

 template <unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 struct assocLegendreType<2u, Order, valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  static_assert(Order > 2u, "Case for Order greater than Degree.");
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  public:
  using type = typename zero <passed> :: type;
 };

 template <unsigned int L, class Type, char Sign, Type Numerator, Type Denominator>
	 struct assocLegendreType<L, L, valueRatio<Type, Sign, Numerator, Denominator> >
 { //OK!
  private:
  //Check if passed |x| <= 1 or L even. 
  static_assert((Numerator <= Denominator) || ((L % 2u) == 0u), "Argument outside range. Function would generate complex result.");
  using common_t = typename std :: common_type <unsigned int, Type> :: type;
  using const1 = valueRatio<common_t, '+', static_cast<common_t>(1u), static_cast<common_t>(1u)>;
  using constm1 = valueRatio<common_t, '-', static_cast<common_t>(1u), static_cast<common_t>(1u)>;
  using x = valueRatio<common_t, Sign, static_cast<common_t>(Numerator), static_cast<common_t>(Denominator)>;
  using x2 = typename multipliesType <x, x> :: type;
  using lo2 = valueRatio<common_t, '+', static_cast<common_t>(L), static_cast<common_t>(2u)>;
  using elem0 = typename powType <typename minusType <const1, x2> :: type, lo2> :: type;

  template <unsigned int Index> using j =
	  valueRatio<common_t, '+', static_cast<common_t>(Index), static_cast<common_t>(1u)>;
  template <unsigned int Index> using elem1 =
	  typename plusType <j<Index>, j<Index>, constm1> :: type;
  template <class ... Elements> using reduce = accumulateType<multipliesType, Elements...>;
  template <unsigned int ... Indices> using prod =
	  typename sortType<lessType, elem0, typename elem1 <Indices> :: type...> :: template type<reduce>;
  using result = typename typeCast <typename iotaValue <L, unsigned int, 1u> :: template type <prod> :: type> :: template
	  onto <valueRatio<Type, Sign, Numerator, Denominator> > :: type;
  constexpr const static char resultSign =
	  (L % 2u == 0u) ? result :: sign : (result :: sign == '+' ? '-' : '+');
  public:
  using type = valueRatio<Type, resultSign, result :: num, result :: den>;
 };

 template <unsigned int Degree, unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 struct assocLegendreType<Degree, Order, valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  //Check if passed |x| <= 1 or Order even. 
  static_assert((Numerator <= Denominator) || ((Order % 2u) == 0u), "Argument outside range. Function would generate complex result.");
  template <bool Equivalent, bool CloseProximity, bool InRange, class ... Empty> struct Implementation;
  template <bool Equivalent, bool CloseProximity, class ... Empty>
	  struct Implementation<Equivalent, CloseProximity, false, Empty...>;
  template <class ... Empty> struct Implementation<false, false, true, Empty...>;
  template <class ... Empty> struct Implementation<false, true, true, Empty...>; //OK
  template <class ... Empty> struct Implementation<true, false, true, Empty...>;
  //template <class ... Empty> struct Implementation<true, true, true, Empty...>; //XXX: Case impossible - Requires Degree == Order and that is already handled.
  constexpr const static bool isEquivalent = ((Degree % 2u) == (Order % 2u));
  constexpr const static bool isInRange = !(Degree < Order); //M -> Order; L -> Degree; M <= L
  constexpr const static bool isCloseProximity = isInRange ? ((Degree - Order) < 2u) : false;
  public:
  using type = typename Implementation <isEquivalent, isCloseProximity, isInRange> :: type;
 };

 template <unsigned int Degree, unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 template <bool Equivalent, bool CloseProximity, class ... Empty>
 struct assocLegendreType <Degree, Order, valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 Implementation<Equivalent, CloseProximity, false, Empty...>
 {
  private:
  static_assert(Order > Degree, "Case for Order greater than Degree.");
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  public:
  using type = typename zero <passed> :: type;
 };

 template <unsigned int Degree, unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 template <class ... Empty>
 struct assocLegendreType <Degree, Order, valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 Implementation<false, false, true, Empty...>
 {
  private:
  template <class CommonIntegralType, unsigned int Index> struct sumElement;
  template <class CommonIntegralType> struct sumElement<CommonIntegralType, 0u>;
  template <class CommonIntegralType> struct sumElement<CommonIntegralType, (Degree - Order - 1u) / 2u>;
  using common_t = typename std :: common_type <unsigned int, Type> :: type;
  template <unsigned int Index> using element = sumElement<common_t, Index>;
  template <class ... Elements> using reduce = accumulateType<plusType, Elements...>;
  template <unsigned int ... Indices> using sum =
	  typename sortType<lessType, typename element <Indices> :: type...> :: template type<reduce>;
  using sumPart =
	  typename iotaValue <((Degree - Order - 1u) / 2u) + 1u, unsigned int, 0u> :: template
	  type <sum> :: type;
  using x = valueRatio<common_t, Sign, static_cast<common_t>(Numerator), static_cast<common_t>(Denominator)>;
  using const1 = typename identity <x> :: type;
  using x2 = typename multipliesType <x, x> :: type;
  using exp = valueRatio<common_t, '+', static_cast<common_t>(Order), static_cast<common_t>(2u)>;
  using powPart = typename powType <typename minusType <const1, x2> :: type, exp> :: type;
  using result = typename typeCast <typename multipliesType <sumPart, powPart> :: type> :: template
	  onto <valueRatio<Type, Sign, Numerator, Denominator> > :: type;
  constexpr const static char resultSign = //FIXME: Sign may be wrong!
	  (((Degree - Order - 1u) / 2u) % 2u == 0u) ? result :: sign : (result :: sign == '+' ? '-' : '+');
  public:
  using type = valueRatio<Type, resultSign, result :: num, result :: den>;
 };

 template <unsigned int Degree, unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 template <class ... Empty>
 struct assocLegendreType <Degree, Order, valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 Implementation<false, true, true, Empty...>
 {//Case: Order == Degree + 1u
  private:
  using common_t = typename std :: common_type <unsigned int, Type> :: type;
  using x = valueRatio<common_t, Sign, static_cast<common_t>(Numerator), static_cast<common_t>(Denominator)>;
  using const1 = typename identity <x> :: type;
  using x2 = typename multipliesType <x, x> :: type;
  using exp = valueRatio<common_t, '+', static_cast<common_t>(Order), static_cast<common_t>(2u)>;
  using powPart = typename powType <typename minusType <const1, x2> :: type, exp> :: type;
  template <unsigned int Index>
	  using prodElement1 = valueRatio<common_t, '+', static_cast<common_t>(Index), static_cast<common_t>(1u)>;
  template <unsigned int Index>
	  using prodElement = typename plusType <prodElement1<Index>, prodElement1<Index>, const1> :: type;
  template <unsigned int ... Indices> using reduce = accumulateType<multipliesType, prodElement<Indices>...>;
  using prodPart = typename iotaValue <Order, unsigned int, 1u> :: template type <reduce> :: type;
  using result = typename typeCast <typename multipliesType <x, prodPart, powPart> :: type> :: template
	  onto <valueRatio<Type, Sign, Numerator, Denominator> > :: type;
  constexpr const static char resultSign =
	  ((Degree - 1u) % 2u == 0u) ? result :: sign : (result :: sign == '+' ? '-' : '+');
  public:
  using type = valueRatio<Type, resultSign, result :: num, result :: den>;
 };

 template <unsigned int Degree, unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 template <class ... Empty>
 struct assocLegendreType <Degree, Order, valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 Implementation<true, false, true, Empty...>
 {
  private:
  template <class CommonIntegralType, unsigned int Index> struct sumElement;
  template <class CommonIntegralType> struct sumElement<CommonIntegralType, 0u>;
  template <class CommonIntegralType> struct sumElement<CommonIntegralType, (Degree - Order) / 2u>;
  using common_t = typename std :: common_type <unsigned int, Type> :: type;
  template <unsigned int Index> using element = sumElement<common_t, Index>;
  template <class ... Elements> using reduce = accumulateType<plusType, Elements...>;
  template <unsigned int ... Indices> using sum =
	  typename sortType<lessType, typename element <Indices> :: type...> :: template type<reduce>;
  using sumPart =
	  typename iotaValue <((Degree - Order) / 2u) + 1u, unsigned int, 0u> :: template
	  type <sum> :: type;
  using x = valueRatio<common_t, Sign, static_cast<common_t>(Numerator), static_cast<common_t>(Denominator)>;
  using const1 = typename identity <x> :: type;
  using x2 = typename multipliesType <x, x> :: type;
  using exp = valueRatio<common_t, '+', static_cast<common_t>(Order), static_cast<common_t>(2u)>;
  using powPart = typename powType <typename minusType <const1, x2> :: type, exp> :: type;
  using result = typename typeCast <typename multipliesType <sumPart, powPart> :: type> :: template
	  onto <valueRatio<Type, Sign, Numerator, Denominator> > :: type;
  constexpr const static char resultSign = //FIXME: Sign may be wrong!
	  (((Degree - Order) / 2u) % 2u == 0u) ? result :: sign : (result :: sign == '+' ? '-' : '+');
  public:
  using type = valueRatio<Type, resultSign, result :: num, result :: den>;
 };

 template <unsigned int Degree, unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 template <class ... Empty>
	 template <class CommonIntegralType>
 struct assocLegendreType <Degree, Order, valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 Implementation <false, false, true, Empty...> :: template
	 sumElement<CommonIntegralType, 0u>
 {
  private:
  using const4 = valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(4u), static_cast<CommonIntegralType>(1u)>;
  using c1 = valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(Degree - Order - 2u), static_cast<CommonIntegralType>(1u)>;
  using x = valueRatio<CommonIntegralType, Sign, static_cast<CommonIntegralType>(Numerator), static_cast<CommonIntegralType>(Denominator)>;
  template <unsigned int SubIndex> using j =
	  valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(SubIndex), static_cast<CommonIntegralType>(1u)>;
  template <unsigned int SubIndex> using m2oj =
	  valueRatio<CommonIntegralType, '-', static_cast<CommonIntegralType>(2u), static_cast<CommonIntegralType>(SubIndex)>;
  template <unsigned int SubIndex> using elem1 = typename plusType <j<SubIndex>, j<SubIndex>, c1> :: type;
  template <unsigned int SubIndex> using elem2 = typename plusType <const4, m2oj<SubIndex> > :: type;
  template <unsigned int ... SubIndices> using elements1 = concatenateType<x, elem1<SubIndices>...>;
  template <unsigned int ... SubIndices> //Order < Degree so if Degree in range then Order + 1 also.
	  using elements2 = typename iotaValue <Order + 1u, unsigned int, 1u> :: template
	  type <elements1> :: template with<elem2<SubIndices>...>;
  template <class ... Elements> using sort = sortType<lessType, Elements...>;
  template <class ... Elements> using reduce = accumulateType<multipliesType, Elements...>;
  template <template <class...> class Reductor>
	  using allElements = typename iotaValue <(Degree - Order - 1u) / 2u, unsigned int, 1u> :: template
	  type <elements2> :: template type <sort> :: template type<Reductor>;
  public:
  using type = typename allElements <reduce> :: type;
 };

 template <unsigned int Degree, unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 template <class ... Empty>
	 template <class CommonIntegralType>
 struct assocLegendreType <Degree, Order, valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 Implementation <false, false, true, Empty...> :: template
	 sumElement<CommonIntegralType, (Degree - Order - 1u) / 2u>
 {
  private:
  constexpr const static auto c1i = static_cast<CommonIntegralType>(Degree - Order);
  constexpr const static auto c2i = static_cast<CommonIntegralType>((Degree - Order - 1u) / 2u);
  using const1 = valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(1u), static_cast<CommonIntegralType>(1u)>;
  using c0 = valueRatio<CommonIntegralType, ((c2i % 2u) == 0u) ? '+' : '-', static_cast<CommonIntegralType>(1u), c1i>;
  using c1 = valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(Degree - Order - 2u), static_cast<CommonIntegralType>(1u)>;
  using c2 = valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(Degree - Order - 2u), static_cast<CommonIntegralType>(2u)>;
  using i2 = valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(Degree - Order - 1u), static_cast<CommonIntegralType>(1u)>;
  using x = valueRatio<CommonIntegralType, Sign, static_cast<CommonIntegralType>(Numerator), static_cast<CommonIntegralType>(Denominator)>;
  using x2 = typename multipliesType <x, x> :: type;
  template <unsigned int SubIndex> using j =
	  valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(SubIndex), static_cast<CommonIntegralType>(1u)>;
  using elem0 = typename multipliesType <c0, x> :: type;
  template <unsigned int SubIndex> using elem1 = typename plusType <j<SubIndex>, j<SubIndex>, i2, c1> :: type;
  template <unsigned int SubIndex> using elem2 =
	  typename multipliesType <x2, typename plusType <const1, typename dividesType <c2, j<SubIndex> > :: type> :: type> :: type;
  template <unsigned int ... SubIndices> using elements1 = concatenateType<elem0, elem1<SubIndices>...>;
  template <unsigned int ... SubIndices> //Order < Degree so if Degree in range then Order + 1 also.
	  using elements2 = typename iotaValue <Order + 1u, unsigned int, 1u> :: template
	  type <elements1> :: template with<elem2<SubIndices>...>;
  template <class ... Elements> using sort = sortType<lessType, Elements...>;
  template <class ... Elements> using reduce = accumulateType<multipliesType, Elements...>;
  template <template <class...> class Reductor>
	  using allElements = typename iotaValue <(Degree - Order - 1u) / 2u, unsigned int, 1u> :: template
	  type <elements2> :: template type <sort> :: template type<Reductor>;
  public:
  using type = typename allElements <reduce> :: type;
 };

 template <unsigned int Degree, unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 template <class ... Empty>
	 template <class CommonIntegralType, unsigned int Index>
 struct assocLegendreType <Degree, Order, valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 Implementation <false, false, true, Empty...> :: sumElement
 {
  private:
  using const1 = valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(1u), static_cast<CommonIntegralType>(1u)>;
  using const4 = valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(4u), static_cast<CommonIntegralType>(1u)>;
  using c1 = valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(Degree - Order - 2u), static_cast<CommonIntegralType>(1u)>;
  using c2 = valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(Degree - Order - 2u), static_cast<CommonIntegralType>(2u)>;
  using i = valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(Index), static_cast<CommonIntegralType>(1u)>;
  using i2 = valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(Degree - Order - 1u), static_cast<CommonIntegralType>(1u)>;
  using x = valueRatio<CommonIntegralType, Sign, static_cast<CommonIntegralType>(Numerator), static_cast<CommonIntegralType>(Denominator)>;
  using x2 = typename multipliesType <x, x> :: type;
  template <unsigned int SubIndex> using j =
	  valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(SubIndex), static_cast<CommonIntegralType>(1u)>;
  template <unsigned int SubIndex> using ioj =
	  valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(Index), static_cast<CommonIntegralType>(SubIndex)>;
  template <unsigned int SubIndex> using m2oj =
	  valueRatio<CommonIntegralType, '-', static_cast<CommonIntegralType>(2), static_cast<CommonIntegralType>(SubIndex)>;
  template <unsigned int SubIndex> using i4oj = typename multipliesType <const4, ioj<SubIndex> > :: type;
  using elem0 = typename dividesType <x, typename plusType <i2, const1> :: type> :: type;
  template <unsigned int SubIndex> using elem1 = typename plusType <j<SubIndex>, j<SubIndex>, i2, c1> :: type;
  template <unsigned int SubIndex> using elem2 =
	  typename multipliesType <x2, typename plusType <const1, typename dividesType <c2, j<SubIndex> > :: type> :: type> :: type;
  template <unsigned int SubIndex> using elem3 = typename plusType <const4, i4oj<SubIndex>, m2oj<SubIndex> > :: type;
  template <unsigned int ... SubIndices> using elements1 = concatenateType<elem0, elem1<SubIndices>...>;
  template <unsigned int ... SubIndices> //Order < Degree so if Degree in range then Order + 1 also.
	  using elements2 = typename iotaValue <Order + 1u, unsigned int, 1u> :: template
	  type <elements1> :: template with<elem2<SubIndices>...>;
  template <unsigned int ... SubIndices>
	  using elements3 = typename iotaValue <Index, unsigned int, 1u> :: template
	  type <elements2> :: template with<elem2<SubIndices>...>;
  template <class ... Elements> using sort = sortType<lessType, Elements...>;
  template <class ... Elements> using reduce = accumulateType<multipliesType, Elements...>;
  template <template <class...> class Reductor>
	  using allElements = typename iotaValue <(Degree - Order - Index - Index - 1u) / 2u, unsigned int, 1u> :: template
	  type <elements3> :: template type <sort> :: template type<Reductor>;
  using ans = typename allElements <reduce> :: type;
  constexpr const static char ansSign = (Index % 2u == 0u) ? ans :: sign : ((ans :: sign == '+') ? '-' : '+') ;
  public:
  using type = valueRatio<CommonIntegralType, ansSign, ans :: num, ans :: den>;
 };

 template <unsigned int Degree, unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 template <class ... Empty>
	 template <class CommonIntegralType>
 struct assocLegendreType <Degree, Order, valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 Implementation <true, false, true, Empty...> :: template
	 sumElement<CommonIntegralType, 0u>
 {
  private:
  using c1 = valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(Degree - Order - 1u), static_cast<CommonIntegralType>(1u)>;
  using const1 = valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(1u), static_cast<CommonIntegralType>(1u)>;
  using const4 = valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(4u), static_cast<CommonIntegralType>(1u)>;
  template <unsigned int SubIndex>
	  using elem1a = valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(SubIndex), static_cast<CommonIntegralType>(1u)>;
  template <unsigned int SubIndex> using elem1 = typename plusType <elem1a<SubIndex>, elem1a<SubIndex>, c1> :: type;
  template <unsigned int SubIndex>
	  using elem2a = valueRatio<CommonIntegralType, '-', static_cast<CommonIntegralType>(2u), static_cast<CommonIntegralType>(SubIndex)>;
  template <unsigned int SubIndex> using elem2 = typename plusType <const4, elem2a<SubIndex> > :: type;
  template <unsigned int ... SubIndices> using elements1Generator = concatenateType<elem1<SubIndices>...>;
  template <unsigned int ... SubIndices>
	  using elements1 = typename iotaValue <Order, unsigned int, 1u> :: template
	  type <elements1Generator> :: template with<elem2<SubIndices>...>;
  template <class ... Elements> using sort = sortType<lessType, Elements...>;
  template <template <class...> class Reductor>
	  using allElements = typename iotaValue <(Degree - Order) / 2u, unsigned int, 1u> :: template
	  type <elements1> :: template type <sort> :: template type<Reductor>;
  template <class ... Elements> using reduce = accumulateType<multipliesType, Elements...>;
  public:
  using type = typename allElements <reduce> :: type;
 };

 template <unsigned int Degree, unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 template <class ... Empty>
	 template <class CommonIntegralType>
 struct assocLegendreType <Degree, Order, valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 Implementation <true, false, true, Empty...> :: template
	 sumElement<CommonIntegralType, (Degree - Order) / 2u>
 {
  private:
  using c1 = valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(Degree - Order - 1u), static_cast<CommonIntegralType>(1u)>;
  using c2 = valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(Degree - Order), static_cast<CommonIntegralType>(1u)>;
  using c3 = valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(Degree - Order - 1u), static_cast<CommonIntegralType>(2u)>;
  using const1 = valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(1u), static_cast<CommonIntegralType>(1u)>;
  using x = valueRatio<CommonIntegralType, Sign, static_cast<CommonIntegralType>(Numerator), static_cast<CommonIntegralType>(Denominator)>;
  using x2 = typename multipliesType <x, x> :: type;
  template <unsigned int SubIndex>
	  using elem1a = valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(SubIndex), static_cast<CommonIntegralType>(1u)>;
  template <unsigned int SubIndex> using elem1 = typename plusType <elem1a<SubIndex>, elem1a<SubIndex>, c2, c1> :: type;
  template <unsigned int SubIndex> using elem2a = typename plusType <const1, typename dividesType <c3, elem1a<SubIndex> > :: type> :: type;
  template <unsigned int SubIndex> using elem2 = typename multipliesType <x2, elem2a<SubIndex> > :: type;
  template <unsigned int ... SubIndices> using elements1Generator = concatenateType<elem1<SubIndices>...>;
  template <unsigned int ... SubIndices>
	  using elements1 = typename iotaValue <Order, unsigned int, 1u> :: template
	  type <elements1Generator> :: template with<elem2<SubIndices>...>;
  template <class ... Elements> using sort = sortType<lessType, Elements...>;
  template <template <class...> class Reductor>
	  using allElements = typename iotaValue <(Degree - Order) / 2u, unsigned int, 1u> :: template
	  type <elements1> :: template type <sort> :: template type<Reductor>;
  template <class ... Elements> using reduce = accumulateType<multipliesType, Elements...>;
  using ans = typename allElements <reduce> :: type;
  constexpr const static char ansSign = (((Degree - Order) / 2u) % 2u == 0u) ? ans :: sign : ((ans :: sign == '+') ? '-' : '+') ;
  public:
  using type = valueRatio<CommonIntegralType, ansSign, ans :: num, ans :: den>;
 };

 template <unsigned int Degree, unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 template <class ... Empty>
	 template <class CommonIntegralType, unsigned int Index>
 struct assocLegendreType <Degree, Order, valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 Implementation <true, false, true, Empty...> :: sumElement
 {
  private:
  using const1 = valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(1u), static_cast<CommonIntegralType>(1u)>;
  using const4 = typename plusType <const1, const1, const1, const1> :: type;
  using c1 = valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(Degree - Order - 1u), static_cast<CommonIntegralType>(1u)>;
  using c2 = valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(Degree - Order - 1u), static_cast<CommonIntegralType>(2u)>;
  using i = valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(Index), static_cast<CommonIntegralType>(1u)>;
  using x = valueRatio<CommonIntegralType, Sign, static_cast<CommonIntegralType>(Numerator), static_cast<CommonIntegralType>(Denominator)>;
  using x2 = typename multipliesType <x, x> :: type;
  template <unsigned int SubIndex> using j =
	  valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(SubIndex), static_cast<CommonIntegralType>(1u)>;
  template <unsigned int SubIndex> using ioj =
	  valueRatio<CommonIntegralType, '+', static_cast<CommonIntegralType>(Index), static_cast<CommonIntegralType>(SubIndex)>;
  template <unsigned int SubIndex> using m2oj =
	  valueRatio<CommonIntegralType, '-', static_cast<CommonIntegralType>(2u), static_cast<CommonIntegralType>(SubIndex)>;
  template <unsigned int SubIndex> using i4oj =
	  typename multipliesType <const4, ioj<SubIndex> > :: type;
  template <unsigned int SubIndex> using elem1 = typename plusType <j<SubIndex>, j<SubIndex>, i, i, c1> :: type;
  template <unsigned int SubIndex> using elem2 =
	  typename multipliesType <x2, typename plusType <const1, typename dividesType <c2, j<SubIndex> > :: type> :: type> :: type;
  template <unsigned int SubIndex> using elem3 = typename plusType <const4, i4oj<SubIndex>, m2oj<SubIndex> > :: type;
  template <unsigned int ... SubIndices> using elements1 = concatenateType<elem1<SubIndices>...>;
  template <unsigned int ... SubIndices> using elements2 =
	  typename iotaValue <Order, unsigned int, 1> :: template type <elements1> :: template with<elem2<SubIndices>...>;
  template <unsigned int ... SubIndices> using elements3 =
	  typename iotaValue <Index, unsigned int, 1> :: template type <elements2> :: template with<elem3<SubIndices>...>;
  template <class ... Elements> using sort = sortType<lessType, Elements...>;
  template <class ... Elements> using reduce = accumulateType<multipliesType, Elements...>;
  template <template <class...> class Reductor>
	  using allElements = typename iotaValue <(Degree - Order - Index - Index) / 2u, unsigned int, 1u> :: template
	  type <elements3> :: template type <sort> :: template type<Reductor>;
  using ans = typename allElements <reduce> :: type;
  constexpr const static char ansSign = (Index % 2u == 0u) ? ans :: sign : ((ans :: sign == '+') ? '-' : '+') ;
  public:
  using type = valueRatio<CommonIntegralType, ansSign, ans :: num, ans :: den>;
 };

 template <unsigned int Degree, unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
	 constexpr typename assocLegendreType <Degree, Order, valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 assoc_legendre(std :: integral_constant<unsigned int, Degree>, std :: integral_constant<unsigned int, Order>, valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <unsigned int Degree, unsigned int Order, class Type, char Sign, Type Numerator, Type Denominator>
inline constexpr typename crap :: assocLegendreType <Degree, Order, crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: assoc_legendre(std :: integral_constant<unsigned int, Degree>, std :: integral_constant<unsigned int, Order>, crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

