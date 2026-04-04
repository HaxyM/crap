#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM851TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM851TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM851_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM851>;

 template <>
 struct textEncodingType<text_encoding_id_IBM851_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM851_t;
  using name = string<char, 'I', 'B', 'M', '8', '5', '1'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '8', '5', '1'>,
      string<char, 'c', 'p', '8', '5', '1'>,
      string<char, '8', '5', '1'>,
      string<char, 'c', 's', 'I', 'B', 'M', '8', '5', '1'> >;
 };

 template <>
 struct textEncodingType<string<char, '8', '5', '1'> >
 : textEncodingType<text_encoding_id_IBM851_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '8', '5', '1'> >
 : textEncodingType<text_encoding_id_IBM851_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '8', '5', '1'> >
 : textEncodingType<text_encoding_id_IBM851_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '8', '5', '1'> >
 : textEncodingType<text_encoding_id_IBM851_t>
 {
 };
}
#endif
