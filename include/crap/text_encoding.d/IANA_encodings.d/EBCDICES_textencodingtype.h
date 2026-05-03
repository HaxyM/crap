#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_EBCDICESTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_EBCDICESTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_EBCDICES_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: EBCDICES>;

 template <>
 struct textEncodingType<text_encoding_id_EBCDICES_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_EBCDICES_t;
  using name = string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'E', 'S'>;
  using aliases = typeList<
      string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'E', 'S'>,
      string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'E', 'S'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'E', 'S'> >
 : textEncodingType<text_encoding_id_EBCDICES_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'E', 'S'> >
 : textEncodingType<text_encoding_id_EBCDICES_t>
 {
 };
}
#endif
