#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_EBCDICDKNOTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_EBCDICDKNOTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_EBCDICDKNO_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: EBCDICDKNO>;

 template <>
 struct textEncodingType<text_encoding_id_EBCDICDKNO_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_EBCDICDKNO_t;
  using name = string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'D', 'K', '-', 'N', 'O'>;
  using aliases = typeList<
      string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'D', 'K', '-', 'N', 'O'>,
      string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'D', 'K', 'N', 'O'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'D', 'K', 'N', 'O'> >
 : textEncodingType<text_encoding_id_EBCDICDKNO_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'D', 'K', '-', 'N', 'O'> >
 : textEncodingType<text_encoding_id_EBCDICDKNO_t>
 {
 };
}
#endif
