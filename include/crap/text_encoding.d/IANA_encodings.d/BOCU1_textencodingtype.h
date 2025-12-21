#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_BOCU1TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_BOCU1TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_BOCU1_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: BOCU1>;

 template <>
 struct textEncodingType<text_encoding_id_BOCU1_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_BOCU1_t;
  using name = string<char, 'B', 'O', 'C', 'U', '-', '1'>;
  using aliases = typeList<
      string<char, 'B', 'O', 'C', 'U', '-', '1'>,
      string<char, 'c', 's', 'B', 'O', 'C', 'U', '1'>,
      string<char, 'c', 's', 'B', 'O', 'C', 'U', '-', '1'> >;
 };

 template <>
 struct textEncodingType<string<char, 'B', 'O', 'C', 'U', '-', '1'> >
 : textEncodingType<text_encoding_id_BOCU1_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'B', 'O', 'C', 'U', '-', '1'> >
 : textEncodingType<text_encoding_id_BOCU1_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'B', 'O', 'C', 'U', '1'> >
 : textEncodingType<text_encoding_id_BOCU1_t>
 {
 };
}
#endif
