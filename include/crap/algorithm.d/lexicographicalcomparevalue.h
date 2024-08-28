#ifndef CRAP_ALGORITHM_LEXICOGRAPHICALCOMPAREVALUE
#define CRAP_ALGORITHM_LEXICOGRAPHICALCOMPAREVALUE

#include "../utility.d/valuelist.h"
#include "../version.d/libintegralconstantcallable.h"

#include <cstddef>

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
  template <Type...> struct with;
  template <Type Only> struct with<Only>;
  template <Type First, Type ... Rest> struct with<First, Rest...>;
 };

 template <class Type, template <Type, Type> class Operator, Type First1, Type ... Rest1>
	 struct lexicographicalCompareValue<Type, Operator, First1, Rest1...>
 {
  using detailedResult_t = typename lexicographicalCompareValue <Type, Operator> :: detailedResult_t;
  template <Type...> struct with;
  template <Type Only> struct with<Only>;
  template <Type First2, Type ... Rest2> struct with<First2, Rest2...>;
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
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type Value1> template <Type...>
	 struct lexicographicalCompareValue <Type, Operator, Value1> :: with
 { //Default is actually for empty case.
  using detailedResult_t = typename lexicographicalCompareValue <Type, Operator> :: detailedResult_t;
  constexpr const static detailedResult_t detailedResult = detailedResult_t :: greater;
  constexpr const static bool value = false;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type Value1> template <Type Only>
	 struct lexicographicalCompareValue <Type, Operator, Value1> :: with<Only>
 {
  private:
  constexpr const static auto less = Operator <Value1, Only> :: value;
  constexpr const static auto greater = Operator <Only, Value1> :: value;
  public:
  using detailedResult_t = typename lexicographicalCompareValue <Type, Operator> :: detailedResult_t;
  constexpr const static detailedResult_t detailedResult = 
	  less ? (detailedResult_t :: less) : (greater ? (detailedResult_t :: greater) : (detailedResult_t :: equal));
  constexpr const static bool value = (detailedResult == (detailedResult_t :: less));
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type Value1> template <Type First, Type ... Rest>
	 struct lexicographicalCompareValue <Type, Operator, Value1> :: with<First, Rest...>
 {
  private:
  constexpr const static auto greater = Operator <First, Value1> :: value;
  public:
  using detailedResult_t = typename lexicographicalCompareValue <Type, Operator> :: detailedResult_t;
  constexpr const static detailedResult_t detailedResult = 
	  greater ? (detailedResult_t :: greater) : (detailedResult_t :: less);
  constexpr const static bool value = (detailedResult == (detailedResult_t :: less));
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type First1, Type ... Rest1> template <Type...>
	 struct lexicographicalCompareValue <Type, Operator, First1, Rest1...> :: with
 {
  using detailedResult_t = typename lexicographicalCompareValue <Type, Operator> :: detailedResult_t;
  constexpr const static detailedResult_t detailedResult = detailedResult_t :: greater;
  constexpr const static bool value = false;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type First1, Type ... Rest1> template <Type Only>
	 struct lexicographicalCompareValue <Type, Operator, First1, Rest1...> :: with<Only>
 {
  private:
  constexpr const static auto less = Operator <First1, Only> :: value;
  public:
  using detailedResult_t = typename lexicographicalCompareValue <Type, Operator> :: detailedResult_t;
  constexpr const static detailedResult_t detailedResult = 
	  less ? (detailedResult_t :: less) : (detailedResult_t :: greater);
  constexpr const static bool value = (detailedResult == (detailedResult_t :: less));
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type First1, Type ... Rest1>
	 template <Type First2, Type ... Rest2>
	 struct lexicographicalCompareValue <Type, Operator, First1, Rest1...> :: with<First2, Rest2...>
 {
  public:
  using detailedResult_t = typename lexicographicalCompareValue <Type, Operator> :: detailedResult_t;
  private:
  constexpr const static std :: size_t half1 = (sizeof...(Rest1) + 1u) / 2u;
  constexpr const static std :: size_t half2 = (sizeof...(Rest2) + 1u) / 2u;
  constexpr const static std :: size_t half = (half1 < half2) ? half1 : half2;
  using values1 = valueList<Type, First1, Rest1...>;
  using values2 = valueList<Type, First2, Rest2...>;
  template <Type ... SubValues> using This = lexicographicalCompareValue<Type, Operator, SubValues...>;
  template <Type ... SubValues>
	  using lower1 = typename values1 :: template till <half, This> :: template with<SubValues...>;
  constexpr const static detailedResult_t lowerResult = values2 :: template till <half, lower1> :: detailedResult;
  template <detailedResult_t LowerResult, std :: size_t> struct upper;
  template <std :: size_t Half> struct upper<detailedResult_t :: equal, Half>;
  public:
  constexpr const static detailedResult_t detailedResult = upper <lowerResult, half> :: detailedResult;
  constexpr const static bool value = (detailedResult == (detailedResult_t :: less));
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type First1, Type ... Rest1>
	 template <Type First2, Type ... Rest2>
	 template <typename lexicographicalCompareValue <Type, Operator> :: detailedResult_t LowerResult, std :: size_t>
	 struct lexicographicalCompareValue <Type, Operator, First1, Rest1...> :: with <First2, Rest2...> :: upper
 {
  constexpr const static typename lexicographicalCompareValue <Type, Operator, First1, Rest2...> :: template
	  with <First2, Rest2...> :: detailedResult_t detailedResult = LowerResult;
 };

 template <class Type, template <Type, Type> class Operator, Type First1, Type ... Rest1>
	 template <Type First2, Type ... Rest2>
	 template <std :: size_t Half>
	 struct lexicographicalCompareValue <Type, Operator, First1, Rest1...> ::
	 with <First2, Rest2...> ::
	 upper<lexicographicalCompareValue <Type, Operator> :: detailedResult_t :: equal, Half>
 {
  private:
  using values1 = valueList<Type, First1, Rest1...>;
  using values2 = valueList<Type, First2, Rest2...>;
  template <Type ... SubValues> using This = lexicographicalCompareValue<Type, Operator, SubValues...>;
  template <Type ... SubValues>
	  using upper1 = typename values1 :: template since <Half, This> :: template with<SubValues...>;
  public:
  constexpr const static typename lexicographicalCompareValue <Type, Operator, First1, Rest2...> :: template
	  with <First2, Rest2...> :: detailedResult_t detailedResult
	  = values2 :: template since <Half, upper1> :: detailedResult;
 };
}

template <class Type, template <Type, Type> class Operator> template <Type ... Values2>
inline constexpr crap :: lexicographicalCompareValue <Type, Operator> :: with <Values2...> :: operator typename
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
crap :: lexicographicalCompareValue <Type, Operator> :: template with <Values2...> :: value_type () const noexcept
#else
crap :: lexicographicalCompareValue <Type, Operator> :: with <Values2...> :: value_type () const noexcept
#endif
{
 return crap :: lexicographicalCompareValue <Type, Operator> :: with <Values2...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator> template <Type ... Values2>
inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
crap :: lexicographicalCompareValue <Type, Operator> :: template with <Values2...> :: value_type
#else
crap :: lexicographicalCompareValue <Type, Operator> :: with <Values2...> :: value_type
#endif
crap :: lexicographicalCompareValue <Type, Operator> :: with <Values2...> :: operator () () const noexcept
{
 return crap :: lexicographicalCompareValue <Type, Operator> :: with <Values2...> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type Value1> template <Type ... Values2>
inline constexpr crap :: lexicographicalCompareValue <Type, Operator, Value1> :: with <Values2...> :: operator
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
typename crap :: lexicographicalCompareValue <Type, Operator, Value1> :: template with <Values2...> :: value_type ()
#else
typename crap :: lexicographicalCompareValue <Type, Operator, Value1> :: with <Values2...> :: value_type ()
#endif
	const noexcept
{
 return crap :: lexicographicalCompareValue <Type, Operator, Value1> :: with <Values2...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type Value1> template <Type ... Values2>
inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
crap :: lexicographicalCompareValue <Type, Operator, Value1> :: template with <Values2...> :: value_type
#else
crap :: lexicographicalCompareValue <Type, Operator, Value1> :: with <Values2...> :: value_type
#endif
crap :: lexicographicalCompareValue <Type, Operator, Value1> :: with <Values2...> :: operator () () const noexcept
{
 return crap :: lexicographicalCompareValue <Type, Operator, Value1> :: with <Values2...> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type Value1> template <Type Only>
inline constexpr crap :: lexicographicalCompareValue <Type, Operator, Value1> :: with <Only> :: operator
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
typename crap :: lexicographicalCompareValue <Type, Operator, Value1> :: template with <Only> :: value_type ()
#else
typename crap :: lexicographicalCompareValue <Type, Operator, Value1> :: with <Only> :: value_type ()
#endif
	const noexcept
{
 return crap :: lexicographicalCompareValue <Type, Operator, Value1> :: with <Only> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type Value1> template <Type Only>
inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
crap :: lexicographicalCompareValue <Type, Operator, Value1> :: template with <Only> :: value_type
#else
crap :: lexicographicalCompareValue <Type, Operator, Value1> :: with <Only> :: value_type
#endif
crap :: lexicographicalCompareValue <Type, Operator, Value1> :: with <Only> :: operator () () const noexcept
{
 return crap :: lexicographicalCompareValue <Type, Operator, Value1> :: with <Only> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type Value1> template <Type First, Type ... Rest>
inline constexpr
crap :: lexicographicalCompareValue <Type, Operator, Value1> :: with <First, Rest...> :: operator typename
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
crap :: lexicographicalCompareValue <Type, Operator, Value1> :: template with <First, Rest...> :: value_type ()
#else
crap :: lexicographicalCompareValue <Type, Operator, Value1> :: with <First, Rest...> :: value_type ()
#endif
	const noexcept
{
 return crap :: lexicographicalCompareValue <Type, Operator, Value1> :: with <First, Rest...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type Value1> template <Type First, Type ... Rest>
inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
crap :: lexicographicalCompareValue <Type, Operator, Value1> :: template with <First, Rest...> :: value_type
#else
crap :: lexicographicalCompareValue <Type, Operator, Value1> :: with <First, Rest...> :: value_type
#endif
crap :: lexicographicalCompareValue <Type, Operator, Value1> :: with <First, Rest...> :: operator () ()
	const noexcept
{
 return crap :: lexicographicalCompareValue <Type, Operator, Value1> :: with <First, Rest...> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type First1, Type ... Rest1> template <Type ... Values2>
inline constexpr crap :: lexicographicalCompareValue <Type, Operator, First1, Rest1...> ::
	with <Values2...> :: operator typename
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
crap :: lexicographicalCompareValue <Type, Operator, First1, Rest1...> :: template with <Values2...> :: value_type ()
#else
crap :: lexicographicalCompareValue <Type, Operator, First1, Rest1...> :: with <Values2...> :: value_type ()
#endif
	const noexcept
{
 return crap :: lexicographicalCompareValue <Type, Operator, First1, Rest1...> :: with <Values2...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type First1, Type ... Rest1> template <Type ... Values2>
inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
crap :: lexicographicalCompareValue <Type, Operator, First1, Rest1...> :: template with <Values2...> :: value_type
#else
crap :: lexicographicalCompareValue <Type, Operator, First1, Rest1...> :: with <Values2...> :: value_type
#endif
crap :: lexicographicalCompareValue <Type, Operator, First1, Rest1...> :: with <Values2...> :: operator () ()
	const noexcept
{
 return crap :: lexicographicalCompareValue <Type, Operator, First1, Rest1...> :: with <Values2...> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type First1, Type ... Rest1> template <Type Only>
inline constexpr
crap :: lexicographicalCompareValue <Type, Operator, First1, Rest1...> :: with <Only> :: operator typename
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
crap :: lexicographicalCompareValue <Type, Operator, First1, Rest1...> :: template with <Only> :: value_type ()
#else
crap :: lexicographicalCompareValue <Type, Operator, First1, Rest1...> :: with <Only> :: value_type ()
#endif
	const noexcept
{
 return crap :: lexicographicalCompareValue <Type, Operator, First1, Rest1...> :: with <Only> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type First1, Type ... Rest1> template <Type Only>
inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
crap :: lexicographicalCompareValue <Type, Operator, First1, Rest1...> :: template with <Only> :: value_type
#else
crap :: lexicographicalCompareValue <Type, Operator, First1, Rest1...> :: with <Only> :: value_type
#endif
crap :: lexicographicalCompareValue <Type, Operator, First1, Rest1...> :: with <Only> :: operator () () const noexcept
{
 return crap :: lexicographicalCompareValue <Type, Operator, First1, Rest1...> :: with <Only> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type First1, Type ... Rest1>
template <Type First2, Type ... Rest2>
inline constexpr crap :: lexicographicalCompareValue <Type, Operator, First1, Rest1...> ::
	with <First2,  Rest2...> :: operator
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
typename crap :: lexicographicalCompareValue <Type, Operator, First1, Rest1...> :: template
#else
typename crap :: lexicographicalCompareValue <Type, Operator, First1, Rest1...> ::
#endif
	with <First2, Rest2...> :: value_type () const noexcept
{
 return crap :: lexicographicalCompareValue <Type, Operator, First1, Rest1...> :: with <First2, Rest2...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type First1, Type ... Rest1>
template <Type First2, Type ... Rest2>
inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
crap :: lexicographicalCompareValue <Type, Operator, First1, Rest1...> :: template
#else
crap :: lexicographicalCompareValue <Type, Operator, First1, Rest1...> ::
#endif
	with <First2,  Rest2...> :: value_type
crap :: lexicographicalCompareValue <Type, Operator, First1, Rest1...> ::
	with <First2,  Rest2...> :: operator () () const noexcept
{
 return crap :: lexicographicalCompareValue <Type, Operator, First1, Rest1...> :: with <First2,  Rest2...> :: value;
}
#endif
#endif

