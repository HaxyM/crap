#ifndef CRAP_ALGORITHM_ISPARTITIONEDVALUE
#define CRAP_ALGORITHM_ISPARTITIONEDVALUE

#include "noneofvalue.h"
#include "partitionpointvalue.h"
#include "../utility/valuelist.h"

namespace crap
{
 template <class Type, template <Type> class, Type...> struct isPartitionedValue;

 template <class Type, template <Type> class Operator> struct isPartitionedValue<Type, Operator>
 {
  constexpr const static bool value = true;
 };

 template <class Type, template <Type> class Operator, Type Value> struct isPartitionedValue<Type, Operator, Value>
 {
  constexpr const static bool value = true;
 };

 template <class Type, template <Type> class Operator, Type Value1, Type Value2>
	 struct isPartitionedValue<Type, Operator, Value1, Value2>
 {
  constexpr const static bool value = Operator <Value1> :: value;
 };

 template <class Type, template <Type> class Operator, Type ... Values> struct isPartitionedValue
 {
  private:
  using partitionPoint = partitionPointValue<Type, Operator, Values...>;
  template <std :: size_t Value, std :: size_t Npos> struct checkTail;
  template <std :: size_t Npos> struct checkTail<Npos, Npos>;
  public:
  constexpr const static bool value = checkTail <partitionPoint :: value, partitionPoint :: npos> :: value;
 };

 template <class Type, template <Type> class Operator, Type ... Values>
	 template <std :: size_t Value, std :: size_t Npos>
	struct isPartitionedValue <Type, Operator, Values...> :: checkTail
 {
  private:
  template <Type ... SubValues> using noneOf = noneOfValue<Type, Operator, SubValues...>;
  public:
  constexpr const static bool value = valueList <Type, Values...> :: template since<Value + 1u, noneOf> :: value;
 };

 template <class Type, template <Type> class Operator, Type ... Values> template <std :: size_t Npos>
	 struct isPartitionedValue <Type, Operator, Values...> :: template checkTail<Npos, Npos>
 {
  constexpr const static bool value = true;
 };
}
#endif

