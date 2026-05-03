#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_KOI8RTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_KOI8RTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_KOI8R_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: KOI8R>;

 template <>
 struct textEncodingType<text_encoding_id_KOI8R_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_KOI8R_t;
  using name = string<char, 'K', 'O', 'I', '8', '-', 'R'>;
  using aliases = typeList<
      string<char, 'K', 'O', 'I', '8', '-', 'R'>,
      string<char, 'c', 's', 'K', 'O', 'I', '8', 'R'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'K', 'O', 'I', '8', 'R'> >
 : textEncodingType<text_encoding_id_KOI8R_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'K', 'O', 'I', '8', '-', 'R'> >
 : textEncodingType<text_encoding_id_KOI8R_t>
 {
 };
}
#endif
