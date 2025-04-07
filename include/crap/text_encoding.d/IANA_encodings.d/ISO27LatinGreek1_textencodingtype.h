#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO27LATINGREEK1TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO27LATINGREEK1TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO27LatinGreek1_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO27LatinGreek1>;

 template <>
 struct textEncodingType<text_encoding_id_ISO27LatinGreek1_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO27LatinGreek1_t;
  using name = string<char, 'L', 'a', 't', 'i', 'n', '-', 'g', 'r', 'e', 'e', 'k', '-', '1'>;
  using aliases = typeList<
      string<char, 'L', 'a', 't', 'i', 'n', '-', 'g', 'r', 'e', 'e', 'k', '-', '1'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '2', '7'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '2', '7', 'L', 'a', 't', 'i', 'n', 'G', 'r', 'e', 'e', 'k', '1'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '2', '7', 'L', 'a', 't', 'i', 'n', 'G', 'r', 'e', 'e', 'k', '1'> >
 : textEncodingType<text_encoding_id_ISO27LatinGreek1_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '2', '7'> >
 : textEncodingType<text_encoding_id_ISO27LatinGreek1_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'L', 'a', 't', 'i', 'n', '-', 'g', 'r', 'e', 'e', 'k', '-', '1'> >
 : textEncodingType<text_encoding_id_ISO27LatinGreek1_t>
 {
 };
}
#endif
