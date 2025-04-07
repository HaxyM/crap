#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO5427CYRILLICTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO5427CYRILLICTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO5427Cyrillic_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO5427Cyrillic>;

 template <>
 struct textEncodingType<text_encoding_id_ISO5427Cyrillic_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO5427Cyrillic_t;
  using name = string<char, 'I', 'S', 'O', '_', '5', '4', '2', '7'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '_', '5', '4', '2', '7'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '3', '7'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '5', '4', '2', '7', 'C', 'y', 'r', 'i', 'l', 'l', 'i', 'c'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '5', '4', '2', '7', 'C', 'y', 'r', 'i', 'l', 'l', 'i', 'c'> >
 : textEncodingType<text_encoding_id_ISO5427Cyrillic_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '_', '5', '4', '2', '7'> >
 : textEncodingType<text_encoding_id_ISO5427Cyrillic_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '3', '7'> >
 : textEncodingType<text_encoding_id_ISO5427Cyrillic_t>
 {
 };
}
#endif
