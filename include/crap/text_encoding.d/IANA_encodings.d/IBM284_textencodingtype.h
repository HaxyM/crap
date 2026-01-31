#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM284TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM284TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM284_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM284>;

 template <>
 struct textEncodingType<text_encoding_id_IBM284_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM284_t;
  using name = string<char, 'I', 'B', 'M', '2', '8', '4'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '2', '8', '4'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'e', 's'>,
      string<char, 'C', 'P', '2', '8', '4'>,
      string<char, 'c', 's', 'I', 'B', 'M', '2', '8', '4'> >;
 };

 template <>
 struct textEncodingType<string<char, 'C', 'P', '2', '8', '4'> >
 : textEncodingType<text_encoding_id_IBM284_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '2', '8', '4'> >
 : textEncodingType<text_encoding_id_IBM284_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'e', 's'> >
 : textEncodingType<text_encoding_id_IBM284_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '2', '8', '4'> >
 : textEncodingType<text_encoding_id_IBM284_t>
 {
 };
}
#endif
