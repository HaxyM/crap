#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_GBKTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_GBKTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_GBK_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: GBK>;

 template <>
 struct textEncodingType<text_encoding_id_GBK_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_GBK_t;
  using name = string<char, 'G', 'B', 'K'>;
  using aliases = typeList<
      string<char, 'G', 'B', 'K'>,
      string<char, 'C', 'P', '9', '3', '6'>,
      string<char, 'M', 'S', '9', '3', '6'>,
      string<char, 'w', 'i', 'n', 'd', 'o', 'w', 's', '-', '9', '3', '6'>,
      string<char, 'c', 's', 'G', 'B', 'K'> >;
 };

 template <>
 struct textEncodingType<string<char, 'C', 'P', '9', '3', '6'> >
 : textEncodingType<text_encoding_id_GBK_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'G', 'B', 'K'> >
 : textEncodingType<text_encoding_id_GBK_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'G', 'B', 'K'> >
 : textEncodingType<text_encoding_id_GBK_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'M', 'S', '9', '3', '6'> >
 : textEncodingType<text_encoding_id_GBK_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'w', 'i', 'n', 'd', 'o', 'w', 's', '-', '9', '3', '6'> >
 : textEncodingType<text_encoding_id_GBK_t>
 {
 };
}
#endif
