#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_UTF7TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_UTF7TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_UTF7_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: UTF7>;

 template <>
 struct textEncodingType<text_encoding_id_UTF7_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_UTF7_t;
  using name = string<char, 'U', 'T', 'F', '-', '7'>;
  using aliases = typeList<
      string<char, 'U', 'T', 'F', '-', '7'>,
      string<char, 'c', 's', 'U', 'T', 'F', '7'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'U', 'T', 'F', '7'> >
 : textEncodingType<text_encoding_id_UTF7_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'U', 'T', 'F', '-', '7'> >
 : textEncodingType<text_encoding_id_UTF7_t>
 {
 };
}
#endif
