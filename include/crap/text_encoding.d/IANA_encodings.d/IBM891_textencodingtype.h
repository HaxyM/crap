#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM891TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM891TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM891_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM891>;

 template <>
 struct textEncodingType<text_encoding_id_IBM891_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM891_t;
  using name = string<char, 'I', 'B', 'M', '8', '9', '1'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '8', '9', '1'>,
      string<char, 'c', 'p', '8', '9', '1'>,
      string<char, 'c', 's', 'I', 'B', 'M', '8', '9', '1'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '8', '9', '1'> >
 : textEncodingType<text_encoding_id_IBM891_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '8', '9', '1'> >
 : textEncodingType<text_encoding_id_IBM891_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '8', '9', '1'> >
 : textEncodingType<text_encoding_id_IBM891_t>
 {
 };
}
#endif
