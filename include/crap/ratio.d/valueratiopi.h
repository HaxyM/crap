#ifndef CRAP_RATIO_VALUERATIOPI
#define CRAP_RATIO_VALUERATIOPI

#include "dividestype.h"
#include "identity.h"
#include "minustype.h"
#include "multipliestype.h"
#include "plustype.h"
#include "sqrttype.h"
#include "valueratiosqrt1_2.h"
#include "../numeric.d/identity.h"

#include <cstddef>
#include <ratio>

namespace crap
{
 template <class Type, std :: size_t Steps = 4u> struct valueRatioPi;

 template <class Type> struct valueRatioPi<Type, 0u>
 {
  private:
  using b = valueRatioSqrt1_2_t<Type>;
  using val = typename plusType <typename identity <b> :: type, b> :: type;
  public:
  using type = typename multipliesType <val, val> :: type;
 };

 template <class Type, std :: size_t Steps> struct valueRatioPi
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

 template <class Type, std :: size_t Steps>
	 template <std :: size_t CurrentStep, class...>
 struct valueRatioPi <Type, Steps> :: Implementation
 {
  private:
  using prev = typename valueRatioPi <Type, Steps> :: template Implementation <CurrentStep - 1u>;
  using aSum = typename plusType <typename prev :: a, typename prev :: b> :: type;
  using bMul = typename multipliesType <typename prev :: a, typename prev :: b> :: type;
  public:
  using b = typename sqrtType <bMul> :: type;
  private:
  using two = typename plusType <typename identity <b> :: type, typename identity <b> :: type> :: type;
  public:
  using a = typename dividesType <aSum, two> :: type;
  private:
  using tDiff = typename minusType <typename prev :: a, a> :: type;
  using tMul = typename multipliesType <typename prev :: p, tDiff, tDiff> :: type;
  public:
  using t = typename minusType <typename prev :: t, tMul> :: type;
  using p = typename plusType <typename prev :: p, typename prev :: p> :: type;
 };

 template <class Type, std :: size_t Steps>
	 template <class ... Empty>
 struct valueRatioPi <Type, Steps> :: template Implementation<0u, Empty...>
 {
  public:
  using b = valueRatioSqrt1_2_t<Type> ;
  using a = typename identity <b> :: type;
  using p = typename identity <b> :: type;
  private:
  constexpr const static auto one = identity <typename std :: make_unsigned <Type> :: type> :: value;
  public:
  using t = valueRatio<Type, '+', one,(one + one + one + one)>;
 };

 template <class Type, std :: size_t Steps>
	 template <class ... Empty>
 struct valueRatioPi <Type, Steps> :: template Implementation<Steps, Empty...>
 {
  private:
  using prev = typename valueRatioPi <Type, Steps> :: template Implementation <Steps - 1u>;
  using aSum = typename plusType <typename prev :: a, typename prev :: b> :: type;
  using bMul = typename multipliesType <typename prev :: a, typename prev :: b> :: type;
  public:
  using b = typename sqrtType <bMul> :: type;
  private:
  using two = typename plusType <typename identity <b> :: type, typename identity <b> :: type> :: type;
  public:
  using a = typename dividesType <aSum, two> :: type;
  private:
  using tDiff = typename minusType <typename prev :: a, a> :: type;
  using tMul = typename multipliesType <typename prev :: p, tDiff, tDiff> :: type;
  public:
  using t = typename minusType <typename prev :: t, tMul> :: type;
 };

 template <class Type, std :: size_t Steps = 4u> using valueRatioPi_t = typename valueRatioPi <Type, Steps> :: type;
}
#endif

