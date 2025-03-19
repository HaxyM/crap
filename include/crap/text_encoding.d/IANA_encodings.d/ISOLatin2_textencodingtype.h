#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISOLATIN2TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISOLATIN2TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISOLatin2_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISOLatin2>;

 template <>
 struct textEncodingType<text_encoding_id_ISOLatin2_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISOLatin2_t;
  using name = string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '2', ':', '1', '9', '8', '7'>;
  using aliases = typeList<
	  string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '0', '1'>,
	  string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '2'>,
	  string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '2'>,
	  string<char, 'l', 'a', 't', 'i', 'n', '2'>,
	  string<char, 'l', '2'>,
	  string<char, 'c', 's', 'I', 'S', 'O', 'L', 'a', 't', 'i', 'n', '2'> >; //Libstdc++ adds alias "ISO-8859-2:1987" (name)
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', 'L', 'a', 't', 'i', 'n', '2'> >
 : textEncodingType<text_encoding_id_ISOLatin2_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '2'> >
 : textEncodingType<text_encoding_id_ISOLatin2_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '2'> >
 : textEncodingType<text_encoding_id_ISOLatin2_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '2', ':', '1', '9', '8', '7'> >
 : textEncodingType<text_encoding_id_ISOLatin2_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '0', '1'> >
 : textEncodingType<text_encoding_id_ISOLatin2_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'l', '2'> >
 : textEncodingType<text_encoding_id_ISOLatin2_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'l', 'a', 't', 'i', 'n', '2'> >
 : textEncodingType<text_encoding_id_ISOLatin2_t>
 {
 };
}
#endif
