#ifndef CRAP_ALGORITHM_MINELEMENTVALUE
#define CRAP_ALGORITHM_MINELEMENTVALUE

#include <cstddef>

#include "../utility.d/bisectvalue.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct minElementValue;

 template <class Type, template <Type, Type> class Operator> struct minElementValue<Type, Operator>
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
	 struct minElementValue<Type, Operator, Value>
 {
  template <class NewType, template <NewType, NewType> class, NewType...> friend struct minElementValue;
  private:
  constexpr const static Type minValue = Value;
  public:
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
	 struct minElementValue<Type, Operator, Value1, Value2>
 {
  template <class NewType, template <NewType, NewType> class, NewType...> friend struct minElementValue;
  private:
  constexpr const static Type minValue = ((Operator <Value2, Value1> :: value) ? Value2 : Value1);
  public:
  constexpr const static std :: size_t value = ((Operator <Value2, Value1> :: value) ? 1u : 0u);
  constexpr const static std :: size_t npos = 2u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> struct minElementValue
 {
  template <class NewType, template <NewType, NewType> class, NewType...> friend struct minElementValue;
  private:
  template <Type ... SubValues> using This = minElementValue<Type, Operator, SubValues...>;
  using lower = typename bisectValue <Type, Values...> :: template lower<This>;
  using upper = typename bisectValue <Type, Values...> :: template upper<This>;
  constexpr const static Type minValue =
	  ((Operator <upper :: minValue, lower :: minValue> :: value) ? (upper :: minValue) : (lower :: minValue));
  public:
  constexpr const static std :: size_t value =
	  ((Operator <upper :: minValue, lower :: minValue> :: value) ? (lower :: npos + upper :: value) : (lower :: value));
  constexpr const static std :: size_t npos = sizeof...(Values);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };
}

template <class Type, template <Type, Type> class Operator>
	inline constexpr crap :: minElementValue <Type, Operator> :: operator
	typename crap :: minElementValue <Type, Operator> :: value_type () const noexcept
{
 return crap :: minElementValue <Type, Operator> :: value;
};
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator>
	inline constexpr typename crap :: minElementValue <Type, Operator> :: value_type
	crap :: minElementValue <Type, Operator> :: operator () () const noexcept
{
 return crap :: minElementValue <Type, Operator> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type Value>
	inline constexpr crap :: minElementValue <Type, Operator, Value> :: operator
	typename crap :: minElementValue <Type, Operator, Value> :: value_type () const noexcept
{
 return crap :: minElementValue <Type, Operator, Value> :: value;
};
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type Value>
	inline constexpr typename crap :: minElementValue <Type, Operator, Value> :: value_type
	crap :: minElementValue <Type, Operator, Value> :: operator () () const noexcept
{
 return crap :: minElementValue <Type, Operator, Value> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
	inline constexpr crap :: minElementValue <Type, Operator, Value1, Value2> :: operator
	typename crap :: minElementValue <Type, Operator, Value1, Value2> :: value_type () const noexcept
{
 return crap :: minElementValue <Type, Operator, Value1, Value2> :: value;
};
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
	inline constexpr typename crap :: minElementValue <Type, Operator, Value1, Value2> :: value_type
	crap :: minElementValue <Type, Operator, Value1, Value2> :: operator () () const noexcept
{
 return crap :: minElementValue <Type, Operator, Value1, Value2> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type ... Values>
	inline constexpr crap :: minElementValue <Type, Operator, Values...> :: operator
	typename crap :: minElementValue <Type, Operator, Values...> :: value_type () const noexcept
{
 return crap :: minElementValue <Type, Operator, Values...> :: value;
};
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type ... Values>
	inline constexpr typename crap :: minElementValue <Type, Operator, Values...> :: value_type
	crap :: minElementValue <Type, Operator, Values...> :: operator () () const noexcept
{
 return crap :: minElementValue <Type, Operator, Values...> :: value;
}
#endif
#endif

