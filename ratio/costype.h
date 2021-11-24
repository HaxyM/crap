#ifndef CRAP_RATIO_COSTYPE
#define CRAP_RATIO_COSTYPE

#include "identity.h"
#include "negatetype.h"
#include "multipliestype.h"
#include "plustype.h"
#include "valueratio.h"
#include "../cmath/costype.h"
#include "../numeric/identity.h"
#include "../numeric/iotavalue.h"

#include <cstddef>
#include <ratio>
#include <type_traits>

namespace crap
{
 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator, std :: size_t Steps>
	 struct cosType<valueRatio<Type, Sign, Numerator, Denominator>, Steps>
 {
  private:
  using valueType = typename std :: make_unsigned <Type> :: type;
  using x = valueRatio<Type, Sign, Numerator, Denominator>;
  template <valueType N> using constant1 = valueRatio<Type, '+', identity <valueType> :: value, 2u * N + 1u>;
  template <valueType N> using constant2 = valueRatio<Type, '+', identity <valueType> :: value, 2u * N + 2u>;
  template <valueType N> using prodTerm1 = typename multipliesType <x, constant1<N> > :: type;
  template <valueType N> using prodTerm2 = typename multipliesType <x, constant2<N> > :: type;
  template <valueType N>
	  using prodTerm = typename negateType <typename multipliesType <prodTerm1<N>, prodTerm2<N> > :: type> :: type;
  template <valueType ... N> using product = typename multipliesType <prodTerm<N>...> :: type;
  template <std :: size_t N> using sumTerm = typename iotaValue <N, valueType, 0> :: template type<product>;
  template <std :: size_t ... N> using sum = typename plusType <typename identity <x> :: type, sumTerm<N>...> :: type;
  public:
  using type = typename iotaValue <Steps, std :: size_t, 1u> :: template type<sum>;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 constexpr typename cosType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 cos(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
inline constexpr typename crap :: cosType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: cos(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

