#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_UNICODEIBM1265TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_UNICODEIBM1265TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_UnicodeIBM1265_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: UnicodeIBM1265>;

 template <>
 struct textEncodingType<text_encoding_id_UnicodeIBM1265_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_UnicodeIBM1265_t;
  using name = string<char, 'I', 'S', 'O', '-', 'U', 'n', 'i', 'c', 'o', 'd', 'e', '-', 'I', 'B', 'M', '-', '1', '2', '6', '5'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '-', 'U', 'n', 'i', 'c', 'o', 'd', 'e', '-', 'I', 'B', 'M', '-', '1', '2', '6', '5'>,
      string<char, 'c', 's', 'U', 'n', 'i', 'c', 'o', 'd', 'e', 'I', 'B', 'M', '1', '2', '6', '5'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'U', 'n', 'i', 'c', 'o', 'd', 'e', 'I', 'B', 'M', '1', '2', '6', '5'> >
 : textEncodingType<text_encoding_id_UnicodeIBM1265_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', 'U', 'n', 'i', 'c', 'o', 'd', 'e', '-', 'I', 'B', 'M', '-', '1', '2', '6', '5'> >
 : textEncodingType<text_encoding_id_UnicodeIBM1265_t>
 {
 };
}
#endif
