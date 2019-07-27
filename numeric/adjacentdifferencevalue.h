#ifndef CRAP_NUMERIC_ADJACENTDIFFERENCEVALUE
#define CRAP_NUMERIC_ADJACENTDIFFERENCEVALUE

#include "../utility/valuelist.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct adjacentDifferenceValue;

 template <class Type, template <Type, Type> class Operator> struct adjacentDifferenceValue<Type, Operator>
 {
  using type = valueList<Type>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> struct adjacentDifferenceValue
 {
  private:
  using values = valueList<Type, Values...>;
  template <std :: size_t Index> using valueAt = Operator<values :: template at<Index + 1u>, values :: template at<Index> >;
  template <std :: size_t ... Indices> static valueList<Type, values :: template at<0u>, valueAt <Indices> :: value...>
  generate(std :: index_sequence<Indices...>);
  public:
  using type = decltype(generate(std :: make_index_sequence<values :: size - 1u>{}));
 };
}
#endif

