#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_NATSSEFIADDTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_NATSSEFIADDTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_NATSSEFIADD_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: NATSSEFIADD>;

 template <>
 struct textEncodingType<text_encoding_id_NATSSEFIADD_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_NATSSEFIADD_t;
  using name = string<char, 'N', 'A', 'T', 'S', '-', 'S', 'E', 'F', 'I', '-', 'A', 'D', 'D'>;
  using aliases = typeList<
  	  string<char, 'N', 'A', 'T', 'S', '-', 'S', 'E', 'F', 'I', '-', 'A', 'D', 'D'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '8', '-', '2'>,
	  string<char, 'c', 's', 'N', 'A', 'T', 'S', 'S', 'E', 'F', 'I', 'A', 'D', 'D'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'N', 'A', 'T', 'S', 'S', 'E', 'F', 'I', 'A', 'D', 'D'> >
 : textEncodingType<text_encoding_id_NATSSEFIADD_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '8', '-', '2'> >
 : textEncodingType<text_encoding_id_NATSSEFIADD_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'N', 'A', 'T', 'S', '-', 'S', 'E', 'F', 'I', '-', 'A', 'D', 'D'> >
 : textEncodingType<text_encoding_id_NATSSEFIADD_t>
 {
 };
}
#endif
