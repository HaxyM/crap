#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBMEBCDICATDETEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBMEBCDICATDETEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBMEBCDICATDE_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBMEBCDICATDE>;

 template <>
 struct textEncodingType<text_encoding_id_IBMEBCDICATDE_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBMEBCDICATDE_t;
  using name = string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'A', 'T', '-', 'D', 'E'>;
  using aliases = typeList<
      string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'A', 'T', '-', 'D', 'E'>,
      string<char, 'c', 's', 'I', 'B', 'M', 'E', 'B', 'C', 'D', 'I', 'C', 'A', 'T', 'D', 'E'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', 'E', 'B', 'C', 'D', 'I', 'C', 'A', 'T', 'D', 'E'> >
 : textEncodingType<text_encoding_id_IBMEBCDICATDE_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'B', 'C', 'D', 'I', 'C', '-', 'A', 'T', '-', 'D', 'E'> >
 : textEncodingType<text_encoding_id_IBMEBCDICATDE_t>
 {
 };
}
#endif
