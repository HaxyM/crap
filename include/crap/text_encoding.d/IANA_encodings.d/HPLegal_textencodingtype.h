#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_HPLEGALTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_HPLEGALTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_HPLegal_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: HPLegal>;

 template <>
 struct textEncodingType<text_encoding_id_HPLegal_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_HPLegal_t;
  using name = string<char, 'H', 'P', '-', 'L', 'e', 'g', 'a', 'l'>;
  using aliases = typeList<
      string<char, 'H', 'P', '-', 'L', 'e', 'g', 'a', 'l'>,
      string<char, 'c', 's', 'H', 'P', 'L', 'e', 'g', 'a', 'l'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'H', 'P', 'L', 'e', 'g', 'a', 'l'> >
 : textEncodingType<text_encoding_id_HPLegal_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'H', 'P', '-', 'L', 'e', 'g', 'a', 'l'> >
 : textEncodingType<text_encoding_id_HPLegal_t>
 {
 };
}
#endif
