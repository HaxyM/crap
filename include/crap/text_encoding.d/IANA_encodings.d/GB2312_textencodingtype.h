#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_GB2312TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_GB2312TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_GB2312_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: GB2312>;

 template <>
 struct textEncodingType<text_encoding_id_GB2312_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_GB2312_t;
  using name = string<char, 'G', 'B', '2', '3', '1', '2'>;
  using aliases = typeList<
      string<char, 'G', 'B', '2', '3', '1', '2'>,
      string<char, 'c', 's', 'G', 'B', '2', '3', '1', '2'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'G', 'B', '2', '3', '1', '2'> >
 : textEncodingType<text_encoding_id_GB2312_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'G', 'B', '2', '3', '1', '2'> >
 : textEncodingType<text_encoding_id_GB2312_t>
 {
 };
}
#endif
