#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_UCS4TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_UCS4TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_UCS4_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: UCS4>;

 template <>
 struct textEncodingType<text_encoding_id_UCS4_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_UCS4_t;
  using name = string<char, 'I', 'S', 'O', '-', '1', '0', '6', '4', '6', '-', 'U', 'C', 'S', '-', '4'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '-', '1', '0', '6', '4', '6', '-', 'U', 'C', 'S', '-', '4'>,
      string<char, 'c', 's', 'U', 'C', 'S', '4'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'U', 'C', 'S', '4'> >
 : textEncodingType<text_encoding_id_UCS4_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '1', '0', '6', '4', '6', '-', 'U', 'C', 'S', '-', '4'> >
 : textEncodingType<text_encoding_id_UCS4_t>
 {
 };
}
#endif
