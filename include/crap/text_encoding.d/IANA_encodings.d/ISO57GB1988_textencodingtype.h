#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO57GB1988TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO57GB1988TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO57GB1988_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO57GB1988>;

 template <>
 struct textEncodingType<text_encoding_id_ISO57GB1988_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO57GB1988_t;
  using name = string<char, 'G', 'B', '_', '1', '9', '8', '8', '-', '8', '0'>;
  using aliases = typeList<
      string<char, 'G', 'B', '_', '1', '9', '8', '8', '-', '8', '0'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '5', '7'>,
      string<char, 'c', 'n'>,
      string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'C', 'N'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '5', '7', 'G', 'B', '1', '9', '8', '8'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 'n'> >
 : textEncodingType<text_encoding_id_ISO57GB1988_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '5', '7', 'G', 'B', '1', '9', '8', '8'> >
 : textEncodingType<text_encoding_id_ISO57GB1988_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'G', 'B', '_', '1', '9', '8', '8', '-', '8', '0'> >
 : textEncodingType<text_encoding_id_ISO57GB1988_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'C', 'N'> >
 : textEncodingType<text_encoding_id_ISO57GB1988_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '5', '7'> >
 : textEncodingType<text_encoding_id_ISO57GB1988_t>
 {
 };
}
#endif
