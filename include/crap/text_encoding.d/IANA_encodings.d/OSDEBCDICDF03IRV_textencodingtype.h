#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_OSDEBCDICDF03IRVTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_OSDEBCDICDF03IRVTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_OSDEBCDICDF03IRV_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: OSDEBCDICDF03IRV>;

 template <>
 struct textEncodingType<text_encoding_id_OSDEBCDICDF03IRV_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_OSDEBCDICDF03IRV_t;
  using name = string<char, 'O', 'S', 'D', '_', 'E', 'B', 'C', 'D', 'I', 'C', '_', 'D', 'F', '0', '3', '_', 'I', 'R', 'V'>;
  using aliases = typeList<
      string<char, 'O', 'S', 'D', '_', 'E', 'B', 'C', 'D', 'I', 'C', '_', 'D', 'F', '0', '3', '_', 'I', 'R', 'V'>,
      string<char, 'c', 's', 'O', 'S', 'D', 'E', 'B', 'C', 'D', 'I', 'C', 'D', 'F', '0', '3', 'I', 'R', 'V'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'O', 'S', 'D', 'E', 'B', 'C', 'D', 'I', 'C', 'D', 'F', '0', '3', 'I', 'R', 'V'> >
 : textEncodingType<text_encoding_id_OSDEBCDICDF03IRV_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'O', 'S', 'D', '_', 'E', 'B', 'C', 'D', 'I', 'C', '_', 'D', 'F', '0', '3', '_', 'I', 'R', 'V'> >
 : textEncodingType<text_encoding_id_OSDEBCDICDF03IRV_t>
 {
 };
}
#endif
