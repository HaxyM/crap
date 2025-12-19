#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_GB18030TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_GB18030TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_GB18030_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: GB18030>;

 template <>
 struct textEncodingType<text_encoding_id_GB18030_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_GB18030_t;
  using name = string<char, 'G', 'B', '1', '8', '0', '3', '0'>;
  using aliases = typeList<
      string<char, 'G', 'B', '1', '8', '0', '3', '0'>,
      string<char, 'c', 's', 'G', 'B', '1', '8', '0', '3', '0'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'G', 'B', '1', '8', '0', '3', '0'> >
 : textEncodingType<text_encoding_id_GB18030_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'G', 'B', '1', '8', '0', '3', '0'> >
 : textEncodingType<text_encoding_id_GB18030_t>
 {
 };
}
#endif
