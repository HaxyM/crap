#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM01143TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM01143TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM01143_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM01143>;

 template <>    
 struct textEncodingType<text_encoding_id_IBM01143_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM01143_t;
  using name = string<char, 'I', 'B', 'M', '0', '1', '1', '4', '3'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '0', '1', '1', '4', '3'>,
      string<char, 'C', 'C', 'S', 'I', 'D', '0', '1', '1', '4', '3'>,
      string<char, 'C', 'P', '0', '1', '1', '4', '3'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'f', 'i', '-', '2', '7', '8', '+', 'e', 'u', 'r', 'o'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 's', 'e', '-', '2', '7', '8', '+', 'e', 'u', 'r', 'o'>,
      string<char, 'c', 's', 'I', 'B', 'M', '0', '1', '1', '4', '3'> >;
 };

 template <>
 struct textEncodingType<string<char, 'C', 'C', 'S', 'I', 'D', '0', '1', '1', '4', '3'> >
 : textEncodingType<text_encoding_id_IBM01143_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'C', 'P', '0', '1', '1', '4', '3'> >
 : textEncodingType<text_encoding_id_IBM01143_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '0', '1', '1', '4', '3'> >
 : textEncodingType<text_encoding_id_IBM01143_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'f', 'i', '-', '2', '7', '8', '+', 'e', 'u', 'r', 'o'> >
 : textEncodingType<text_encoding_id_IBM01143_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 's', 'e', '-', '2', '7', '8', '+', 'e', 'u', 'r', 'o'> >
 : textEncodingType<text_encoding_id_IBM01143_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '0', '1', '1', '4', '3'> >
 : textEncodingType<text_encoding_id_IBM01143_t>
 {
 };
}
#endif
