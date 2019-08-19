#ifndef CRAP_FUNCTIONAL_LOGICALOPERATORSFORTYPE
#define CRAP_FUNCTIONAL_LOGICALOPERATORSFORTYPE

#include "logicalandvalue.h"
#include "logicalnotvalue.h"
#include "logicalorvalue.h"

namespace crap
{
 template <class Type> struct logicalOperatorsForType
 {
  template <Type Value> using LogicalNot = logicalNotValue<Type, Value>;
  template <Type Value1, Type Value2> using LogicalOr = logicalOrValue<Type, Value1, Value2>;
  template <Type Value1, Type Value2> using LogicalAnd = logicalAndValue<Type, Value1, Value2>;
  template <Type Value> constexpr const static auto logicalNot = logicalNotValue <Type, Value> :: value;
  template <Type Value1, Type Value2> constexpr const static auto logicalOr = logicalOrValue <Type, Value1, Value2> :: value;
  template <Type Value1, Type Value2> constexpr const static auto logicalAnd = logicalAndValue <Type, Value1, Value2> :: value;
 };
}
#endif

