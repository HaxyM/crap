#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_UTF32TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_UTF32TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_UTF32_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: UTF32>;

 template <>
 struct textEncodingType<text_encoding_id_UTF32_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_UTF32_t;
  using name = string<char, 'U', 'T', 'F', '-', '3', '2'>;
  using aliases = typeList<
      string<char, 'U', 'T', 'F', '-', '3', '2'>,
      string<char, 'c', 's', 'U', 'T', 'F', '3', '2'> >;
 };

 template <>
 struct textEncodingType<string<char, 'U', 'T', 'F', '-', '3', '2'> >
 : textEncodingType<text_encoding_id_UTF32_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'U', 'T', 'F', '3', '2'> >
 : textEncodingType<text_encoding_id_UTF32_t>
 {
 };
}
#endif
