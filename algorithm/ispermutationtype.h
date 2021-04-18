#ifndef CRAP_ALGORITHM_ISPERMUTATIONTYPE
#define CRAP_ALGORITHM_ISPERMUTATIONTYPE

#include "allofvalue.h"
#include "counttype.h"
#include "findtype.h"
#include "mismatchtype.h"
#include "../numeric/iotavalue.h"
#include "../utility/emptytype.h"
#include "../utility/typelist.h"

#include <cstddef>

namespace crap
{
 template <template <class, class> class, class...> struct isPermutationType;

 template <template <class, class> class Operator> struct isPermutationType<Operator>
 {
  template <class ... Types2> using with = emptyType<Types2...>;
 };

 template <template <class, class> class Operator, class Type1>
	 struct isPermutationType<Operator, Type1>
 {
  template <class...> struct with;
  template <class Type2> struct with<Type2>;
 };

 template <template <class, class> class Operator, class ... Types1> struct isPermutationType
 {
  private:
  template <bool, class...> struct withImplementation;
  template <class ... Types2> struct withImplementation<true, Types2...>;
  public:
  template <class ... Types2> using with = withImplementation<sizeof...(Types1) == sizeof...(Types2), Types2...>;
 };

 template <template <class, class> class Operator, class Type1> template <class...>
	 struct isPermutationType <Operator, Type1> :: with
 {
  constexpr const static bool value = false;
 };

 template <template <class, class> class Operator, class Type1> template <class Type2>
	 struct isPermutationType <Operator, Type1> :: template with<Type2>
 {
  constexpr const static bool value = (Operator <Type1, Type2> :: value);
 };

 template <template <class, class> class Operator, class ... Types1> template <bool, class...>
	 struct isPermutationType <Operator, Types1...> :: withImplementation
 {
  constexpr const static bool value = false;
 };

 template <template <class, class> class Operator, class ... Types1> template <class ... Types2>
	 struct isPermutationType <Operator, Types1...> :: template withImplementation<true, Types2...>
 {
  private:
  template <std :: size_t MismatchValue, std :: size_t MismatchNpos> struct checkUnequal;
  template <std :: size_t MismatchNpos> struct checkUnequal<MismatchNpos, MismatchNpos>;
  using check = typename mismatchType <Operator, Types1...> :: template with<Types2...>;
  public:
  constexpr const static bool value = checkUnequal <check :: value, check :: npos> :: value;
 };

 template <template <class, class> class Operator, class ... Types1> template <class ... Types2>
	 template <std :: size_t MismatchValue, std :: size_t MismatchNpos>
 struct isPermutationType <Operator, Types1...> :: template
	withImplementation <true, Types2...> :: checkUnequal
 {
  private:
  template <std :: size_t Index> struct checkIndex;
  template <std :: size_t ... Indices> using check = allOfValue<std :: size_t, checkIndex, Indices...>;
  public:
  constexpr const static bool value =
	  iotaValue <MismatchNpos - MismatchValue, std :: size_t, MismatchValue> :: template type <check> :: value;
 };

 template <template <class, class> class Operator, class ... Types1> template <class ... Types2>
	 template <std :: size_t MismatchNpos>
 struct isPermutationType <Operator, Types1...> :: template
	withImplementation <true, Types2...> :: template
	checkUnequal<MismatchNpos, MismatchNpos>
 {
  constexpr const static bool value = true;
 };

 template <template <class, class> class Operator, class ... Types1>
	 template <class ... Types2>
	 template <std :: size_t MismatchValue, std :: size_t MismatchNpos>
	 template <std :: size_t Index>
 struct isPermutationType <Operator, Types1...> :: template
	withImplementation <true, Types2...> :: template
	checkUnequal <MismatchValue, MismatchNpos> :: checkIndex
 {
  private:
  using types1 = typeList<Types1...>;
  template <std :: size_t FindValue, std :: size_t FindNpos> struct checkCount;
  template <std :: size_t FindNpos> struct checkCount<FindNpos, FindNpos>;
  template <class ... SubTypes>
	  using find = findType<typename types1 :: template at<Index>, Operator, SubTypes...>;
  using findRes = typename types1 :: template subRange<MismatchValue, Index, find>;
  public:
  constexpr const static bool value = checkCount <findRes :: value, findRes :: npos> :: value;
 };

 template <template <class, class> class Operator, class ... Types1>
	 template <class ... Types2>
	 template <std :: size_t MismatchValue, std :: size_t MismatchNpos>
	 template <std :: size_t Index>
	 template <std :: size_t FindValue, std :: size_t FindNpos>
 struct isPermutationType <Operator, Types1...> :: template
	withImplementation <true, Types2...> :: template
	checkUnequal <MismatchValue, MismatchNpos> :: template
	checkIndex <Index> :: checkCount
 {
  constexpr const static bool value = true;
 };

 template <template <class, class> class Operator, class ... Types1>
	 template <class ... Types2>
	 template <std :: size_t MismatchValue, std :: size_t MismatchNpos>
	 template <std :: size_t Index>
	 template <std :: size_t FoundNpos>
 struct isPermutationType <Operator, Types1...> :: template
	withImplementation <true, Types2...> :: template
	checkUnequal <MismatchValue, MismatchNpos> :: template
	checkIndex <Index> :: template
	checkCount<FoundNpos, FoundNpos>
 {
  private:
  using types1 = typeList<Types1...>;
  using types2 = typeList<Types2...>;
  template <class ... SubTypes>
	  using count = countType<typename types1 :: template at<Index>, Operator, SubTypes...>;
  using count1 = typename types1 :: template since<MismatchValue, count>;
  using count2 = typename types2 :: template since<MismatchValue, count>;
  public:
  constexpr const static bool value = ((count1 :: value) == (count2 :: value));
 };
}
#endif

