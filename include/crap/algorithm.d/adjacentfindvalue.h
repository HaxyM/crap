#ifndef CRAP_ALGORITHM_ADJACENTFINDVALUE
#define CRAP_ALGORITHM_ADJACENTFINDVALUE

#include "../utility.d/valuelist.h"
#include "../version.d/libintegralconstantcallable.h"

#include <cstddef>

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct adjacentFindValue;

 template <class Type, template <Type, Type> class Operator> struct adjacentFindValue<Type, Operator>
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type Value>
        struct adjacentFindValue<Type, Operator, Value>
 {
  constexpr const static std :: size_t value = 1u;
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
        struct adjacentFindValue<Type, Operator, Value1, Value2>
 {
  constexpr const static std :: size_t value = ((Operator <Value1, Value2> :: value) ? 0u : 2u);
  constexpr const static std :: size_t npos = 2u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> struct adjacentFindValue
 {
  private:
  using values = valueList<Values...>;
  constexpr const static std :: size_t half = values :: size / 2u;
  template <Type ... SubValues> using This = adjacentFindValue<Type, Operator, SubValues...>;
  using lower = typename values :: template till<half, This>;
  template <std :: size_t LowerValue, std :: size_t LowerNpos> struct checkMiddle;
  template <std :: size_t LowerNpos> struct checkMiddle<LowerNpos, LowerNpos>;
  public:
  constexpr const static std :: size_t value = checkMiddle <lower :: value, lower :: npos> :: value;
  constexpr const static std :: size_t npos = sizeof...(Values);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
        template <std :: size_t LowerValue, std :: size_t LowerNpos>
	struct adjacentFindValue <Type, Operator, Values...> :: checkMiddle
 {
  constexpr const static std :: size_t value = LowerValue;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
        template <std :: size_t LowerNpos>
	struct adjacentFindValue <Type, Operator, Values...> :: checkMiddle<LowerNpos, LowerNpos>
 {
  private:
  using values = valueList<Values...>;
  constexpr const static std :: size_t half = values :: size / 2u;
  constexpr const static Type value1 = values :: template At <half - 1u> :: value;
  constexpr const static Type value2 = values :: template At <half> :: value;
  template <bool, class...> struct checkUpper;
  template <class ... Empty> struct checkUpper<true, Empty...>;
  template <class ... Empty> struct checkUpper<false, Empty...>;
  public:
  constexpr const static std :: size_t value = checkUpper <Operator <value1, value2> :: value> :: value;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
        template <std :: size_t LowerNpos>
        template <class ... Empty>
 struct adjacentFindValue <Type, Operator, Values...> ::
	checkMiddle <LowerNpos, LowerNpos> :: checkUpper<true, Empty...>
 {
  constexpr const static std :: size_t value = LowerNpos - 1u;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <std :: size_t LowerNpos>
	 template <class ... Empty>
 struct adjacentFindValue <Type, Operator, Values...> ::
	checkMiddle <LowerNpos, LowerNpos> ::
	checkUpper<false, Empty...>
 {
  private:
  using values = valueList<Values...>;
  constexpr const static std :: size_t half = values :: size / 2u;
  template <Type ... SubValues> using This = adjacentFindValue<Type, Operator, SubValues...>;
  using upper = typename values :: template since<half, This>;
  public:
  constexpr const static std :: size_t value = LowerNpos + (upper :: value);
 };
}

template <class Type, template <Type, Type> class Operator>
        inline constexpr crap :: adjacentFindValue <Type, Operator> :: operator
        typename crap :: adjacentFindValue <Type, Operator> :: value_type () const noexcept
{
 return crap :: adjacentFindValue <Type, Operator> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator>
        inline constexpr typename crap :: adjacentFindValue <Type, Operator> :: value_type
        crap :: adjacentFindValue <Type, Operator> :: operator () () const noexcept
{
 return crap :: adjacentFindValue <Type, Operator> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type Value>
        inline constexpr crap :: adjacentFindValue <Type, Operator, Value> :: operator
        typename crap :: adjacentFindValue <Type, Operator, Value> :: value_type () const noexcept
{
 return crap :: adjacentFindValue <Type, Operator, Value> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type Value>
        inline constexpr typename crap :: adjacentFindValue <Type, Operator, Value> :: value_type
        crap :: adjacentFindValue <Type, Operator, Value> :: operator () () const noexcept
{
 return crap :: adjacentFindValue <Type, Operator, Value> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
        inline constexpr crap :: adjacentFindValue <Type, Operator, Value1, Value2> :: operator
        typename crap :: adjacentFindValue <Type, Operator, Value1, Value2> :: value_type () const noexcept
{
 return crap :: adjacentFindValue <Type, Operator, Value1, Value2> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
        inline constexpr typename crap :: adjacentFindValue <Type, Operator, Value1, Value2> :: value_type
        crap :: adjacentFindValue <Type, Operator, Value1, Value2> :: operator () () const noexcept
{
 return crap :: adjacentFindValue <Type, Operator, Value1, Value2> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type ... Values>
        inline constexpr crap :: adjacentFindValue <Type, Operator, Values...> :: operator
        typename crap :: adjacentFindValue <Type, Operator, Values...> :: value_type () const noexcept
{
 return crap :: adjacentFindValue <Type, Operator, Values...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type ... Values>
        inline constexpr typename crap :: adjacentFindValue <Type, Operator, Values...> :: value_type
        crap :: adjacentFindValue <Type, Operator, Values...> :: operator () () const noexcept
{
 return crap :: adjacentFindValue <Type, Operator, Values...> :: value;
}
#endif
#endif
