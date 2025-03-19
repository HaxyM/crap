#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISOLATIN6TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISOLATIN6TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISOLatin6_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISOLatin6>;

 template <>
 struct textEncodingType<text_encoding_id_ISOLatin6_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISOLatin6_t;
  using name = string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '1', '0'>;
  using aliases = typeList<
	  string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '1', '0'>,
	  string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '5', '7'>,
      string<char, 'l', '6'>,
	  string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '1', '0', ':', '1', '9', '9', '2'>,
      string<char, 'c', 's', 'I', 'S', 'O', 'L', 'a', 't', 'i', 'n', '6'>,
	  string<char, 'l', 'a', 't', 'i', 'n', '6'> >;
	  
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', 'L', 'a', 't', 'i', 'n', '6'> >
 : textEncodingType<text_encoding_id_ISOLatin6_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '1', '0'> >
 : textEncodingType<text_encoding_id_ISOLatin6_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '1', '0', ':', '1', '9', '9', '2'> >
 : textEncodingType<text_encoding_id_ISOLatin6_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '5', '7'> >
 : textEncodingType<text_encoding_id_ISOLatin6_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'l', 'a', 't', 'i', 'n', '6'> >
 : textEncodingType<text_encoding_id_ISOLatin6_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'l', ''> >
 : textEncodingType<text_encoding_id_ISOLatin6_t>
 {
 };
}
#endif
