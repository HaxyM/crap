#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_MACINTOSHTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_MACINTOSHTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_Macintosh_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: Macintosh>;

 template <>
 struct textEncodingType<text_encoding_id_Macintosh_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_Macintosh_t;
  using name = string<char, 'm', 'a', 'c', 'i', 'n', 't', 'o', 's', 'h'>;
  using aliases = typeList<
      string<char, 'm', 'a', 'c', 'i', 'n', 't', 'o', 's', 'h'>,
      string<char, 'm', 'a', 'c'>,
      string<char, 'c', 's', 'M', 'a', 'c', 'i', 'n', 't', 'o', 's', 'h'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'M', 'a', 'c', 'i', 'n', 't', 'o', 's', 'h'> >
 : textEncodingType<text_encoding_id_Macintosh_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'm', 'a', 'c'> >
 : textEncodingType<text_encoding_id_Macintosh_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'm', 'a', 'c', 'i', 'n', 't', 'o', 's', 'h'> >
 : textEncodingType<text_encoding_id_Macintosh_t>
 {
 };
}
#endif
