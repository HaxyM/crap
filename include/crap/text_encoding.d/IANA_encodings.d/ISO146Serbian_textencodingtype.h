#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO146SERBIANTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO146SERBIANTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO146Serbian_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO146Serbian>;

 template <>
 struct textEncodingType<text_encoding_id_ISO146Serbian_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO146Serbian_t;
  using name = string<char, 'J', 'U', 'S', '_', 'I', '.', 'B', '1', '.', '0', '0', '3', '-', 's', 'e', 'r', 'b'>;
  using aliases = typeList<
      string<char, 'J', 'U', 'S', '_', 'I', '.', 'B', '1', '.', '0', '0', '3', '-', 's', 'e', 'r', 'b'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '4', '6'>,
      string<char, 's', 'e', 'r', 'b', 'i', 'a', 'n'>,
      string<char, 'c', 's', 'I', 'S', 'O', '1', '4', '6', 'S', 'e', 'r', 'b', 'i', 'a', '1n'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '4', '6', 'S', 'e', 'r', 'b', 'i', 'a', 'n'> >
 : textEncodingType<text_encoding_id_ISO146Serbian_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '4', '3'> >
 : textEncodingType<text_encoding_id_ISO146Serbian_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'J', 'U', 'S', '_', 'I', '.', 'B', '1', '.', '0', '0', '3', '-', 's', 'e', 'r', 'b'> >
 : textEncodingType<text_encoding_id_ISO146Serbian_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 's', 'e', 'r', 'b', 'i', 'a', 'n'> >
 : textEncodingType<text_encoding_id_ISO146Serbian_t>
 {
 };
}
#endif
