#ifndef CRAP_ALGORITHM_ISHEAPVALUE
#define CRAP_ALGORITHM_ISHEAPVALUE

#include "../algorithm.d/findifvalue.h"
#include "../numeric.d/iotavalue.h"
#include "../utility.d/valuelist.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct isHeapValue;

 template <class Type, template <Type, Type> class Operator> struct isHeapValue<Type, Operator>
 {
  constexpr const static bool value = true;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type Value>
	 struct isHeapValue<Type, Operator, Value>
 {
  constexpr const static bool value = true;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
	 struct isHeapValue<Type, Operator, Value1, Value2>
 {
  constexpr const static bool value = !(Operator <Value1, Value2> :: value);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2, Type Value3>
	 struct isHeapValue<Type, Operator, Value1, Value2, Value3>
 {
  private:
  template <bool, class...> struct CheckRight;
  template <class ... Empty> struct CheckRight<true, Empty...>;
  template <class ... Empty> struct CheckRight<false, Empty...>;
  public:
  constexpr const static bool value = CheckRight <!(Operator <Value1, Value2> :: value)> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> struct isHeapValue
 {
  private:
  template <std :: size_t Index> struct CheckIfFails;
  template <std :: size_t ... Indices> using CheckIndices =
	  findIfValue<std :: size_t, CheckIfFails, Indices...>;
  using Implementation =
	  typename iotaValue <sizeof...(Values) - 1u, std :: size_t, 1u> :: template
	  type<CheckIndices>;
  public:
  constexpr const static bool value = (Implementation :: value == Implementation :: npos);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2, Type Value3>
	 template <class ... Empty>
 struct isHeapValue <Type, Operator, Value1, Value2, Value3> :: CheckRight<true, Empty...>
 {
  constexpr const static bool value = !(Operator <Value1, Value3> :: value);
 };

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2, Type Value3>
	 template <class ... Empty>
 struct isHeapValue <Type, Operator, Value1, Value2, Value3> :: CheckRight<false, Empty...>
 {
  constexpr const static bool value = false;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <std :: size_t Index>
 struct isHeapValue <Type, Operator, Values...> :: CheckIfFails
 {
  private:
  constexpr const static std :: size_t parentIndex = (Index - 1u) / 2u;
  constexpr const static Type parent =
	  valueList <Type, Values...> :: template At <parentIndex> :: value;
  constexpr const static Type child =
	  valueList <Type, Values...> :: template At <Index> :: value;
  public:
  constexpr const static bool value = Operator <parent, child> :: value;
 };
}

template <class Type, template <Type, Type> class Operator>
        inline constexpr crap :: isHeapValue <Type, Operator> :: operator
        typename crap :: isHeapValue <Type, Operator> :: value_type () const noexcept
{
 return crap :: isHeapValue <Type, Operator> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator>
	inline constexpr typename crap :: isHeapValue <Type, Operator> :: value_type
	crap :: isHeapValue <Type, Operator> :: operator () () const noexcept
{
 return crap :: isHeapValue <Type, Operator> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type Value>
        inline constexpr crap :: isHeapValue <Type, Operator, Value> :: operator
        typename crap :: isHeapValue <Type, Operator, Value> :: value_type () const noexcept
{
 return crap :: isHeapValue <Type, Operator, Value> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type Value>
	inline constexpr typename crap :: isHeapValue <Type, Operator, Value> :: value_type
	crap :: isHeapValue <Type, Operator, Value> :: operator () () const noexcept
{
 return crap :: isHeapValue <Type, Operator, Value> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
        inline constexpr crap :: isHeapValue <Type, Operator, Value1, Value2> :: operator
        typename crap :: isHeapValue <Type, Operator, Value1, Value2> :: value_type () const noexcept
{
 return crap :: isHeapValue <Type, Operator, Value1, Value2> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
	inline constexpr typename crap :: isHeapValue <Type, Operator, Value1, Value2> :: value_type
	crap :: isHeapValue <Type, Operator, Value1, Value2> :: operator () () const noexcept
{
 return crap :: isHeapValue <Type, Operator, Value1, Value2> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2, Type Value3>
        inline constexpr crap :: isHeapValue <Type, Operator, Value1, Value2, Value3> :: operator
        typename crap :: isHeapValue <Type, Operator, Value1, Value2, Value3> :: value_type () const noexcept
{
 return crap :: isHeapValue <Type, Operator, Value1, Value2, Value3> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2, Type Value3>
	inline constexpr typename crap :: isHeapValue <Type, Operator, Value1, Value2, Value3> :: value_type
	crap :: isHeapValue <Type, Operator, Value1, Value2, Value3> :: operator () () const noexcept
{
 return crap :: isHeapValue <Type, Operator, Value1, Value2, Value3> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type ... Values>
        inline constexpr crap :: isHeapValue <Type, Operator, Values...> :: operator
        typename crap :: isHeapValue <Type, Operator, Values...> :: value_type () const noexcept
{
 return crap :: isHeapValue <Type, Operator, Values...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type ... Values>
	inline constexpr typename crap :: isHeapValue <Type, Operator, Values...> :: value_type
	crap :: isHeapValue <Type, Operator, Values...> :: operator () () const noexcept
{
 return crap :: isHeapValue <Type, Operator, Values...> :: value;
}
#endif
#endif

