#ifndef CRAP_ALGORITHM_LEXICOGRAPHICALCOMPARETYPE
#define CRAP_ALGORITHM_LEXICOGRAPHICALCOMPARETYPE

#include "../utility/typelist.h"

#include <cstddef>

namespace crap
{
 template <template <class, class> class, class...> struct lexicographicalCompareType;

 template <template <class, class> class Operator> struct lexicographicalCompareType<Operator>
 {
  enum class detailedResult_t
  {
   less = -1,
   equal,
   greater,
  };
  template <class ... Types2> struct with;
 };

 template <template <class, class> class Operator, class Type1>
	 struct lexicographicalCompareType<Operator, Type1>
 {
  using detailedResult_t = typename lexicographicalCompareType <Operator> :: detailedResult_t;
  template <class...> struct with;
  template <class Only> struct with<Only>;
  template <class First, class ... Rest> struct with<First, Rest...>;
 };

 template <template <class, class> class Operator, class First1, class ... Rest1>
	 struct lexicographicalCompareType<Operator, First1, Rest1...>
 {
  using detailedResult_t = typename lexicographicalCompareType <Operator> :: detailedResult_t;
  template <class...> struct with;
  template <class Only> struct with<Only>;
  template <class First2, class ... Rest2> struct with<First2, Rest2...>;
 };

 template <template <class, class> class Operator> template <class ... Types2>
	 struct lexicographicalCompareType <Operator> :: with
 {
  using detailedResult_t = typename lexicographicalCompareType <Operator> :: detailedResult_t;
  constexpr const static detailedResult_t detailedResult =
	  ((sizeof...(Types2) != 0u) ? (detailedResult_t :: less) : (detailedResult_t :: equal));
  constexpr const static bool value = (detailedResult == (detailedResult_t :: less));
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <template <class, class> class Operator, class Type1> template <class...>
	 struct lexicographicalCompareType <Operator, Type1> :: with
 { //Default is actually for empty case.
  using detailedResult_t = typename lexicographicalCompareType <Operator> :: detailedResult_t;
  constexpr const static detailedResult_t detailedResult = detailedResult_t :: greater;
  constexpr const static bool value = false;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <template <class, class> class Operator, class Type1> template <class Only>
	 struct lexicographicalCompareType <Operator, Type1> :: template with<Only>
 {
  private:
  constexpr const static auto less = Operator <Type1, Only> :: value;
  constexpr const static auto greater = Operator <Only, Type1> :: value;
  public:
  using detailedResult_t = typename lexicographicalCompareType <Operator> :: detailedResult_t;
  constexpr const static detailedResult_t detailedResult = 
	  less ? (detailedResult_t :: less) : (greater ? (detailedResult_t :: greater) : (detailedResult_t :: equal));
  constexpr const static bool value = (detailedResult == (detailedResult_t :: less));
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <template <class, class> class Operator, class Type1> template <class First, class ... Rest>
	 struct lexicographicalCompareType <Operator, Type1> :: template with<First, Rest...>
 {
  private:
  constexpr const static auto greater = Operator <First, Type1> :: value;
  public:
  using detailedResult_t = typename lexicographicalCompareType <Operator> :: detailedResult_t;
  constexpr const static detailedResult_t detailedResult = 
	  greater ? (detailedResult_t :: greater) : (detailedResult_t :: less);
  constexpr const static bool value = (detailedResult == (detailedResult_t :: less));
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <template <class, class> class Operator, class First1, class ... Rest1> template <class...>
	 struct lexicographicalCompareType <Operator, First1, Rest1...> :: with
 {
  using detailedResult_t = typename lexicographicalCompareType <Operator> :: detailedResult_t;
  constexpr const static detailedResult_t detailedResult = detailedResult_t :: greater;
  constexpr const static bool value = false;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <template <class, class> class Operator, class First1, class ... Rest1> template <class Only>
	 struct lexicographicalCompareType <Operator, First1, Rest1...> :: template with<Only>
 {
  private:
  constexpr const static auto less = Operator <First1, Only> :: value;
  public:
  using detailedResult_t = typename lexicographicalCompareType <Operator> :: detailedResult_t;
  constexpr const static detailedResult_t detailedResult = 
	  less ? (detailedResult_t :: less) : (detailedResult_t :: greater);
  constexpr const static bool value = (detailedResult == (detailedResult_t :: less));
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <template <class, class> class Operator, class First1, class ... Rest1>
	 template <class First2, class ... Rest2>
	 struct lexicographicalCompareType <Operator, First1, Rest1...> :: template with<First2, Rest2...>
 {
  public:
  using detailedResult_t = typename lexicographicalCompareType <Operator> :: detailedResult_t;
  private:
  constexpr const static std :: size_t half1 = (sizeof...(Rest1) + 1u) / 2u;
  constexpr const static std :: size_t half2 = (sizeof...(Rest2) + 1u) / 2u;
  constexpr const static std :: size_t half = (half1 < half2) ? half1 : half2;
  using values1 = typeList<First1, Rest1...>;
  using values2 = typeList<First2, Rest2...>;
  template <class ... SubTypes> using This = lexicographicalCompareType<Operator, SubTypes...>;
  template <class ... SubTypes>
	  using lower1 = typename values1 :: template till <half, This> :: template with<SubTypes...>;
  constexpr const static detailedResult_t lowerResult = values2 :: template till <half, lower1> :: detailedResult;
  template <detailedResult_t LowerResult, std :: size_t> struct upper;
  template <std :: size_t Half> struct upper<detailedResult_t :: equal, Half>;
  public:
  constexpr const static detailedResult_t detailedResult = upper <lowerResult, half> :: detailedResult;
  constexpr const static bool value = (detailedResult == (detailedResult_t :: less));
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <template <class, class> class Operator, class First1, class ... Rest1>
	 template <class First2, class ... Rest2>
	 template <typename lexicographicalCompareType <Operator> :: detailedResult_t LowerResult, std :: size_t>
	 struct lexicographicalCompareType <Operator, First1, Rest1...> :: template with <First2, Rest2...> :: upper
 {
  constexpr const static typename lexicographicalCompareType <Operator, First1, Rest2...> :: template
	  with <First2, Rest2...> :: detailedResult_t detailedResult = LowerResult;
 };

 template <template <class, class> class Operator, class First1, class ... Rest1>
	 template <class First2, class ... Rest2>
	 template <std :: size_t Half>
	 struct lexicographicalCompareType <Operator, First1, Rest1...> :: template
	 with <First2, Rest2...> :: template
	 upper<lexicographicalCompareType <Operator> :: detailedResult_t :: equal, Half>
 {
  private:
  using values1 = typeList<First1, Rest1...>;
  using values2 = typeList<First2, Rest2...>;
  template <class ... SubTypes> using This = lexicographicalCompareType<Operator, SubTypes...>;
  template <class ... SubTypes>
	  using upper1 = typename values1 :: template since <Half, This> :: template with<SubTypes...>;
  public:
  constexpr const static typename lexicographicalCompareType <Operator, First1, Rest2...> :: template
	  with <First2, Rest2...> :: detailedResult_t detailedResult
	  = values2 :: template since <Half, upper1> :: detailedResult;
 };
}

template <template <class, class> class Operator> template <class ... Types2>
inline constexpr crap :: lexicographicalCompareType <Operator> :: template with <Types2...> :: operator
typename crap :: lexicographicalCompareType <Operator> :: template with <Types2...> :: value_type () const noexcept
{
 return crap :: lexicographicalCompareType <Operator> :: template with <Types2...> :: value;
}

template <template <class, class> class Operator, class Type1> template <class ... Types2>
inline constexpr crap :: lexicographicalCompareType <Operator, Type1> :: template with <Types2...> :: operator
typename crap :: lexicographicalCompareType <Operator, Type1> :: template with <Types2...> :: value_type ()
	const noexcept
{
 return crap :: lexicographicalCompareType <Operator, Type1> :: template with <Types2...> :: value;
}

template <template <class, class> class Operator, class Type1> template <class Only>
inline constexpr crap :: lexicographicalCompareType <Operator, Type1> :: template with <Only> :: operator
typename crap :: lexicographicalCompareType <Operator, Type1> :: template with <Only> :: value_type ()
	const noexcept
{
 return crap :: lexicographicalCompareType <Operator, Type1> :: template with <Only> :: value;
}

template <template <class, class> class Operator, class Type1> template <class First, class ... Rest>
inline constexpr crap :: lexicographicalCompareType <Operator, Type1> :: template with <First, Rest...> :: operator
typename crap :: lexicographicalCompareType <Operator, Type1> :: template with <First, Rest...> :: value_type ()
	const noexcept
{
 return crap :: lexicographicalCompareType <Operator, Type1> :: template with <First, Rest...> :: value;
}

template <template <class, class> class Operator, class First1, class ... Rest1> template <class ... Types2>
inline constexpr crap :: lexicographicalCompareType <Operator, First1, Rest1...> :: template
	with <Types2...> :: operator
typename crap :: lexicographicalCompareType <Operator, First1, Rest1...> :: template with <Types2...> :: value_type ()
	const noexcept
{
 return crap :: lexicographicalCompareType <Operator, First1, Rest1...> :: template with <Types2...> :: value;
}

template <template <class, class> class Operator, class First1, class ... Rest1> template <class Only>
inline constexpr crap :: lexicographicalCompareType <Operator, First1, Rest1...> :: template with <Only> :: operator
typename crap :: lexicographicalCompareType <Operator, First1, Rest1...> :: template with <Only> :: value_type ()
	const noexcept
{
 return crap :: lexicographicalCompareType <Operator, First1, Rest1...> :: template with <Only> :: value;
}

template <template <class, class> class Operator, class First1, class ... Rest1>
template <class First2, class ... Rest2>
inline constexpr crap :: lexicographicalCompareType <Operator, First1, Rest1...> :: template
	with <First2,  Rest2...> :: operator
typename crap :: lexicographicalCompareType <Operator, First1, Rest1...> :: template
	with <First2, Rest2...> :: value_type () const noexcept
{
 return crap :: lexicographicalCompareType <Operator, First1, Rest1...> :: template with <First2, Rest2...> :: value;
}
#endif

