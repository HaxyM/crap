#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO58GB231280TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO58GB231280TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO58GB231280_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO58GB231280>;

 template <>
 struct textEncodingType<text_encoding_id_ISO58GB231280_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO58GB231280_t;
  using name = string<char, 'G', 'B', '_', '2', '3', '1', '2', '-', '8', '0'>;
  using aliases = typeList<
      string<char, 'G', 'B', '_', '2', '3', '1', '2', '-', '8', '0'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '5', '8'>,
      string<char, 'c', 'h', 'i', 'n', 'e', 's', 'e'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '5', '8', 'G', 'B', '2', '3', '1', '2', '8', '0'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 'h', 'i', 'n', 'e', 's', 'e'> >
 : textEncodingType<text_encoding_id_ISO58GB231280_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '5', '8', 'G', 'B', '2', '3', '1', '2', '8', '0'> >
 : textEncodingType<text_encoding_id_ISO58GB231280_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'G', 'B', '_', '2', '3', '1', '2', '-', '8', '0'> >
 : textEncodingType<text_encoding_id_ISO58GB231280_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '5', '8'> >
 : textEncodingType<text_encoding_id_ISO58GB231280_t>
 {
 };
}
#endif
