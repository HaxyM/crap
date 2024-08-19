#ifndef CRAP_ALGORITHM_MISMATCHTYPE
#define CRAP_ALGORITHM_MISMATCHTYPE

#include "../utility.d/typelist.h"
#include "../version.d/libintegralconstantcallable.h"

#include <cstddef>

namespace crap
{
 template <template <class, class> class, class...> struct mismatchType;

 template <template <class, class> class Operator> struct mismatchType<Operator>
 {
  template <class ... Types2> struct with;
 };

 template <template <class, class> class Operator, class Only1> struct mismatchType<Operator, Only1>
 {
  template <class...> struct with;
  template <class Only2> struct with<Only2>;
  template <class First2, class ... Rest2> struct with<First2, Rest2...>;
 };

 template <template <class, class> class Operator, class First1, class ... Rest1>
	 struct mismatchType<Operator, First1, Rest1...>
 {
  template <class...> struct with;
  template <class Only2> struct with<Only2>;
  template <class First2, class ... Rest2> struct with<First2, Rest2...>;
 };

 template <template <class, class> class Operator> template <class ... Types2>
	 struct mismatchType <Operator> :: with
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = sizeof...(Types2);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class Only1> template <class...>
	 struct mismatchType <Operator, Only1> :: with
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class Only1> template <class Only2>
	 struct mismatchType <Operator, Only1> :: with<Only2>
 {
  constexpr const static std :: size_t value = ((Operator <Only1, Only2> :: value) ? 1u : 0u);
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class Only1> template <class First2, class ... Rest2>
	 struct mismatchType <Operator, Only1> :: with<First2, Rest2...>
 {
  constexpr const static std :: size_t value = ((Operator <Only1, First2> :: value) ? 1u : 0u);
  constexpr const static std :: size_t npos = sizeof...(Rest2) + 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class First1, class ... Rest1> template <class...>
	 struct mismatchType <Operator, First1, Rest1...> :: with
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = sizeof...(Rest1) + 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class First1, class ... Rest1> template <class Only2>
	 struct mismatchType <Operator, First1, Rest1...> :: with<Only2>
 {
  constexpr const static std :: size_t value = ((Operator <First1, Only2> :: value) ? 1u : 0u);
  constexpr const static std :: size_t npos = sizeof...(Rest1) + 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class First1, class ... Rest1>
	 template <class First2, class ... Rest2>
	 struct mismatchType <Operator, First1, Rest1...> :: with<First2, Rest2...>
 {
  private:
  using types1 = typeList<First1, Rest1...>;
  using types2 = typeList<First2, Rest2...>;
  constexpr const static std :: size_t half =
	  ((types1 :: size > types2 :: size) ? (types1 :: size) : (types2 :: size)) / 2u;
  template <class ... SubTypes> using This = mismatchType<Operator, SubTypes...>;
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

 template <template <class, class> class Operator, class First1, class ... Rest1>
	 template <class First2, class ... Rest2>
	 template <std :: size_t LowerValue, std :: size_t LowerNpos>
	 struct mismatchType <Operator, First1, Rest1...> :: with <First2, Rest2...> :: upper
 {
  constexpr const static std :: size_t value = LowerValue;
 };

 template <template <class, class> class Operator, class First1, class ... Rest1>
	 template <class First2, class ... Rest2>
	 template <std :: size_t LowerNpos>
 struct mismatchType <Operator, First1, Rest1...> ::
	 with <First2, Rest2...> :: upper<LowerNpos, LowerNpos>
 {
  private:
  using types1 = typeList<First1, Rest1...>;
  using types2 = typeList<First2, Rest2...>;
  template <class ... SubTypes> using This = mismatchType<Operator, SubTypes...>;
  using result = typename types2 :: template
	  since<LowerNpos, types1 :: template since <LowerNpos, This> :: template with>;
  public:
  constexpr const static std :: size_t value = LowerNpos + (result :: value);
 }; 
}

template <template <class, class> class Operator> template <class ... Types2>
        inline constexpr
	crap :: mismatchType <Operator> :: with <Types2...> :: operator typename
	crap :: mismatchType <Operator> :: with <Types2...> :: value_type ()
	const noexcept
{
 return crap :: mismatchType <Operator> :: with <Types2...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator> template <class ... Types2>
        inline constexpr typename
	crap :: mismatchType <Operator> :: with <Types2...> :: value_type
	crap :: mismatchType <Operator> :: with <Types2...> :: operator () ()
	const noexcept
{
 return crap :: mismatchType <Operator> :: with <Types2...> :: value;
}
#endif

template <template <class, class> class Operator, class Only1> template <class ... Empty>
        inline constexpr
	crap :: mismatchType <Operator, Only1> :: with <Empty...> :: operator typename
	crap :: mismatchType <Operator, Only1> :: with <Empty...> :: value_type ()
	const noexcept
{
 return crap :: mismatchType <Operator, Only1> :: with <Empty...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class Only1> template <class ... Empty>
        inline constexpr typename
	crap :: mismatchType <Operator, Only1> :: with <Empty...> :: value_type
	crap :: mismatchType <Operator, Only1> :: with <Empty...> :: operator () ()
	const noexcept
{
 return crap :: mismatchType <Operator, Only1> :: with <Empty...> :: value;
}
#endif

template <template <class, class> class Operator, class Only1> template <class Only2>
        inline constexpr
	crap :: mismatchType <Operator, Only1> :: with <Only2> :: operator typename
	crap :: mismatchType <Operator, Only1> :: with <Only2> :: value_type ()
	const noexcept
{
 return crap :: mismatchType <Operator, Only1> :: with <Only2> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class Only1> template <class Only2>
        inline constexpr typename
	crap :: mismatchType <Operator, Only1> :: with <Only2> :: value_type
	crap :: mismatchType <Operator, Only1> :: with <Only2> :: operator () ()
	const noexcept
{
 return crap :: mismatchType <Operator, Only1> :: with <Only2> :: value;
}
#endif

template <template <class, class> class Operator, class Only1> template <class First2, class ... Rest2>
        inline constexpr
	crap :: mismatchType <Operator, Only1> :: with <First2, Rest2...> :: operator typename
	crap :: mismatchType <Operator, Only1> :: with <First2, Rest2...> :: value_type ()
	const noexcept
{
 return crap :: mismatchType <Operator, Only1> :: with <First2, Rest2...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class Only1> template <class First2, class ... Rest2>
        inline constexpr typename
	crap :: mismatchType <Operator, Only1> :: with <First2, Rest2...> :: value_type
	crap :: mismatchType <Operator, Only1> :: with <First2, Rest2...> :: operator () ()
	const noexcept
{
 return crap :: mismatchType <Operator, Only1> :: with <First2, Rest2...> :: value;
}
#endif

template <template <class, class> class Operator, class First1, class ... Rest1> template <class ... Empty>
        inline constexpr
	crap :: mismatchType <Operator, First1, Rest1...> :: with <Empty...> :: operator typename
	crap :: mismatchType <Operator, First1, Rest1...> :: with <Empty...> :: value_type ()
	const noexcept
{
 return crap :: mismatchType <Operator, First1, Rest1...> :: with <Empty...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class First1, class ... Rest1> template <class ... Empty>
        inline constexpr typename
	crap :: mismatchType <Operator, First1, Rest1...> :: with <Empty...> :: value_type
	crap :: mismatchType <Operator, First1, Rest1...> :: with <Empty...> :: operator () ()
	const noexcept
{
 return crap :: mismatchType <Operator, First1, Rest1...> :: with <Empty...> :: value;
}
#endif

template <template <class, class> class Operator, class First1, class ... Rest1> template <class Only2>
        inline constexpr
	crap :: mismatchType <Operator, First1, Rest1...> :: with <Only2> :: operator typename
	crap :: mismatchType <Operator, First1, Rest1...> :: with <Only2> :: value_type ()
	const noexcept
{
 return crap :: mismatchType <Operator, First1, Rest1...> :: with <Only2> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class First1, class ... Rest1> template <class Only2>
        inline constexpr typename
	crap :: mismatchType <Operator, First1, Rest1...> :: with <Only2> :: value_type
	crap :: mismatchType <Operator, First1, Rest1...> :: with <Only2> :: operator () ()
	const noexcept
{
 return crap :: mismatchType <Operator, First1, Rest1...> :: with <Only2> :: value;
}
#endif

template <template <class, class> class Operator, class First1, class ... Rest1>
template <class First2, class ... Rest2>
        inline constexpr
	crap :: mismatchType <Operator, First1, Rest1...> :: with <First2, Rest2...> :: operator typename
	crap :: mismatchType <Operator, First1, Rest1...> :: with <First2, Rest2...> :: value_type ()
	const noexcept
{
 return crap :: mismatchType <Operator, First1, Rest1...> :: with <First2, Rest2...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class First1, class ... Rest1>
template <class First2, class ... Rest2>
        inline constexpr typename
	crap :: mismatchType <Operator, First1, Rest1...> :: with <First2, Rest2...> :: value_type
	crap :: mismatchType <Operator, First1, Rest1...> :: with <First2, Rest2...> :: operator () ()
	const noexcept
{
 return crap :: mismatchType <Operator, First1, Rest1...> :: with <First2, Rest2...> :: value;
}
#endif
#endif

