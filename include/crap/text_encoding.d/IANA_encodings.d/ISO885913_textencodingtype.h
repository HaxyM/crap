#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO885913TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO885913TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO885913_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO885913>;

 template <>
 struct textEncodingType<text_encoding_id_ISO885913_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO885913_t;
  using name = string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '1', '3'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '1', '3'>,
      string<char, 'c', 's', 'I', 'S', 'O', '8', '8', '5', '9', '1', '3'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '8', '8', '5', '9', '1', '3'> >
 : textEncodingType<text_encoding_id_ISO885913_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '1', '3'> >
 : textEncodingType<text_encoding_id_ISO885913_t>
 {
 };
}
#endif
