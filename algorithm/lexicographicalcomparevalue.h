#ifndef CRAP_ALGORITHM_LEXICOGRAPHICALCOMPAREVALUE
#define CRAP_ALGORITHM_LEXICOGRAPHICALCOMPAREVALUE

#include <type_traits>
#include "../utility/valuelist.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct lexicographicalCompareValue;

 template <class Type, template <Type, Type> class Operator> struct lexicographicalCompareValue<Type, Operator>
 {
  enum class results
  {
   smaller,
   equal,
   greater,
  };
  template <Type ... Values2> struct with;
 };

 template <class Type, template <Type, Type> class Operator, Type Value>
	 struct lexicographicalCompareValue<Type, Operator, Value>
 {
  using results = typename lexicographicalCompareValue <Type, Operator> :: results;
  template <Type ... Values2> struct with;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1>
	 struct lexicographicalCompareValue
 {
  using results = typename lexicographicalCompareValue <Type, Operator> :: results;
  template <Type ... Values2> struct with;
 };

 template <class Type, template <Type, Type> class Operator> template <Type ... Values2>
	 struct lexicographicalCompareValue <Type, Operator> :: with
 {
  using results = typename lexicographicalCompareValue <Type, Operator> :: results;
  constexpr const static results detailedResult =
	  ((sizeof...(Values2) != 0u) ? (results :: smaller) : (results :: equal));
  constexpr const static bool value = (detailedResult == (results :: smaller));
 };

 template <class Type, template <Type, Type> class Operator, Type Value> template <Type ... Values2>
	 struct lexicographicalCompareValue <Type, Operator, Value> :: with
 {
  public:
  using results = typename lexicographicalCompareValue <Type, Operator, Value> :: results;
  private:
  constexpr const static results getResult(...) noexcept;
  //template <Type FirstValue>
  //constexpr const static results getResult(std :: integral_constant<Type, FirstValue>) noexcept;
  template <Type FirstValue>
	  constexpr const static results getResult(std :: integral_constant<Type, FirstValue>, ...) noexcept;
  public:
  constexpr const static results detailedResult = getResult(std :: integral_constant<Type, Values2>{}...);
  constexpr const static bool value = (detailedResult == (results :: smaller));
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1>
	 template <Type ... Values2> struct lexicographicalCompareValue <Type, Operator, Values1...> :: with
 {
  public:
  using results = typename lexicographicalCompareValue <Type, Operator, Values1...> :: results;
  private:
  template <Type ... SubValues> using This = lexicographicalCompareValue <Type, Operator, SubValues...>;
  constexpr const static results getResult(...) noexcept;
  constexpr const static results getResult(Type, ...) noexcept;
  public:
  constexpr const static results detailedResult = getResult(Values2...);
  constexpr const static bool value = (detailedResult == (results :: smaller));
 };
}

template <class Type, template <Type, Type> class Operator, Type Value>
template <Type ... Values2> inline constexpr const typename
crap :: lexicographicalCompareValue <Type, Operator, Value> :: template with <Values2...> :: results
crap :: lexicographicalCompareValue <Type, Operator, Value> :: template with <Values2...> :: getResult(...) noexcept
{
 return crap :: lexicographicalCompareValue <Type, Operator, Value> :: template with <Values2...> :: results :: larger;
}

template <class Type, template <Type, Type> class Operator, Type Value>
template <Type ... Values2> template <Type FirstValue> inline constexpr const typename
crap :: lexicographicalCompareValue <Type, Operator, Value> :: template with <Values2...> :: results
crap :: lexicographicalCompareValue <Type, Operator, Value> :: template with <Values2...> :: getResult(std :: integral_constant<Type, FirstValue>, ...) noexcept
{
 constexpr const bool firstSmaller = Operator <Value, FirstValue> :: value;
 constexpr const bool firstGreater = Operator <FirstValue, Value> :: value;
 constexpr const bool hasTail = (sizeof...(Values2) > 1u);
 constexpr const auto Smaller = crap :: lexicographicalCompareValue <Type, Operator, Value> :: template with <Values2...> :: results :: smaller;
 constexpr const auto Greater = crap :: lexicographicalCompareValue <Type, Operator, Value> :: template with <Values2...> :: results :: greater;
 constexpr const auto Equal = crap :: lexicographicalCompareValue <Type, Operator, Value> :: template with <Values2...> :: results :: equal;
 constexpr const auto equalWithTail = (hasTail ? Smaller : Equal);
 constexpr const auto greaterOrEqual = (firstGreater ? Greater : equalWithTail);
 return (firstSmaller ? Smaller : greaterOrEqual);
}

template <class Type, template <Type, Type> class Operator, Type ... Values1>
template <Type ... Values2> inline constexpr const typename
crap :: lexicographicalCompareValue <Type, Operator, Values1...> :: template with <Values2...> :: results
crap :: lexicographicalCompareValue <Type, Operator, Values1...> :: template with <Values2...> :: getResult(...) noexcept
{
 return crap :: lexicographicalCompareValue <Type, Operator, Values1...> :: template with <Values2...> :: results :: greater;
}

template <class Type, template <Type, Type> class Operator, Type ... Values1>
template <Type ... Values2> inline constexpr const typename
crap :: lexicographicalCompareValue <Type, Operator, Values1...> :: template with <Values2...> :: results
crap :: lexicographicalCompareValue <Type, Operator, Values1...> :: template with <Values2...> :: getResult(Type, ...) noexcept
{
 using values1 = valueList<Type, Values1...>;
 using values2 = valueList<Type, Values2...>;
 constexpr const std :: size_t half = ((values1 :: size) < (values2 :: size) ? (values1 :: size) : (values2 :: size)) / 2u;
 using lower1 = typename values1 :: template till <half, This>;
 using upper1 = typename values1 :: template since <half, This>;
 using lower = typename values2 :: template till<half, lower1 :: template with>;
 using upper = typename values2 :: template since<half, upper1 :: template with>;
 constexpr const auto Equal = crap :: lexicographicalCompareValue <Type, Operator, Value> :: template with <Values2...> :: results :: equal;
 return (((lower :: detailedResult) == Equal) ? (upper :: detailedResult) : (lower :: detailedResult));
}
#endif

