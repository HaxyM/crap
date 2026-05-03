#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_EBCDICFRTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_EBCDICFRTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_EBCDICFR_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: EBCDICFR>;

 template <>
 struct textEncodingType<text_encoding_id_EBCDICFR_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_EBCDICFR_t;
  using name = string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'F', 'R'>;
  using aliases = typeList<
      string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'F', 'R'>,
      string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'F', 'R'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'F', 'R'> >
 : textEncodingType<text_encoding_id_EBCDICFR_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'F', 'R'> >
 : textEncodingType<text_encoding_id_EBCDICFR_t>
 {
 };
}
#endif
