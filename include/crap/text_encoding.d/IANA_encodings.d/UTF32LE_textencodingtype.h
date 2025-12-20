#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_UTF32LETEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_UTF32LETEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_UTF32LE_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: UTF32LE>;

 template <>
 struct textEncodingType<text_encoding_id_UTF32LE_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_UTF32LE_t;
  using name = string<char, 'U', 'T', 'F', '-', '3', '2', 'L', 'E'>;
  using aliases = typeList<
      string<char, 'U', 'T', 'F', '-', '3', '2', 'L', 'E'>,
      string<char, 'c', 's', 'U', 'T', 'F', '3', '2', 'L', 'E'> >;
 };

 template <>
 struct textEncodingType<string<char, 'U', 'T', 'F', '-', '3', '2', 'L', 'E'> >
 : textEncodingType<text_encoding_id_UTF32LE_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'U', 'T', 'F', '3', '2', 'L', 'E'> >
 : textEncodingType<text_encoding_id_UTF32LE_t>
 {
 };
}
#endif
