#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_UCS2TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_UCS2TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_UCS2_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: UCS2>;

 template <>
 struct textEncodingType<text_encoding_id_UCS2_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_UCS2_t;
  using name = string<char, 'I', 'S', 'O', '-', '1', '0', '6', '4', '6', '-', 'U', 'C', 'S', '-', '2'>;
  using aliases = typeList<
      string<char, 'I', 'S', 'O', '-', '1', '0', '6', '4', '6', '-', 'U', 'C', 'S', '-', '2'>,
      string<char, 'c', 's', 'U', 'n', 'i', 'c', 'o', 'd', 'e'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'U', 'n', 'i', 'c', 'o', 'd', 'e'> >
 : textEncodingType<text_encoding_id_UCS2_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '1', '0', '6', '4', '6', '-', 'U', 'C', 'S', '-', '2'> >
 : textEncodingType<text_encoding_id_UCS2_t>
 {
 };
}
#endif
