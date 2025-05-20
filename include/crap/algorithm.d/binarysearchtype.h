#ifndef CRAP_ALGORITHM_BINARYSEARCHTYPE
#define CRAP_ALGORITHM_BINARYSEARCHTYPE

#include "../utility.d/typelist.h"
#include "../utility.d/typemultiplexer.h"
#include "../version.d/libintegralconstantcallable.h"

#include <cstddef>

namespace crap
{
 template <class , template <class, class> class, class...> struct binarySearchType;

 template <class Type, template <class, class> class Operator> struct binarySearchType<Type, Operator>
 {
  constexpr const static bool value = false;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <class, class> class Operator, class Type1>
	 struct binarySearchType<Type, Operator, Type1>
 {
  private:
  constexpr const static bool smaller = Operator <Type, Type1> :: value;
  constexpr const static bool larger = Operator <Type1, Type> :: value;
  public:
  constexpr const static bool value = !(smaller || larger);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <class, class> class Operator, class ... Types> struct binarySearchType
 {
  private:
  using midType = typename typeList <Types...> :: template at<sizeof...(Types) / 2u>;
  template <bool, class...> struct Continue;
  template <class ... Any> struct Continue<false, Any...>;
  constexpr const static bool equal = !((Operator <Type, midType> :: value) || (Operator <midType, Type> :: value));
  public:
  constexpr const static bool value = Continue <equal> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <class, class> class Operator, class ... Types>
	 template <bool, class...>
 struct binarySearchType <Type, Operator, Types...> :: Continue
 {
  constexpr const static bool value = true;
 };

 template <class Type, template <class, class> class Operator, class ... Types>
	 template <class ... Any>
 struct binarySearchType <Type, Operator, Types...> :: template Continue<false, Any...>
 {
  private:
  using types = typeList<Types...>;
  constexpr const static std :: size_t half = (types :: size) / 2u;
  using midType = typename types :: template at<half>;
  constexpr const static bool smaller = Operator <Type, midType> :: value;
  template <class ... SubTypes> using This = binarySearchType<Type, Operator, SubTypes...>;
  template <template <class...> class Container>
	  using TillSource = typename types :: template till<half, Container>;
  template <template <class...> class Container>
	  using SinceSource = typename types :: template since<half + 1u, Container>;
  using result = typename typeMultiplexer <smaller, This, TillSource, SinceSource> :: type;
  public:
  constexpr const static bool value = result :: value;
 };
}

template <class Type, template <class, class> class Operator>
        inline constexpr crap :: binarySearchType <Type, Operator> :: operator
        typename crap :: binarySearchType <Type, Operator> :: value_type () const noexcept
{
 return crap :: binarySearchType <Type, Operator> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <class, class> class Operator>
	inline constexpr typename crap :: binarySearchType <Type, Operator> :: value_type
	crap :: binarySearchType <Type, Operator> :: operator () () const noexcept
{
 return crap :: binarySearchType <Type, Operator> :: value;
}
#endif

template <class Type, template <class, class> class Operator, class Type1>
        inline constexpr crap :: binarySearchType <Type, Operator, Type1> :: operator
        typename crap :: binarySearchType <Type, Operator, Type1> :: value_type () const noexcept
{
 return crap :: binarySearchType <Type, Operator, Type1> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <class, class> class Operator, class Type1>
	inline constexpr typename crap :: binarySearchType <Type, Operator, Type1> :: value_type
	crap :: binarySearchType <Type, Operator, Type1> :: operator () () const noexcept
{
 return crap :: binarySearchType <Type, Operator, Type1> :: value;
}
#endif

template <class Type, template <class, class> class Operator, class ... Types>
        inline constexpr crap :: binarySearchType <Type, Operator, Types...> :: operator
        typename crap :: binarySearchType <Type, Operator, Types...> :: value_type () const noexcept
{
 return crap :: binarySearchType <Type, Operator, Types...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <class, class> class Operator, class ... Types>
	inline constexpr typename crap :: binarySearchType <Type, Operator, Types...> :: value_type
	crap :: binarySearchType <Type, Operator, Types...> :: operator () () const noexcept
{
 return crap :: binarySearchType <Type, Operator, Types...> :: value;
}
#endif
#endif

