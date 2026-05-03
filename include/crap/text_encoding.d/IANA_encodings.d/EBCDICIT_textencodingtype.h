#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_EBCDICITTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_EBCDICITTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_EBCDICIT_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: EBCDICIT>;

 template <>
 struct textEncodingType<text_encoding_id_EBCDICIT_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_EBCDICIT_t;
  using name = string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'I', 'T'>;
  using aliases = typeList<
      string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'I', 'T'>,
      string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'I', 'T'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'I', 'T'> >
 : textEncodingType<text_encoding_id_EBCDICIT_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'I', 'T'> >
 : textEncodingType<text_encoding_id_EBCDICIT_t>
 {
 };
}
#endif
