#ifndef CRAP_ALGORITHM_INCLUDESTYPE
#define CRAP_ALGORITHM_INCLUDESTYPE

#include "binarysearchtype.h"
#include "equalrangetype.h"
#include "../utility.d/typelist.h"

#include <cstddef>

namespace crap
{
 template <template <class, class> class, class...> struct includesType;

 template <template <class, class> class Operator> struct includesType<Operator>
 {
  template <class ... Types2> struct with;
 };

 template <template <class, class> class Operator, class Type1>
	 struct includesType<Operator, Type1>
 {
  template <class...> struct with;
  template <class Only> struct with<Only>;
  template <class First, class ... Rest> struct with<First, Rest...>;
 };

 template <template <class, class> class Operator, class ... Types1> struct includesType
 {
  template <class...> struct with;
  template <class Only> struct with<Only>;
  template <class First, class ... Rest> struct with<First, Rest...>;
 };

 template <template <class, class> class Operator> template <class ... Types2>
	 struct includesType <Operator> :: with
 {
  constexpr const static bool value = (sizeof...(Types2) == 0u);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <template <class, class> class Operator, class Type1> template <class...>
	 struct includesType <Operator, Type1> :: with
 {
  constexpr const static bool value = true;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <template <class, class> class Operator, class Type1> template <class Only>
	 struct includesType <Operator, Type1> :: template with<Only>
 {
  constexpr const static bool value = !((Operator <Type1, Only> :: value) || (Operator <Only, Type1> :: value));
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <template <class, class> class Operator, class Type1> template <class First, class ... Rest>
	 struct includesType <Operator, Type1> :: template with<First, Rest...>
 {
  constexpr const static bool value = false;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <template <class, class> class Operator, class ... Types1> template <class...>
	 struct includesType <Operator, Types1...> :: with
 {
  constexpr const static bool value = true;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <template <class, class> class Operator, class ... Types1> template <class Only>
	 struct includesType <Operator, Types1...> :: template with<Only>
 {
  constexpr const static bool value = binarySearchType <Only, Operator, Types1...> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <template <class, class> class Operator, class ... Types1> template <class First, class ... Rest>
	 struct includesType <Operator, Types1...> :: template with<First, Rest...>
 {
  private:
  using mid = typename typeList <Types1...> :: template at<sizeof...(Types1) / 2u>;
  using range1 = equalRangeType<mid, Operator, Types1...>;
  using range2 = equalRangeType<mid, Operator, First, Rest...>;
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

 template <template <class, class> class Operator, class ... Types1>
	 template <class First, class ... Rest> template <bool, std :: size_t, std :: size_t>
	 struct includesType <Operator, Types1...> :: template with <First, Rest...> :: checkLower
 {
  constexpr const static bool value = false;
 };

 template <template <class, class> class Operator, class ... Types1>
	 template <class First, class ... Rest> template <std :: size_t End1, std :: size_t End2>
 struct includesType <Operator, Types1...> :: template with <First, Rest...> :: template
	 checkLower<true, End1, End2>
 {
  private:
  template <class ... SubTypes> using This = includesType<Operator, SubTypes...>;
  using types1 = typeList<Types1...>;
  using types2 = typeList<First, Rest...>;
  public:
  constexpr const static bool value =
	  types2 :: template till <End2, types1 :: template till <End1, This> :: template with> :: value;
 };

 template <template <class, class> class Operator, class ... Types1>
	 template <class First, class ... Rest> template <bool, std :: size_t, std :: size_t>
	 struct includesType <Operator, Types1...> :: template with <First, Rest...> :: checkUpper
 {
  constexpr const static bool value = false;
 };

 template <template <class, class> class Operator, class ... Types1>
	 template <class First, class ... Rest> template <std :: size_t Begin1, std :: size_t Begin2>
 struct includesType <Operator, Types1...> :: template with <First, Rest...> :: template
	 checkUpper<true, Begin1, Begin2>
 {
  private:
  template <class ... SubTypes> using This = includesType<Operator, SubTypes...>;
  using types1 = typeList<Types1...>;
  using types2 = typeList<First, Rest...>;
  public:
  constexpr const static bool value =
	  types2 :: template since <Begin2, types1 :: template since <Begin1, This> :: template with> :: value;
 };
}

template <template <class, class> class Operator> template <class ... Types2>
        inline constexpr
	crap :: includesType <Operator> :: template with <Types2...> :: operator typename
	crap :: includesType <Operator> :: template with <Types2...> :: value_type ()
	const noexcept
{
 return crap :: includesType <Operator> :: template with <Types2...> :: value;
}

template <template <class, class> class Operator, class Type1> template <class ... Empty>
        inline constexpr
	crap :: includesType <Operator, Type1> :: template with <Empty...> :: operator typename
	crap :: includesType <Operator, Type1> :: template with <Empty...> :: value_type ()
	const noexcept
{
 return crap :: includesType <Operator, Type1> :: template with <Empty...> :: value;
}

template <template <class, class> class Operator, class Type1> template <class Only>
        inline constexpr
	crap :: includesType <Operator, Type1> :: template with <Only> :: operator typename
	crap :: includesType <Operator, Type1> :: template with <Only> :: value_type ()
	const noexcept
{
 return crap :: includesType <Operator, Type1> :: template with <Only> :: value;
}

template <template <class, class> class Operator, class Type1> template <class First, class ... Rest>
        inline constexpr
	crap :: includesType <Operator, Type1> :: template with <First, Rest...> :: operator typename
	crap :: includesType <Operator, Type1> :: template with <First, Rest...> :: value_type ()
	const noexcept
{
 return crap :: includesType <Operator, Type1> :: template with <First, Rest...> :: value;
}

template <template <class, class> class Operator, class ... Types1> template <class ... Empty>
        inline constexpr
	crap :: includesType <Operator, Types1...> :: template with <Empty...> :: operator typename
	crap :: includesType <Operator, Types1...> :: template with <Empty...> :: value_type ()
	const noexcept
{
 return crap :: includesType <Operator, Types1...> :: template with <Empty...> :: value;
}

template <template <class, class> class Operator, class ... Types1> template <class Only>
        inline constexpr
	crap :: includesType <Operator, Types1...> :: template with <Only> :: operator typename
	crap :: includesType <Operator, Types1...> :: template with <Only> :: value_type ()
	const noexcept
{
 return crap :: includesType <Operator, Types1...> :: template with <Only> :: value;
}

template <template <class, class> class Operator, class ... Types1> template <class First, class ... Rest>
        inline constexpr
	crap :: includesType <Operator, Types1...> :: template with <First, Rest...> :: operator typename
	crap :: includesType <Operator, Types1...> :: template with <First, Rest...> :: value_type ()
	const noexcept
{
 return crap :: includesType <Operator, Types1...> :: template with <First, Rest...> :: value;
}
#endif

