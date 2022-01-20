#ifndef CRAP_ALGORITHM_ISSORTEDVALUE
#define CRAP_ALGORITHM_ISSORTEDVALUE

#include "../utility.d/valuelist.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct isSortedValue;

 template <class Type, template <Type, Type> class Operator> struct isSortedValue<Type, Operator>
 {
  constexpr const static bool value = true;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1> struct isSortedValue<Type, Operator, Value1>
 {
  constexpr const static bool value = true;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> struct isSortedValue
 {
  private:
  using values = valueList<Type, Values...>;
  constexpr const static std :: size_t half = (values :: size) / 2u;
  template <Type ... SubValues> using This = isSortedValue<Type, Operator, SubValues...>;
  using lower = typename values :: template till<half, This>;
  using upper = typename values :: template since<half, This>;
  constexpr const static Type lowerLast = values :: template At <half - 1u> :: value;
  constexpr const static Type upperFirst = values :: template At <half> :: value;
  constexpr const static bool borderSorted = !(Operator <upperFirst, lowerLast> :: value);
  public:
  constexpr const static bool value = (lower :: value) && borderSorted && (upper :: value);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <class Type, template <Type, Type> class Operator>
        inline constexpr crap :: isSortedValue <Type, Operator> :: operator
        typename crap :: isSortedValue <Type, Operator> :: value_type () const noexcept
{
 return crap :: isSortedValue <Type, Operator> :: value;
}

template <class Type, template <Type, Type> class Operator, Type Value>
        inline constexpr crap :: isSortedValue <Type, Operator, Value> :: operator
        typename crap :: isSortedValue <Type, Operator, Value> :: value_type () const noexcept
{
 return crap :: isSortedValue <Type, Operator, Value> :: value;
}

template <class Type, template <Type, Type> class Operator, Type ... Values>
        inline constexpr crap :: isSortedValue <Type, Operator, Values...> :: operator
        typename crap :: isSortedValue <Type, Operator, Values...> :: value_type () const noexcept
{
 return crap :: isSortedValue <Type, Operator, Values...> :: value;
}
#endif

