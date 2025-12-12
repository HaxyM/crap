#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_UTF8TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_UTF8TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_UTF8_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: UTF8>;

 template <>
 struct textEncodingType<text_encoding_id_UTF8_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_UTF8_t;
  using name = string<char, 'U', 'T', 'F', '-', '8'>;
  using aliases = typeList<
      string<char, 'U', 'T', 'F', '-', '8'>,
      string<char, 'c', 's', 'U', 'T', 'F', '8'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'U', 'T', 'F', '8'> >
 : textEncodingType<text_encoding_id_UTF8_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'U', 'T', 'F', '-', '8'> >
 : textEncodingType<text_encoding_id_UTF8_t>
 {
 };
}
#endif
