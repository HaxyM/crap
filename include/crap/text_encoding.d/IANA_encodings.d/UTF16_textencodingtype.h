#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_UTF16TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_UTF16TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_UTF16_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: UTF16>;

 template <>
 struct textEncodingType<text_encoding_id_UTF16_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_UTF16_t;
  using name = string<char, 'U', 'T', 'F', '-', '1', '6'>;
  using aliases = typeList<
      string<char, 'U', 'T', 'F', '-', '1', '6'>,
      string<char, 'c', 's', 'U', 'T', 'F', '1', '6'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'U', 'T', 'F', '1', '6'> >
 : textEncodingType<text_encoding_id_UTF16_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'U', 'T', 'F', '-', '1', '6'> >
 : textEncodingType<text_encoding_id_UTF16_t>
 {
 };
}
#endif
