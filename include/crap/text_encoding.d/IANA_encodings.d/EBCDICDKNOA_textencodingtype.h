#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_EBCDICDKNOATEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_EBCDICDKNOATEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_EBCDICDKNOA_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: EBCDICDKNOA>;

 template <>
 struct textEncodingType<text_encoding_id_EBCDICDKNOA_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_EBCDICDKNOA_t;
  using name = string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'D', 'K', '-', 'N', 'O', '-', 'A'>;
  using aliases = typeList<
      string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'D', 'K', '-', 'N', 'O', '-', 'A'>,
      string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'D', 'K', 'N', 'O', 'A'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'D', 'K', 'N', 'O', 'A'> >
 : textEncodingType<text_encoding_id_EBCDICDKNOA_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'D', 'K', '-', 'N', 'O', '-', 'A'> >
 : textEncodingType<text_encoding_id_EBCDICDKNOA_t>
 {
 };
}
#endif
