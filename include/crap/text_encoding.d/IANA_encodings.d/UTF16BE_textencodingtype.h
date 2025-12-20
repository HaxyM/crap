#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_UTF16BETEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_UTF16BETEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_UTF16BE_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: UTF16BE>;

 template <>
 struct textEncodingType<text_encoding_id_UTF16BE_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_UTF16BE_t;
  using name = string<char, 'U', 'T', 'F', '-', '1', '6', 'B', 'E'>;
  using aliases = typeList<
      string<char, 'U', 'T', 'F', '-', '1', '6', 'B', 'E'>,
      string<char, 'c', 's', 'U', 'T', 'F', '1', '6', 'B', 'E'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'U', 'T', 'F', '1', '6', 'B', 'E'> >
 : textEncodingType<text_encoding_id_UTF16BE_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'U', 'T', 'F', '-', '1', '6', 'B', 'E'> >
 : textEncodingType<text_encoding_id_UTF16BE_t>
 {
 };
}
#endif
