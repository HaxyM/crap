#ifndef CRAP_ALGORITHM_MINVALUE
#define CRAP_ALGORITHM_MINVALUE

#include "../numeric/reducevalue.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct minValue;

 template <class Type, template <Type, Type> class Operator, Type Value>
	 struct minValue<Type, Operator, Value>
 {
  constexpr const static Type value = Value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
	 struct minValue<Type, Operator, Value1, Value2>
 {
  constexpr const static Type value = ((Operator <Value1, Value2> :: value) ? Value1 : Value2);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 struct minValue
 {
  private:
  static_assert(sizeof...(Values) > 0u, "Extremum of empty set is not defined.");
  template <Type ... SubValues> using This = minValue<Type, Operator, SubValues...>;
  public:
  constexpr const static Type value = reduceValue <Type, This, Values...> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <class Type, template <Type, Type> class Operator, Type Value1>
        inline constexpr crap :: minValue <Type, Operator, Value1> :: operator
        typename crap :: minValue <Type, Operator, Value1> :: value_type () const noexcept
{
 return crap :: minValue <Type, Operator, Value1> :: value;
}

template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
        inline constexpr crap :: minValue <Type, Operator, Value1, Value2> :: operator
        typename crap :: minValue <Type, Operator, Value1, Value2> :: value_type () const noexcept
{
 return crap :: minValue <Type, Operator, Value1, Value2> :: value;
}

template <class Type, template <Type, Type> class Operator, Type ... Values>
        inline constexpr crap :: minValue <Type, Operator, Values...> :: operator
        typename crap :: minValue <Type, Operator, Values...> :: value_type () const noexcept
{
 return crap :: minValue <Type, Operator, Values...> :: value;
}
#endif
