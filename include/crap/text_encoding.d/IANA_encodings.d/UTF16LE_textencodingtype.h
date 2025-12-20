#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_UTF16LETEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_UTF16LETEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_UTF16LE_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: UTF16LE>;

 template <>
 struct textEncodingType<text_encoding_id_UTF16LE_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_UTF16LE_t;
  using name = string<char, 'U', 'T', 'F', '-', '1', '6', 'L', 'E'>;
  using aliases = typeList<
      string<char, 'U', 'T', 'F', '-', '1', '6', 'L', 'E'>,
      string<char, 'c', 's', 'U', 'T', 'F', '1', '6', 'L', 'E'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'U', 'T', 'F', '1', '6', 'L', 'E'> >
 : textEncodingType<text_encoding_id_UTF16LE_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'U', 'T', 'F', '-', '1', '6', 'L', 'E'> >
 : textEncodingType<text_encoding_id_UTF16LE_t>
 {
 };
}
#endif
