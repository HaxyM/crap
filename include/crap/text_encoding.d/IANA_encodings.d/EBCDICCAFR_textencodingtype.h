#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_EBCDICCAFRTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_EBCDICCAFRTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_EBCDICCAFR_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: EBCDICCAFR>;

 template <>
 struct textEncodingType<text_encoding_id_EBCDICCAFR_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_EBCDICCAFR_t;
  using name = string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'C', 'A', '-', 'F', 'R'>;
  using aliases = typeList<
      string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'C', 'A', '-', 'F', 'R'>,
      string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'C', 'A', 'F', 'R'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'E', 'B', 'C', 'D', 'I', 'C', 'C', 'A', 'F', 'R'> >
 : textEncodingType<text_encoding_id_EBCDICCAFR_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'C', 'A', '-', 'F', 'R'> >
 : textEncodingType<text_encoding_id_EBCDICCAFR_t>
 {
 };
}
#endif
