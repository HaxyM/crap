#ifndef CRAP_FUNCTIONAL_COMPARATORSFORTYPE
#define CRAP_FUNCTIONAL_COMPARATORSFORTYPE

#include "lessvalue.h"
#include "equaltovalue.h"
#include "greatervalue.h"
#include "lessequalvalue.h"
#include "notequaltovalue.h"
#include "greaterequalvalue.h"
#include "../utility.d/language.h"

namespace crap
{
 template <class Type> struct comparatorsForType
 {
  template <Type Value1, Type Value2> using Less = lessValue<Type, Value1, Value2>;
  template <Type Value1, Type Value2> using EqualTo = equalToValue<Type, Value1, Value2>;
  template <Type Value1, Type Value2> using Greater = greaterValue<Type, Value1, Value2>;
  template <Type Value1, Type Value2> using LessEqual = lessEqualValue<Type, Value1, Value2>;
  template <Type Value1, Type Value2> using NotEqualTo = notEqualToValue<Type, Value1, Value2>;
  template <Type Value1, Type Value2> using GreaterEqual = greaterEqualValue<Type, Value1, Value2>;
  #if CPP14
  template <Type Value1, Type Value2> constexpr const static auto less = lessValue <Type, Value1, Value2> :: value;
  template <Type Value1, Type Value2> constexpr const static auto equalTo = equalToValue <Type, Value1, Value2> :: value;
  template <Type Value1, Type Value2> constexpr const static auto greater = greaterValue <Type, Value1, Value2> :: value;
  template <Type Value1, Type Value2> constexpr const static auto lessequal = lessEqualValue <Type, Value1, Value2> :: value;
  template <Type Value1, Type Value2> constexpr const static auto notEqualTo = notEqualToValue <Type, Value1, Value2> :: value;
  template <Type Value1, Type Value2> constexpr const static auto greaterEqual = greaterEqualValue <Type, Value1, Value2> :: value;
  #endif
 };
}
#endif

