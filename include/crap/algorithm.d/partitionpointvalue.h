#ifndef CRAP_ALGORITHM_PARTITIONPOINTVALUE
#define CRAP_ALGORITHM_PARTITIONPOINTVALUE

#include "../utility.d/bisectvalue.h"
#include "../version.d/libintegralconstantcallable.h"

#include <cstddef>

namespace crap
{
 template <class Type, template <Type> class, Type...> struct partitionPointValue;

 template <class Type, template <Type> class Operator> struct partitionPointValue<Type, Operator>
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type> class Operator, Type Value> struct partitionPointValue<Type, Operator, Value>
 {
  constexpr const static std :: size_t value = ((Operator <Value> :: value) ? 1u : 0u);
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type> class Operator, Type ... Values> struct partitionPointValue
 {
  private:
  using values = bisectValue<Type, Values...>;
  template <Type ... SubValues> using This = partitionPointValue<Type, Operator, SubValues...>;
  template <std :: size_t LowerValue, std :: size_t LowerNpos> struct upper;
  template <std :: size_t LowerNpos> struct upper<LowerNpos, LowerNpos>;
  using lower = typename values :: template lower<This>;
  public:
  constexpr const static std :: size_t value = upper <lower :: value, lower :: npos> :: value;
  constexpr const static std :: size_t npos = sizeof...(Values);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type> class Operator, Type ... Values>
	 template <std :: size_t LowerValue, std :: size_t LowerNpos>
	struct partitionPointValue <Type, Operator, Values...> :: upper
 {
  constexpr const static std :: size_t value = LowerValue;
 };

 template <class Type, template <Type> class Operator, Type ... Values>
	 template <std :: size_t LowerNpos>
	struct partitionPointValue <Type, Operator, Values...> :: upper<LowerNpos, LowerNpos>
 {
  private:
  using values = bisectValue<Type, Values...>;
  template <Type ... SubValues> using This = partitionPointValue<Type, Operator, SubValues...>;
  public:
  constexpr const static std :: size_t value = LowerNpos + (values :: template upper <This> :: value);
 };
}

template <class Type, template <Type> class Operator>
        inline constexpr crap :: partitionPointValue <Type, Operator> :: operator
        typename crap :: partitionPointValue <Type, Operator> :: value_type () const noexcept
{
 return crap :: partitionPointValue <Type, Operator> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type> class Operator>
	inline constexpr typename crap :: partitionPointValue <Type, Operator> :: value_type
	crap :: partitionPointValue <Type, Operator> :: operator () () const noexcept
{
 return crap :: partitionPointValue <Type, Operator> :: value;
}
#endif

template <class Type, template <Type> class Operator, Type Value>
        inline constexpr crap :: partitionPointValue <Type, Operator, Value> :: operator
        typename crap :: partitionPointValue <Type, Operator, Value> :: value_type () const noexcept
{
 return crap :: partitionPointValue <Type, Operator, Value> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type> class Operator, Type Value>
	inline constexpr typename crap :: partitionPointValue <Type, Operator, Value> :: value_type
	crap :: partitionPointValue <Type, Operator, Value> :: operator () () const noexcept
{
 return crap :: partitionPointValue <Type, Operator, Value> :: value;
}
#endif

template <class Type, template <Type> class Operator, Type ... Values>
        inline constexpr crap :: partitionPointValue <Type, Operator, Values...> :: operator
        typename crap :: partitionPointValue <Type, Operator, Values...> :: value_type () const noexcept
{
 return crap :: partitionPointValue <Type, Operator, Values...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type> class Operator, Type ... Values>
	inline constexpr typename crap :: partitionPointValue <Type, Operator, Values...> :: value_type
	crap :: partitionPointValue <Type, Operator, Values...> :: operator () () const noexcept
{
 return crap :: partitionPointValue <Type, Operator, Values...> :: value;
}
#endif
#endif

