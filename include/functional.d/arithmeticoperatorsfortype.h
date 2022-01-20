#ifndef CRAP_FUNCTIONAL_ARITHMETICOPERATORSFORTYPE
#define CRAP_FUNCTIONAL_ARITHMETICOPERATORSFORTYPE

#include "dividesvalue.h"
#include "minusvalue.h"
#include "modulusvalue.h"
#include "multipliesvalue.h"
#include "negatevalue.h"
#include "plusvalue.h"

#include "../utility.d/language.h"

namespace crap
{
 template <class Type> struct arithmeticOperatorsForType
 {
  template <Type Value> using Negate = negateValue<Type, Value>;
  template <Type ... Values> using Plus = plusValue<Type, Values...>;
  template <Type ... Values> using Minus = minusValue<Type, Values...>;
  template <Type ... Values> using Divides = dividesValue<Type, Values...>;
  template <Type ... Values> using Modulus = modulusValue<Type, Values...>;
  template <Type ... Values> using Multiplies = multipliesValue<Type, Values...>;
  template <Type Value1, Type Value2> using Plus2 = plusValue<Type, Value1, Value2>;
  template <Type Value1, Type Value2> using Minus2 = minusValue<Type, Value1, Value2>;
  template <Type Value1, Type Value2> using Divides2 = dividesValue<Type, Value1, Value2>;
  template <Type Value1, Type Value2> using Modulus2 = modulusValue<Type, Value1, Value2>;
  template <Type Value1, Type Value2> using Multiplies2 = multipliesValue<Type, Value1, Value2>;
  #if CPP14
  template <Type Value> constexpr const static auto negate = negateValue <Type, Value> :: value;
  template <Type ... Values> constexpr const static auto plus = plusValue <Type, Values...> :: value;
  template <Type ... Values> constexpr const static auto minus = minusValue <Type, Values...> :: value;
  template <Type ... Values> constexpr const static auto divides = dividesValue <Type, Values...> :: value;
  template <Type ... Values> constexpr const static auto modulus = modulusValue <Type, Values...> :: value;
  template <Type ... Values> constexpr const static auto multiplies = multipliesValue <Type, Values...> :: value;
  template <Type Value1, Type Value2> constexpr const static auto plus2 = plusValue <Type, Value1, Value2> :: value;
  template <Type Value1, Type Value2> constexpr const static auto minus2 = minusValue <Type, Value1, Value2> :: value;
  template <Type Value1, Type Value2> constexpr const static auto divides2 = dividesValue <Type, Value1, Value2> :: value;
  template <Type Value1, Type Value2> constexpr const static auto modulus2 = modulusValue <Type, Value1, Value2> :: value;
  template <Type Value1, Type Value2> constexpr const static auto multiplies2 = multipliesValue <Type, Value1, Value2> :: value;
  #endif
 };
}
#endif

