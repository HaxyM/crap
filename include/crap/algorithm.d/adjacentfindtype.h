#ifndef CRAP_ALGORITHM_ADJACENTFINDTYPE
#define CRAP_ALGORITHM_ADJACENTFINDTYPE

#include "../utility.d/typelist.h"
#include "../version.d/libintegralconstantcallable.h"

#include <cstddef>

namespace crap
{
 template <template <class, class> class, class...> struct adjacentFindType;

 template <template <class, class> class Operator> struct adjacentFindType<Operator>
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class Type> struct adjacentFindType<Operator, Type>
 {
  constexpr const static std :: size_t value = 1u;
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class Type1, class Type2>
	 struct adjacentFindType<Operator, Type1, Type2>
 {
  constexpr const static std :: size_t value = ((Operator <Type1, Type2> :: value) ? 0u : 2u);
  constexpr const static std :: size_t npos = 2u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class ... Types> struct adjacentFindType
 {
  private:
  using types = typeList<Types...>;
  constexpr const static std :: size_t half = types :: size / 2u;
  template <class ... SubTypes> using This = adjacentFindType<Operator, SubTypes...>;
  using lower = typename types :: template till<half, This>;
  template <std :: size_t LowerValue, std :: size_t LowerNpos> struct checkMiddle;
  template <std :: size_t LowerNpos> struct checkMiddle<LowerNpos, LowerNpos>;
  public:
  constexpr const static std :: size_t value = checkMiddle <lower :: value, lower :: npos> :: value;
  constexpr const static std :: size_t npos = sizeof...(Types);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class ... Types>
	 template <std :: size_t LowerValue, std :: size_t LowerNpos>
	struct adjacentFindType <Operator, Types...> :: checkMiddle
 {
  constexpr const static std :: size_t value = LowerValue;
 };

 template <template <class, class> class Operator, class ... Types>
	 template <std :: size_t LowerNpos>
	struct adjacentFindType <Operator, Types...> :: checkMiddle<LowerNpos, LowerNpos>
 {
  private:
  using types = typeList<Types...>;
  constexpr const static std :: size_t half = types :: size / 2u;
  using type1 = typename types :: template at<half - 1u>;
  using type2 = typename types :: template at<half>;
  template <bool, class...> struct checkUpper;
  template <class ... Empty> struct checkUpper<false, Empty...>;
  public:
  constexpr const static std :: size_t value = checkUpper <Operator <type1, type2> :: value> :: value;
 };

 template <template <class, class> class Operator, class ... Types>
	 template <std :: size_t LowerNpos>
	 template <bool, class...>
 struct adjacentFindType <Operator, Types...> ::
	checkMiddle <LowerNpos, LowerNpos> :: checkUpper
 {
  constexpr const static std :: size_t value = LowerNpos - 1u;
 };

 template <template <class, class> class Operator, class ... Types>
	 template <std :: size_t LowerNpos>
	 template <class ... Empty>
 struct adjacentFindType <Operator, Types...> ::
	checkMiddle <LowerNpos, LowerNpos> ::
	checkUpper<false, Empty...>
 {
  private:
  using types = typeList<Types...>;
  constexpr const static std :: size_t half = types :: size / 2u;
  template <class ... SubTypes> using This = adjacentFindType<Operator, SubTypes...>;
  using upper = typename types :: template since<half, This>;
  public:
  constexpr const static std :: size_t value = LowerNpos + (upper :: value);
 };
}

template <template <class, class> class Operator>
        inline constexpr crap :: adjacentFindType <Operator> :: operator
        typename crap :: adjacentFindType <Operator> :: value_type () const noexcept
{
 return crap :: adjacentFindType <Operator> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator>
	inline constexpr typename crap :: adjacentFindType <Operator> :: value_type
	crap :: adjacentFindType <Operator> :: operator () () const noexcept
{
 return crap :: adjacentFindType <Operator> :: value;
}
#endif

template <template <class, class> class Operator, class Type>
        inline constexpr crap :: adjacentFindType <Operator, Type> :: operator
        typename crap :: adjacentFindType <Operator, Type> :: value_type () const noexcept
{
 return crap :: adjacentFindType <Operator, Type> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class Type>
	inline constexpr typename crap :: adjacentFindType <Operator, Type> :: value_type
	crap :: adjacentFindType <Operator, Type> :: operator () () const noexcept
{
 return crap :: adjacentFindType <Operator, Type> :: value;
}
#endif

template <template <class, class> class Operator, class Type1, class Type2>
        inline constexpr crap :: adjacentFindType <Operator, Type1, Type2> :: operator
        typename crap :: adjacentFindType <Operator, Type1, Type2> :: value_type () const noexcept
{
 return crap :: adjacentFindType <Operator, Type1, Type2> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class Type1, class Type2>
	inline constexpr typename crap :: adjacentFindType <Operator, Type1, Type2> :: value_type
	crap :: adjacentFindType <Operator, Type1, Type2> :: operator () () const noexcept
{
 return crap :: adjacentFindType <Operator, Type1, Type2> :: value;
}
#endif

template <template <class, class> class Operator, class ... Types>
        inline constexpr crap :: adjacentFindType <Operator, Types...> :: operator
        typename crap :: adjacentFindType <Operator, Types...> :: value_type () const noexcept
{
 return crap :: adjacentFindType <Operator, Types...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class ... Types>
	inline constexpr typename crap :: adjacentFindType <Operator, Types...> :: value_type
	crap :: adjacentFindType <Operator, Types...> :: operator () () const noexcept
{
 return crap :: adjacentFindType <Operator, Types...> :: value;
}
#endif
#endif

