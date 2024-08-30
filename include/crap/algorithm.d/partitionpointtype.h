#ifndef CRAP_ALGORITHM_PARTITIONPOINTTYPE
#define CRAP_ALGORITHM_PARTITIONPOINTTYPE

#include "../utility.d/bisecttype.h"
#include "../version.d/libintegralconstantcallable.h"

#include <cstddef>

namespace crap
{
 template <template <class> class, class...> struct partitionPointType;

 template <template <class> class Operator> struct partitionPointType<Operator>
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class> class Operator, class Type> struct partitionPointType<Operator, Type>
 {
  constexpr const static std :: size_t value = ((Operator <Type> :: value) ? 1u : 0u);
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class> class Operator, class ... Types> struct partitionPointType
 {
  private:
  using types = bisectType<Types...>;
  template <class ... SubTypes> using This = partitionPointType<Operator, SubTypes...>;
  template <std :: size_t LowerValue, std :: size_t LowerNpos> struct upper;
  template <std :: size_t LowerNpos> struct upper<LowerNpos, LowerNpos>;
  using lower = typename types :: template lower<This>;
  public:
  constexpr const static std :: size_t value = upper <lower :: value, lower :: npos> :: value;
  constexpr const static std :: size_t npos = sizeof...(Types);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class> class Operator, class ... Types>
	 template <std :: size_t LowerValue, std :: size_t LowerNpos>
	struct partitionPointType <Operator, Types...> :: upper
 {
  constexpr const static std :: size_t value = LowerValue;
 };

 template <template <class> class Operator, class ... Types>
	 template <std :: size_t LowerNpos>
	struct partitionPointType <Operator, Types...> :: upper<LowerNpos, LowerNpos>
 {
  private:
  using types = bisectType<Types...>;
  template <class ... SubTypes> using This = partitionPointType<Operator, SubTypes...>;
  public:
  constexpr const static std :: size_t value = LowerNpos + (types :: template upper <This> :: value);
 };
}

template <template <class> class Operator>
        inline constexpr crap :: partitionPointType <Operator> :: operator
        typename crap :: partitionPointType <Operator> :: value_type () const noexcept
{
 return crap :: partitionPointType <Operator> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class> class Operator>
	inline constexpr typename crap :: partitionPointType <Operator> :: value_type
	crap :: partitionPointType <Operator> :: operator () () const noexcept
{
 return crap :: partitionPointType <Operator> :: value;
}
#endif

template <template <class> class Operator, class Type>
        inline constexpr crap :: partitionPointType <Operator, Type> :: operator
        typename crap :: partitionPointType <Operator, Type> :: value_type () const noexcept
{
 return crap :: partitionPointType <Operator, Type> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class> class Operator, class Type>
	inline constexpr typename crap :: partitionPointType <Operator, Type> :: value_type
	crap :: partitionPointType <Operator, Type> :: operator () () const noexcept
{
 return crap :: partitionPointType <Operator, Type> :: value;
}
#endif

template <template <class> class Operator, class ... Types>
        inline constexpr crap :: partitionPointType <Operator, Types...> :: operator
        typename crap :: partitionPointType <Operator, Types...> :: value_type () const noexcept
{
 return crap :: partitionPointType <Operator, Types...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class> class Operator, class ... Types>
	inline constexpr typename crap :: partitionPointType <Operator, Types...> :: value_type
	crap :: partitionPointType <Operator, Types...> :: operator () () const noexcept
{
 return crap :: partitionPointType <Operator, Types...> :: value;
}
#endif
#endif

