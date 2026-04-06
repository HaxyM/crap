#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM880TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM880TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM880_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM880>;

 template <>
 struct textEncodingType<text_encoding_id_IBM880_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM880_t;
  using name = string<char, 'I', 'B', 'M', '8', '8', '0'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '8', '8', '0'>,
      string<char, 'c', 'p', '8', '8', '0'>,
      string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'C', 'y', 'r', 'i', 'l', 'l', 'i', 'c'>,
      string<char, 'c', 's', 'I', 'B', 'M', '8', '8', '0'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '8', '8', '0'> >
 : textEncodingType<text_encoding_id_IBM880_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '8', '8', '0'> >
 : textEncodingType<text_encoding_id_IBM880_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'C', 'y', 'r', 'i', 'l', 'l', 'i', 'c'> >
 : textEncodingType<text_encoding_id_IBM880_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '8', '8', '0'> >
 : textEncodingType<text_encoding_id_IBM880_t>
 {
 };
}
#endif
