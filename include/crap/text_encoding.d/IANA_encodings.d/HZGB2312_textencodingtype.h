#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_HZGB2312TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_HZGB2312TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_HZGB2312_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: HZGB2312>;

 template <>
 struct textEncodingType<text_encoding_id_HZGB2312_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_HZGB2312_t;
  using name = string<char, 'H', 'Z', '-', 'G', 'B', '-', '2', '3', '1', '2'>;
  using aliases = typeList<
      string<char, 'H', 'Z', '-', 'G', 'B', '-', '2', '3', '1', '2'> >;
 };

 template <>
 struct textEncodingType<string<char, 'H', 'Z', '-', 'G', 'B', '-', '2', '3', '1', '2'> >
 : textEncodingType<text_encoding_id_HZGB2312_t>
 {
 };
}
#endif
