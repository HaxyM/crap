#ifndef CRAP_ALGORITHM_ISPARTITIONEDTYPE
#define CRAP_ALGORITHM_ISPARTITIONEDTYPE

#include "noneoftype.h"
#include "partitionpointtype.h"
#include "../utility.d/typelist.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <template <class> class, class...> struct isPartitionedType;

 template <template <class> class Operator>
	 struct isPartitionedType<Operator>
 {
  constexpr const static bool value = true;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class> class Operator, class Type>
	 struct isPartitionedType<Operator, Type>
 {
  constexpr const static bool value = true;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class> class Operator, class Type1, class Type2>
	 struct isPartitionedType<Operator, Type1, Type2>
 {
  constexpr const static bool value = Operator <Type1> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <template <class> class Operator, class ... Types> struct isPartitionedType
 {
  private:
  using partitionPoint = partitionPointType<Operator, Types...>;
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

 template <template <class> class Operator, class ... Types>
	 template <std :: size_t Value, std :: size_t Npos>
	struct isPartitionedType <Operator, Types...> :: checkTail
 {
  private:
  template <class ... SubTypes> using noneOf = noneOfType<Operator, SubTypes...>;
  public:
  constexpr const static bool value =
	  typeList <Types...> :: template since <Value + 1u, noneOf> :: value;
 };

 template <template <class> class Operator, class ... Types> template <std :: size_t Npos>
	 struct isPartitionedType <Operator, Types...> :: checkTail<Npos, Npos>
 {
  constexpr const static bool value = true;
 };
}

template <template <class> class Operator>
        inline constexpr crap :: isPartitionedType <Operator> :: operator
        typename crap :: isPartitionedType <Operator> :: value_type () const noexcept
{
 return crap :: isPartitionedType <Operator> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class> class Operator>
        inline constexpr typename crap :: isPartitionedType <Operator> :: value_type
        crap :: isPartitionedType <Operator> :: operator () () const noexcept
{
 return crap :: isPartitionedType <Operator> :: value;
}
#endif

template <template <class> class Operator, class Type>
        inline constexpr crap :: isPartitionedType <Operator, Type> :: operator
        typename crap :: isPartitionedType <Operator, Type> :: value_type () const noexcept
{
 return crap :: isPartitionedType <Operator, Type> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class> class Operator, class Type>
        inline constexpr typename crap :: isPartitionedType <Operator, Type> :: value_type
        crap :: isPartitionedType <Operator, Type> :: operator () () const noexcept
{
 return crap :: isPartitionedType <Operator, Type> :: value;
}
#endif

template <template <class> class Operator, class Type1, class Type2>
        inline constexpr crap :: isPartitionedType <Operator, Type1, Type2> :: operator
        typename crap :: isPartitionedType <Operator, Type1, Type2> :: value_type () const noexcept
{
 return crap :: isPartitionedType <Operator, Type1, Type2> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class> class Operator, class Type1, class Type2>
        inline constexpr typename crap :: isPartitionedType <Operator, Type1, Type2> :: value_type
        crap :: isPartitionedType <Operator, Type1, Type2> :: operator () () const noexcept
{
 return crap :: isPartitionedType <Operator, Type1, Type2> :: value;
}
#endif

template <template <class> class Operator, class ... Types>
        inline constexpr crap :: isPartitionedType <Operator, Types...> :: operator
        typename crap :: isPartitionedType <Operator, Types...> :: value_type () const noexcept
{
 return crap :: isPartitionedType <Operator, Types...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <template <class> class Operator, class ... Types>
        inline constexpr typename crap :: isPartitionedType <Operator, Types...> :: value_type
        crap :: isPartitionedType <Operator, Types...> :: operator () () const noexcept
{
 return crap :: isPartitionedType <Operator, Types...> :: value;
}
#endif
#endif

