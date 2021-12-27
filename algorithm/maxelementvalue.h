#ifndef CRAP_ALGORITHM_MAXELEMENTVALUE
#define CRAP_ALGORITHM_MAXELEMENTVALUE

#include <cstddef>

#include "../utility/bisectvalue.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct maxElementValue;

 template <class Type, template <Type, Type> class Operator> struct maxElementValue<Type, Operator>
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type, Type> class Operator, Type Value>
	 struct maxElementValue<Type, Operator, Value>
 {
  template <class NewType, template <NewType, NewType> class, NewType...> friend struct maxElementValue;
  private:
  constexpr const static Type maxValue = Value;
  public:
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
	 struct maxElementValue<Type, Operator, Value1, Value2>
 {
  template <class NewType, template <NewType, NewType> class, NewType...> friend struct maxElementValue;
  private:
  constexpr const static Type maxValue = ((Operator <Value1, Value2> :: value) ? Value2 : Value1);
  public:
  constexpr const static std :: size_t value = ((Operator <Value1, Value2> :: value) ? 1u : 0u);
  constexpr const static std :: size_t npos = 2u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> struct maxElementValue
 {
  template <class NewType, template <NewType, NewType> class, NewType...> friend struct maxElementValue;
  private:
  template <Type ... SubValues> using This = maxElementValue<Type, Operator, SubValues...>;
  using lower = typename bisectValue <Type, Values...> :: template lower<This>;
  using upper = typename bisectValue <Type, Values...> :: template upper<This>;
  constexpr const static Type maxValue =
	  ((Operator <lower :: maxValue, upper :: maxValue> :: value) ? (upper :: maxValue) : (lower :: maxValue));
  public:
  constexpr const static std :: size_t value =
	  ((Operator <lower :: maxValue, upper :: maxValue> :: value) ? (lower :: npos + upper :: value) : (lower :: value));
  constexpr const static std :: size_t npos = sizeof...(Values);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <class Type, template <Type, Type> class Operator>
	inline constexpr crap :: maxElementValue <Type, Operator> :: operator
	typename crap :: maxElementValue <Type, Operator> :: value_type () const noexcept
{
 return crap :: maxElementValue <Type, Operator> :: value;
};

template <class Type, template <Type, Type> class Operator, Type Value>
	inline constexpr crap :: maxElementValue <Type, Operator, Value> :: operator
	typename crap :: maxElementValue <Type, Operator, Value> :: value_type () const noexcept
{
 return crap :: maxElementValue <Type, Operator, Value> :: value;
};

template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
	inline constexpr crap :: maxElementValue <Type, Operator, Value1, Value2> :: operator
	typename crap :: maxElementValue <Type, Operator, Value1, Value2> :: value_type () const noexcept
{
 return crap :: maxElementValue <Type, Operator, Value1, Value2> :: value;
};

template <class Type, template <Type, Type> class Operator, Type ... Values>
	inline constexpr crap :: maxElementValue <Type, Operator, Values...> :: operator
	typename crap :: maxElementValue <Type, Operator, Values...> :: value_type () const noexcept
{
 return crap :: maxElementValue <Type, Operator, Values...> :: value;
};
#endif

