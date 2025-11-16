#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO10367BOXTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO10367BOXTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO10367Box_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO10367Box>;

 template <>
 struct textEncodingType<text_encoding_id_ISO10367Box_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO10367Box_t;
  using name = string<char, 'I', 'S', 'O', '_', '1', '0', '3', '6', '7', '-', 'b', 'o', 'x'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '_', '1', '0', '3', '6', '7', '-', 'b', 'o', 'x'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '5', '5'>,
      string<char, 'c', 's', 'I', 'S', 'O', '1', '0', '3', '6', '7', 'B', 'o', 'x'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '0', '3', '6', '7', 'B', 'o', 'x'> >
 : textEncodingType<text_encoding_id_ISO10367Box_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '_', '1', '0', '3', '6', '7', '-', 'b', 'o', 'x'> >
 : textEncodingType<text_encoding_id_ISO10367Box_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '5', '5'> >
 : textEncodingType<text_encoding_id_ISO10367Box_t>
 {
 };
}
#endif
