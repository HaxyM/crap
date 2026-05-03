#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_VIQRTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_VIQRTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_VIQR_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: VIQR>;

 template <>
 struct textEncodingType<text_encoding_id_VIQR_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_VIQR_t;
  using name = string<char, 'V', 'I', 'Q', 'R'>;
  using aliases = typeList<
      string<char, 'V', 'I', 'Q', 'R'>,
      string<char, 'c', 's', 'V', 'I', 'Q', 'R'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'V', 'I', 'Q', 'R'> >
 : textEncodingType<text_encoding_id_VIQR_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'V', 'I', 'Q', 'R'> >
 : textEncodingType<text_encoding_id_VIQR_t>
 {
 };
}
#endif
