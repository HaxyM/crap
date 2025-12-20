#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_UNICODE11TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_UNICODE11TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_Unicode11_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: Unicode11>;

 template <>
 struct textEncodingType<text_encoding_id_Unicode11_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_Unicode11_t;
  using name = string<char, 'I', 'S', 'O', '-', 'U', 'n', 'i', 'c', 'o', 'd', 'e', '-', 'I', 'B', 'M', '-', '1', '2', '6', '5'>;
  using aliases = typeList<
      string<char, 'U', 'N', 'I', 'C', 'O', 'D', 'E', '-', '1', '-', '1'>,
      string<char, 'c', 's', 'U', 'n', 'i', 'c', 'o', 'd', 'e', '1', '1'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'U', 'n', 'i', 'c', 'o', 'd', 'e', '1', '1'> >
 : textEncodingType<text_encoding_id_Unicode11_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'U', 'N', 'I', 'C', 'O', 'D', 'E', '-', '1', '-', '1'> >
 : textEncodingType<text_encoding_id_Unicode11_t>
 {
 };
}
#endif
