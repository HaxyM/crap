#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_UNICODEJAPANESETEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_UNICODEJAPANESETEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_UnicodeJapanese_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: UnicodeJapanese>;

 template <>
 struct textEncodingType<text_encoding_id_UnicodeJapanese_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_UnicodeJapanese_t;
  using name = string<char, 'I', 'S', 'O', '-', '1', '0', '6', '4', '6', '-', 'J', '-', '1'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '-', '1', '0', '6', '4', '6', '-', 'J', '-', '1'>,
      string<char, 'c', 's', 'U', 'n', 'i', 'c', 'o', 'd', 'e', 'J', 'a', 'p', 'a', 'n', 'e', 's', 'e'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'U', 'n', 'i', 'c', 'o', 'd', 'e', 'J', 'a', 'p', 'a', 'n', 'e', 's', 'e'> >
 : textEncodingType<text_encoding_id_UnicodeJapanese_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '1', '0', '6', '4', '6', '-', 'J', '-', '1'> >
 : textEncodingType<text_encoding_id_UnicodeJapanese_t>
 {
 };
}
#endif
