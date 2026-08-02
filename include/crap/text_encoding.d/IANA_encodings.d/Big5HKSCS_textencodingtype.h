#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_BIG5HKSCSTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_BIG5HKSCSTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_Big5HKSCS_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: Big5HKSCS>;

 template <>    
 struct textEncodingType<text_encoding_id_Big5HKSCS_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_Big5HKSCS_t;
  using name = string<char, 'B', 'i', 'g', '5', '-', 'H', 'K', 'S', 'C', 'S'>;
  using aliases = typeList<
      string<char, 'B', 'i', 'g', '5', '-', 'H', 'K', 'S', 'C', 'S'>,
      string<char, 'c', 's', 'B', 'i', 'g', '5', 'H', 'K', 'S', 'C', 'S'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'B', 'i', 'g', '5', 'H', 'K', 'S', 'C', 'S'> >
 : textEncodingType<text_encoding_id_Big5HKSCS_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'B', 'i', 'g', '5', '-', 'H', 'K', 'S', 'C', 'S'> >
 : textEncodingType<text_encoding_id_Big5HKSCS_t>
 {
 };
}
#endif
