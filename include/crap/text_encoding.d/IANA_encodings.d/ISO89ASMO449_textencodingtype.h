#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO89ASMO449TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO89ASMO449TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO89ASMO449_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO89ASMO449>;

 template <>
 struct textEncodingType<text_encoding_id_ISO89ASMO449_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO89ASMO449_t;
  using name = string<char, 'A', 'S', 'M', 'O', '_', '4', '4', '9'>;
  using aliases = typeList<
      string<char, 'A', 'S', 'M', 'O', '_', '4', '4', '9'>,
      string<char, 'I', 'S', 'O', '_', '9', '0', '3', '6'>,
      string<char, 'a', 'r', 'a', 'b', 'i', 'c', '7'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '8', '9'>,
      string<char, 'c', 's', 'I', 'S', 'O', '8', '9', 'A', 'S', 'M', 'O', '4', '4', '9'> >;
	  
 };

 template <>
 struct textEncodingType<string<char, 'A', 'S', 'M', 'O', '_', '4', '4', '9'> >
 : textEncodingType<text_encoding_id_ISO89ASMO449_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'a', 'r', 'a', 'b', 'i', 'c', '7'> >
 : textEncodingType<text_encoding_id_ISO89ASMO449_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '8', '9', 'A', 'S', 'M', 'O', '4', '4', '9'> >
 : textEncodingType<text_encoding_id_ISO89ASMO449_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '_', '9', '0', '3', '6'> >
 : textEncodingType<text_encoding_id_ISO89ASMO449_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '8', '9'> >
 : textEncodingType<text_encoding_id_ISO89ASMO449_t>
 {
 };
}
#endif
