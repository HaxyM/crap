#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_OSDEBCDICDF041TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_OSDEBCDICDF041TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_OSDEBCDICDF041_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: OSDEBCDICDF041>;

 template <>
 struct textEncodingType<text_encoding_id_OSDEBCDICDF041_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_OSDEBCDICDF041_t;
  using name = string<char, 'O', 'S', 'D', '_', 'E', 'B', 'C', 'D', 'I', 'C', '_', 'D', 'F', '0', '4', '_', '1'>;
  using aliases = typeList<
      string<char, 'O', 'S', 'D', '_', 'E', 'B', 'C', 'D', 'I', 'C', '_', 'D', 'F', '0', '4', '_', '1'>,
      string<char, 'c', 's', 'O', 'S', 'D', 'E', 'B', 'C', 'D', 'I', 'C', 'D', 'F', '0', '4', '1'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'O', 'S', 'D', 'E', 'B', 'C', 'D', 'I', 'C', 'D', 'F', '0', '4', '1'> >
 : textEncodingType<text_encoding_id_OSDEBCDICDF041_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'O', 'S', 'D', '_', 'E', 'B', 'C', 'D', 'I', 'C', '_', 'D', 'F', '0', '4', '_', '1'> >
 : textEncodingType<text_encoding_id_OSDEBCDICDF041_t>
 {
 };
}
#endif
