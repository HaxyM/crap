#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_PC8CODEPAGE437TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_PC8CODEPAGE437TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_PC8CodePage437_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: PC8CodePage437>;

 template <>
 struct textEncodingType<text_encoding_id_PC8CodePage437_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_PC8CodePage437_t;
  using name = string<char, 'I', 'B', 'M', '4', '3', '7'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '4', '3', '7'>,
      string<char, 'c', 'p', '4', '3', '7'>,
      string<char, '4', '3', '7'>,
      string<char, 'c', 's', 'P', 'C', '8', 'C', 'o', 'd', 'e', 'P', 'a', 'g', 'e', '4', '3', '7'> >;
 };

 template <>
 struct textEncodingType<string<char, '4', '3', '7'> >
 : textEncodingType<text_encoding_id_PC8CodePage437_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '4', '3', '7'> >
 : textEncodingType<text_encoding_id_PC8CodePage437_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'P', 'C', '8', 'C', 'o', 'd', 'e', 'P', 'a', 'g', 'e', '4', '3', '7'> >
 : textEncodingType<text_encoding_id_PC8CodePage437_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '4', '3', '7'> >
 : textEncodingType<text_encoding_id_PC8CodePage437_t>
 {
 };
}
#endif
