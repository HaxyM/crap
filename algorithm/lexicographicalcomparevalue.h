#ifndef CRAP_ALGORITHM_LEXICOGRAPHICALCOMPAREVALUE
#define CRAP_ALGORITHM_LEXICOGRAPHICALCOMPAREVALUE

#include "copyvalue.h"
#include "../utility/frontvalue.h"
#include "../utility/valuedemultiplexer.h"
#include "../utility/valuelist.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct lexicographicalCompareValue;

 template <class Type, template <Type, Type> class Operator> struct lexicographicalCompareValue<Type, Operator>
 {
  enum class detailedResult_t
  {
   less = -1,
   equal,
   greater,
  };
  template <Type ... Values2> struct with;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1>
	 struct lexicographicalCompareValue<Type, Operator, Value1>
 {
  using detailedResult_t = typename lexicographicalCompareValue <Type, Operator> :: detailedResult_t;
  template <Type ... Values2> struct with;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1>
	 struct lexicographicalCompareValue
 {
  using detailedResult_t = typename lexicographicalCompareValue <Type, Operator> :: detailedResult_t;
  template <Type ... Values2> struct with;
 };

 template <class Type, template <Type, Type> class Operator> template <Type ... Values2>
	 struct lexicographicalCompareValue <Type, Operator> :: with
 {
  using detailedResult_t = typename lexicographicalCompareValue <Type, Operator> :: detailedResult_t;
  constexpr const static detailedResult_t detailedResult =
	  ((sizeof...(Values2) != 0u) ? (detailedResult_t :: less) : (detailedResult_t :: equal));
  constexpr const static bool value = (detailedResult == (detailedResult_t :: less));
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1> template <Type ... Values2>
	 struct lexicographicalCompareValue <Type, Operator, Value1> :: with
 {
  private:
  template <Type...> struct emptyImplementation;
  template <Type...> struct nonemptyImplementation;
  constexpr const static bool isEmpty = (sizeof...(Values2) == 0u);
  using result = typename valueDemultiplexer <Type, isEmpty, copyValue <Type> :: template type, emptyImplementation, nonemptyImplementation> :: type;
  public:
  using detailedResult_t = typename lexicographicalCompareValue <Type, Operator> :: detailedResult_t;
  constexpr const static detailedResult_t detailedResult = (result :: detailedResult);
  constexpr const static bool value = (detailedResult == (detailedResult_t :: less));
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1>
	 template <Type ... Values2> struct lexicographicalCompareValue <Type, Operator, Values1...> :: with
 {
  private:
  template <Type...> struct emptyImplementation;
  template <Type...> struct nonemptyImplementation;
  constexpr const static bool isEmpty = (sizeof...(Values2) == 0u);
  using result = typename valueDemultiplexer <Type, isEmpty, copyValue <Type> :: template type, emptyImplementation, nonemptyImplementation> :: type;
  public:
  using detailedResult_t = typename lexicographicalCompareValue <Type, Operator> :: detailedResult_t;
  constexpr const static detailedResult_t detailedResult = (result :: detailedResult);
  constexpr const static bool value = (detailedResult == (detailedResult_t :: less));
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1> template <Type ... Values2> template <Type...>
	 struct lexicographicalCompareValue <Type, Operator, Value1> :: template with <Values2...> :: emptyImplementation
 {
  using detailedResult_t = typename lexicographicalCompareValue <Type, Operator> :: detailedResult_t;
  constexpr const static detailedResult_t detailedResult = (detailedResult_t :: greater);
 };

 template <class Type, template <Type, Type> class Operator, Type Value1> template <Type ... Values2> template <Type...>
	 struct lexicographicalCompareValue <Type, Operator, Value1> :: template with <Values2...> :: nonemptyImplementation
 {
  private:
  constexpr const static Type front = frontValue <Type, Values2...> :: value;
  constexpr const static bool smaller = Operator <Value1, front> :: value;
  constexpr const static bool greater = Operator <front, Value1> :: value;
  constexpr const static bool shorter = (sizeof...(Values2) > 1u);
  constexpr const static bool equal = !(smaller || greater || shorter);
  constexpr const static bool less = !(equal || greater);
  public:
  using detailedResult_t = typename lexicographicalCompareValue <Type, Operator> :: detailedResult_t;
  constexpr const static detailedResult_t detailedResult =
	  (less ? (detailedResult_t :: less) : (equal ? (detailedResult_t :: equal) : (detailedResult_t :: greater)));
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1> template <Type ... Values2> template <Type...>
	 struct lexicographicalCompareValue <Type, Operator, Values1...> :: template with <Values2...> :: emptyImplementation
 {
  using detailedResult_t = typename lexicographicalCompareValue <Type, Operator> :: detailedResult_t;
  constexpr const static detailedResult_t detailedResult = (detailedResult_t :: greater);
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1> template <Type ... Values2> template <Type...>
	 struct lexicographicalCompareValue <Type, Operator, Values1...> :: template with <Values2...> :: nonemptyImplementation
 {
  private:
  using values1 = valueList<Type, Values1...>;
  using values2 = valueList<Type, Values2...>;
  constexpr const static std :: size_t half1 = ((values1 :: size) / 2u);
  constexpr const static std :: size_t half = ((half1 < (values2 :: size)) ? half1 : (values2 :: size));
  template <Type ... SubValues> using This = lexicographicalCompareValue<Type, Operator, SubValues...>;
  using lower = typename values2 :: template till<half, values1 :: template till <half, This> :: template with>;
  using upper = typename values2 :: template since<half, values1 :: template since <half, This> :: template with>;
  public:
  using detailedResult_t = typename lexicographicalCompareValue <Type, Operator> :: detailedResult_t;
  constexpr const static detailedResult_t detailedResult =
	  (((lower :: detailedResult) == (detailedResult_t :: equal)) ? (upper :: detailedResult) : (lower :: detailedResult));
 };
}

template <class Type, template <Type, Type> class Operator> template <Type ... Values2>
inline constexpr crap :: lexicographicalCompareValue <Type, Operator> :: template with <Values2...> :: operator
typename crap :: lexicographicalCompareValue <Type, Operator> :: template with <Values2...> :: value_type ()
	const noexcept
{
 return crap :: lexicographicalCompareValue <Type, Operator> :: template with <Values2...> :: value;
}

template <class Type, template <Type, Type> class Operator, Type Value1> template <Type ... Values2>
inline constexpr crap :: lexicographicalCompareValue <Type, Operator, Value1> :: template
	with <Values2...> :: operator
typename crap :: lexicographicalCompareValue <Type, Operator, Value1> :: template with <Values2...> :: value_type ()
	const noexcept
{
 return crap :: lexicographicalCompareValue <Type, Operator, Value1> :: template with <Values2...> :: value;
}

template <class Type, template <Type, Type> class Operator, Type ... Values1> template <Type ... Values2>
inline constexpr crap :: lexicographicalCompareValue <Type, Operator, Values1...> :: template
	with <Values2...> :: operator
typename crap :: lexicographicalCompareValue <Type, Operator, Values1...> :: template
	with <Values2...> :: value_type () const noexcept
{
 return crap :: lexicographicalCompareValue <Type, Operator, Values1...> :: template with <Values2...> :: value;
}
#endif

