#ifndef CRAP_ALGORITHM_ISPERMUTATIONVALUE
#define CRAP_ALGORITHM_ISPERMUTATIONVALUE

#include "allofvalue.h"
#include "countvalue.h"
#include "findvalue.h"
#include "mismatchvalue.h"
#include "../iterator.d/emptyvalue.h"
#include "../numeric.d/iotavalue.h"
#include "../utility.d/valuelist.h"
#include "../version.d/libintegralconstantcallable.h"

#include <cstddef>

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct isPermutationValue;

 template <class Type, template <Type, Type> class Operator> struct isPermutationValue<Type, Operator>
 {
  template <Type ... Values2> using with = emptyValue<Type, Values2...>;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1>
	 struct isPermutationValue<Type, Operator, Value1>
 {
  template <Type...> struct with;
  template <Type Value2> struct with<Value2>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1> struct isPermutationValue
 {
  private:
  template <bool, Type...> struct withImplementation;
  template <Type ... Values2> struct withImplementation<true, Values2...>;
  public:
  template <Type ... Values2> using with = withImplementation<sizeof...(Values1) == sizeof...(Values2), Values2...>;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1> template <Type...>
	 struct isPermutationValue <Type, Operator, Value1> :: with
 {
  constexpr const static bool value = false;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type Value1> template <Type Value2>
	 struct isPermutationValue <Type, Operator, Value1> :: with<Value2>
 {
  constexpr const static bool value = (Operator <Value1, Value2> :: value);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1> template <bool, Type...>
	 struct isPermutationValue <Type, Operator, Values1...> :: withImplementation
 {
  constexpr const static bool value = false;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1> template <Type ... Values2>
	 struct isPermutationValue <Type, Operator, Values1...> :: withImplementation<true, Values2...>
 {
  private:
  template <std :: size_t MismatchValue, std :: size_t MismatchNpos> struct checkUnequal;
  template <std :: size_t MismatchNpos> struct checkUnequal<MismatchNpos, MismatchNpos>;
  using check = typename mismatchValue <Type, Operator, Values1...> :: template with<Values2...>;
  public:
  constexpr const static bool value = checkUnequal <check :: value, check :: npos> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1> template <Type ... Values2>
	 template <std :: size_t MismatchValue, std :: size_t MismatchNpos>
 struct isPermutationValue <Type, Operator, Values1...> ::
	withImplementation <true, Values2...> :: checkUnequal
 {
  private:
  template <std :: size_t Index> struct checkIndex;
  template <std :: size_t ... Indices> using check = allOfValue<std :: size_t, checkIndex, Indices...>;
  public:
  constexpr const static bool value =
	  iotaValue <MismatchNpos - MismatchValue, std :: size_t, MismatchValue> :: template type <check> :: value;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1> template <Type ... Values2>
	 template <std :: size_t MismatchNpos>
 struct isPermutationValue <Type, Operator, Values1...> ::
	withImplementation <true, Values2...> ::
	checkUnequal<MismatchNpos, MismatchNpos>
 {
  constexpr const static bool value = true;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1>
	 template <Type ... Values2>
	 template <std :: size_t MismatchValue, std :: size_t MismatchNpos>
	 template <std :: size_t Index>
 struct isPermutationValue <Type, Operator, Values1...> ::
	withImplementation <true, Values2...> ::
	checkUnequal <MismatchValue, MismatchNpos> :: checkIndex
 {
  private:
  using values1 = valueList<Type, Values1...>;
  template <std :: size_t FindValue, std :: size_t FindNpos> struct checkCount;
  template <std :: size_t FindNpos> struct checkCount<FindNpos, FindNpos>;
  template <Type ... SubValues>
	  using find = findValue<Type, values1 :: template At <Index> :: value, Operator, SubValues...>;
  using findRes = typename values1 :: template subRange<MismatchValue, Index, find>;
  public:
  constexpr const static bool value = checkCount <findRes :: value, findRes :: npos> :: value;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1>
	 template <Type ... Values2>
	 template <std :: size_t MismatchValue, std :: size_t MismatchNpos>
	 template <std :: size_t Index>
	 template <std :: size_t FindValue, std :: size_t FindNpos>
 struct isPermutationValue <Type, Operator, Values1...> ::
	withImplementation <true, Values2...> ::
	checkUnequal <MismatchValue, MismatchNpos> ::
	checkIndex <Index> :: checkCount
 {
  constexpr const static bool value = true;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1>
	 template <Type ... Values2>
	 template <std :: size_t MismatchValue, std :: size_t MismatchNpos>
	 template <std :: size_t Index>
	 template <std :: size_t FoundNpos>
 struct isPermutationValue <Type, Operator, Values1...> ::
	withImplementation <true, Values2...> ::
	checkUnequal <MismatchValue, MismatchNpos> ::
	checkIndex <Index> ::
	checkCount<FoundNpos, FoundNpos>
 {
  private:
  using values1 = valueList<Type, Values1...>;
  using values2 = valueList<Type, Values2...>;
  template <Type ... SubValues>
	  using count = countValue <Type, values1 :: template At <Index> :: value, Operator, SubValues...>;
  using count1 = typename values1 :: template since<MismatchValue, count>;
  using count2 = typename values2 :: template since<MismatchValue, count>;
  public:
  constexpr const static bool value = ((count1 :: value) == (count2 :: value));
 };
}

template <class Type, template <Type, Type> class Operator, Type Value1> template <Type ... Values2>
inline constexpr crap :: isPermutationValue <Type, Operator, Value1> :: with <Values2...> :: operator
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
typename crap :: isPermutationValue <Type, Operator, Value1> :: template with <Values2...> :: value_type ()
#else
typename crap :: isPermutationValue <Type, Operator, Value1> :: with <Values2...> :: value_type ()
#endif
	const noexcept
{
 return crap :: isPermutationValue <Type, Operator, Value1> :: with <Values2...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type Value1> template <Type ... Values2>
inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
crap :: isPermutationValue <Type, Operator, Value1> :: template with <Values2...> :: value_type
#else
crap :: isPermutationValue <Type, Operator, Value1> :: with <Values2...> :: value_type
#endif
crap :: isPermutationValue <Type, Operator, Value1> :: with <Values2...> :: operator () () const noexcept
{
 return crap :: isPermutationValue <Type, Operator, Value1> :: with <Values2...> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type Value1> template <Type Value2>
inline constexpr crap :: isPermutationValue <Type, Operator, Value1> :: with <Value2> :: operator
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
typename crap :: isPermutationValue <Type, Operator, Value1> :: template with <Value2> :: value_type ()
#else
typename crap :: isPermutationValue <Type, Operator, Value1> :: with <Value2> :: value_type ()
#endif
	const noexcept
{
 return crap :: isPermutationValue <Type, Operator, Value1> :: with <Value2> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type Value1> template <Type Value2>
inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
crap :: isPermutationValue <Type, Operator, Value1> :: template with <Value2> :: value_type
#else
crap :: isPermutationValue <Type, Operator, Value1> :: with <Value2> :: value_type
#endif
crap :: isPermutationValue <Type, Operator, Value1> :: with <Value2> :: operator () () const noexcept
{
 return crap :: isPermutationValue <Type, Operator, Value1> :: with <Value2> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type ... Values1>
template <bool EqualSize, Type ... Values2>
inline constexpr crap :: isPermutationValue <Type, Operator, Values1...> ::
	withImplementation <EqualSize, Values2...> :: operator
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
typename crap :: isPermutationValue <Type, Operator, Values1...> :: template
#else
typename crap :: isPermutationValue <Type, Operator, Values1...> ::
#endif
	withImplementation <EqualSize, Values2...> :: value_type () const noexcept
{
 return crap :: isPermutationValue <Type, Operator, Values1...> ::
	 withImplementation <EqualSize, Values2...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type ... Values1>
template <bool EqualSize, Type ... Values2>
inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
crap :: isPermutationValue <Type, Operator, Values1...> :: template
#else
crap :: isPermutationValue <Type, Operator, Values1...> ::
#endif
	withImplementation <EqualSize, Values2...> :: value_type
crap :: isPermutationValue <Type, Operator, Values1...> ::
	withImplementation <EqualSize, Values2...> :: operator () () const noexcept
{
 return crap :: isPermutationValue <Type, Operator, Values1...> ::
	 withImplementation <EqualSize, Values2...> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type ... Values1>
template <Type ... Values2>
inline constexpr crap :: isPermutationValue <Type, Operator, Values1...> ::
	withImplementation <true, Values2...> :: operator
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
typename crap :: isPermutationValue <Type, Operator, Values1...> :: template
#else
typename crap :: isPermutationValue <Type, Operator, Values1...> ::
#endif
	withImplementation <true, Values2...> :: value_type () const noexcept
{
 return crap :: isPermutationValue <Type, Operator, Values1...> ::
	 withImplementation <true, Values2...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type ... Values1>
template <Type ... Values2>
inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
crap :: isPermutationValue <Type, Operator, Values1...> :: template
#else
crap :: isPermutationValue <Type, Operator, Values1...> ::
#endif
	withImplementation <true, Values2...> :: value_type
crap :: isPermutationValue <Type, Operator, Values1...> ::
	withImplementation <true, Values2...> :: operator () () const noexcept
{
 return crap :: isPermutationValue <Type, Operator, Values1...> ::
	 withImplementation <true, Values2...> :: value;
}
#endif
#endif

