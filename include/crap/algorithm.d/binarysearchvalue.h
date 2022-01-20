#ifndef CRAP_ALGORITHM_BINARYSEARCHVALUE
#define CRAP_ALGORITHM_BINARYSEARCHVALUE

#include "copyvalue.h"
#include "../utility.d/valuelist.h"
#include "../utility.d/valuedemultiplexer.h"
#include "../utility.d/valuemultiplexer.h"

namespace crap
{
 template <class Type, Type, template <Type, Type> class, Type...> struct binarySearchValue;

 template <class Type, Type Value, template <Type, Type> class Operator> struct binarySearchValue<Type, Value, Operator>
 {
  constexpr const static bool value = false;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type Value, template <Type, Type> class Operator, Type Value1> struct binarySearchValue<Type, Value, Operator, Value1>
 {
  private:
  constexpr const static bool smaller = Operator <Value, Value1> :: value;
  constexpr const static bool larger = Operator <Value1, Value> :: value;
  public:
  constexpr const static bool value = !(smaller || larger);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type Value, template <Type, Type> class Operator, Type ... Values> struct binarySearchValue
 {
  private:
  using values = valueList<Type, Values...>;
  constexpr const static Type midValue = values :: template At <(values :: size) / 2u> :: value;
  template <Type...> using found = std :: true_type;
  template <Type...> struct Continue;
  constexpr const static bool equal = (Operator <Value, midValue> :: value) && (Operator <midValue, Value> :: value);
  using result = typename valueDemultiplexer <Type, equal, copyValue <Type, Values...> :: template type, found, Continue> :: type;
  public:
  constexpr const static bool value = result :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type Value, template <Type, Type> class Operator, Type ... Values>
	 template <Type...>
 struct binarySearchValue <Type, Value, Operator, Values...> :: Continue
 {
  private:
  using values = valueList<Type, Values...>;
  constexpr const static Type midValue = values :: template At <(values :: size) / 2u> :: value;
  constexpr const static bool smaller = Operator <Value, midValue> :: value;
  template <Type ... SubValues> using This = binarySearchValue<Type, Value, Operator, SubValues...>;
  template <template <Type...> class Container> using TillSource = typename values :: template till <(values :: size) / 2u, Container>;
  template <template <Type...> class Container> using SinceSource = typename values :: template since <(values :: size) / 2u, Container>;
  using result = typename valueMultiplexer <Type, smaller, This, TillSource, SinceSource> :: type;
  public:
  constexpr const static bool value = result :: value;
 };
}

template <class Type, Type Value, template <Type, Type> class Operator>
        inline constexpr crap :: binarySearchValue <Type, Value, Operator> :: operator
        typename crap :: binarySearchValue <Type, Value, Operator> :: value_type () const noexcept
{
 return crap :: binarySearchValue <Type, Value, Operator> :: value;
}

template <class Type, Type Value, template <Type, Type> class Operator, Type Value1>
        inline constexpr crap :: binarySearchValue <Type, Value, Operator, Value1> :: operator
        typename crap :: binarySearchValue <Type, Value, Operator, Value1> :: value_type () const noexcept
{
 return crap :: binarySearchValue <Type, Value, Operator, Value1> :: value;
}

template <class Type, Type Value, template <Type, Type> class Operator, Type ... Values>
        inline constexpr crap :: binarySearchValue <Type, Value, Operator, Values...> :: operator
        typename crap :: binarySearchValue <Type, Value, Operator, Values...> :: value_type () const noexcept
{
 return crap :: binarySearchValue <Type, Value, Operator, Values...> :: value;
}
#endif

