#ifndef CRAP_ALGORITHM_MINELEMENTTYPE
#define CRAP_ALGORITHM_MINELEMENTTYPE

#include <cstddef>
#include <type_traits>

#include "../utility.d/bisecttype.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <template <class, class> class, class...> struct minElementType;

 template <template <class, class> class Operator> struct minElementType<Operator>
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class Type>
	 struct minElementType<Operator, Type>
 {
  template <template <class, class> class, class...> friend struct minElementType;
  private:
  using minType = Type;
  public:
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class Type1, class Type2>
	 struct minElementType<Operator, Type1, Type2>
 {
  template <template <class, class> class, class...> friend struct minElementType;
  private:
  using minType = typename std :: conditional<(Operator <Type2, Type1> :: value), Type2, Type1> :: type;
  public:
  constexpr const static std :: size_t value = ((Operator <Type2, Type1> :: value) ? 1u : 0u);
  constexpr const static std :: size_t npos = 2u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class ... Types> struct minElementType
 {
  template <template <class, class> class, class...> friend struct minElementType;
  private:
  template <class ... SubTypes> using This = minElementType<Operator, SubTypes...>;
  using lower = typename bisectType <Types...> :: template lower<This>;
  using upper = typename bisectType <Types...> :: template upper<This>;
  using minType = typename
	  std :: conditional<(Operator <typename upper :: minType, typename lower :: minType> :: value),
	      typename upper :: minType, typename lower :: minType> :: type;
  public:
  constexpr const static std :: size_t value =
	  ((Operator <typename upper :: minType, typename lower :: minType> :: value) ? (lower :: npos + upper :: value) : (lower :: value));
  constexpr const static std :: size_t npos = sizeof...(Types);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };
}

template <template <class, class> class Operator>
	inline constexpr crap :: minElementType <Operator> :: operator
	typename crap :: minElementType <Operator> :: value_type () const noexcept
{
 return crap :: minElementType <Operator> :: value;
};
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator>
	inline constexpr typename crap :: minElementType <Operator> :: value_type
	crap :: minElementType <Operator> :: operator () () const noexcept
{
 return crap :: minElementType <Operator> :: value;
}
#endif

template <template <class, class> class Operator, class Type>
	inline constexpr crap :: minElementType <Operator, Type> :: operator
	typename crap :: minElementType <Operator, Type> :: value_type () const noexcept
{
 return crap :: minElementType <Operator, Type> :: value;
};
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class Type>
	inline constexpr typename crap :: minElementType <Operator, Type> :: value_type
	crap :: minElementType <Operator, Type> :: operator () () const noexcept
{
 return crap :: minElementType <Operator, Type> :: value;
}
#endif

template <template <class, class> class Operator, class Type1, class Type2>
	inline constexpr crap :: minElementType <Operator, Type1, Type2> :: operator
	typename crap :: minElementType <Operator, Type1, Type2> :: value_type () const noexcept
{
 return crap :: minElementType <Operator, Type1, Type2> :: value;
};
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class Type1, class Type2>
	inline constexpr typename crap :: minElementType <Operator, Type1, Type2> :: value_type
	crap :: minElementType <Operator, Type1, Type2> :: operator () () const noexcept
{
 return crap :: minElementType <Operator, Type1, Type2> :: value;
}
#endif

template <template <class, class> class Operator, class ... Types>
	inline constexpr crap :: minElementType <Operator, Types...> :: operator
	typename crap :: minElementType <Operator, Types...> :: value_type () const noexcept
{
 return crap :: minElementType <Operator, Types...> :: value;
};
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class ... Types>
	inline constexpr typename crap :: minElementType <Operator, Types...> :: value_type
	crap :: minElementType <Operator, Types...> :: operator () () const noexcept
{
 return crap :: minElementType <Operator, Types...> :: value;
}
#endif
#endif

