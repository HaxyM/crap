#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM285TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM285TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM285_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM285>;

 template <>
 struct textEncodingType<text_encoding_id_IBM285_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM285_t;
  using name = string<char, 'I', 'B', 'M', '2', '8', '5'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '2', '8', '5'>,
      string<char, 'C', 'P', '2', '8', '5'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'g', 'b'>,
      string<char, 'c', 's', 'I', 'B', 'M', '2', '8', '5'> >;
 };

 template <>
 struct textEncodingType<string<char, 'C', 'P', '2', '8', '5'> >
 : textEncodingType<text_encoding_id_IBM285_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '2', '8', '5'> >
 : textEncodingType<text_encoding_id_IBM285_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'g', 'b'> >
 : textEncodingType<text_encoding_id_IBM285_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '2', '8', '5'> >
 : textEncodingType<text_encoding_id_IBM285_t>
 {
 };
}
#endif
