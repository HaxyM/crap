#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_EUCPKDFMTJAPANESETEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_EUCPKDFMTJAPANESETEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_EUCPkdFmtJapanese_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: EUCPkdFmtJapanese>;

 template <>
 struct textEncodingType<text_encoding_id_EUCPkdFmtJapanese_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_EUCPkdFmtJapaneses_t;
  using name = string<char, 'E', 'x', 't', 'e', 'n', 'd', 'e', 'd', '_', 'U', 'N', 'I', 'X', '_', 'C', 'o', 'd', 'e', '_', 'P', 'a', 'c', 'k', 'e', 'd', '_', 'F', 'o', 'r', 'm', 'a', 't', '_', 'f', 'o', 'r', '_', 'J', 'a', 'p', 'a', 'n', 'e', 's', 'e'>;
  using aliases = typeList<
	  string<char, 'E', 'x', 't', 'e', 'n', 'd', 'e', 'd', '_', 'U', 'N', 'I', 'X', '_', 'C', 'o', 'd', 'e', '_', 'P', 'a', 'c', 'k', 'e', 'd', '_', 'F', 'o', 'r', 'm', 'a', 't', '_', 'f', 'o', 'r', '_', 'J', 'a', 'p', 'a', 'n', 'e', 's', 'e'>,
	  string<char, 'c', 's', 'E', 'U', 'C', 'P', 'k', 'd', 'F', 'm', 't', 'J', 'a', 'p', 'a', 'n', 'e', 's', 'e'>,
      string<char, 'E', 'U', 'C', '-', 'J', 'P'> >;
	  
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'E', 'U', 'C', 'P', 'k', 'd', 'F', 'm', 't', 'J', 'a', 'p', 'a', 'n', 'e', 's', 'e'> >
 : textEncodingType<text_encoding_id_EUCPkdFmtJapanese_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'U', 'C', '-', 'J', 'P'> >
 : textEncodingType<text_encoding_id_EUCPkdFmtJapanese_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'x', 't', 'e', 'n', 'd', 'e', 'd', '_', 'U', 'N', 'I', 'X', '_', 'C', 'o', 'd', 'e', '_', 'P', 'a', 'c', 'k', 'e', 'd', '_', 'F', 'o', 'r', 'm', 'a', 't', '_', 'f', 'o', 'r', '_', 'J', 'a', 'p', 'a', 'n', 'e', 's', 'e'> >
 : textEncodingType<text_encoding_id_EUCPkdFmtJapanese_t>
 {
 };
}
#endif
