#ifndef CRAP_ALGORITHM_SEARCHTYPE
#define CRAP_ALGORITHM_SEARCHTYPE

#include "findtype.h"
#include "mismatchtype.h"
#include "../utility.d/bisecttype.h"
#include "../utility.d/sizetype.h"
#include "../utility.d/typelist.h"
#include "../version.d/libintegralconstantcallable.h"

#include <cstddef>

namespace crap
{
 template <template <class, class> class, class...> struct searchType;

 template <template <class, class> class Operator> struct searchType<Operator>
 {
  template <class ... Pattern> struct with;
 };

 template <template <class, class> class Operator, class Type> struct searchType<Operator, Type>
 {
  template <class...> struct with;
  template <class Only> struct with<Only>;
  template <class First, class ... Rest> struct with<First, Rest...>;
 };

 template <template <class, class> class Operator, class ... Types> struct searchType
 {
  template <class...> struct with;
  template <class Only> struct with<Only>;
  template <class First, class ... Rest> struct with<First, Rest...>;
 };

 template <template <class, class> class Operator> template <class ... Pattern>
	 struct searchType <Operator> :: with
 {
  constexpr const static std :: size_t matched = 0u;
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class Type> template <class...>
	 struct searchType <Operator, Type> :: with
 {
  constexpr const static std :: size_t matched = 0u;
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class Type> template <class Only>
	 struct searchType <Operator, Type> :: with<Only>
 {
  constexpr const static std :: size_t matched = ((Operator <Only, Type> :: value) ? 1u : 0u);
  constexpr const static std :: size_t value = ((Operator <Only, Type> :: value) ? 0u : 1u);
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class Type> template <class First, class ... Rest>
	 struct searchType <Operator, Type> :: with<First, Rest...>
 {
  constexpr const static std :: size_t matched = ((Operator <First, Type> :: value) ? 1u : 0u);
  constexpr const static std :: size_t value = 1u;
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class ... Types> template <class...>
	 struct searchType <Operator, Types...> :: with
 {
  constexpr const static std :: size_t matched = 0u;
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = sizeof...(Types);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class ... Types> template <class Only>
	 struct searchType <Operator, Types...> :: with<Only>
 {
  private:
  using found = findType<Only, Operator, Types...>;
  public:
  constexpr const static std :: size_t matched = ((found :: value == found :: npos) ? 0u : 1u);
  constexpr const static std :: size_t value = found :: value;
  constexpr const static std :: size_t npos = found :: npos;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class ... Types> template <class First, class ... Rest>
	 struct searchType <Operator, Types...> :: with<First, Rest...>
 {
  private:
  using values = bisectType<Types...>;
  template <class ... SubTypes>
	  using This = typename searchType <Operator, SubTypes...> :: template with<First, Rest...>;
  using lower = typename values :: template lower<This>;
  template <std :: size_t LowerValue, std :: size_t LowerNpos, std :: size_t LowerMatched> struct upper;
  template <std :: size_t LowerNpos> struct upper<LowerNpos, LowerNpos, 0u>;
  template <std :: size_t LowerNpos, std :: size_t LowerMatched> struct upper<LowerNpos, LowerNpos, LowerMatched>;
  public:
  constexpr const static std :: size_t matched = upper <lower :: value, lower :: npos, lower :: matched> :: matched;
  constexpr const static std :: size_t value = upper <lower :: value, lower :: npos, lower :: matched> :: value;
  constexpr const static std :: size_t npos = sizeof...(Types);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class ... Types>
	 template <class First, class ... Rest>
	 template <std :: size_t LowerValue, std :: size_t LowerNpos, std :: size_t LowerMatched>
 struct searchType <Operator, Types...> ::
	with <First, Rest...> :: upper
 {
  constexpr const static std :: size_t matched = LowerMatched;
  constexpr const static std :: size_t value = LowerValue;
  constexpr const static std :: size_t npos = LowerNpos;
 };

 template <template <class, class> class Operator, class ... Types>
	 template <class First, class ... Rest>
	 template <std :: size_t LowerNpos>
 struct searchType <Operator, Types...> ::
 	with <First, Rest...> :: upper<LowerNpos, LowerNpos, 0u>
 {
  private:
  constexpr const static std :: size_t half = sizeof...(Types) / 2u;
  using values = bisectType<Types...>;
  template <class ... SubTypes>
	  using This = typename searchType <Operator, SubTypes...> :: template with<First, Rest...>;
  using result = typename values :: template upper<This>;
  public:
  constexpr const static std :: size_t matched = result :: matched;
  constexpr const static std :: size_t value = half + (result :: value);
  constexpr const static std :: size_t npos = sizeof...(Types);
 };

 template <template <class, class> class Operator, class ... Types>
	 template <class First, class ... Rest>
	 template <std :: size_t LowerNpos, std :: size_t LowerMatched>
 struct searchType <Operator, Types...> ::
	with <First, Rest...> :: upper<LowerNpos, LowerNpos, LowerMatched>
 {
  private:
  using values = bisectType<Types...>;
  template <template <class...> class Container>
	  using subPattern = typename typeList<First, Rest...> :: template since<LowerMatched, Container>;
  template <class ... SubTypes> using mismatch = mismatchType<Operator, SubTypes...>;
  using result = subPattern<values :: template upper <mismatch> :: template with>;
  constexpr const static std :: size_t subPatternLength = subPattern <sizeType> :: value;
  constexpr const static std :: size_t upperLength = values :: template upper <sizeType> :: value;
  template <std :: size_t MismatchValue, std :: size_t SubPatternLength, std :: size_t UpperLength>
	  struct partialCheck;
  template <std :: size_t PerfectMatch> struct partialCheck<PerfectMatch, PerfectMatch, PerfectMatch>;
  template <std :: size_t SubPatternLength, std :: size_t UpperLength>
	  struct partialCheck<SubPatternLength, SubPatternLength, UpperLength>;
  template <std :: size_t SubPatternLength, std :: size_t UpperLength>
	  struct partialCheck<UpperLength, SubPatternLength, UpperLength>;
  public:
  constexpr const static std :: size_t matched =
	  partialCheck <result :: value, subPatternLength, upperLength> :: matched;
  constexpr const static std :: size_t value =
	  (partialCheck <result :: value, subPatternLength, upperLength> :: value);
  constexpr const static std :: size_t npos = sizeof...(Types);
 };

 template <template <class, class> class Operator, class ... Types>
	 template <class First, class ... Rest>
	 template <std :: size_t LowerNpos, std :: size_t LowerMatched>
	 template <std :: size_t MismatchValue, std :: size_t SubPatternLength, std :: size_t UpperLength>
 struct searchType <Operator, Types...> ::
	with <First, Rest...> ::
	upper <LowerNpos, LowerNpos, LowerMatched> :: partialCheck
 {
  private:
  constexpr const static std :: size_t shift = (sizeof...(Types) / 2u) + MismatchValue;
  template <class ... SubTypes>
	  using This = typename searchType <Operator, SubTypes...> :: template with<First, Rest...>;
  using result = typename typeList <Types...> :: template since<shift, This>;
  public:
  constexpr const static std :: size_t matched = result :: matched;
  constexpr const static std :: size_t value = shift + (result :: value);
  constexpr const static std :: size_t npos = sizeof...(Types);
 };

 template <template <class, class> class Operator, class ... Types>
	 template <class First, class ... Rest>
	 template <std :: size_t LowerNpos, std :: size_t LowerMatched>
	 template <std :: size_t PerfectMatch>
 struct searchType <Operator, Types...> ::
	with <First, Rest...> ::
	upper <LowerNpos, LowerNpos, LowerMatched> ::
	partialCheck<PerfectMatch, PerfectMatch, PerfectMatch>
 {
  constexpr const static std :: size_t matched = sizeof...(Rest) + 1u;
  constexpr const static std :: size_t value = sizeof...(Types) - matched;
  constexpr const static std :: size_t npos = sizeof...(Types);
 };

 template <template <class, class> class Operator, class ... Types>
	 template <class First, class ... Rest>
	 template <std :: size_t LowerNpos, std :: size_t LowerMatched>
	 template <std :: size_t SubPatternLength, std :: size_t UpperLength>
 struct searchType <Operator, Types...> ::
	with <First, Rest...> ::
	upper <LowerNpos, LowerNpos, LowerMatched> ::
	partialCheck<SubPatternLength, SubPatternLength, UpperLength>
 {
  constexpr const static std :: size_t matched = 0u;
  constexpr const static std :: size_t value = LowerNpos - LowerMatched;
  constexpr const static std :: size_t npos = sizeof...(Types);
 };

 template <template <class, class> class Operator, class ... Types>
	 template <class First, class ... Rest>
	 template <std :: size_t LowerNpos, std :: size_t LowerMatched>
	 template <std :: size_t SubPatternLength, std :: size_t UpperLength>
 struct searchType <Operator, Types...> ::
	with <First, Rest...> ::
	upper <LowerNpos, LowerNpos, LowerMatched> ::
	partialCheck<UpperLength, SubPatternLength, UpperLength>
 {
  constexpr const static std :: size_t matched = LowerMatched + UpperLength;
  constexpr const static std :: size_t value = sizeof...(Types);
  constexpr const static std :: size_t npos = sizeof...(Types);
 };
}

template <template <class, class> class Operator> template <class ... Pattern>
        inline constexpr
	crap :: searchType <Operator> :: with <Pattern...> :: operator typename
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: searchType <Operator> :: template with <Pattern...> :: value_type ()
#else
	crap :: searchType <Operator> :: with <Pattern...> :: value_type ()
#endif
	const noexcept
{
 return crap :: searchType <Operator> :: with <Pattern...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator> template <class ... Pattern>
        inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
        crap :: searchType <Operator> :: template with <Pattern...> :: value_type
#else
        crap :: searchType <Operator> :: with <Pattern...> :: value_type
#endif
        crap :: searchType <Operator> :: with <Pattern...> :: operator () ()
	const noexcept
{
 return crap :: searchType <Operator> :: with <Pattern...> :: value;
}
#endif

template <template <class, class> class Operator, class Type> template <class ... Empty>
        inline constexpr
	crap :: searchType <Operator, Type> :: with <Empty...> :: operator typename
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: searchType <Operator, Type> :: template with <Empty...> :: value_type ()
#else
	crap :: searchType <Operator, Type> :: with <Empty...> :: value_type ()
#endif
	const noexcept
{
 return crap :: searchType <Operator, Type> :: with <Empty...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class Type> template <class ... Empty>
        inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
        crap :: searchType <Operator, Type> :: template with <Empty...> :: value_type
#else
        crap :: searchType <Operator, Type> :: with <Empty...> :: value_type
#endif
        crap :: searchType <Operator, Type> :: with <Empty...> :: operator () ()
	const noexcept
{
 return crap :: searchType <Operator, Type> :: with <Empty...> :: value;
}
#endif

template <template <class, class> class Operator, class Type> template <class Only>
        inline constexpr
	crap :: searchType <Operator, Type> :: with <Only> :: operator typename
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: searchType <Operator, Type> :: template with <Only> :: value_type ()
#else
	crap :: searchType <Operator, Type> :: with <Only> :: value_type ()
#endif
	const noexcept
{
 return crap :: searchType <Operator, Type> :: with <Only> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class Type> template <class Only>
        inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
        crap :: searchType <Operator, Type> :: template with <Only> :: value_type
#else
        crap :: searchType <Operator, Type> :: with <Only> :: value_type
#endif
        crap :: searchType <Operator, Type> :: with <Only> :: operator () ()
	const noexcept
{
 return crap :: searchType <Operator, Type> :: with <Only> :: value;
}
#endif

template <template <class, class> class Operator, class Type> template <class First, class ... Rest>
        inline constexpr
	crap :: searchType <Operator, Type> :: with <First, Rest...> :: operator typename
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: searchType <Operator, Type> :: template with <First, Rest...> :: value_type ()
#else
	crap :: searchType <Operator, Type> :: with <First, Rest...> :: value_type ()
#endif
	const noexcept
{
 return crap :: searchType <Operator, Type> :: with <First, Rest...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class Type> template <class First, class ... Rest>
        inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
        crap :: searchType <Operator, Type> :: template with <First, Rest...> :: value_type
#else
        crap :: searchType <Operator, Type> :: with <First, Rest...> :: value_type
#endif
        crap :: searchType <Operator, Type> :: with <First, Rest...> :: operator () ()
	const noexcept
{
 return crap :: searchType <Operator, Type> :: with <First, Rest...> :: value;
}
#endif

template <template <class, class> class Operator, class ... Types> template <class ... Empty>
        inline constexpr
	crap :: searchType <Operator, Types...> :: with <Empty...> :: operator typename
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: searchType <Operator, Types...> :: template with <Empty...> :: value_type ()
#else
	crap :: searchType <Operator, Types...> :: with <Empty...> :: value_type ()
#endif
	const noexcept
{
 return crap :: searchType <Operator, Types...> :: with <Empty...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class ... Types> template <class ... Empty>
        inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
        crap :: searchType <Operator, Types...> :: template with <Empty...> :: value_type
#else
        crap :: searchType <Operator, Types...> :: with <Empty...> :: value_type
#endif
        crap :: searchType <Operator, Types...> :: with <Empty...> :: operator () ()
	const noexcept
{
 return crap :: searchType <Operator, Types...> :: with <Empty...> :: value;
}
#endif

template <template <class, class> class Operator, class ... Types> template <class Only>
        inline constexpr
	crap :: searchType <Operator, Types...> :: with <Only> :: operator typename
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: searchType <Operator, Types...> :: template with <Only> :: value_type ()
#else
	crap :: searchType <Operator, Types...> :: with <Only> :: value_type ()
#endif
	const noexcept
{
 return crap :: searchType <Operator, Types...> :: with <Only> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class ... Types> template <class Only>
        inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
        crap :: searchType <Operator, Types...> :: template with <Only> :: value_type
#else
        crap :: searchType <Operator, Types...> :: with <Only> :: value_type
#endif
        crap :: searchType <Operator, Types...> :: with <Only> :: operator () ()
	const noexcept
{
 return crap :: searchType <Operator, Types...> :: with <Only> :: value;
}
#endif

template <template <class, class> class Operator, class ... Types> template <class First, class ... Rest>
        inline constexpr
	crap :: searchType <Operator, Types...> :: with <First, Rest...> :: operator typename
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: searchType <Operator, Types...> :: template with <First, Rest...> :: value_type ()
#else
	crap :: searchType <Operator, Types...> :: with <First, Rest...> :: value_type ()
#endif
	const noexcept
{
 return crap :: searchType <Operator, Types...> :: with <First, Rest...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class ... Types> template <class First, class ... Rest>
        inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
        crap :: searchType <Operator, Types...> :: template with <First, Rest...> :: value_type
#else
        crap :: searchType <Operator, Types...> :: with <First, Rest...> :: value_type
#endif
        crap :: searchType <Operator, Types...> :: with <First, Rest...> :: operator () ()
	const noexcept
{
 return crap :: searchType <Operator, Types...> :: with <First, Rest...> :: value;
}
#endif
#endif

