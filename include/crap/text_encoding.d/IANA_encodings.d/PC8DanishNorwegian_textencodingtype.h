#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_PC8DANISHNORWEGIANTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_PC8DANISHNORWEGIANTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_PC8DanishNorwegian_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: PC8DanishNorwegian>;

 template <>
 struct textEncodingType<text_encoding_id_PC8DanishNorwegian_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_PC8DanishNorwegian_t;
  using name = string<char, 'P', 'C', '8', '-', 'D', 'a', 'n', 'i', 's', 'h', '-', 'N', 'o', 'r', 'w', 'e', 'g', 'i', 'a', 'n'>;
  using aliases = typeList<
      string<char, 'P', 'C', '8', '-', 'D', 'a', 'n', 'i', 's', 'h', '-', 'N', 'o', 'r', 'w', 'e', 'g', 'i', 'a', 'n'>,
      string<char, 'c', 's', 'P', 'C', '8', 'D', 'a', 'n', 'i', 's', 'h', 'N', 'o', 'r', 'w', 'e', 'g', 'i', 'a', 'n'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'P', 'C', '8', 'D', 'a', 'n', 'i', 's', 'h', 'N', 'o', 'r', 'w', 'e', 'g', 'i', 'a', 'n'> >
 : textEncodingType<text_encoding_id_PC8DanishNorwegian_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'P', 'C', '8', '-', 'D', 'a', 'n', 'i', 's', 'h', '-', 'N', 'o', 'r', 'w', 'e', 'g', 'i', 'a', 'n'> >
 : textEncodingType<text_encoding_id_PC8DanishNorwegian_t>
 {
 };
}
#endif
