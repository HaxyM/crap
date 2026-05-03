#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_EBCDICESSTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_EBCDICESSTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_EBCDICESS_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: EBCDICESS>;

 template <>
 struct textEncodingType<text_encoding_id_EBCDICESS_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_EBCDICESS_t;
  using name = string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'E', 'S', '-', 'S'>;
  using aliases = typeList<
      string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'E', 'S', '-', 'S'>,
      string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'E', 'S', 'S'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'E', 'S', 'S'> >
 : textEncodingType<text_encoding_id_EBCDICESS_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'E', 'S', '-', 'S'> >
 : textEncodingType<text_encoding_id_EBCDICESS_t>
 {
 };
}
#endif
