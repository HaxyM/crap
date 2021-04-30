#ifndef CRAP_ALGORITHM_INCLUDESVALUE
#define CRAP_ALGORITHM_INCLUDESVALUE

#include "binarysearchvalue.h"
#include "equalrangevalue.h"
#include "../utility/valuelist.h"

#include <cstddef>

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct includesValue;

 template <class Type, template <Type, Type> class Operator> struct includesValue<Type, Operator>
 {
  template <Type ... Values2> struct with;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1>
	 struct includesValue<Type, Operator, Value1>
 {
  template <Type...> struct with;
  template <Type Only> struct with<Only>;
  template <Type First, Type ... Rest> struct with<First, Rest...>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1> struct includesValue
 {
  template <Type...> struct with;
  template <Type Only> struct with<Only>;
  template <Type First, Type ... Rest> struct with<First, Rest...>;
 };

 template <class Type, template <Type, Type> class Operator> template <Type ... Values2>
	 struct includesValue <Type, Operator> :: with
 {
  constexpr const static bool value = (sizeof...(Values2) == 0u);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1> template <Type...>
	 struct includesValue <Type, Operator, Value1> :: with
 {
  constexpr const static bool value = true;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1> template <Type Only>
	 struct includesValue <Type, Operator, Value1> :: template with<Only>
 {
  constexpr const static bool value = !((Operator <Value1, Only> :: value) || (Operator <Only, Value1> :: value));
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1> template <Type First, Type ... Rest>
	 struct includesValue <Type, Operator, Value1> :: template with<First, Rest...>
 {
  constexpr const static bool value = false;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1> template <Type...>
	 struct includesValue <Type, Operator, Values1...> :: with
 {
  constexpr const static bool value = true;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1> template <Type Only>
	 struct includesValue <Type, Operator, Values1...> :: template with<Only>
 {
  constexpr const static bool value = binarySearchValue <Type, Only, Operator, Values1...> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1> template <Type First, Type ... Rest>
	 struct includesValue <Type, Operator, Values1...> :: template with<First, Rest...>
 {
  private:
  constexpr const static Type mid = valueList <Type, Values1...> :: template At <sizeof...(Values1) / 2u> :: value;
  using range1 = equalRangeValue<Type, mid, Operator, Values1...>;
  using range2 = equalRangeValue<Type, mid, Operator, First, Rest...>;
  constexpr const static bool midOk = !((range1 :: end - range1 :: begin) < (range2 :: end - range2 :: begin));
  template <bool, std :: size_t, std :: size_t> struct checkLower;
  template <std :: size_t End1, std :: size_t End2> struct checkLower<true, End1, End2>;
  template <bool, std :: size_t, std :: size_t> struct checkUpper;
  template <std :: size_t Begin1, std :: size_t Begin2> struct checkUpper<true, Begin1, Begin2>;
  public:
  constexpr const static bool value =
	  midOk &&
	  checkLower <midOk, range1 :: begin, range2 :: begin> :: value &&
	  checkUpper <midOk, range1 :: end, range2 :: end> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1>
	 template <Type First, Type ... Rest> template <bool, std :: size_t, std :: size_t>
	 struct includesValue <Type, Operator, Values1...> :: template with <First, Rest...> :: checkLower
 {
  constexpr const static bool value = false;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1>
	 template <Type First, Type ... Rest> template <std :: size_t End1, std :: size_t End2>
 struct includesValue <Type, Operator, Values1...> :: template with <First, Rest...> :: template
	 checkLower<true, End1, End2>
 {
  private:
  template <Type ... SubValues> using This = includesValue<Type, Operator, SubValues...>;
  using values1 = valueList<Type, Values1...>;
  using values2 = valueList<Type, First, Rest...>;
  public:
  constexpr const static bool value =
	  values2 :: template till <End2, values1 :: template till <End1, This> :: template with> :: value;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1>
	 template <Type First, Type ... Rest> template <bool, std :: size_t, std :: size_t>
	 struct includesValue <Type, Operator, Values1...> :: template with <First, Rest...> :: checkUpper
 {
  constexpr const static bool value = false;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1>
	 template <Type First, Type ... Rest> template <std :: size_t Begin1, std :: size_t Begin2>
 struct includesValue <Type, Operator, Values1...> :: template with <First, Rest...> :: template
	 checkUpper<true, Begin1, Begin2>
 {
  private:
  template <Type ... SubValues> using This = includesValue<Type, Operator, SubValues...>;
  using values1 = valueList<Type, Values1...>;
  using values2 = valueList<Type, First, Rest...>;
  public:
  constexpr const static bool value =
	  values2 :: template since <Begin2, values1 :: template since <Begin1, This> :: template with> :: value;
 };
}

template <class Type, template <Type, Type> class Operator> template <Type ... Values2>
        inline constexpr
	crap :: includesValue <Type, Operator> :: template with <Values2...> :: operator typename
	crap :: includesValue <Type, Operator> :: template with <Values2...> :: value_type ()
	const noexcept
{
 return crap :: includesValue <Type, Operator> :: template with <Values2...> :: value;
}

template <class Type, template <Type, Type> class Operator, Type Value1> template <Type ... Empty>
        inline constexpr
	crap :: includesValue <Type, Operator, Value1> :: template with <Empty...> :: operator typename
	crap :: includesValue <Type, Operator, Value1> :: template with <Empty...> :: value_type ()
	const noexcept
{
 return crap :: includesValue <Type, Operator, Value1> :: template with <Empty...> :: value;
}

template <class Type, template <Type, Type> class Operator, Type Value1> template <Type Only>
        inline constexpr
	crap :: includesValue <Type, Operator, Value1> :: template with <Only> :: operator typename
	crap :: includesValue <Type, Operator, Value1> :: template with <Only> :: value_type ()
	const noexcept
{
 return crap :: includesValue <Type, Operator, Value1> :: template with <Only> :: value;
}

template <class Type, template <Type, Type> class Operator, Type Value1> template <Type First, Type ... Rest>
        inline constexpr
	crap :: includesValue <Type, Operator, Value1> :: template with <First, Rest...> :: operator typename
	crap :: includesValue <Type, Operator, Value1> :: template with <First, Rest...> :: value_type ()
	const noexcept
{
 return crap :: includesValue <Type, Operator, Value1> :: template with <First, Rest...> :: value;
}

template <class Type, template <Type, Type> class Operator, Type ... Values1> template <Type ... Empty>
        inline constexpr
	crap :: includesValue <Type, Operator, Values1...> :: template with <Empty...> :: operator typename
	crap :: includesValue <Type, Operator, Values1...> :: template with <Empty...> :: value_type ()
	const noexcept
{
 return crap :: includesValue <Type, Operator, Values1...> :: template with <Empty...> :: value;
}

template <class Type, template <Type, Type> class Operator, Type ... Values1> template <Type Only>
        inline constexpr
	crap :: includesValue <Type, Operator, Values1...> :: template with <Only> :: operator typename
	crap :: includesValue <Type, Operator, Values1...> :: template with <Only> :: value_type ()
	const noexcept
{
 return crap :: includesValue <Type, Operator, Values1...> :: template with <Only> :: value;
}

template <class Type, template <Type, Type> class Operator, Type ... Values1> template <Type First, Type ... Rest>
        inline constexpr
	crap :: includesValue <Type, Operator, Values1...> :: template with <First, Rest...> :: operator typename
	crap :: includesValue <Type, Operator, Values1...> :: template with <First, Rest...> :: value_type ()
	const noexcept
{
 return crap :: includesValue <Type, Operator, Values1...> :: template with <First, Rest...> :: value;
}
#endif

