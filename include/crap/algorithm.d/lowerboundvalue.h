#ifndef CRAP_ALGORITHM_LOWERBOUNDVALUE
#define CRAP_ALGORITHM_LOWERBOUNDVALUE

#include "../utility.d/bisectvalue.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <class Type, Type, template <Type, Type> class, Type...> struct lowerBoundValue;

 template <class Type, Type Value, template <Type, Type> class Operator>
	 struct lowerBoundValue<Type, Value, Operator>
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, Type Value, template <Type, Type> class Operator, Type Value1>
	 struct lowerBoundValue<Type, Value, Operator, Value1>
 {
  constexpr const static std :: size_t value = (Operator <Value1, Value> :: value ? 1u : 0u);
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, Type Value, template <Type, Type> class Operator, Type ... Values> struct lowerBoundValue
 {
  private:
  using values = bisectValue<Type, Values...>;
  template <Type ... SubValues> using This = lowerBoundValue<Type, Value, Operator, SubValues...>;
  using lower = typename values :: template lower<This>;
  template <std :: size_t LowerValue, std :: size_t LowerNpos> struct upper;
  template <std :: size_t LowerNpos> struct upper<LowerNpos, LowerNpos>; 
  public:
  constexpr const static std :: size_t value = upper <lower :: value, lower :: npos> :: value;
  constexpr const static std :: size_t npos = sizeof...(Values);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, Type Value, template <Type, Type> class Operator, Type ... Values>
	 template <std :: size_t LowerValue, std :: size_t>
 struct lowerBoundValue <Type, Value, Operator, Values...> :: upper
 {
  constexpr const static std :: size_t value = LowerValue;
 };

 template <class Type, Type Value, template <Type, Type> class Operator, Type ... Values>
	 template <std :: size_t LowerNpos>
 struct lowerBoundValue <Type, Value, Operator, Values...> :: upper<LowerNpos, LowerNpos>
 {
  private:
  using values = bisectValue<Type, Values...>;
  template <Type ... SubValues> using This = lowerBoundValue<Type, Value, Operator, SubValues...>;
  public:
  constexpr const static std :: size_t value = LowerNpos + values :: template upper <This> :: value;
 };
}

template <class Type, Type Value, template <Type, Type> class Operator>
        inline constexpr crap :: lowerBoundValue <Type, Value, Operator> :: operator
        typename crap :: lowerBoundValue <Type, Value, Operator> :: value_type () const noexcept
{
 return crap :: lowerBoundValue <Type, Value, Operator> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, Type Value, template <Type, Type> class Operator>
        inline constexpr typename crap :: lowerBoundValue <Type, Value, Operator> :: value_type
        crap :: lowerBoundValue <Type, Value, Operator> :: operator () () const noexcept
{
 return crap :: lowerBoundValue <Type, Value, Operator> :: value;
}
#endif

template <class Type, Type Value, template <Type, Type> class Operator, Type Value1>
        inline constexpr crap :: lowerBoundValue <Type, Value, Operator, Value1> :: operator
        typename crap :: lowerBoundValue <Type, Value, Operator, Value1> :: value_type () const noexcept
{
 return crap :: lowerBoundValue <Type, Value, Operator, Value1> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, Type Value, template <Type, Type> class Operator, Type Value1>
        inline constexpr typename crap :: lowerBoundValue <Type, Value, Operator, Value1> :: value_type
        crap :: lowerBoundValue <Type, Value, Operator, Value1> :: operator () () const noexcept
{
 return crap :: lowerBoundValue <Type, Value, Operator, Value1> :: value;
}
#endif

template <class Type, Type Value, template <Type, Type> class Operator, Type ... Values>
        inline constexpr crap :: lowerBoundValue <Type, Value, Operator, Values...> :: operator
        typename crap :: lowerBoundValue <Type, Value, Operator, Values...> :: value_type () const noexcept
{
 return crap :: lowerBoundValue <Type, Value, Operator, Values...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, Type Value, template <Type, Type> class Operator, Type ... Values>
        inline constexpr typename crap :: lowerBoundValue <Type, Value, Operator, Values...> :: value_type
        crap :: lowerBoundValue <Type, Value, Operator, Values...> :: operator () () const noexcept
{
 return crap :: lowerBoundValue <Type, Value, Operator, Values...> :: value;
}
#endif
#endif

