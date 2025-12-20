#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_UTF32BETEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_UTF32BETEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_UTF32BE_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: UTF32BE>;

 template <>
 struct textEncodingType<text_encoding_id_UTF32BE_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_UTF32BE_t;
  using name = string<char, 'U', 'T', 'F', '-', '3', '2', 'B', 'E'>;
  using aliases = typeList<
      string<char, 'U', 'T', 'F', '-', '3', '2', 'B', 'E'>,
      string<char, 'c', 's', 'U', 'T', 'F', '3', '2', 'B', 'E'> >;
 };

 template <>
 struct textEncodingType<string<char, 'U', 'T', 'F', '-', '3', '2', 'B', 'E'> >
 : textEncodingType<text_encoding_id_UTF32BE_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'U', 'T', 'F', '3', '2', 'B', 'E'> >
 : textEncodingType<text_encoding_id_UTF32BE_t>
 {
 };
}
#endif
