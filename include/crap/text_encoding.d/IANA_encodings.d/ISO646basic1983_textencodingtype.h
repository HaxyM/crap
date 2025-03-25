#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO646BASIC1983TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO646BASIC1983TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO646basic1983_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO646basic1983>;

 template <>
 struct textEncodingType<text_encoding_id_ISO646basic1983_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO646basic1983_t;
  using name = string<char, 'I', 'S', 'O', '_', '6', '4', '6', '.', 'b', 'a', 's', 'i', 'c', ':', '1', '9', '8', '3'>;
  using aliases = typeList<
  	  string<char, 'I', 'S', 'O', '_', '6', '4', '6', '.', 'b', 'a', 's', 'i', 'c', ':', '1', '9', '8', '3'>,
      string<char, 'r', 'e', 'f'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '6', '4', '6', 'b', 'a', 's', 'i', 'c', '1', '9', '8', '3'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '6', '4', '6', 'b', 'a', 's', 'i', 'c', '1', '9', '8', '3'> >
 : textEncodingType<text_encoding_id_ISO646basic1983_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '_', '6', '4', '6', '.', 'b', 'a', 's', 'i', 'c', ':', '1', '9', '8', '3'> >
 : textEncodingType<text_encoding_id_ISO646basic1983_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'r', 'e', 'f'> >
 : textEncodingType<text_encoding_id_ISO646basic1983_t>
 {
 };
}
#endif
