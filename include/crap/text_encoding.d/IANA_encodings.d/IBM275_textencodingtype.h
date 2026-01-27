#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM275TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM275TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM275_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM275>;

 template <>
 struct textEncodingType<text_encoding_id_IBM275_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM275_t;
  using name = string<char, 'I', 'B', 'M', '2', '7', '5'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '2', '7', '5'>,
      string<char, 'c', 'p', '2', '7', '5'>,
      string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'B', 'R'>,
      string<char, 'c', 's', 'I', 'B', 'M', '2', '7', '5'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '2', '7', '5'> >
 : textEncodingType<text_encoding_id_IBM275_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '2', '7', '5'> >
 : textEncodingType<text_encoding_id_IBM275_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'B', 'R'> >
 : textEncodingType<text_encoding_id_IBM275_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '2', '7', '5'> >
 : textEncodingType<text_encoding_id_IBM275_t>
 {
 };
}
#endif
