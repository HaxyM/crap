#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_SCSUTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_SCSUTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_SCSU_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: SCSU>;

 template <>
 struct textEncodingType<text_encoding_id_SCSU_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_SCSU_t;
  using name = string<char, 'S', 'C', 'S', 'U'>;
  using aliases = typeList<
      string<char, 'S', 'C', 'S', 'U'>,
      string<char, 'c', 's', 'S', 'C', 'S', 'U'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'S', 'C', 'S', 'U'> >
 : textEncodingType<text_encoding_id_SCSU_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'S', 'C', 'S', 'U'> >
 : textEncodingType<text_encoding_id_SCSU_t>
 {
 };
}
#endif
