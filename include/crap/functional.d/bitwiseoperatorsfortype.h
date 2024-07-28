#ifndef CRAP_FUNCTIONAL_BITWISEOPERATORSFORTYPE
#define CRAP_FUNCTIONAL_BITWISEOPERATORSFORTYPE

#include "bitwiseorvalue.h"
#include "bitwiseandvalue.h"
#include "bitwisenotvalue.h"
#include "bitwisexorvalue.h"

#include "../version.d/variabletemplates.h"

namespace crap
{
 template <class Type> struct bitwiseOperatorsForType
 {
  template <Type Value> using BitwiseNot = bitwiseNotValue<Type, Value>;
  template <Type ... Values> using BitwiseOr = bitwiseOrValue<Type, Values...>;
  template <Type ... Values> using BitwiseAnd = bitwiseAndValue<Type, Values...>;
  template <Type ... Values> using BitwiseXor = bitwiseXorValue<Type, Values...>;
  template <Type Value1, Type Value2> using BitwiseOr2 = bitwiseOrValue<Type, Value1, Value2>;
  template <Type Value1, Type Value2> using BitwiseAnd2 = bitwiseAndValue<Type, Value1, Value2>;
  template <Type Value1, Type Value2> using BitwiseXor2 = bitwiseXorValue<Type, Value1, Value2>;
#if (crap_variable_templates >= 201304L)
  template <Type Value> constexpr const static auto bitwiseNot = bitwiseNotValue <Type, Value> :: value;
  template <Type ... Values> constexpr const static auto bitwiseOr = bitwiseOrValue <Type, Values...> :: value;
  template <Type ... Values> constexpr const static auto bitwiseAnd = bitwiseAndValue <Type, Values...> :: value;
  template <Type ... Values> constexpr const static auto bitwiseXor = bitwiseXorValue <Type, Values...> :: value;
  template <Type Value1, Type Value2>
	  constexpr const static auto bitwiseOr2 = bitwiseOrValue <Type, Value1, Value2> :: value;
  template <Type Value1, Type Value2>
	  constexpr const static auto bitwiseAnd2 = bitwiseAndValue <Type, Value1, Value2> :: value;
  template <Type Value1, Type Value2>
	  constexpr const static auto bitwiseXor2 = bitwiseXorValue <Type, Value1, Value2> :: value;
#endif
 };
}
#endif

