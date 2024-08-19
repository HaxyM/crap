#ifndef CRAP_ALGORITHM_MISMATCHVALUE
#define CRAP_ALGORITHM_MISMATCHVALUE

#include "../utility.d/valuelist.h"
#include "../version.d/libintegralconstantcallable.h"

#include <cstddef>

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct mismatchValue;

 template <class Type, template <Type, Type> class Operator> struct mismatchValue<Type, Operator>
 {
  template <Type ... Types2> struct with;
 };

 template <class Type, template <Type, Type> class Operator, Type Only1>
	 struct mismatchValue<Type, Operator, Only1>
 {
  template <Type...> struct with;
  template <Type Only2> struct with<Only2>;
  template <Type First2, Type ... Rest2> struct with<First2, Rest2...>;
 };

 template <class Type, template <Type, Type> class Operator, Type First1, Type ... Rest1>
	 struct mismatchValue<Type, Operator, First1, Rest1...>
 {
  template <Type...> struct with;
  template <Type Only2> struct with<Only2>;
  template <Type First2, Type ... Rest2> struct with<First2, Rest2...>;
 };

 template <class Type, template <Type, Type> class Operator> template <Type ... Types2>
	 struct mismatchValue <Type, Operator> :: with
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = sizeof...(Types2);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type Only1> template <Type...>
	 struct mismatchValue <Type, Operator, Only1> :: with
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type Only1> template <Type Only2>
	 struct mismatchValue <Type, Operator, Only1> :: with<Only2>
 {
  constexpr const static std :: size_t value = ((Operator <Only1, Only2> :: value) ? 1u : 0u);
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type Only1> template <Type First2, Type ... Rest2>
	 struct mismatchValue <Type, Operator, Only1> :: with<First2, Rest2...>
 {
  constexpr const static std :: size_t value = ((Operator <Only1, First2> :: value) ? 1u : 0u);
  constexpr const static std :: size_t npos = sizeof...(Rest2) + 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type First1, Type ... Rest1> template <Type...>
	 struct mismatchValue <Type, Operator, First1, Rest1...> :: with
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = sizeof...(Rest1) + 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type First1, Type ... Rest1> template <Type Only2>
	 struct mismatchValue <Type, Operator, First1, Rest1...> :: with<Only2>
 {
  constexpr const static std :: size_t value = ((Operator <First1, Only2> :: value) ? 1u : 0u);
  constexpr const static std :: size_t npos = sizeof...(Rest1) + 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type First1, Type ... Rest1>
	 template <Type First2, Type ... Rest2>
	 struct mismatchValue <Type, Operator, First1, Rest1...> :: with<First2, Rest2...>
 {
  private:
  using types1 = valueList<Type, First1, Rest1...>;
  using types2 = valueList<Type, First2, Rest2...>;
  constexpr const static std :: size_t half =
	  ((types1 :: size > types2 :: size) ? (types1 :: size) : (types2 :: size)) / 2u;
  template <Type ... SubTypes> using This = mismatchValue<Type, Operator, SubTypes...>;
  using lower = typename types2 :: template till<half, types1 :: template till <half, This> :: template with>;
  template <std :: size_t LowerValue, std :: size_t LowerNpos> struct upper;
  template <std :: size_t LowerNpos> struct upper<LowerNpos, LowerNpos>;
  public:
  constexpr const static std :: size_t value = upper <lower :: value, lower :: npos> :: value;
  constexpr const static std :: size_t npos =
	  ((types1 :: size > types2 :: size) ? (types1 :: size) : (types2 :: size));
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type First1, Type ... Rest1>
	 template <Type First2, Type ... Rest2>
	 template <std :: size_t LowerValue, std :: size_t LowerNpos>
	 struct mismatchValue <Type, Operator, First1, Rest1...> :: with <First2, Rest2...> :: upper
 {
  constexpr const static std :: size_t value = LowerValue;
 };

 template <class Type, template <Type, Type> class Operator, Type First1, Type ... Rest1>
	 template <Type First2, Type ... Rest2>
	 template <std :: size_t LowerNpos>
 struct mismatchValue <Type, Operator, First1, Rest1...> ::
	 with <First2, Rest2...> :: upper<LowerNpos, LowerNpos>
 {
  private:
  using types1 = valueList<Type, First1, Rest1...>;
  using types2 = valueList<Type, First2, Rest2...>;
  template <Type ... SubTypes> using This = mismatchValue<Type, Operator, SubTypes...>;
  using result = typename types2 :: template
	  since<LowerNpos, types1 :: template since <LowerNpos, This> :: template with>;
  public:
  constexpr const static std :: size_t value = LowerNpos + (result :: value);
 };
}

template <class Type, template <Type, Type> class Operator> template <Type ... Types2>
        inline constexpr
	crap :: mismatchValue <Type, Operator> :: with <Types2...> :: operator typename
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: mismatchValue <Type, Operator> :: template with <Types2...> :: value_type ()
#else
	crap :: mismatchValue <Type, Operator> :: with <Types2...> :: value_type ()
#endif
	const noexcept
{
 return crap :: mismatchValue <Type, Operator> :: with <Types2...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator> template <Type ... Types2>
        inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: mismatchValue <Type, Operator> :: template with <Types2...> :: value_type
#else
	crap :: mismatchValue <Type, Operator> :: with <Types2...> :: value_type
#endif
	crap :: mismatchValue <Type, Operator> :: with <Types2...> :: operator () ()
	const noexcept
{
 return crap :: mismatchValue <Type, Operator> :: with <Types2...> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type Only1> template <Type ... Empty>
        inline constexpr
	crap :: mismatchValue <Type, Operator, Only1> :: with <Empty...> :: operator typename
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: mismatchValue <Type, Operator, Only1> :: typename with <Empty...> :: value_type ()
#else
	crap :: mismatchValue <Type, Operator, Only1> :: with <Empty...> :: value_type ()
#endif
	const noexcept
{
 return crap :: mismatchValue <Type, Operator, Only1> :: with <Empty...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type Only1> template <Type ... Empty>
        inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: mismatchValue <Type, Operator, Only1> :: template with <Empty...> :: value_type
#else
	crap :: mismatchValue <Type, Operator, Only1> :: with <Empty...> :: value_type
#endif
	crap :: mismatchValue <Type, Operator, Only1> :: with <Empty...> :: operator () ()
	const noexcept
{
 return crap :: mismatchValue <Type, Operator, Only1> :: with <Empty...> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type Only1> template <Type Only2>
        inline constexpr
	crap :: mismatchValue <Type, Operator, Only1> :: with <Only2> :: operator typename
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: mismatchValue <Type, Operator, Only1> :: template with <Only2> :: value_type ()
#else
	crap :: mismatchValue <Type, Operator, Only1> :: with <Only2> :: value_type ()
#endif
	const noexcept
{
 return crap :: mismatchValue <Type, Operator, Only1> :: with <Only2> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type Only1> template <Type Only2>
        inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: mismatchValue <Type, Operator, Only1> :: template with <Only2> :: value_type
#else
	crap :: mismatchValue <Type, Operator, Only1> :: with <Only2> :: value_type
#endif
	crap :: mismatchValue <Type, Operator, Only1> :: with <Only2> :: operator () ()
	const noexcept
{
 return crap :: mismatchValue <Type, Operator, Only1> :: with <Only2> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type Only1> template <Type First2, Type ... Rest2>
        inline constexpr
	crap :: mismatchValue <Type, Operator, Only1> :: with <First2, Rest2...> :: operator typename
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: mismatchValue <Type, Operator, Only1> :: template with <First2, Rest2...> :: value_type ()
#else
	crap :: mismatchValue <Type, Operator, Only1> :: with <First2, Rest2...> :: value_type ()
#endif
	const noexcept
{
 return crap :: mismatchValue <Type, Operator, Only1> :: with <First2, Rest2...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type Only1> template <Type First2, Type ... Rest2>
        inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: mismatchValue <Type, Operator, Only1> :: template with <First2, Rest2...> :: value_type
#else
	crap :: mismatchValue <Type, Operator, Only1> :: with <First2, Rest2...> :: value_type
#endif
	crap :: mismatchValue <Type, Operator, Only1> :: with <First2, Rest2...> :: operator () ()
	const noexcept
{
 return crap :: mismatchValue <Type, Operator, Only1> :: with <First2, Rest2...> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type First1, Type ... Rest1> template <Type ... Empty>
        inline constexpr
	crap :: mismatchValue <Type, Operator, First1, Rest1...> :: with <Empty...> :: operator typename
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: mismatchValue <Type, Operator, First1, Rest1...> :: template with <Empty...> :: value_type ()
#else
	crap :: mismatchValue <Type, Operator, First1, Rest1...> :: with <Empty...> :: value_type ()
#endif
	const noexcept
{
 return crap :: mismatchValue <Type, Operator, First1, Rest1...> :: with <Empty...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type First1, Type ... Rest1> template <Type ... Empty>
        inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: mismatchValue <Type, Operator, First1, Rest1...> :: template with <Empty...> :: value_type
#else
	crap :: mismatchValue <Type, Operator, First1, Rest1...> :: with <Empty...> :: value_type
#endif
	crap :: mismatchValue <Type, Operator, First1, Rest1...> :: with <Empty...> :: operator () ()
	const noexcept
{
 return crap :: mismatchValue <Type, Operator, First1, Rest1...> :: with <Empty...> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type First1, Type ... Rest1> template <Type Only2>
        inline constexpr
	crap :: mismatchValue <Type, Operator, First1, Rest1...> :: with <Only2> :: operator typename
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: mismatchValue <Type, Operator, First1, Rest1...> :: template with <Only2> :: value_type ()
#else
	crap :: mismatchValue <Type, Operator, First1, Rest1...> :: with <Only2> :: value_type ()
#endif
	const noexcept
{
 return crap :: mismatchValue <Type, Operator, First1, Rest1...> :: with <Only2> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type First1, Type ... Rest1> template <Type Only2>
        inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: mismatchValue <Type, Operator, First1, Rest1...> :: template with <Only2> :: value_type
#else
	crap :: mismatchValue <Type, Operator, First1, Rest1...> :: with <Only2> :: value_type
#endif
	crap :: mismatchValue <Type, Operator, First1, Rest1...> :: with <Only2> :: operator () ()
	const noexcept
{
 return crap :: mismatchValue <Type, Operator, First1, Rest1...> :: with <Only2> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type First1, Type ... Rest1>
template <Type First2, Type ... Rest2>
        inline constexpr
	crap :: mismatchValue <Type, Operator, First1, Rest1...> :: with <First2, Rest2...> :: operator typename
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: mismatchValue <Type, Operator, First1, Rest1...> :: template with <First2, Rest2...> :: value_type ()
#else
	crap :: mismatchValue <Type, Operator, First1, Rest1...> :: with <First2, Rest2...> :: value_type ()
#endif
	const noexcept
{
 return crap :: mismatchValue <Type, Operator, First1, Rest1...> :: with <First2, Rest2...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type First1, Type ... Rest1>
template <Type First2, Type ... Rest2>
        inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: mismatchValue <Type, Operator, First1, Rest1...> :: template with <First2, Rest2...> :: value_type
#else
	crap :: mismatchValue <Type, Operator, First1, Rest1...> :: with <First2, Rest2...> :: value_type
#endif
	crap :: mismatchValue <Type, Operator, First1, Rest1...> :: with <First2, Rest2...> :: operator () ()
	const noexcept
{
 return crap :: mismatchValue <Type, Operator, First1, Rest1...> :: with <First2, Rest2...> :: value;
}
#endif
#endif

