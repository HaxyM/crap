#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_EBCDICESATEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_EBCDICESATEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_EBCDICESA_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: EBCDICESA>;

 template <>
 struct textEncodingType<text_encoding_id_EBCDICESA_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_EBCDICESA_t;
  using name = string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'E', 'S', '-', 'A'>;
  using aliases = typeList<
      string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'E', 'S', '-', 'A'>,
      string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'E', 'S', 'A'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'E', 'S', 'A'> >
 : textEncodingType<text_encoding_id_EBCDICESA_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'E', 'S', '-', 'A'> >
 : textEncodingType<text_encoding_id_EBCDICESA_t>
 {
 };
}
#endif
