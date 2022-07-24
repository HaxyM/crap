#ifndef CRAP_RATIO_SQRTTYPE
#define CRAP_RATIO_SQRTTYPE

#include "dividestype.h"
#include "equaltotype.h"
#include "minustype.h"
#include "multipliestype.h"
#include "plustype.h"
#include "valueratio.h"
#include "../algorithm.d/anyoftype.h"
#include "../cmath.d/sqrttype.h"
#include "../functional.d/dividestype.h"
#include "../functional.d/minustype.h"
#include "../functional.d/multipliestype.h"
#include "../functional.d/plustype.h"

#include <cstddef>
#include <type_traits>

namespace crap
{
 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator, std :: size_t Steps>
	 struct sqrtType<valueRatio<Type, Sign, Numerator, Denominator>, Steps>
 {
  private:
  static_assert(Sign == '+', "Value must be positive.");
  template <class x, bool isLast, std :: size_t Step, class ... Prevs> struct step;
  template <class x, std :: size_t Step, class ... Prevs> struct step<x, true, Step, Prevs...>;
  public:
  using type = typename step <valueRatio<Type, Sign, Numerator, Denominator>, false, 0u> :: type;
  constexpr const static std :: size_t steps = step <valueRatio<Type, Sign, Numerator, Denominator>, false, 0u> :: steps;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator, std :: size_t Steps>
	 template <class x, bool last, std :: size_t Step, class ... Prevs>
 struct sqrtType <valueRatio<Type, Sign, Numerator, Denominator>, Steps> :: step
 {
  private:
  using z = valueRatio<Type, Sign, Numerator, Denominator>;
  using partNum = typename minusType <typename multipliesType <x, x> :: type, z> :: type;
  using part = typename dividesType <partNum, typename plusType <x, x> :: type> :: type;
  using result = typename minusType <x, part> :: type;
  template <class checkedType> using isCurrent = equalToType<checkedType, result>;
  constexpr const static bool isLast = anyOfType <isCurrent, Prevs...> :: value;
  public:
  using type = typename step <result, isLast, Step + 1u, result, Prevs...> :: type;
  constexpr const static std :: size_t steps = step <result, isLast, Step + 1u, result, Prevs...> :: steps;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator, std :: size_t Steps>
	 template <class x, std :: size_t Step, class ... Prevs>
 struct sqrtType <valueRatio<Type, Sign, Numerator, Denominator>, Steps> :: template
	 step<x, true, Step, Prevs...>
 {
  using type = x;
  constexpr const static std :: size_t steps = Step;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 constexpr typename sqrtType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 sqrt(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
inline constexpr typename crap :: sqrtType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: sqrt(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

