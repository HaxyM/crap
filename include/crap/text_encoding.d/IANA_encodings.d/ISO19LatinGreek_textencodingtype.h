#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO19LATINGREEKTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO19LATINGREEKTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO19LatinGreek_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO19LatinGreek>;

 template <>
 struct textEncodingType<text_encoding_id_ISO19LatinGreek_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO19LatinGreek_t;
  using name = string<char, 'l', 'a', 't', 'i', 'n', '-', 'g', 'r', 'e', 'e', 'k'>;
  using aliases = typeList<
      string<char, 'l', 'a', 't', 'i', 'n', '-', 'g', 'r', 'e', 'e', 'k'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '9'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '1', '9', 'L', 'a', 't', 'i', 'n', 'G', 'r', 'e', 'e', 'k'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '9', 'L', 'a', 't', 'i', 'n', 'G', 'r', 'e', 'e', 'k'> >
 : textEncodingType<text_encoding_id_ISO19LatinGreek_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '9'> >
 : textEncodingType<text_encoding_id_ISO19LatinGreek_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'l', 'a', 't', 'i', 'n', '-', 'g', 'r', 'e', 'e', 'k'> >
 : textEncodingType<text_encoding_id_ISO19LatinGreek_t>
 {
 };
}
#endif
