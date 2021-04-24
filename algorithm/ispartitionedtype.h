#ifndef CRAP_ALGORITHM_ISPARTITIONEDTYPE
#define CRAP_ALGORITHM_ISPARTITIONEDTYPE

#include "noneoftype.h"
#include "partitionpointtype.h"
#include "../utility/typelist.h"

namespace crap
{
 template <template <class> class, class...> struct isPartitionedType;

 template <template <class> class Operator> struct isPartitionedType<Operator>
 {
  constexpr const static bool value = true;
 };

 template <template <class> class Operator, class Type> struct isPartitionedType<Operator, Type>
 {
  constexpr const static bool value = true;
 };

 template <template <class> class Operator, class Type1, class Type2>
	 struct isPartitionedType<Operator, Type1, Type2>
 {
  constexpr const static bool value = Operator <Type1> :: value;
 };

 template <template <class> class Operator, class ... Types> struct isPartitionedType
 {
  private:
  using partitionPoint = partitionPointType<Operator, Types...>;
  template <std :: size_t Value, std :: size_t Npos> struct checkTail;
  template <std :: size_t Npos> struct checkTail<Npos, Npos>;
  public:
  constexpr const static bool value = checkTail <partitionPoint :: value, partitionPoint :: npos> :: value;
 };

 template <template <class> class Operator, class ... Types>
	 template <std :: size_t Value, std :: size_t Npos>
	struct isPartitionedType <Operator, Types...> :: checkTail
 {
  private:
  template <class ... SubTypes> using noneOf = noneOfType<Operator, SubTypes...>;
  public:
  constexpr const static bool value = typeList <Types...> :: template since<Value + 1u, noneOf> :: value;
 };

 template <template <class> class Operator, class ... Types> template <std :: size_t Npos>
	 struct isPartitionedType <Operator, Types...> :: template checkTail<Npos, Npos>
 {
  constexpr const static bool value = true;
 };
}
#endif

