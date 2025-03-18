#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISOLATIN4TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISOLATIN4TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISOLatin4_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISOLatin4>;

 template <>
 struct textEncodingType<text_encoding_id_ISOLatin4_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISOLatin4_t;
  using name = string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '4', ':', '1', '9', '8', '8'>;
  using aliases = typeList<
	  string<char 'i', 's', 'o', '-', 'i', 'r', '-', '1', '1', '0'>,
	  string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '4'>,
	  string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '4'>,
	  string<char, 'l', 'a', 't', 'i', 'n', '4'>,
	  string<char, 'l', '4'>,
	  string<char 'c', 's', 'I', 'S', 'O', 'L', 'a', 't', 'i', 'n', '4'> >; //Libstdc++ adds alias "ISO-8859-4:1988" (name)
 };

 template <>
 struct textEncodingType<string<char 'c', 's', 'I', 'S', 'O', 'L', 'a', 't', 'i', 'n', '4'> >
 : textEncodingType<text_encoding_id_ISOLatin4_t>
 {
 };

 template <>
 struct textEncodingType<string<char 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '4'> >
 : textEncodingType<text_encoding_id_ISOLatin4_t>
 {
 };

 template <>
 struct textEncodingType<string<char 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '4'> >
 : textEncodingType<text_encoding_id_ISOLatin4_t>
 {
 };

 template <>
 struct textEncodingType<string<char 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '4', ':', '1', '9', '8', '8'> >
 : textEncodingType<text_encoding_id_ISOLatin4_t>
 {
 };

 template <>
 struct textEncodingType<string<char 'i', 's', 'o', '-', 'i', 'r', '-', '1', '1', '0'> >
 : textEncodingType<text_encoding_id_ISOLatin4_t>
 {
 };

 template <>
 struct textEncodingType<string<char 'l', '4'> >
 : textEncodingType<text_encoding_id_ISOLatin4_t>
 {
 };

 template <>
 struct textEncodingType<string<char 'l', 'a', 't', 'i', 'n', '4'> >
 : textEncodingType<text_encoding_id_ISOLatin4_t>
 {
 };
}
#endif
