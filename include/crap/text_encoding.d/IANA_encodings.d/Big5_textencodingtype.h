#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_BIG5TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_BIG5TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_Big5_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: Big5>;

 template <>
 struct textEncodingType<text_encoding_id_Big5_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_Big5_t;
  using name = string<char, 'B', 'i', 'g', '5'>;
  using aliases = typeList<
      string<char, 'B', 'i', 'g', '5'>,
      string<char, 'c', 's', 'B', 'i', 'g', '5'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'B', 'i', 'g', '5'> >
 : textEncodingType<text_encoding_id_Big5_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'B', 'i', 'g', '5'> >
 : textEncodingType<text_encoding_id_Big5_t>
 {
 };
}
#endif
