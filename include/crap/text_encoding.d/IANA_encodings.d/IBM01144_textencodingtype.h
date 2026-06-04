#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM01144TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM01144TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM01144_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM01144>;

 template <>    
 struct textEncodingType<text_encoding_id_IBM01144_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM01144_t;
  using name = string<char, 'I', 'B', 'M', '0', '1', '1', '4', '4'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '0', '1', '1', '4', '4'>,
      string<char, 'C', 'C', 'S', 'I', 'D', '0', '1', '1', '4', '4'>,
      string<char, 'C', 'P', '0', '1', '1', '4', '4'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'i', 't', '-', '2', '8', '0', '+', 'e', 'u', 'r', 'o'>,
      string<char, 'c', 's', 'I', 'B', 'M', '0', '1', '1', '4', '4'> >;
 };

 template <>
 struct textEncodingType<string<char, 'C', 'C', 'S', 'I', 'D', '0', '1', '1', '4', '4'> >
 : textEncodingType<text_encoding_id_IBM01144_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'C', 'P', '0', '1', '1', '4', '4'> >
 : textEncodingType<text_encoding_id_IBM01144_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '0', '1', '1', '4', '4'> >
 : textEncodingType<text_encoding_id_IBM01144_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'i', 't', '-', '2', '8', '0', '+', 'e', 'u', 'r', 'o'> >
 : textEncodingType<text_encoding_id_IBM01144_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '0', '1', '1', '4', '4'> >
 : textEncodingType<text_encoding_id_IBM01144_t>
 {
 };
}
#endif
