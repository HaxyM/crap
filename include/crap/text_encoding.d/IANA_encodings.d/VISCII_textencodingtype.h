#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_VISCIITEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_VISCIITEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_VISCII_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: VISCII>;

 template <>
 struct textEncodingType<text_encoding_id_VISCII_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_VISCII_t;
  using name = string<char, 'V', 'I', 'S', 'C', 'I', 'I'>;
  using aliases = typeList<
      string<char, 'V', 'I', 'S', 'C', 'I', 'I'>,
      string<char, 'c', 's', 'V', 'I', 'S', 'C', 'I', 'I'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'V', 'I', 'S', 'C', 'I', 'I'> >
 : textEncodingType<text_encoding_id_VISCII_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'V', 'I', 'S', 'C', 'I', 'I'> >
 : textEncodingType<text_encoding_id_VISCII_t>
 {
 };
}
#endif
