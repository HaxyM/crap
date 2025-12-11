#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_DKUSTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_DKUSTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_DKUS_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: DKUS>;

 template <>
 struct textEncodingType<text_encoding_id_DKUS_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_DKUS_t;
  using name = string<char, 'd', 'k', '-', 'u', 's'>;
  using aliases = typeList<
      string<char, 'd', 'k', '-', 'u', 's'>,
      string<char, 'c', 's', 'D', 'K', 'U', 'S'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'D', 'K', 'U', 'S'> >
 : textEncodingType<text_encoding_id_DKUS_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'd', 'k', '-', 'u', 's'> >
 : textEncodingType<text_encoding_id_DKUS_t>
 {
 };
}
#endif
