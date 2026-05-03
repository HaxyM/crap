#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_EBCDICFISEATEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_EBCDICFISEATEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_EBCDICFISEA_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: EBCDICFISEA>;

 template <>
 struct textEncodingType<text_encoding_id_EBCDICFISEA_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_EBCDICFISEA_t;
  using name = string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'F', 'I', '-', 'S', 'E', '-', 'A'>;
  using aliases = typeList<
      string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'F', 'I', '-', 'S', 'E', '-', 'A'>,
      string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'F', 'I', 'S', 'E', 'A'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'F', 'I', 'S', 'E', 'A'> >
 : textEncodingType<text_encoding_id_EBCDICFISEA_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'F', 'I', '-', 'S', 'E', '-', 'A'> >
 : textEncodingType<text_encoding_id_EBCDICFISEA_t>
 {
 };
}
#endif
