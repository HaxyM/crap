#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_EBCDICPTTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_EBCDICPTTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_EBCDICPT_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: EBCDICPT>;

 template <>
 struct textEncodingType<text_encoding_id_EBCDICPT_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_EBCDICPT_t;
  using name = string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'P', 'T'>;
  using aliases = typeList<
      string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'P', 'T'>,
      string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'P', 'T'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'P', 'T'> >
 : textEncodingType<text_encoding_id_EBCDICPT_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'P', 'T'> >
 : textEncodingType<text_encoding_id_EBCDICPT_t>
 {
 };
}
#endif
