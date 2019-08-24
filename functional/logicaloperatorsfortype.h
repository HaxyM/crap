#ifndef CRAP_FUNCTIONAL_LOGICALOPERATORSFORTYPE
#define CRAP_FUNCTIONAL_LOGICALOPERATORSFORTYPE

#include "logicalandvalue.h"
#include "logicalnotvalue.h"
#include "logicalorvalue.h"

#include "../utility/language.h"

namespace crap
{
 template <class Type> struct logicalOperatorsForType
 {
  template <Type Value> using LogicalNot = logicalNotValue<Type, Value>;
  template <Type ... Values> using LogicalOr = logicalOrValue<Type, Values...>;
  template <Type ... Values> using LogicalAnd = logicalAndValue<Type, Values...>;
  template <Type Value1, Type Value2> using LogicalOr2 = logicalOrValue<Type, Value1, Value2>;
  template <Type Value1, Type Value2> using LogicalAnd2 = logicalAndValue<Type, Value1, Value2>;
  #if CPP14
  template <Type Value> constexpr const static auto logicalNot = logicalNotValue <Type, Value> :: value;
  template <Type ... Values> constexpr const static auto logicalOr = logicalOrValue <Type, Values...> :: value;
  template <Type ... Values> constexpr const static auto logicalAnd = logicalAndValue <Type, Values...> :: value;
  template <Type Value1, Type Value2> constexpr const static auto logicalOr2 = logicalOrValue <Type, Value1, Value2> :: value;
  template <Type Value1, Type Value2> constexpr const static auto logicalAnd2 = logicalAndValue <Type, Value1, Value2> :: value;
  #endif
 };
}
#endif

