#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM01148TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM01148TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM01148_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM01148>;

 template <>    
 struct textEncodingType<text_encoding_id_IBM01148_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM01148_t;
  using name = string<char, 'I', 'B', 'M', '0', '1', '1', '4', '8'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '0', '1', '1', '4', '8'>,
      string<char, 'C', 'C', 'S', 'I', 'D', '0', '1', '1', '4', '8'>,
      string<char, 'C', 'P', '0', '1', '1', '4', '8'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'i', 'n', 't', 'e', 'r', 'n', 'a', 't', 'i', 'o', 'n', 'a', 'l', '-', '5', '0', '0', '+', 'e', 'u', 'r', 'o'>,
      string<char, 'c', 's', 'I', 'B', 'M', '0', '1', '1', '4', '8'> >;
 };

 template <>
 struct textEncodingType<string<char, 'C', 'C', 'S', 'I', 'D', '0', '1', '1', '4', '8'> >
 : textEncodingType<text_encoding_id_IBM01148_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'C', 'P', '0', '1', '1', '4', '8'> >
 : textEncodingType<text_encoding_id_IBM01148_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '0', '1', '1', '4', '8'> >
 : textEncodingType<text_encoding_id_IBM01148_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'i', 'n', 't', 'e', 'r', 'n', 'a', 't', 'i', 'o', 'n', 'a', 'l', '-', '5', '0', '0', '+', 'e', 'u', 'r', 'o'> >
 : textEncodingType<text_encoding_id_IBM01148_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '0', '1', '1', '4', '8'> >
 : textEncodingType<text_encoding_id_IBM01148_t>
 {
 };
}
#endif
