#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_VENTURAUSTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_VENTURAUSTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_VenturaUS_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: VenturaUS>;

 template <>
 struct textEncodingType<text_encoding_id_VenturaUS_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_VenturaUS_t;
  using name = string<char, 'V', 'e', 'n', 't', 'u', 'r', 'a', '-', 'U', 'S'>;
  using aliases = typeList<
      string<char, 'V', 'e', 'n', 't', 'u', 'r', 'a', '-', 'U', 'S'>,
      string<char, 'c', 's', 'V', 'e', 'n', 't', 'u', 'r', 'a', 'U', 'S'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'V', 'e', 'n', 't', 'u', 'r', 'a', 'U', 'S'> >
 : textEncodingType<text_encoding_id_VenturaUS_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'V', 'e', 'n', 't', 'u', 'r', 'a', '-', 'U', 'S'> >
 : textEncodingType<text_encoding_id_VenturaUS_t>
 {
 };
}
#endif
