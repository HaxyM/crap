#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO115481TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO115481TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO115481_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO115481>;

 template <>
 struct textEncodingType<text_encoding_id_ISO115481_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO115481_t;
  using name = string<char, 'I', 'S', 'O', '-', '1', '1', '5', '4', '8', '-', '1'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '-', '1', '1', '5', '4', '8', '-', '1'>,
      string<char, 'I', 'S', 'O', '_', '1', '1', '5', '4', '8', '-', '1'>,
      string<char, 'I', 'S', 'O', '_', 'T', 'R', '_', '1', '1', '5', '4', '8', '-', '1'>,
      string<char, 'c', 's', 'I', 'S', 'O', '1', '1', '5', '4', '8', '1'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '1', '5', '4', '8', '1'> >
 : textEncodingType<text_encoding_id_ISO115481_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '_', '1', '1', '5', '4', '8', '-', '1'> >
 : textEncodingType<text_encoding_id_ISO115481_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '_', 'T', 'R', '_', '1', '1', '5', '4', '8', '-', '1'> >
 : textEncodingType<text_encoding_id_ISO115481_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '1', '1', '5', '4', '8', '-', '1'> >
 : textEncodingType<text_encoding_id_ISO115481_t>
 {
 };
}
#endif
