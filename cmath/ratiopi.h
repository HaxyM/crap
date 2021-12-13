#ifndef CRAP_CMATH_RATIOPI
#define CRAP_CMATH_RATIOPI

#include "ratiosqrt1_2.h"
#include "sqrttype.h"
#include "../functional/dividestype.h"
#include "../functional/minustype.h"
#include "../functional/multipliestype.h"
#include "../functional/plustype.h"

#include <cstddef>
#include <ratio>

namespace crap
{
 template <std :: size_t Steps = 1u> struct ratioPi;

 template <> struct ratioPi<0u>
 {
  private:
  using val = typename plusType <std :: ratio<1, 1>, ratioSqrt1_2_t<3u> > :: type;
  public:
  using type = typename multipliesType <val, val> :: type;
 };

 template <std :: size_t Steps> struct ratioPi
 {
  private:
  template <std :: size_t CurrentStep, class...> struct Implementation;
  template <class ... Empty> struct Implementation<0u, Empty...>;
  template <class ... Empty> struct Implementation<Steps, Empty...>;
  using elem = Implementation<Steps>;
  using sum = typename plusType <typename elem :: a, typename elem :: b> :: type;
  using num = typename multipliesType <sum, sum> :: type;
  using den =
	  typename plusType <typename elem :: t, typename elem :: t, typename elem :: t, typename elem :: t> :: type;
  public:
  using type = typename dividesType <num, den> :: type;
 };

 template <std :: size_t Steps>
	 template <std :: size_t CurrentStep, class...>
 struct ratioPi <Steps> :: Implementation
 {
  private:
  using prev = typename ratioPi <Steps> :: template Implementation <CurrentStep - 1u>;
  using aSum = typename plusType <typename prev :: a, typename prev :: b> :: type;
  using bMul = typename multipliesType <typename prev :: a, typename prev :: b> :: type;
  public:
  using a = typename dividesType <aSum, std :: ratio<2,1> > :: type;
  using b = typename sqrtType <bMul, 2u> :: type;
  private:
  using tDiff = typename minusType <typename prev :: a, a> :: type;
  using tMul = typename multipliesType <typename prev :: p, tDiff, tDiff> :: type;
  public:
  using t = typename minusType <typename prev :: t, tMul> :: type;
  using p = typename plusType <typename prev :: p, typename prev :: p> :: type;
 };

 template <std :: size_t Steps>
	 template <class ... Empty>
 struct ratioPi <Steps> :: template Implementation<0u, Empty...>
 {
  using a = std :: ratio<1,1>;
  using b = ratioSqrt1_2_t<3u> ;
  using t = std :: ratio<1,4>;
  using p = std :: ratio<1,1>;
 };

 template <std :: size_t Steps>
	 template <class ... Empty>
 struct ratioPi <Steps> :: template Implementation<Steps, Empty...>
 {
  private:
  using prev = typename ratioPi <Steps> :: template Implementation <Steps - 1u>;
  using aSum = typename plusType <typename prev :: a, typename prev :: b> :: type;
  using bMul = typename multipliesType <typename prev :: a, typename prev :: b> :: type;
  public:
  using a = typename dividesType <aSum, std :: ratio<2,1> > :: type;
  using b = typename sqrtType <bMul, 2u> :: type;
  private:
  using tDiff = typename minusType <typename prev :: a, a> :: type;
  using tMul = typename multipliesType <typename prev :: p, tDiff, tDiff> :: type;
  public:
  using t = typename minusType <typename prev :: t, tMul> :: type;
 };

 template <std :: size_t Steps = 1u> using ratioPi_t = typename ratioPi <Steps> :: type;
}
#endif

