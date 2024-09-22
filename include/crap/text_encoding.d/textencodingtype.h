#ifndef CRAP_TEXTENCODING_TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_TEXTENCODINGTYPE

#include "../string.d/string.h"

namespace crap
{
 template <class = void> struct textEncodingType;

 template <> struct textEncodingType<void>
 {
  template <class, class...> struct literal;
  template <class ... Ignored> struct literal<char, Ignored...>;
  template <class ... Ignored> struct literal<wchar_t, Ignored...>;
 };

 template <class ... Ignored>
 struct textEncodingType <void> :: literal<char, Ignored...>
 {
#if !defined(__clang__) && defined(__GNUC__)
  constexpr const static char name[] = __GNUC_EXECUTION_CHARSET_NAME;
#elif defined(__clang__)
  constexpr const static char name[] = __clang_literal_encoding__;
#else
#warning "No known way to get execution encoding. Assuming Unknown."
#endif
 };

 template <class ... Ignored>
 struct textEncodingType <void> :: literal<wchar_t, Ignored...>
 {
#if !defined(__clang__) && defined(__GNUC__)
  constexpr const static char name[] = __GNUC_WIDE_EXECUTION_CHARSET_NAME;
#elif defined(__clang__)
  constexpr const static char name[] = __clang_wide_literal_encoding__;
#else
#warning "No known way to get execution encoding. Assuming Unknown."
#endif
 };
}
#endif

