#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISOLATIN5TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISOLATIN5TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISOLatin5_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISOLatin5>;

 template <>
 struct textEncodingType<text_encoding_id_ISOLatin5_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISOLatin5_t;
  using name = string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '9', ':', '1', '9', '8', '9'>;
  using aliases = typeList<
	  string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '9', ':', '1', '9', '8', '9'>,
	  string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '4', '8'>,
	  string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '9'>,
	  string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '9'>,
	  string<char, 'l', 'a', 't', 'i', 'n', '5'>,
      string<char, 'l', '5'>,
	  string<char, 'c', 's', 'I', 'S', 'O', 'L', 'a', 't', 'i', 'n', '5'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', 'L', 'a', 't', 'i', 'n', '5'> >
 : textEncodingType<text_encoding_id_ISOLatin5_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '9'> >
 : textEncodingType<text_encoding_id_ISOLatin5_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '9'> >
 : textEncodingType<text_encoding_id_ISOLatin5_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '9', ':', '1', '9', '8', '9'> >
 : textEncodingType<text_encoding_id_ISOLatin5_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '4', '8'> >
 : textEncodingType<text_encoding_id_ISOLatin5_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'l', 'a', 't', 'i', 'n', '5'> >
 : textEncodingType<text_encoding_id_ISOLatin5_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'l', '5'> >
 : textEncodingType<text_encoding_id_ISOLatin5_t>
 {
 };
}
#endif
