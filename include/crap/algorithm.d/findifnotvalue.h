#ifndef CRAP_ALGORITHM_FINDIFNOTVALUE
#define CRAP_ALGORITHM_FINDIFNOTVALUE

#include <cstddef>

#include "../utility.d/bisectvalue.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <class Type, template <Type> class, Type...> struct findIfNotValue;

 template <class Type, template <Type> class Operator> struct findIfNotValue<Type, Operator>
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type> class Operator, Type Value> struct findIfNotValue<Type, Operator, Value>
 {
  constexpr const static std :: size_t value = (Operator <Value> :: value ? 1u : 0u);
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type> class Operator, Type ... Values> struct findIfNotValue
 {
  private:
  using values = bisectValue<Type, Values...>;
  template <Type ... SubValues> using This = findIfNotValue<Type, Operator, SubValues...>;
  using lower = typename values :: template lower<This>;
  template <std :: size_t LowerIndex, std :: size_t, Type...> struct upperCheck;
  template <std :: size_t LowerNpos, Type ... SubValues> struct upperCheck<LowerNpos, LowerNpos, SubValues...>;
  template <Type ... SubValues> using upperCheckThis = upperCheck<lower :: value, lower :: npos, SubValues...>;
  using upper = typename values :: template upper<upperCheckThis>;
  public:
  constexpr const static std :: size_t value = upper :: value;
  constexpr const static std :: size_t npos = sizeof...(Values);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type> class Operator, Type ... Values>
	 template <std :: size_t LowerIndex, std :: size_t, Type...>
 struct findIfNotValue <Type, Operator, Values...> :: upperCheck
 {
  constexpr const static std :: size_t value = LowerIndex;
 };

 template <class Type, template <Type> class Operator, Type ... Values>
	 template <std :: size_t LowerNpos, Type ... SubValues>
 struct findIfNotValue <Type, Operator, Values...> :: template upperCheck<LowerNpos, LowerNpos, SubValues...>
 {
  constexpr const static std :: size_t value = LowerNpos + (findIfNotValue <Type, Operator, SubValues...> :: value);
 };
}

template <class Type, template <Type> class Operator>
inline constexpr crap :: findIfNotValue <Type, Operator> :: operator
typename crap :: findIfNotValue <Type, Operator> :: value_type () const noexcept
{
 return crap :: findIfNotValue <Type, Operator> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type> class Operator>
        inline constexpr typename crap :: findIfNotValue <Type, Operator> :: value_type
        crap :: findIfNotValue <Type, Operator> :: operator () () const noexcept
{
 return crap :: findIfNotValue <Type, Operator> :: value;
}
#endif

template <class Type, template <Type> class Operator, Type Value>
inline constexpr crap :: findIfNotValue <Type, Operator, Value> :: operator
typename crap :: findIfNotValue <Type, Operator, Value> :: value_type () const noexcept
{
 return crap :: findIfNotValue <Type, Operator, Value> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type> class Operator, Type Value>
        inline constexpr typename crap :: findIfNotValue <Type, Operator, Value> :: value_type
        crap :: findIfNotValue <Type, Operator, Value> :: operator () () const noexcept
{
 return crap :: findIfNotValue <Type, Operator, Value> :: value;
}
#endif

template <class Type, template <Type> class Operator, Type ... Values>
inline constexpr crap :: findIfNotValue <Type, Operator, Values...> :: operator
typename crap :: findIfNotValue <Type, Operator, Values...> :: value_type () const noexcept
{
 return crap :: findIfNotValue <Type, Operator, Values...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type> class Operator, Type ... Values>
        inline constexpr typename crap :: findIfNotValue <Type, Operator, Values...> :: value_type
        crap :: findIfNotValue <Type, Operator, Values...> :: operator () () const noexcept
{
 return crap :: findIfNotValue <Type, Operator, Values...> :: value;
}
#endif
#endif

