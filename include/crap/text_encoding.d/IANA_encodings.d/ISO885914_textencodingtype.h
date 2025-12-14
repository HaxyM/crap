#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO885914TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO885914TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO885914_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO885914>;

 template <>
 struct textEncodingType<text_encoding_id_ISO885914_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO885914_t;
  using name = string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '1', '4'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '1', '4'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '9', '9'>,
      string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '1', '4', ':', '1', '9', '9', '8'>,
      string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '1', '4'>,
      string<char, 'l', 'a', 't', 'i', 'n', '8'>,
      string<char, 'i', 's', 'o', '-', 'c', 'e', 'l', 't', 'i', 'c'>,
      string<char, 'l', '8'>,
      string<char, 'c', 's', 'I', 'S', 'O', '8', '8', '5', '9', '1', '4'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '8', '8', '5', '9', '1', '4'> >
 : textEncodingType<text_encoding_id_ISO885914_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '1', '4'> >
 : textEncodingType<text_encoding_id_ISO885914_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '1', '4', ':', '1', '9', '9', '8'> >
 : textEncodingType<text_encoding_id_ISO885914_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '1', '4'> >
 : textEncodingType<text_encoding_id_ISO885914_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'c', 'e', 'l', 't', 'i', 'c'> >
 : textEncodingType<text_encoding_id_ISO885914_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '9', '9'> >
 : textEncodingType<text_encoding_id_ISO885914_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'l', '8'> >
 : textEncodingType<text_encoding_id_ISO885914_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'l', 'a', 't', 'i', 'n', '8'> >
 : textEncodingType<text_encoding_id_ISO885914_t>
 {
 };
}
#endif
