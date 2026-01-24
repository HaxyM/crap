#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_VENTURAMATHTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_VENTURAMATHTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_VenturaMath_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: VenturaMath>;

 template <>
 struct textEncodingType<text_encoding_id_VenturaMath_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_VenturaMath_t;
  using name = string<char, 'V', 'e', 'n', 't', 'u', 'r', 'a', '-', 'M', 'a', 't', 'h'>;
  using aliases = typeList<
      string<char, 'V', 'e', 'n', 't', 'u', 'r', 'a', '-', 'M', 'a', 't', 'h'>,
      string<char, 'c', 's', 'V', 'e', 'n', 't', 'u', 'r', 'a', 'M', 'a', 't', 'h'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'V', 'e', 'n', 't', 'u', 'r', 'a', 'M', 'a', 't', 'h'> >
 : textEncodingType<text_encoding_id_VenturaMath_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'V', 'e', 'n', 't', 'u', 'r', 'a', '-', 'M', 'a', 't', 'h'> >
 : textEncodingType<text_encoding_id_VenturaMath_t>
 {
 };
}
#endif
