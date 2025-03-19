#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISOLATIN3TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISOLATIN3TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISOLatin3_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISOLatin3>;

 template <>
 struct textEncodingType<text_encoding_id_ISOLatin3_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISOLatin3_t;
  using name = string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '3', ':', '1', '9', '8', '8'>;
  using aliases = typeList<
	  string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '0', '9'>,
	  string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '3'>,
	  string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '3'>,
	  string<char, 'l', 'a', 't', 'i', 'n', '3'>,
	  string<char, 'l', '3'>,
	  string<char, 'c', 's', 'I', 'S', 'O', 'L', 'a', 't', 'i', 'n', '3'> >; //Libstdc++ adds alias "ISO-8859-3:1988" (name)
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', 'L', 'a', 't', 'i', 'n', '3'> >
 : textEncodingType<text_encoding_id_ISOLatin3_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '3'> >
 : textEncodingType<text_encoding_id_ISOLatin3_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '3'> >
 : textEncodingType<text_encoding_id_ISOLatin3_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '3', ':', '1', '9', '8', '8'> >
 : textEncodingType<text_encoding_id_ISOLatin3_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '0', '9'> >
 : textEncodingType<text_encoding_id_ISOLatin3_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'l', '3'> >
 : textEncodingType<text_encoding_id_ISOLatin3_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'l', 'a', 't', 'i', 'n', '3'> >
 : textEncodingType<text_encoding_id_ISOLatin3_t>
 {
 };
}
#endif
