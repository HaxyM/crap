#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_UNICODEIBM1268TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_UNICODEIBM1268TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_UnicodeIBM1268_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: UnicodeIBM1268>;

 template <>
 struct textEncodingType<text_encoding_id_UnicodeIBM1268_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_UnicodeIBM1268_t;
  using name = string<char, 'I', 'S', 'O', '-', 'U', 'n', 'i', 'c', 'o', 'd', 'e', '-', 'I', 'B', 'M', '-', '1', '2', '6', '8'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '-', 'U', 'n', 'i', 'c', 'o', 'd', 'e', '-', 'I', 'B', 'M', '-', '1', '2', '6', '8'>,
      string<char, 'c', 's', 'U', 'n', 'i', 'c', 'o', 'd', 'e', 'I', 'B', 'M', '1', '2', '6', '8'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'U', 'n', 'i', 'c', 'o', 'd', 'e', 'I', 'B', 'M', '1', '2', '6', '8'> >
 : textEncodingType<text_encoding_id_UnicodeIBM1268_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', 'U', 'n', 'i', 'c', 'o', 'd', 'e', '-', 'I', 'B', 'M', '-', '1', '2', '6', '8'> >
 : textEncodingType<text_encoding_id_UnicodeIBM1268_t>
 {
 };
}
#endif
