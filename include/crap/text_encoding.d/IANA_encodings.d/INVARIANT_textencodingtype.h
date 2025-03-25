#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_INVARIANTTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_INVARIANTTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_INVARIANT_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: INVARIANT>;

 template <>
 struct textEncodingType<text_encoding_id_INVARIANT_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_INVARIANT_t;
  using name = string<char, 'I', 'N', 'V', 'A', 'R', 'I', 'A', 'N', 'T'>;
  using aliases = typeList<
  	  string<char, 'I', 'N', 'V', 'A', 'R', 'I', 'A', 'N', 'T'>,
	  string<char, 'c', 's', 'I', 'N', 'V', 'A', 'R', 'I', 'A', 'N', 'T'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'N', 'V', 'A', 'R', 'I', 'A', 'N', 'T'> >
 : textEncodingType<text_encoding_id_INVARIANT_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'N', 'V', 'A', 'R', 'I', 'A', 'N', 'T'> >
 : textEncodingType<text_encoding_id_INVARIANT_t>
 {
 };
}
#endif
