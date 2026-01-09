#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_DECMCSTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_DECMCSTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_DECMCS_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: DECMCS>;

 template <>
 struct textEncodingType<text_encoding_id_DECMCS_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_DECMCS_t;
  using name = string<char, 'D', 'E', 'C', '-', 'M', 'C', 'S'>;
  using aliases = typeList<
      string<char, 'D', 'E', 'C', '-', 'M', 'C', 'S'>,
      string<char, 'd', 'e', 'c'>,
      string<char, 'c', 's', 'D', 'E', 'C', 'M', 'C', 'S'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'D', 'E', 'C', 'M', 'C', 'S'> >
 : textEncodingType<text_encoding_id_DECMCS_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'd', 'e', 'c'> >
 : textEncodingType<text_encoding_id_DECMCS_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'D', 'E', 'C', '-', 'M', 'C', 'S'> >
 : textEncodingType<text_encoding_id_DECMCS_t>
 {
 };
}
#endif
