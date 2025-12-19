#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_OSDEBCDICDF0415TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_OSDEBCDICDF0415TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_OSDEBCDICDF0415_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: OSDEBCDICDF0415>;

 template <>
 struct textEncodingType<text_encoding_id_OSDEBCDICDF0415_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_OSDEBCDICDF0415_t;
  using name = string<char, 'O', 'S', 'D', '_', 'E', 'B', 'C', 'D', 'I', 'C', '_', 'D', 'F', '0', '4', '_', '1', '5'>;
  using aliases = typeList<
      string<char, 'O', 'S', 'D', '_', 'E', 'B', 'C', 'D', 'I', 'C', '_', 'D', 'F', '0', '4', '_', '1', '5'>,
      string<char, 'c', 's', 'O', 'S', 'D', 'E', 'B', 'C', 'D', 'I', 'C', 'D', 'F', '0', '4', '1', '5'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'O', 'S', 'D', 'E', 'B', 'C', 'D', 'I', 'C', 'D', 'F', '0', '4', '1', '5'> >
 : textEncodingType<text_encoding_id_OSDEBCDICDF0415_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'O', 'S', 'D', '_', 'E', 'B', 'C', 'D', 'I', 'C', '_', 'D', 'F', '0', '4', '_', '1', '5'> >
 : textEncodingType<text_encoding_id_OSDEBCDICDF0415_t>
 {
 };
}
#endif
