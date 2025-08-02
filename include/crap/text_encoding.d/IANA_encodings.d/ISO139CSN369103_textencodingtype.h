#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO139CSN369103TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO139CSN369103TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO139CSN369103_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO139CSN369103>;

 template <>
 struct textEncodingType<text_encoding_id_ISO139CSN369103_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO139CSN369103_t;
  using name = string<char, 'C', 'S', 'N', '_', '3', '6', '9', '1', '0', '3'>;
  using aliases = typeList<
      string<char, 'C', 'S', 'N', '_', '3', '6', '9', '1', '0', '3'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '3', '9'>,
      string<char, 'c', 's', 'I', 'S', 'O', '1', '3', '9', 'C', 'S', 'N', '3', '6', '9', '1', '0', '3'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '3', '9', 'C', 'S', 'N', '3', '6', '9', '1', '0', '3'> >
 : textEncodingType<text_encoding_id_ISO139CSN369103_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'C', 'S', 'N', '_', '3', '6', '9', '1', '0', '3'> >
 : textEncodingType<text_encoding_id_ISO139CSN369103_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '3', '9'> >
 : textEncodingType<text_encoding_id_ISO139CSN369103_t>
 {
 };
}
#endif
