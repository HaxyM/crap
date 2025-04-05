#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_EUCKRTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_EUCKRTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_EUCKR_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: EUCKR>;

 template <>
 struct textEncodingType<text_encoding_id_EUCKR_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_EUCKR_t;
  using name = string<char, 'E', 'U', 'C', '-', 'K', 'R'>;
  using aliases = typeList<
  	  string<char, 'E', 'U', 'C', '-', 'K', 'R'>,
	  string<char, 'c', 's', 'E', 'U', 'C', 'K', 'R'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'E', 'U', 'C', 'K', 'R'> >
 : textEncodingType<text_encoding_id_EUCKR_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'U', 'C', '-', 'K', 'R'> >
 : textEncodingType<text_encoding_id_EUCKR_t>
 {
 };
}
#endif
