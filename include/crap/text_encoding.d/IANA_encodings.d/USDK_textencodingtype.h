#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_USDKTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_USDKTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_USDK_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: USDK>;

 template <>
 struct textEncodingType<text_encoding_id_USDK_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_USDK_t;
  using name = string<char, 'u', 's', '-', 'd', 'k'>;
  using aliases = typeList<
      string<char, 'u', 's', '-', 'd', 'k'>,
      string<char, 'c', 's', 'U', 'S', 'D', 'K'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'U', 'S', 'D', 'K'> >
 : textEncodingType<text_encoding_id_USDK_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'u', 's', '-', 'd', 'k'> >
 : textEncodingType<text_encoding_id_USDK_t>
 {
 };
}
#endif
