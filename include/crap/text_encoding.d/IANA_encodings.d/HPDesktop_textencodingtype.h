#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_HPDESKTOPTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_HPDESKTOPTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_HPDesktop_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: HPDesktop>;

 template <>
 struct textEncodingType<text_encoding_id_HPDesktop_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_HPDesktop_t;
  using name = string<char, 'H', 'P', '-', 'D', 'e', 's', 'k', 'T', 'o', 'p'>;
  using aliases = typeList<
      string<char, 'H', 'P', '-', 'D', 'e', 's', 'k', 'T', 'o', 'p'>,
      string<char, 'c', 's', 'H', 'P', 'D', 'e', 's', 'k', 't', 'o', 'p'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'H', 'P', 'D', 'e', 's', 'k', 't', 'o', 'p'> >
 : textEncodingType<text_encoding_id_HPDesktop_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'H', 'P', '-', 'D', 'e', 's', 'k', 'T', 'o', 'p'> >
 : textEncodingType<text_encoding_id_HPDesktop_t>
 {
 };
}
#endif
