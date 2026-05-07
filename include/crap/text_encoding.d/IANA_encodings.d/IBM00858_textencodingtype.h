#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM00858TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM00858TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM00858_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM00858>;

 template <>    
 struct textEncodingType<text_encoding_id_IBM00858_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM00858_t;
  using name = string<char, 'I', 'B', 'M', '0', '0', '8', '5', '8'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '0', '0', '8', '5', '8'>,
      string<char, 'C', 'C', 'S', 'I', 'D', '0', '0', '8', '5', '8'>,
      string<char, 'C', 'P', '0', '0', '8', '5', '8'>,
      string<char, 'P', 'C', '-', 'M', 'u', 'l', 't', 'i', 'l', 'i', 'n', 'g', 'u', 'a', 'l', '-', '8', '5', '0', '+', 'e', 'u', 'r', 'o'>,
      string<char, 'c', 's', 'I', 'B', 'M', '0', '0', '8', '5', '8'> >;
 };

 template <>
 struct textEncodingType<string<char, 'C', 'C', 'S', 'I', 'D', '0', '0', '8', '5', '8'> >
 : textEncodingType<text_encoding_id_IBM00858_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'C', 'P', '0', '0', '8', '5', '8'> >
 : textEncodingType<text_encoding_id_IBM00858_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '0', '0', '8', '5', '8'> >
 : textEncodingType<text_encoding_id_IBM00858_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '0', '0', '8', '5', '8'> >
 : textEncodingType<text_encoding_id_IBM00858_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'P', 'C', '-', 'M', 'u', 'l', 't', 'i', 'l', 'i', 'n', 'g', 'u', 'a', 'l', '-', '8', '5', '0', '+', 'e', 'u', 'r', 'o'> >
 : textEncodingType<text_encoding_id_IBM00858_t>
 {
 };
}
#endif
