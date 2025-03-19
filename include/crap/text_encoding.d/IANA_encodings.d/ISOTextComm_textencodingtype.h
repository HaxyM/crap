#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISOTEXTCOMMTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISOTEXTCOMMTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISOTextComm_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISOTextComm>;

 template <>
 struct textEncodingType<text_encoding_id_ISOTextComm_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISOLTextComm_t;
  using name = string<char, 'I', 'S', 'O', '_', '6', '9', '3', '7', '-', '2', '-', 'a', 'd', 'd'>;
  using aliases = typeList<
	  string<char, 'I', 'S', 'O', '_', '6', '9', '3', '7', '-', '2', '-', 'a', 'd', 'd'>,
	  string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '4', '2'>,
      string<char, 'c', 's', 'I', 'S', 'O', 'T', 'e', 'x', 't', 'C', 'o', 'm', 'm'> >;
	  
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', 'T', 'e', 'x', 't', 'C', 'o', 'm', 'm'> >
 : textEncodingType<text_encoding_id_ISOTextComm_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '_', '6', '9', '3', '7', '-', '2', '-', 'a', 'd', 'd'> >
 : textEncodingType<text_encoding_id_ISOTextComm_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '4', '2'> >
 : textEncodingType<text_encoding_id_ISOTextComm_t>
 {
 };
}
#endif
