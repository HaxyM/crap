#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM01147TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM01147TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM01147_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM01147>;

 template <>    
 struct textEncodingType<text_encoding_id_IBM01147_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM01147_t;
  using name = string<char, 'I', 'B', 'M', '0', '1', '1', '4', '7'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '0', '1', '1', '4', '7'>,
      string<char, 'C', 'C', 'S', 'I', 'D', '0', '1', '1', '4', '7'>,
      string<char, 'C', 'P', '0', '1', '1', '4', '7'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'f', 'r', '-', '2', '9', '7', '+', 'e', 'u', 'r', 'o'>,
      string<char, 'c', 's', 'I', 'B', 'M', '0', '1', '1', '4', '7'> >;
 };

 template <>
 struct textEncodingType<string<char, 'C', 'C', 'S', 'I', 'D', '0', '1', '1', '4', '7'> >
 : textEncodingType<text_encoding_id_IBM01147_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'C', 'P', '0', '1', '1', '4', '7'> >
 : textEncodingType<text_encoding_id_IBM01147_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '0', '1', '1', '4', '7'> >
 : textEncodingType<text_encoding_id_IBM01147_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'f', 'r', '-', '2', '9', '7', '+', 'e', 'u', 'r', 'o'> >
 : textEncodingType<text_encoding_id_IBM01147_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '0', '1', '1', '4', '7'> >
 : textEncodingType<text_encoding_id_IBM01147_t>
 {
 };
}
#endif
