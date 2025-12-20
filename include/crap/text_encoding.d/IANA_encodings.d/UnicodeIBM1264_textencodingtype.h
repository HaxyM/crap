#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_UNICODEIBM1264TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_UNICODEIBM1264TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_UnicodeIBM1264_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: UnicodeIBM1264>;

 template <>
 struct textEncodingType<text_encoding_id_UnicodeIBM1264_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_UnicodeIBM1264_t;
  using name = string<char, 'I', 'S', 'O', '-', 'U', 'n', 'i', 'c', 'o', 'd', 'e', '-', 'I', 'B', 'M', '-', '1', '2', '6', '4'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '-', 'U', 'n', 'i', 'c', 'o', 'd', 'e', '-', 'I', 'B', 'M', '-', '1', '2', '6', '4'>,
      string<char, 'c', 's', 'U', 'n', 'i', 'c', 'o', 'd', 'e', 'I', 'B', 'M', '1', '2', '6', '4'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'U', 'n', 'i', 'c', 'o', 'd', 'e', 'I', 'B', 'M', '1', '2', '6', '4'> >
 : textEncodingType<text_encoding_id_UnicodeIBM1264_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', 'U', 'n', 'i', 'c', 'o', 'd', 'e', '-', 'I', 'B', 'M', '-', '1', '2', '6', '4'> >
 : textEncodingType<text_encoding_id_UnicodeIBM1264_t>
 {
 };
}
#endif
