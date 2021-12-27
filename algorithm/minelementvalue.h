#ifndef CRAP_ALGORITHM_MINELEMENTVALUE
#define CRAP_ALGORITHM_MINELEMENTVALUE

#include <cstddef>

#include "../utility/bisectvalue.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct minElementValue;

 template <class Type, template <Type, Type> class Operator> struct minElementValue<Type, Operator>
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
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
 };

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
	 struct minElementValue<Type, Operator, Value1, Value2>
 {
  template <class NewType, template <NewType, NewType> class, NewType...> friend struct minElementValue;
  private:
  constexpr const static Type minValue = ((Operator <Value1, Value2> :: value) ? Value1 : Value2);
  public:
  constexpr const static std :: size_t value = ((Operator <Value1, Value2> :: value) ? 0u : 1u);
  constexpr const static std :: size_t npos = 2u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> struct minElementValue
 {
  template <class NewType, template <NewType, NewType> class, NewType...> friend struct minElementValue;
  private:
  template <Type ... SubValues> using This = minElementValue<Type, Operator, SubValues...>;
  using lower = typename bisectValue <Type, Values...> :: template lower<This>;
  using upper = typename bisectValue <Type, Values...> :: template upper<This>;
  constexpr const static Type minValue =
	  ((Operator <lower :: minValue, upper :: minValue> :: value) ? (lower :: minValue) : (upper :: minValue));
  public:
  constexpr const static std :: size_t value =
	  ((Operator <lower :: minValue, upper :: minValue> :: value) ? (lower :: value) : (lower :: npos + upper :: value));
  constexpr const static std :: size_t npos = sizeof...(Values);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <class Type, template <Type, Type> class Operator>
	inline constexpr crap :: minElementValue <Type, Operator> :: operator
	typename crap :: minElementValue <Type, Operator> :: value_type () const noexcept
{
 return crap :: minElementValue <Type, Operator> :: value;
};

template <class Type, template <Type, Type> class Operator, Type Value>
	inline constexpr crap :: minElementValue <Type, Operator, Value> :: operator
	typename crap :: minElementValue <Type, Operator, Value> :: value_type () const noexcept
{
 return crap :: minElementValue <Type, Operator, Value> :: value;
};

template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
	inline constexpr crap :: minElementValue <Type, Operator, Value1, Value2> :: operator
	typename crap :: minElementValue <Type, Operator, Value1, Value2> :: value_type () const noexcept
{
 return crap :: minElementValue <Type, Operator, Value1, Value2> :: value;
};

template <class Type, template <Type, Type> class Operator, Type ... Values>
	inline constexpr crap :: minElementValue <Type, Operator, Values...> :: operator
	typename crap :: minElementValue <Type, Operator, Values...> :: value_type () const noexcept
{
 return crap :: minElementValue <Type, Operator, Values...> :: value;
};
#endif

