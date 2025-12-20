#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_CESU8TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_CESU8TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_CESU8_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: CESU8>;

 template <>
 struct textEncodingType<text_encoding_id_CESU8_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_CESU8_t;
  using name = string<char, 'C', 'E', 'S', 'U', '-', '8'>;
  using aliases = typeList<
      string<char, 'C', 'E', 'S', 'U', '-', '8'>,
      string<char, 'c', 's', 'C', 'E', 'S', 'U', '8'>,
      string<char, 'c', 's', 'C', 'E', 'S', 'U', '-', '8'> >;
 };

 template <>
 struct textEncodingType<string<char, 'C', 'E', 'S', 'U', '-', '8'> >
 : textEncodingType<text_encoding_id_CESU8_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'C', 'E', 'S', 'U', '-', '8'> >
 : textEncodingType<text_encoding_id_CESU8_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'C', 'E', 'S', 'U', '8'> >
 : textEncodingType<text_encoding_id_CESU8_t>
 {
 };
}
#endif
