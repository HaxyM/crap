#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ADOBESTANDARDENCODINGTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ADOBESTANDARDENCODINGTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_AdobeStandardEncoding_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: AdobeStandardEncoding>;

 template <>
 struct textEncodingType<text_encoding_id_AdobeStandardEncoding_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_AdobeStandardEncoding_t;
  using name = string<char, 'A', 'd', 'o', 'b', 'e', '-', 'S', 't', 'a', 'n', 'd', 'a', 'r', 'd', '-', 'E', 'n', 'c', 'o', 'd', 'i', 'n', 'g'>;
  using aliases = typeList<
      string<char, 'A', 'd', 'o', 'b', 'e', '-', 'S', 't', 'a', 'n', 'd', 'a', 'r', 'd', '-', 'E', 'n', 'c', 'o', 'd', 'i', 'n', 'g'>,
      string<char, 'c', 's', 'A', 'd', 'o', 'b', 'e', 'S', 't', 'a', 'n', 'd', 'a', 'r', 'd', 'E', 'n', 'c', 'o', 'd', 'i', 'n', 'g'> >;
 };

 template <>
 struct textEncodingType<string<char, 'A', 'd', 'o', 'b', 'e', '-', 'S', 't', 'a', 'n', 'd', 'a', 'r', 'd', '-', 'E', 'n', 'c', 'o', 'd', 'i', 'n', 'g'> >
 : textEncodingType<text_encoding_id_AdobeStandardEncoding_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'A', 'd', 'o', 'b', 'e', 'S', 't', 'a', 'n', 'd', 'a', 'r', 'd', 'E', 'n', 'c', 'o', 'd', 'i', 'n', 'g'> >
 : textEncodingType<text_encoding_id_AdobeStandardEncoding_t>
 {
 };
}
#endif
