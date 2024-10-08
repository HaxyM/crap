#ifndef CRAP_ALGORITHM_UPPERBOUNDTYPE
#define CRAP_ALGORITHM_UPPERBOUNDTYPE

#include "../utility.d/bisecttype.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <class, template <class, class> class, class...> struct upperBoundType;

 template <class Type, template <class, class> class Operator> struct upperBoundType<Type, Operator>
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <class, class> class Operator, class Type1> struct upperBoundType<Type, Operator, Type1>
 {
  constexpr const static std :: size_t value = (Operator <Type, Type1> :: value ? 0u : 1u);
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <class, class> class Operator, class ... Types> struct upperBoundType
 {
  private:
  using values = bisectType<Types...>;
  template <class ... SubTypes> using This = upperBoundType<Type, Operator, SubTypes...>;
  using lower = typename values :: template lower<This>;
  template <std :: size_t LowerValue, std :: size_t LowerNpos> struct upper;
  template <std :: size_t LowerNpos> struct upper<LowerNpos, LowerNpos>;
  public:
  constexpr const static std :: size_t value = upper <lower :: value, lower :: npos> :: value;
  constexpr const static std :: size_t npos = sizeof...(Types);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <class, class> class Operator, class ... Types>
	 template <std :: size_t LowerValue, std :: size_t>
 struct upperBoundType <Type, Operator, Types...> :: upper
 {
  constexpr const static std :: size_t value = LowerValue;
 };

 template <class Type, template <class, class> class Operator, class ... Types>
	 template <std :: size_t LowerNpos>
 struct upperBoundType <Type, Operator, Types...> :: upper<LowerNpos, LowerNpos>
 {
  private:
  using types = bisectType<Types...>;
  template <class ... SubTypes> using This = upperBoundType<Type, Operator, SubTypes...>;
  public:
  constexpr const static std :: size_t value = LowerNpos + types :: template upper <This> :: value;
 };
}

template <class Type, template <class, class> class Operator>
        inline constexpr crap :: upperBoundType <Type, Operator> :: operator
        typename crap :: upperBoundType <Type, Operator> :: value_type () const noexcept
{
 return crap :: upperBoundType <Type, Operator> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <class, class> class Operator>
        inline constexpr typename crap :: upperBoundType <Type, Operator> :: value_type
        crap :: upperBoundType <Type, Operator> :: operator () () const noexcept
{
 return crap :: upperBoundType <Type, Operator> :: value;
}
#endif

template <class Type, template <class, class> class Operator, class Type1>
        inline constexpr crap :: upperBoundType <Type, Operator, Type1> :: operator
        typename crap :: upperBoundType <Type, Operator, Type1> :: value_type () const noexcept
{
 return crap :: upperBoundType <Type, Operator, Type1> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <class, class> class Operator, class Type1>
        inline constexpr typename crap :: upperBoundType <Type, Operator, Type1> :: value_type
        crap :: upperBoundType <Type, Operator, Type1> :: operator () () const noexcept
{
 return crap :: upperBoundType <Type, Operator, Type1> :: value;
}
#endif

template <class Type, template <class, class> class Operator, class ... Types>
        inline constexpr crap :: upperBoundType <Type, Operator, Types...> :: operator
        typename crap :: upperBoundType <Type, Operator, Types...> :: value_type () const noexcept
{
 return crap :: upperBoundType <Type, Operator, Types...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <class, class> class Operator, class ... Types>
        inline constexpr typename crap :: upperBoundType <Type, Operator, Types...> :: value_type
        crap :: upperBoundType <Type, Operator, Types...> :: operator () () const noexcept
{
 return crap :: upperBoundType <Type, Operator, Types...> :: value;
}
#endif
#endif
