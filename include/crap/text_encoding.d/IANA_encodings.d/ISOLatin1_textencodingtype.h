#include <type_traits>
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISOLATIN1TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISOLATIN1TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISOLatin1_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISOLatin1>;

 template <>
 struct textEncodingType<text_encoding_id_ISOLatin1_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISOLatin1_t;
  using name = string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '1', ':', '1', '9', '8', '7'>;
  using aliases = typeList<
	  string<char 'i', 's', 'o', '-', 'i', 'r', '-', '1', '0', '0'>,
	  string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '1'>,
	  string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '1'>,
	  string<char, 'l', 'a', 't', 'i', 'n', '1'>,
	  string<char, 'l', '1'>,
	  string<char, 'I', 'B', 'M', '8', '1', '9'>,
	  string<char, 'C', 'P', '8', '1', '9'>,
	  string<char 'c', 's', 'I', 'S', 'O', 'L', 'a', 't', 'i', 'n', '1'> >; //Libstdc++ adds alias "ISO-8859-1:1987" (name)
 };

 template <>
 struct textEncodingType<string<char 'C', 'P', '8', '1', '9'> >
 : textEncodingType<text_encoding_id_ISOLatin1_t>
 {
 };

 template <>
 struct textEncodingType<string<char 'c', 's', 'I', 'S', 'O', 'L', 'a', 't', 'i', 'n', '1'> >
 : textEncodingType<text_encoding_id_ISOLatin1_t>
 {
 };

 template <>
 struct textEncodingType<string<char 'I', 'B', 'M', '8', '1', '9'> >
 : textEncodingType<text_encoding_id_ISOLatin1_t>
 {
 };

 template <>
 struct textEncodingType<string<char 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '1'> >
 : textEncodingType<text_encoding_id_ISOLatin1_t>
 {
 };

 template <>
 struct textEncodingType<string<char 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '1'> >
 : textEncodingType<text_encoding_id_ISOLatin1_t>
 {
 };

 template <>
 struct textEncodingType<string<char 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '1', ':', '1', '9', '8', '7'> >
 : textEncodingType<text_encoding_id_ISOLatin1_t>
 {
 };

 template <>
 struct textEncodingType<string<char 'i', 's', 'o', '-', 'i', 'r', '-', '1', '0', '0'> >
 : textEncodingType<text_encoding_id_ISOLatin1_t>
 {
 };

 template <>
 struct textEncodingType<string<char 'l', '1'> >
 : textEncodingType<text_encoding_id_ISOLatin1_t>
 {
 };

 template <>
 struct textEncodingType<string<char 'l', 'a', 't', 'i', 'n', '1'> >
 : textEncodingType<text_encoding_id_ISOLatin1_t>
 {
 };
}
#endif
