#ifndef CRAP_FUNCTIONAL_BITWISEOPERATORSFORTYPE
#define CRAP_FUNCTIONAL_BITWISEOPERATORSFORTYPE

#include "bitwiseorvalue.h"
#include "bitwiseandvalue.h"
#include "bitwisenotvalue.h"
#include "bitwisexorvalue.h"

namespace crap
{
 template <class Type> struct bitwiseOperatorsForType
 {
  template <Type Value> using BitwiseNot = bitwiseNotValue<Type, Value>;
  template <Type Value1, Type Value2> using BitwiseOr = bitwiseOrValue<Type, Value1, Value2>;
  template <Type Value1, Type Value2> using BitwiseAnd = bitwiseAndValue<Type, Value1, Value2>;
  template <Type Value1, Type Value2> using BitwiseXor = bitwiseXorValue<Type, Value1, Value2>;
  template <Type Value> constexpr const static auto bitwiseNot = bitwiseNotValue <Type, Value> :: value;
  template <Type Value1, Type Value2> constexpr const static auto bitwiseOr = bitwiseOrValue <Type, Value1, Value2> :: value;
  template <Type Value1, Type Value2> constexpr const static auto bitwiseAnd = bitwiseAndValue <Type, Value1, Value2> :: value;
  template <Type Value1, Type Value2> constexpr const static auto bitwiseXor = bitwiseXorValue <Type, Value1, Value2> :: value;
 };
}
#endif

