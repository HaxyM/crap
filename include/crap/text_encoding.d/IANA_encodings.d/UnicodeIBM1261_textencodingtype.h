#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_UNICODEIBM1261TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_UNICODEIBM1261TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_UnicodeIBM1261_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: UnicodeIBM1261>;

 template <>
 struct textEncodingType<text_encoding_id_UnicodeIBM1261_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_UnicodeIBM1261_t;
  using name = string<char, 'I', 'S', 'O', '-', 'U', 'n', 'i', 'c', 'o', 'd', 'e', '-', 'I', 'B', 'M', '-', '1', '2', '6', '1'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '-', 'U', 'n', 'i', 'c', 'o', 'd', 'e', '-', 'I', 'B', 'M', '-', '1', '2', '6', '1'>,
      string<char, 'c', 's', 'U', 'n', 'i', 'c', 'o', 'd', 'e', 'I', 'B', 'M', '1', '2', '6', '1'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'U', 'n', 'i', 'c', 'o', 'd', 'e', 'I', 'B', 'M', '1', '2', '6', '1'> >
 : textEncodingType<text_encoding_id_UnicodeIBM1261_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', 'U', 'n', 'i', 'c', 'o', 'd', 'e', '-', 'I', 'B', 'M', '-', '1', '2', '6', '1'> >
 : textEncodingType<text_encoding_id_UnicodeIBM1261_t>
 {
 };
}
#endif
