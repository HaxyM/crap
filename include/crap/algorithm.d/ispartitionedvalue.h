#ifndef CRAP_ALGORITHM_ISPARTITIONEDVALUE
#define CRAP_ALGORITHM_ISPARTITIONEDVALUE

#include "noneofvalue.h"
#include "partitionpointvalue.h"
#include "../utility.d/valuelist.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <class Type, template <Type> class, Type...> struct isPartitionedValue;

 template <class Type, template <Type> class Operator> struct isPartitionedValue<Type, Operator>
 {
  constexpr const static bool value = true;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type> class Operator, Type Value>
	 struct isPartitionedValue<Type, Operator, Value>
 {
  constexpr const static bool value = true;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type> class Operator, Type Value1, Type Value2>
	 struct isPartitionedValue<Type, Operator, Value1, Value2>
 {
  constexpr const static bool value = Operator <Value1> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type> class Operator, Type ... Values> struct isPartitionedValue
 {
  private:
  using partitionPoint = partitionPointValue<Type, Operator, Values...>;
  template <std :: size_t Value, std :: size_t Npos> struct checkTail;
  template <std :: size_t Npos> struct checkTail<Npos, Npos>;
  public:
  constexpr const static bool value =
	  checkTail <partitionPoint :: value, partitionPoint :: npos> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type> class Operator, Type ... Values>
	 template <std :: size_t Value, std :: size_t Npos>
	struct isPartitionedValue <Type, Operator, Values...> :: checkTail
 {
  private:
  template <Type ... SubValues> using noneOf = noneOfValue<Type, Operator, SubValues...>;
  public:
  constexpr const static bool value =
	  valueList <Type, Values...> :: template since <Value + 1u, noneOf> :: value;
 };

 template <class Type, template <Type> class Operator, Type ... Values> template <std :: size_t Npos>
	 struct isPartitionedValue <Type, Operator, Values...> :: checkTail<Npos, Npos>
 {
  constexpr const static bool value = true;
 };
}

template <class Type, template <Type> class Operator>
	inline constexpr crap :: isPartitionedValue <Type, Operator> :: operator
	typename crap :: isPartitionedValue <Type, Operator> :: value_type () const noexcept
{
 return crap :: isPartitionedValue <Type, Operator> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type> class Operator>
        inline constexpr typename crap :: isPartitionedValue <Type, Operator> :: value_type
        crap :: isPartitionedValue <Type, Operator> :: operator () () const noexcept
{
 return crap :: isPartitionedValue <Type, Operator> :: value;
}
#endif

template <class Type, template <Type> class Operator, Type Value>
	inline constexpr crap :: isPartitionedValue <Type, Operator, Value> :: operator
	typename crap :: isPartitionedValue <Type, Operator, Value> :: value_type () const noexcept
{
 return crap :: isPartitionedValue <Type, Operator, Value> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type> class Operator, Type Value>
        inline constexpr typename crap :: isPartitionedValue <Type, Operator, Value> :: value_type
        crap :: isPartitionedValue <Type, Operator, Value> :: operator () () const noexcept
{
 return crap :: isPartitionedValue <Type, Operator, Value> :: value;
}
#endif

template <class Type, template <Type> class Operator, Type Value1, Type Value2>
	inline constexpr crap :: isPartitionedValue <Type, Operator, Value1, Value2> :: operator
	typename crap :: isPartitionedValue <Type, Operator, Value1, Value2> :: value_type () const noexcept
{
 return crap :: isPartitionedValue <Type, Operator, Value1, Value2> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type> class Operator, Type Value1, Type Value2>
        inline constexpr typename crap :: isPartitionedValue <Type, Operator, Value1, Value2> :: value_type
        crap :: isPartitionedValue <Type, Operator, Value1, Value2> :: operator () () const noexcept
{
 return crap :: isPartitionedValue <Type, Operator, Value1, Value2> :: value;
}
#endif

template <class Type, template <Type> class Operator, Type ... Values>
	inline constexpr crap :: isPartitionedValue <Type, Operator, Values...> :: operator
	typename crap :: isPartitionedValue <Type, Operator, Values...> :: value_type () const noexcept
{
 return crap :: isPartitionedValue <Type, Operator, Values...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type> class Operator, Type ... Values>
        inline constexpr typename crap :: isPartitionedValue <Type, Operator, Values...> :: value_type
        crap :: isPartitionedValue <Type, Operator, Values...> :: operator () () const noexcept
{
 return crap :: isPartitionedValue <Type, Operator, Values...> :: value;
}
#endif
#endif

