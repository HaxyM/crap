#ifndef CRAP_ALGORITHM_MAXELEMENTTYPE
#define CRAP_ALGORITHM_MAXELEMENTTYPE

#include "../utility.d/bisecttype.h"
#include "../version.d/libintegralconstantcallable.h"

#include <cstddef>
#include <type_traits>

namespace crap
{
 template <template <class, class> class, class...> struct maxElementType;

 template <template <class, class> class Operator> struct maxElementType<Operator>
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
	 struct maxElementType<Operator, Type>
 {
  template <template <class, class> class, class...> friend struct maxElementType;
  private:
  using maxType = Type;
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
	 struct maxElementType<Operator, Type1, Type2>
 {
  template <template <class, class> class, class...> friend struct maxElementType;
  private:
  using maxType = typename std :: conditional<(Operator <Type1, Type2> :: value), Type2, Type1> :: type;
  public:
  constexpr const static std :: size_t value = ((Operator <Type1, Type2> :: value) ? 1u : 0u);
  constexpr const static std :: size_t npos = 2u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class, class> class Operator, class ... Types> struct maxElementType
 {
  template <template <class, class> class, class...> friend struct maxElementType;
  private:
  template <class ... SubTypes> using This = maxElementType<Operator, SubTypes...>;
  using lower = typename bisectType <Types...> :: template lower<This>;
  using upper = typename bisectType <Types...> :: template upper<This>;
  using maxType = typename
	  std :: conditional<(Operator <typename lower :: maxType, typename upper :: maxType> :: value),
	      typename upper :: maxType, typename lower :: maxType> :: type;
  public:
  constexpr const static std :: size_t value =
	  ((Operator <typename lower :: maxType, typename upper :: maxType> :: value) ? (lower :: npos + upper :: value) : (lower :: value));
  constexpr const static std :: size_t npos = sizeof...(Types);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };
}

template <template <class, class> class Operator>
	inline constexpr crap :: maxElementType <Operator> :: operator
	typename crap :: maxElementType <Operator> :: value_type () const noexcept
{
 return crap :: maxElementType <Operator> :: value;
};
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator>
	inline constexpr typename crap :: maxElementType <Operator> :: value_type
	crap :: maxElementType <Operator> :: operator () () const noexcept
{
 return crap :: maxElementType <Operator> :: value;
}
#endif

template <template <class, class> class Operator, class Type>
	inline constexpr crap :: maxElementType <Operator, Type> :: operator
	typename crap :: maxElementType <Operator, Type> :: value_type () const noexcept
{
 return crap :: maxElementType <Operator, Type> :: value;
};
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class Type>
	inline constexpr typename crap :: maxElementType <Operator, Type> :: value_type
	crap :: maxElementType <Operator, Type> :: operator () () const noexcept
{
 return crap :: maxElementType <Operator, Type> :: value;
}
#endif

template <template <class, class> class Operator, class Type1, class Type2>
	inline constexpr crap :: maxElementType <Operator, Type1, Type2> :: operator
	typename crap :: maxElementType <Operator, Type1, Type2> :: value_type () const noexcept
{
 return crap :: maxElementType <Operator, Type1, Type2> :: value;
};
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class Type1, class Type2>
	inline constexpr typename crap :: maxElementType <Operator, Type1, Type2> :: value_type
	crap :: maxElementType <Operator, Type1, Type2> :: operator () () const noexcept
{
 return crap :: maxElementType <Operator, Type1, Type2> :: value;
}
#endif

template <template <class, class> class Operator, class ... Types>
	inline constexpr crap :: maxElementType <Operator, Types...> :: operator
	typename crap :: maxElementType <Operator, Types...> :: value_type () const noexcept
{
 return crap :: maxElementType <Operator, Types...> :: value;
};
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class, class> class Operator, class ... Types>
	inline constexpr typename crap :: maxElementType <Operator, Types...> :: value_type
	crap :: maxElementType <Operator, Types...> :: operator () () const noexcept
{
 return crap :: maxElementType <Operator, Types...> :: value;
}
#endif
#endif

