#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO143IECP271TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO143IECP271TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO143IECP271_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO143IECP271>;

 template <>
 struct textEncodingType<text_encoding_id_ISO143IECP271_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO143IECP271_t;
  using name = string<char, 'I', 'E', 'C', '_', 'P', '2', '7', '-', '1'>;
  using aliases = typeList<
      string<char, 'I', 'E', 'C', '_', 'P', '2', '7', '-', '1'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '4', '3'>,
      string<char, 'c', 's', 'I', 'S', 'O', '1', '4', '3', 'I', 'E', 'C', 'P', '2', '7', '1'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '4', '3', 'I', 'E', 'C', 'P', '2', '7', '1'> >
 : textEncodingType<text_encoding_id_ISO143IECP271_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'E', 'C', '_', 'P', '2', '7', '-', '1'> >
 : textEncodingType<text_encoding_id_ISO143IECP271_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '4', '3'> >
 : textEncodingType<text_encoding_id_ISO143IECP271_t>
 {
 };
}
#endif
