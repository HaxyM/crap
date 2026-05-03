#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_EBCDICUSTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_EBCDICUSTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_EBCDICUS_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: EBCDICUS>;

 template <>
 struct textEncodingType<text_encoding_id_EBCDICUS_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_EBCDICUS_t;
  using name = string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'U', 'S'>;
  using aliases = typeList<
      string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'U', 'S'>,
      string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'U', 'S'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'U', 'S'> >
 : textEncodingType<text_encoding_id_EBCDICUS_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'U', 'S'> >
 : textEncodingType<text_encoding_id_EBCDICUS_t>
 {
 };
}
#endif
