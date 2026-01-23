#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_PC8TURKISHTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_PC8TURKISHTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_PC8Turkish_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: PC8Turkish>;

 template <>
 struct textEncodingType<text_encoding_id_PC8Turkish_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_PC8Turkish_t;
  using name = string<char, 'P', 'C', '8', '-', 'T', 'u', 'r', 'k', 'i', 's', 'h'>;
  using aliases = typeList<
      string<char, 'P', 'C', '8', '-', 'T', 'u', 'r', 'k', 'i', 's', 'h'>,
      string<char, 'c', 's', 'P', 'C', '8', 'T', 'u', 'r', 'k', 'i', 's', 'h'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'P', 'C', '8', 'T', 'u', 'r', 'k', 'i', 's', 'h'> >
 : textEncodingType<text_encoding_id_PC8Turkish_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'P', 'C', '8', '-', 'T', 'u', 'r', 'k', 'i', 's', 'h'> >
 : textEncodingType<text_encoding_id_PC8Turkish_t>
 {
 };
}
#endif
