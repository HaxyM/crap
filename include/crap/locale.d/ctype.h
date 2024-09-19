#ifndef CRAP_LOCALE_CTYPE
#define CRAP_LOCALE_CTYPE

#include <locale>
#include <type_traits>

#include "ctypebase.h"
#include "../algorithm.d/findvalue.h"
#include "../functional.d/comparatorsfortype.h"
#include "../string.d/string.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <class> struct ctype;

 template <> struct ctype <char>
 { //Defaults for C standard.
  using char_type = char;
  template <char_type ... Chars> using string_type =  string<char_type, Chars...>;
  template <class> struct is;
  template <char Char>
	  struct is<std :: pair<std :: integral_constant<char, Char>, ctypeBase :: blank> >;
  template <char Char>
	  struct is<std :: pair<ctypeBase :: blank>, std :: integral_constant<char, Char> >;
  template <char Char>
	  struct is<std :: pair<std :: integral_constant<char, Char>, ctypeBase :: digit> >;
  template <char Char>
	  struct is<std :: pair<ctypeBase :: digit>, std :: integral_constant<char, Char> >;
  template <char Char>
	  struct is<std :: pair<std :: integral_constant<char, Char>, ctypeBase :: xdigit> >;
  template <char Char>
	  struct is<std :: pair<ctypeBase :: xdigit>, std :: integral_constant<char, Char> >;
 };

 template <> struct ctype <wchar_t>
 { //Requires execution encoding.
 };

 template <char Char>
 struct ctype <char> ::
	is<std :: pair<std :: integral_constant<char, Char>, ctypeBase :: blank> >
 { //Assume ASCII, UTF-8 single octet or pure basic character set.
  private:
  //If certain of ASCII, ASCII superset or any encoding where digits are ordered, use binary search.
  using result = findValue<char, Char, comparatorsForType <char> :: template
	 EqualTo, '\t', ' '>;
  public:
  constexpr const static bool value = (result :: value != result :: npos);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <char Char>
 struct ctype <char> ::
	is<std :: pair<ctypeBase :: blank, std :: integral_constant<char, Char> > >
 : ctype <char> ::
	is<std :: pair<std :: integral_constant<char, Char>, ctypeBase :: blank> >
 {
 };

 template <char Char>
 struct ctype <char> ::
	is<std :: pair<std :: integral_constant<char, Char>, ctypeBase :: digit> >
 { //Assume ASCII, UTF-8 single octet or pure basic character set.
  private:
  //If certain of ASCII, ASCII superset or any encoding where digits are ordered, use binary search.
  using result = findValue<char, Char, comparatorsForType <char> :: template
	 EqualTo, '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'>;
  public:
  constexpr const static bool value = (result :: value != result :: npos);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <char Char>
 struct ctype <char> ::
	is<std :: pair<ctypeBase :: digit, std :: integral_constant<char, Char> > >
 : ctype <char> ::
	is<std :: pair<std :: integral_constant<char, Char>, ctypeBase :: digit> >
 {
 };

 template <char Char>
 struct ctype <char> ::
	is<std :: pair<std :: integral_constant<char, Char>, ctypeBase :: xdigit> >
 { //Assume ASCII, UTF-8 single octet or pure basic character set.
  private:
  //If certain of ASCII, ASCII superset or any encoding where digits are ordered, use binary search.
  using result = findValue<char, Char, comparatorsForType <char> :: template
	 EqualTo, '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	 'A', 'B', 'C', 'D', 'E', 'F', 'a', 'b', 'c', 'd', 'e', 'f'>;
  public:
  constexpr const static bool value = (result :: value != result :: npos);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <char Char>
 struct ctype <char> ::
	is<std :: pair<ctypeBase :: xdigit, std :: integral_constant<char, Char> > >
 : ctype <char> ::
	is<std :: pair<std :: integral_constant<char, Char>, ctypeBase :: xdigit> >
 {
 };
}

template <char Char>
inline constexpr crap :: ctype <char> ::
        is <std :: pair<std :: integral_constant<char, Char>, ctypeBase :: blank> > ::
operator typename crap :: ctype <char> ::
        is <std :: pair<std :: integral_constant<char, Char>, ctypeBase :: blank> > ::
value_type () const noexcept
{
 return crap :: ctype <char> ::
	 is <std :: pair<std :: integral_constant<char, Char>, ctypeBase :: blank> > ::
	 value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <char Char>
inline constexpr crap :: ctype <char> ::
        is <std :: pair<std :: integral_constant<char, Char>, ctypeBase :: blank> > ::
value_type crap :: ctype <char> ::
        is <std :: pair<std :: integral_constant<char, Char>, ctypeBase :: blank> > ::
operator () () const noexcept
{
 return crap :: ctype <char> ::
	 is <std :: pair<std :: integral_constant<char, Char>, ctypeBase :: blank> > ::
	 value;
}
#endif

template <char Char>
inline constexpr crap :: ctype <char> ::
        is <std :: pair<std :: integral_constant<char, Char>, ctypeBase :: digit> > ::
operator typename crap :: ctype <char> ::
        is <std :: pair<std :: integral_constant<char, Char>, ctypeBase :: digit> > ::
value_type () const noexcept
{
 return crap :: ctype <char> ::
	 is <std :: pair<std :: integral_constant<char, Char>, ctypeBase :: digit> > ::
	 value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <char Char>
inline constexpr crap :: ctype <char> ::
        is <std :: pair<std :: integral_constant<char, Char>, ctypeBase :: digit> > ::
value_type crap :: ctype <char> ::
        is <std :: pair<std :: integral_constant<char, Char>, ctypeBase :: digit> > ::
operator () () const noexcept
{
 return crap :: ctype <char> ::
	 is <std :: pair<std :: integral_constant<char, Char>, ctypeBase :: digit> > ::
	 value;
}
#endif

template <char Char>
inline constexpr crap :: ctype <char> ::
        is <std :: pair<std :: integral_constant<char, Char>, ctypeBase :: xdigit> > ::
operator typename crap :: ctype <char> ::
        is <std :: pair<std :: integral_constant<char, Char>, ctypeBase :: xdigit> > ::
value_type () const noexcept
{
 return crap :: ctype <char> ::
	 is <std :: pair<std :: integral_constant<char, Char>, ctypeBase :: xdigit> > ::
	 value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <char Char>
inline constexpr crap :: ctype <char> ::
        is <std :: pair<std :: integral_constant<char, Char>, ctypeBase :: xdigit> > ::
value_type crap :: ctype <char> ::
        is <std :: pair<std :: integral_constant<char, Char>, ctypeBase :: xdigit> > ::
operator () () const noexcept
{
 return crap :: ctype <char> ::
	 is <std :: pair<std :: integral_constant<char, Char>, ctypeBase :: xdigit> > ::
	 value;
}
#endif
#endif

