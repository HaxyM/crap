#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_EBCDICFISETEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_EBCDICFISETEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_EBCDICFISE_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: EBCDICFISE>;

 template <>
 struct textEncodingType<text_encoding_id_EBCDICFISE_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_EBCDICFISE_t;
  using name = string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'F', 'I', '-', 'S', 'E'>;
  using aliases = typeList<
      string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'F', 'I', '-', 'S', 'E'>,
      string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'F', 'I', 'S', 'E'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'F', 'I', 'S', 'E'> >
 : textEncodingType<text_encoding_id_EBCDICFISE_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'F', 'I', '-', 'S', 'E'> >
 : textEncodingType<text_encoding_id_EBCDICFISE_t>
 {
 };
}
#endif
