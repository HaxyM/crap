#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO18GREEK7OLDTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO18GREEK7OLDTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO18Greek7Old_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO18Greek7Old>;

 template <>
 struct textEncodingType<text_encoding_id_ISO18Greek7Old_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO18Greek7Old_t;
  using name = string<char, 'g', 'r', 'e', 'e', 'k', '7', '-', 'o', 'l', 'd'>;
  using aliases = typeList<
      string<char, 'g', 'r', 'e', 'e', 'k', '7', '-', 'o', 'l', 'd'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '8'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '1', '8', 'G', 'r', 'e', 'e', 'k', '7', 'O', 'l', 'd'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '8', 'G', 'r', 'e', 'e', 'k', '7', 'O', 'l', 'd'> >
 : textEncodingType<text_encoding_id_ISO18Greek7Old_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'g', 'r', 'e', 'e', 'k', '7', '-', 'o', 'l', 'd'> >
 : textEncodingType<text_encoding_id_ISO18Greek7Old_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '8'> >
 : textEncodingType<text_encoding_id_ISO18Greek7Old_t>
 {
 };
}
#endif
