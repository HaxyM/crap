#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_KOI8UTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_KOI8UTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_KOI8U_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: KOI8U>;

 template <>    
 struct textEncodingType<text_encoding_id_KOI8U_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_KOI8U_t;
  using name = string<char, 'K', 'O', 'I', '8', '-', 'U'>;
  using aliases = typeList<
      string<char, 'K', 'O', 'I', '8', '-', 'U'>,
      string<char, 'c', 's', 'K', 'O', 'I', '8', 'U'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'K', 'O', 'I', '8', 'U'> >
 : textEncodingType<text_encoding_id_KOI8U_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'K', 'O', 'I', '8', '-', 'U'> >
 : textEncodingType<text_encoding_id_KOI8U_t>
 {
 };
}
#endif
