#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_EBCDICATDEATEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_EBCDICATDEATEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_EBCDICATDEA_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: EBCDICATDEA>;

 template <>
 struct textEncodingType<text_encoding_id_EBCDICATDEA_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_EBCDICATDEA_t;
  using name = string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'A', 'T', '-', 'D', 'E', '-', 'A'>;
  using aliases = typeList<
      string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'A', 'T', '-', 'D', 'E', '-', 'A'>,
      string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'A', 'T', 'D', 'E', 'A'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'A', 'T', 'D', 'E', 'A'> >
 : textEncodingType<text_encoding_id_EBCDICATDEA_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'A', 'T', '-', 'D', 'E', '-', 'A'> >
 : textEncodingType<text_encoding_id_EBCDICATDEA_t>
 {
 };
}
#endif
