#ifndef CRAP_ALGORITHM_SEARCHVALUE
#define CRAP_ALGORITHM_SEARCHVALUE

#include "findvalue.h"
#include "mismatchfortype.h"
#include "../utility.d/bisectvalue.h"
#include "../utility.d/sizefortype.h"
#include "../utility.d/valuelist.h"
#include "../version.d/libintegralconstantcallable.h"

#include <cstddef>

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct searchValue;

 template <class Type, template <Type, Type> class Operator> struct searchValue<Type, Operator>
 {
  template <Type ... Pattern> struct with;
 };

 template <class Type, template <Type, Type> class Operator, Type Value> struct searchValue<Type, Operator, Value>
 {
  template <Type...> struct with;
  template <Type Only> struct with<Only>;
  template <Type First, Type ... Rest> struct with<First, Rest...>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> struct searchValue
 {
  template <Type...> struct with;
  template <Type Only> struct with<Only>;
  template <Type First, Type ... Rest> struct with<First, Rest...>;
 };

 template <class Type, template <Type, Type> class Operator> template <Type ... Pattern>
	 struct searchValue <Type, Operator> :: with
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

 template <class Type, template <Type, Type> class Operator, Type Value> template <Type...>
	 struct searchValue <Type, Operator, Value> :: with
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

 template <class Type, template <Type, Type> class Operator, Type Value> template <Type Only>
	 struct searchValue <Type, Operator, Value> :: with<Only>
 {
  constexpr const static std :: size_t matched = ((Operator <Only, Value> :: value) ? 1u : 0u);
  constexpr const static std :: size_t value = ((Operator <Only, Value> :: value) ? 0u : 1u);
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type Value> template <Type First, Type ... Rest>
	 struct searchValue <Type, Operator, Value> :: with<First, Rest...>
 {
  constexpr const static std :: size_t matched = ((Operator <First, Value> :: value) ? 1u : 0u);
  constexpr const static std :: size_t value = 1u;
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> template <Type...>
	 struct searchValue <Type, Operator, Values...> :: with
 {
  constexpr const static std :: size_t matched = 0u;
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = sizeof...(Values);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> template <Type Only>
	 struct searchValue <Type, Operator, Values...> :: with<Only>
 {
  private:
  using found = findValue<Type, Only, Operator, Values...>;
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

 template <class Type, template <Type, Type> class Operator, Type ... Values> template <Type First, Type ... Rest>
	 struct searchValue <Type, Operator, Values...> :: with<First, Rest...>
 {
  private:
  using values = bisectValue<Type, Values...>;
  template <Type ... SubValues>
	  using This = typename searchValue <Type, Operator, SubValues...> :: template with<First, Rest...>;
  using lower = typename values :: template lower<This>;
  template <std :: size_t LowerValue, std :: size_t LowerNpos, std :: size_t LowerMatched> struct upper;
  template <std :: size_t LowerNpos> struct upper<LowerNpos, LowerNpos, 0u>;
  template <std :: size_t LowerNpos, std :: size_t LowerMatched> struct upper<LowerNpos, LowerNpos, LowerMatched>;
  public:
  constexpr const static std :: size_t matched = upper <lower :: value, lower :: npos, lower :: matched> :: matched;
  constexpr const static std :: size_t value = upper <lower :: value, lower :: npos, lower :: matched> :: value;
  constexpr const static std :: size_t npos = sizeof...(Values);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <Type First, Type ... Rest>
	 template <std :: size_t LowerValue, std :: size_t LowerNpos, std :: size_t LowerMatched>
 struct searchValue <Type, Operator, Values...> ::
	with <First, Rest...> :: upper
 {
  constexpr const static std :: size_t matched = LowerMatched;
  constexpr const static std :: size_t value = LowerValue;
  constexpr const static std :: size_t npos = LowerNpos;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <Type First, Type ... Rest>
	 template <std :: size_t LowerNpos>
 struct searchValue <Type, Operator, Values...> ::
 	with <First, Rest...> :: upper<LowerNpos, LowerNpos, 0u>
 {
  private:
  constexpr const static std :: size_t half = sizeof...(Values) / 2u;
  using values = bisectValue<Type, Values...>;
  template <Type ... SubValues>
	  using This = typename searchValue <Type, Operator, SubValues...> :: template with<First, Rest...>;
  using result = typename values :: template upper<This>;
  public:
  constexpr const static std :: size_t matched = result :: matched;
  constexpr const static std :: size_t value = half + (result :: value);
  constexpr const static std :: size_t npos = sizeof...(Values);
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <Type First, Type ... Rest>
	 template <std :: size_t LowerNpos, std :: size_t LowerMatched>
 struct searchValue <Type, Operator, Values...> ::
	with <First, Rest...> :: upper<LowerNpos, LowerNpos, LowerMatched>
 {
  private:
  using values = bisectValue<Type, Values...>;
  template <template <Type...> class Container>
	  using subPattern = typename valueList<Type, First, Rest...> :: template since<LowerMatched, Container>;
  using result = subPattern<values :: template
	  upper <mismatchForType <Type, Operator> :: template type> :: template with>;
  constexpr const static std :: size_t subPatternLength =
	  subPattern <sizeForType <Type> :: template type> :: value;
  constexpr const static std :: size_t upperLength =
	  values :: template upper <sizeForType <Type> :: template type> :: value;
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
  constexpr const static std :: size_t npos = sizeof...(Values);
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <Type First, Type ... Rest>
	 template <std :: size_t LowerNpos, std :: size_t LowerMatched>
	 template <std :: size_t MismatchValue, std :: size_t SubPatternLength, std :: size_t UpperLength>
 struct searchValue <Type, Operator, Values...> ::
	with <First, Rest...> ::
	upper <LowerNpos, LowerNpos, LowerMatched> :: partialCheck
 {
  private:
  constexpr const static std :: size_t shift = (sizeof...(Values) / 2u) + MismatchValue;
  template <Type ... SubValues>
	  using This = typename searchValue <Type, Operator, SubValues...> :: template with<First, Rest...>;
  using result = typename valueList <Type, Values...> :: template since<shift, This>;
  public:
  constexpr const static std :: size_t matched = result :: matched;
  constexpr const static std :: size_t value = shift + (result :: value);
  constexpr const static std :: size_t npos = sizeof...(Values);
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <Type First, Type ... Rest>
	 template <std :: size_t LowerNpos, std :: size_t LowerMatched>
	 template <std :: size_t PerfectMatch>
 struct searchValue <Type, Operator, Values...> ::
	with <First, Rest...> ::
	upper <LowerNpos, LowerNpos, LowerMatched> ::
	partialCheck<PerfectMatch, PerfectMatch, PerfectMatch>
 {
  constexpr const static std :: size_t matched = sizeof...(Rest) + 1u;
  constexpr const static std :: size_t value = sizeof...(Values) - matched;
  constexpr const static std :: size_t npos = sizeof...(Values);
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <Type First, Type ... Rest>
	 template <std :: size_t LowerNpos, std :: size_t LowerMatched>
	 template <std :: size_t SubPatternLength, std :: size_t UpperLength>
 struct searchValue <Type, Operator, Values...> ::
	with <First, Rest...> ::
	upper <LowerNpos, LowerNpos, LowerMatched> ::
	partialCheck<SubPatternLength, SubPatternLength, UpperLength>
 {
  constexpr const static std :: size_t matched = 0u;
  constexpr const static std :: size_t value = LowerNpos - LowerMatched;
  constexpr const static std :: size_t npos = sizeof...(Values);
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <Type First, Type ... Rest>
	 template <std :: size_t LowerNpos, std :: size_t LowerMatched>
	 template <std :: size_t SubPatternLength, std :: size_t UpperLength>
 struct searchValue <Type, Operator, Values...> ::
	with <First, Rest...> ::
	upper <LowerNpos, LowerNpos, LowerMatched> ::
	partialCheck<UpperLength, SubPatternLength, UpperLength>
 {
  constexpr const static std :: size_t matched = LowerMatched + UpperLength;
  constexpr const static std :: size_t value = sizeof...(Values);
  constexpr const static std :: size_t npos = sizeof...(Values);
 };
}

template <class Type, template <Type, Type> class Operator> template <Type ... Pattern>
        inline constexpr
	crap :: searchValue <Type, Operator> :: with <Pattern...> :: operator typename
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: searchValue <Type, Operator> :: template with <Pattern...> :: value_type ()
#else
	crap :: searchValue <Type, Operator> :: with <Pattern...> :: value_type ()
#endif
	const noexcept
{
 return crap :: searchValue <Type, Operator> :: with <Pattern...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator> template <Type ... Pattern>
        inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
        crap :: searchValue <Type, Operator> :: template with <Pattern...> :: value_type
#else
        crap :: searchValue <Type, Operator> :: with <Pattern...> :: value_type
#endif
        crap :: searchValue <Type, Operator> :: with <Pattern...> :: operator () ()
	const noexcept
{
 return crap :: searchValue <Type, Operator> :: with <Pattern...> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type Value> template <Type ... Empty>
        inline constexpr
	crap :: searchValue <Type, Operator, Value> :: with <Empty...> :: operator typename
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: searchValue <Type, Operator, Value> :: template with <Empty...> :: value_type ()
#else
	crap :: searchValue <Type, Operator, Value> :: with <Empty...> :: value_type ()
#endif
	const noexcept
{
 return crap :: searchValue <Type, Operator, Value> :: with <Empty...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type Value> template <Type ... Empty>
        inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
        crap :: searchValue <Type, Operator, Value> :: template with <Empty...> :: value_type
#else
        crap :: searchValue <Type, Operator, Value> :: with <Empty...> :: value_type
#endif
        crap :: searchValue <Type, Operator, Value> :: with <Empty...> :: operator () ()
	const noexcept
{
 return crap :: searchValue <Type, Operator, Value> :: with <Empty...> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type Value> template <Type Only>
        inline constexpr
	crap :: searchValue <Type, Operator, Value> :: with <Only> :: operator typename
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: searchValue <Type, Operator, Value> :: template with <Only> :: value_type ()
#else
	crap :: searchValue <Type, Operator, Value> :: with <Only> :: value_type ()
#endif
	const noexcept
{
 return crap :: searchValue <Type, Operator, Value> :: with <Only> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type Value> template <Type Only>
        inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
        crap :: searchValue <Type, Operator, Value> :: template with <Only> :: value_type
#else
        crap :: searchValue <Type, Operator, Value> :: with <Only> :: value_type
#endif
        crap :: searchValue <Type, Operator, Value> :: with <Only> :: operator () ()
	const noexcept
{
 return crap :: searchValue <Type, Operator, Value> :: with <Only> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type Value> template <Type First, Type ... Rest>
        inline constexpr
	crap :: searchValue <Type, Operator, Value> :: with <First, Rest...> :: operator typename
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: searchValue <Type, Operator, Value> :: template with <First, Rest...> :: value_type ()
#else
	crap :: searchValue <Type, Operator, Value> :: with <First, Rest...> :: value_type ()
#endif
	const noexcept
{
 return crap :: searchValue <Type, Operator, Value> :: with <First, Rest...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type Value> template <Type First, Type ... Rest>
        inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
        crap :: searchValue <Type, Operator, Value> :: template with <First, Rest...> :: value_type
#else
        crap :: searchValue <Type, Operator, Value> :: with <First, Rest...> :: value_type
#endif
        crap :: searchValue <Type, Operator, Value> :: with <First, Rest...> :: operator () ()
	const noexcept
{
 return crap :: searchValue <Type, Operator, Value> :: with <First, Rest...> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type ... Values> template <Type ... Empty>
        inline constexpr
	crap :: searchValue <Type, Operator, Values...> :: with <Empty...> :: operator typename
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: searchValue <Type, Operator, Values...> :: template with <Empty...> :: value_type ()
#else
	crap :: searchValue <Type, Operator, Values...> :: with <Empty...> :: value_type ()
#endif
	const noexcept
{
 return crap :: searchValue <Type, Operator, Values...> :: with <Empty...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type ... Values> template <Type ... Empty>
        inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
        crap :: searchValue <Type, Operator, Values...> :: template with <Empty...> :: value_type
#else
        crap :: searchValue <Type, Operator, Values...> :: with <Empty...> :: value_type
#endif
        crap :: searchValue <Type, Operator, Values...> :: with <Empty...> :: operator () ()
	const noexcept
{
 return crap :: searchValue <Type, Operator, Values...> :: with <Empty...> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type ... Values> template <Type Only>
        inline constexpr
	crap :: searchValue <Type, Operator, Values...> :: with <Only> :: operator typename
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: searchValue <Type, Operator, Values...> :: template with <Only> :: value_type ()
#else
	crap :: searchValue <Type, Operator, Values...> :: with <Only> :: value_type ()
#endif
	const noexcept
{
 return crap :: searchValue <Type, Operator, Values...> :: with <Only> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type ... Values> template <Type Only>
        inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
        crap :: searchValue <Type, Operator, Values...> :: template with <Only> :: value_type
#else
        crap :: searchValue <Type, Operator, Values...> :: with <Only> :: value_type
#endif
        crap :: searchValue <Type, Operator, Values...> :: with <Only> :: operator () ()
	const noexcept
{
 return crap :: searchValue <Type, Operator, Values...> :: with <Only> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type ... Values> template <Type First, Type ... Rest>
        inline constexpr
	crap :: searchValue <Type, Operator, Values...> :: with <First, Rest...> :: operator typename
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: searchValue <Type, Operator, Values...> :: template with <First, Rest...> :: value_type ()
#else
	crap :: searchValue <Type, Operator, Values...> :: with <First, Rest...> :: value_type ()
#endif
	const noexcept
{
 return crap :: searchValue <Type, Operator, Values...> :: with <First, Rest...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type ... Values> template <Type First, Type ... Rest>
        inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
        crap :: searchValue <Type, Operator, Values...> :: template with <First, Rest...> :: value_type
#else
        crap :: searchValue <Type, Operator, Values...> :: with <First, Rest...> :: value_type
#endif
        crap :: searchValue <Type, Operator, Values...> :: with <First, Rest...> :: operator () ()
	const noexcept
{
 return crap :: searchValue <Type, Operator, Values...> :: with <First, Rest...> :: value;
}
#endif
#endif

