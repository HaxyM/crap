#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_UNICODEIBM1276TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_UNICODEIBM1276TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_UnicodeIBM1276_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: UnicodeIBM1276>;

 template <>
 struct textEncodingType<text_encoding_id_UnicodeIBM1276_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_UnicodeIBM1276_t;
  using name = string<char, 'I', 'S', 'O', '-', 'U', 'n', 'i', 'c', 'o', 'd', 'e', '-', 'I', 'B', 'M', '-', '1', '2', '7', '6'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '-', 'U', 'n', 'i', 'c', 'o', 'd', 'e', '-', 'I', 'B', 'M', '-', '1', '2', '7', '6'>,
      string<char, 'c', 's', 'U', 'n', 'i', 'c', 'o', 'd', 'e', 'I', 'B', 'M', '1', '2', '7', '6'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'U', 'n', 'i', 'c', 'o', 'd', 'e', 'I', 'B', 'M', '1', '2', '7', '6'> >
 : textEncodingType<text_encoding_id_UnicodeIBM1276_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', 'U', 'n', 'i', 'c', 'o', 'd', 'e', '-', 'I', 'B', 'M', '-', '1', '2', '7', '6'> >
 : textEncodingType<text_encoding_id_UnicodeIBM1276_t>
 {
 };
}
#endif
