#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_UNKNOWN8BITTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_UNKNOWN8BITTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_Unknown8BiT_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: Unknown8BiT>;

 template <>
 struct textEncodingType<text_encoding_id_Unknown8BiT_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_Unknown8BiT_t;
  using name = string<char, 'U', 'N', 'K', 'N', 'O', 'W', 'N', '-', '8', 'B', 'I', 'T'>;
  using aliases = typeList<
      string<char, 'U', 'N', 'K', 'N', 'O', 'W', 'N', '-', '8', 'B', 'I', 'T'>,
      string<char, 'c', 's', 'U', 'n', 'k', 'n', 'o', 'w', 'n', '8', 'B', 'i', 'T'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'U', 'n', 'k', 'n', 'o', 'w', 'n', '8', 'B', 'i', 'T'> >
 : textEncodingType<text_encoding_id_Unknown8BiT_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'U', 'N', 'K', 'N', 'O', 'W', 'N', '-', '8', 'B', 'I', 'T'> >
 : textEncodingType<text_encoding_id_Unknown8BiT_t>
 {
 };
}
#endif
