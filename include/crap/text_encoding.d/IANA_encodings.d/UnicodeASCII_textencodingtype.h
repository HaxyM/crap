#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_UNICODEASCIITEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_UNICODEASCIITEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_UnicodeASCII_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: UnicodeASCII>;

 template <>
 struct textEncodingType<text_encoding_id_UnicodeASCII_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_UnicodeASCII_t;
  using name = string<char, 'I', 'S', 'O', '-', '1', '0', '6', '4', '6', '-', 'U', 'C', 'S', '-', 'B', 'a', 's', 'i', 'c'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '-', '1', '0', '6', '4', '6', '-', 'U', 'C', 'S', '-', 'B', 'a', 's', 'i', 'c'>,
      string<char, 'c', 's', 'U', 'n', 'i', 'c', 'o', 'd', 'e', 'A', 'S', 'C', 'I', 'I'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'U', 'n', 'i', 'c', 'o', 'd', 'e', 'A', 'S', 'C', 'I', 'I'> >
 : textEncodingType<text_encoding_id_UnicodeASCII_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '1', '0', '6', '4', '6', '-', 'U', 'C', 'S', '-', 'B', 'a', 's', 'i', 'c'> >
 : textEncodingType<text_encoding_id_UnicodeASCII_t>
 {
 };
}
#endif
