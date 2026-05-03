#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_EBCDICUKTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_EBCDICUKTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_EBCDICUK_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: EBCDICUK>;

 template <>
 struct textEncodingType<text_encoding_id_EBCDICUK_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_EBCDICUK_t;
  using name = string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'U', 'K'>;
  using aliases = typeList<
      string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'U', 'K'>,
      string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'U', 'K'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'U', 'K'> >
 : textEncodingType<text_encoding_id_EBCDICUK_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'U', 'K'> >
 : textEncodingType<text_encoding_id_EBCDICUK_t>
 {
 };
}
#endif
