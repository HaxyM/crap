#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_EUCFIXWIDJAPANESETEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_EUCFIXWIDJAPANESETEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_EUCFixWidJapanese_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: EUCFixWidJapanese>;

 template <>
 struct textEncodingType<text_encoding_id_EUCFixWidJapanese_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_EUCFixWidJapaneses_t;
  using name = string<char, 'E', 'x', 't', 'e', 'n', 'd', 'e', 'd', '_', 'U', 'N', 'I', 'X', '_', 'C', 'o', 'd', 'e', '_', 'F', 'i', 'x', 'e', 'd', '_', 'W', 'i', 'd', 't', 'h', '_', 'f', 'o', 'r', '_', 'J', 'a', 'p', 'a', 'n', 'e', 's', 'e'>;
  using aliases = typeList<
	  string<char, 'E', 'x', 't', 'e', 'n', 'd', 'e', 'd', '_', 'U', 'N', 'I', 'X', '_', 'C', 'o', 'd', 'e', '_', 'F', 'i', 'x', 'e', 'd', '_', 'W', 'i', 'd', 't', 'h', '_', 'f', 'o', 'r', '_', 'J', 'a', 'p', 'a', 'n', 'e', 's', 'e'>,
	  string<char, 'c', 's', 'E', 'U', 'C', 'F', 'i', 'x', 'W', 'i', 'd', 'J', 'a', 'p', 'a', 'n', 'e', 's', 'e'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'E', 'U', 'C', 'F', 'i', 'x', 'W', 'i', 'd', 'J', 'a', 'p', 'a', 'n', 'e', 's', 'e'> >
 : textEncodingType<text_encoding_id_EUCFixWidJapanese_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'x', 't', 'e', 'n', 'd', 'e', 'd', '_', 'U', 'N', 'I', 'X', '_', 'C', 'o', 'd', 'e', '_', 'F', 'i', 'x', 'e', 'd', '_', 'W', 'i', 'd', 't', 'h', '_', 'f', 'o', 'r', '_', 'J', 'a', 'p', 'a', 'n', 'e', 's', 'e'> >
 : textEncodingType<text_encoding_id_EUCFixWidJapanese_t>
 {
 };
}
#endif
