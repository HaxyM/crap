#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_WINDOWS31JTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_WINDOWS31JTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_Windows31J_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: Windows31J>;

 template <>
 struct textEncodingType<text_encoding_id_Windows31J_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_Windows31J_t;
  using name = string<char, 'W', 'i', 'n', 'd', 'o', 'w', 's', '-', '3', '1', 'J'>;
  using aliases = typeList<
      string<char, 'W', 'i', 'n', 'd', 'o', 'w', 's', '-', '3', '1', 'J'>,
      string<char, 'c', 's', 'W', 'i', 'n', 'd', 'o', 'w', 's', '3', '1', 'J'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'W', 'i', 'n', 'd', 'o', 'w', 's', '3', '1', 'J'> >
 : textEncodingType<text_encoding_id_Windows31J_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'W', 'i', 'n', 'd', 'o', 'w', 's', '-', '3', '1', 'J'> >
 : textEncodingType<text_encoding_id_Windows31J_t>
 {
 };
}
#endif
