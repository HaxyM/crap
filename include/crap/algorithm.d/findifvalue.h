#ifndef CRAP_ALGORITHM_FINDIFVALUE
#define CRAP_ALGORITHM_FINDIFVALUE

#include <cstddef>

#include "../utility.d/bisectvalue.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <class Type, template <Type> class, Type...> struct findIfValue;

 template <class Type, template <Type> class Operator> struct findIfValue<Type, Operator>
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type> class Operator, Type Value> struct findIfValue<Type, Operator, Value>
 {
  constexpr const static std :: size_t value = (Operator <Value> :: value ? 0u : 1u);
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type> class Operator, Type ... Values> struct findIfValue
 {
  private:
  using values = bisectValue<Type, Values...>;
  template <Type ... SubValues> using This = findIfValue<Type, Operator, SubValues...>;
  using lower = typename values :: template lower<This>;
  template <std :: size_t LowerValue, std :: size_t> struct CheckUpper;
  template <std :: size_t LowerNpos> struct CheckUpper<LowerNpos, LowerNpos>;
  public:
  constexpr const static std :: size_t value = CheckUpper <lower :: value, lower :: npos> :: value;
  constexpr const static std :: size_t npos = sizeof...(Values);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type> class Operator, Type ... Values>
	 template <std :: size_t LowerValue, std :: size_t>
 struct findIfValue <Type, Operator, Values...> :: CheckUpper
 {
  constexpr const static std :: size_t value = LowerValue;
 };

 template <class Type, template <Type> class Operator, Type ... Values>
	 template <std :: size_t LowerNpos>
 struct findIfValue <Type, Operator, Values...> :: CheckUpper<LowerNpos, LowerNpos>
 {
  private:
  using values = bisectValue<Type, Values...>;
  template <Type ... SubValues> using This = findIfValue<Type, Operator, SubValues...>;
  public:
  constexpr const static std :: size_t value = LowerNpos + values :: template upper <This> :: value;
 };
}

template <class Type, template <Type> class Operator>
inline constexpr crap :: findIfValue <Type, Operator> :: operator
typename crap :: findIfValue <Type, Operator> :: value_type () const noexcept
{
 return crap :: findIfValue <Type, Operator> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type> class Operator>
        inline constexpr typename crap :: findIfValue <Type, Operator> :: value_type
        crap :: findIfValue <Type, Operator> :: operator () () const noexcept
{
 return crap :: findIfValue <Type, Operator> :: value;
}
#endif

template <class Type, template <Type> class Operator, Type Value>
inline constexpr crap :: findIfValue <Type, Operator, Value> :: operator
typename crap :: findIfValue <Type, Operator, Value> :: value_type () const noexcept
{
 return crap :: findIfValue <Type, Operator, Value> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type> class Operator, Type Value>
        inline constexpr typename crap :: findIfValue <Type, Operator, Value> :: value_type
        crap :: findIfValue <Type, Operator, Value> :: operator () () const noexcept
{
 return crap :: findIfValue <Type, Operator, Value> :: value;
}
#endif

template <class Type, template <Type> class Operator, Type ... Values>
inline constexpr crap :: findIfValue <Type, Operator, Values...> :: operator
typename crap :: findIfValue <Type, Operator, Values...> :: value_type () const noexcept
{
 return crap :: findIfValue <Type, Operator, Values...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type> class Operator, Type ... Values>
        inline constexpr typename crap :: findIfValue <Type, Operator, Values...> :: value_type
        crap :: findIfValue <Type, Operator, Values...> :: operator () () const noexcept
{
 return crap :: findIfValue <Type, Operator, Values...> :: value;
}
#endif
#endif

