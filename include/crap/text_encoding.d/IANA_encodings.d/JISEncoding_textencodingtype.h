#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_JISENCODINGTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_JISENCODINGTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_JISEncoding_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: JISEncoding>;

 template <>
 struct textEncodingType<text_encoding_id_JISEncoding_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_JISEncoding_t;
  using name = string<char, 'J', 'I', 'S', '_', 'E', 'n', 'c', 'o', 'd', 'i', 'n', 'g'>;
  using aliases = typeList<
	  string<char, 'J', 'I', 'S', '_', 'E', 'n', 'c', 'o', 'd', 'i', 'n', 'g'>,
      string<char, 'c', 's', 'J', 'I', 'S', 'E', 'n', 'c', 'o', 'd', 'i', 'n', 'g'> >;
	  
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'J', 'I', 'S', 'E', 'n', 'c', 'o', 'd', 'i', 'n', 'g'> >
 : textEncodingType<text_encoding_id_JISEncoding_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'J', 'I', 'S', '_', 'E', 'n', 'c', 'o', 'd', 'i', 'n', 'g'> >
 : textEncodingType<text_encoding_id_JISEncoding_t>
 {
 };
}
#endif
