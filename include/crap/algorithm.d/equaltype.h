#ifndef CRAP_ALGORITHM_EQUALTYPE
#define CRAP_ALGORITHM_EQUALTYPE

#include "../utility.d/bisecttype.h"

namespace crap
{
 template <template <class, class> class, class...> struct equalType;

 template <template <class, class> class Operator> struct equalType<Operator>
 {
  template <class ... Types2> struct with;
 };

 template <template <class, class> class Operator, class Type1> struct equalType<Operator, Type1>
 {
  template <class...> struct with;
  template <class Type2> struct with<Type2>;
 };

 template <template <class, class> class Operator, class ... Types1> struct equalType
 { //TODO: Make friends with checking implementation so not to check size with every recursion.
  private:
  template <bool, class...> struct withImplementation;
  template <class ... Types2> struct withImplementation<true, Types2...>;
  public:
  template <class ... Types2>
	  using with = withImplementation<sizeof...(Types1) == sizeof...(Types2),Types2...>;
 };

 template <template <class, class> class Operator> template <class ... Types2>
	 struct equalType <Operator> :: with
 {
  constexpr const static bool value = (sizeof...(Types2) == 0u);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <template <class, class> class Operator, class Type1> template <class...>
	 struct equalType <Operator, Type1> :: with
 {
  constexpr const static bool value = false;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <template <class, class> class Operator, class Type1> template <class Type2>
	 struct equalType <Operator, Type1> :: template with<Type2>
 {
  constexpr const static bool value = Operator <Type1, Type2> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <template <class, class> class Operator, class ... Types1> template <bool, class...>
	 struct equalType <Operator, Types1...> :: withImplementation
 {
  constexpr const static bool value = false;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <template <class, class> class Operator, class ... Types1> template <class ... Types2>
	 struct equalType <Operator, Types1...> :: template withImplementation<true, Types2...>
 { //TODO: Try to use witImplementation directly.
  private:
  using values1 = bisectType<Types1...>;
  using values2 = bisectType<Types2...>;
  template <class ... SubTypes> using This = equalType<Operator, SubTypes...>;
  template <class ... SubTypes>
	  using lower = typename values1 :: template lower <This> :: template with<SubTypes...>;
  constexpr const static bool lowerEqual = values2 :: template lower <lower> :: value;
  template <bool, template <template <class...> class> class, template <template <class...> class> class>
	  struct upperCheck;
  template <template <template <class...> class> class Upper1, template <template <class...> class> class Upper2>
	  struct upperCheck<true, Upper1, Upper2>;
  public:
  constexpr const static bool value =
	  upperCheck <lowerEqual, values1 :: template upper, values2 :: template upper> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <template <class, class> class Operator, class ... Types1> template <class ... Types2>
	 template <bool, template <template <class...> class> class, template <template <class...> class> class>
	 struct equalType <Operator, Types1...> :: template
	 withImplementation <true, Types2...> :: upperCheck
 {
  constexpr const static bool value = false;
 };

 template <template <class, class> class Operator, class ... Types1> template <class ... Types2>
	 template <template <template <class...> class> class Upper1, template <template <class...> class> class Upper2>
	 struct equalType <Operator, Types1...> :: template
	 withImplementation <true, Types2...> :: template upperCheck<true, Upper1, Upper2>
 {
  private:
  template <class ... SubTypes> using This = equalType<Operator, SubTypes...>;
  public:
  constexpr const static bool value = Upper2 <Upper1 <This> :: template with> :: value;
 };
}

template <template <class, class> class Operator> template <class ... Types2>
inline constexpr crap :: equalType <Operator> :: template with <Types2...> :: operator
typename crap :: equalType <Operator> :: template with <Types2...> :: value_type () const noexcept
{
 return crap :: equalType <Operator> :: template with <Types2...> :: value;
}

template <template <class, class> class Operator, class Type1> template <class ... Types2>
inline constexpr crap :: equalType <Operator, Type1> :: template with <Types2...> :: operator
typename crap :: equalType <Operator, Type1> :: template with <Types2...> :: value_type () const noexcept
{
 return crap :: equalType <Operator, Type1> :: template with <Types2...> :: value;
}

template <template <class, class> class Operator, class Type1> template <class Type2>
inline constexpr crap :: equalType <Operator, Type1> :: template with <Type2> :: operator
typename crap :: equalType <Operator, Type1> :: template with <Type2> :: value_type () const noexcept
{
 return crap :: equalType <Operator, Type1> :: template with <Type2> :: value;
}

template <template <class, class> class Operator, class ... Types1> template <bool Equal, class ... Types2>
inline constexpr crap :: equalType <Operator, Types1...> :: template withImplementation <Equal, Types2...> :: operator
typename crap :: equalType <Operator, Types1...> :: template withImplementation <Equal, Types2...> :: value_type ()
	const noexcept
{
 return crap :: equalType <Operator, Types1...> :: template withImplementation <Equal, Types2...> :: value;
}

template <template <class, class> class Operator, class ... Types1> template <class ... Types2>
inline constexpr crap :: equalType <Operator, Types1...> :: template withImplementation <true, Types2...> :: operator
typename crap :: equalType <Operator, Types1...> :: template withImplementation <true, Types2...> :: value_type ()
	const noexcept
{
 return crap :: equalType <Operator, Types1...> :: template withImplementation <true, Types2...> :: value;
}
#endif

