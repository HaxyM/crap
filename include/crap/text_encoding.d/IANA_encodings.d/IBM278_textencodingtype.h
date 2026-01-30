#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM278TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM278TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM278_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM278>;

 template <>
 struct textEncodingType<text_encoding_id_IBM278_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM278_t;
  using name = string<char, 'I', 'B', 'M', '2', '7', '8'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '2', '7', '8'>,
      string<char, 'C', 'P', '2', '7', '8'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'f', 'i'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 's', 'e'>,
      string<char, 'c', 's', 'I', 'B', 'M', '2', '7', '8'> >;
 };

 template <>
 struct textEncodingType<string<char, 'C', 'P', '2', '7', '8'> >
 : textEncodingType<text_encoding_id_IBM278_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '2', '7', '8'> >
 : textEncodingType<text_encoding_id_IBM278_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'f', 'i'> >
 : textEncodingType<text_encoding_id_IBM278_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 's', 'e'> >
 : textEncodingType<text_encoding_id_IBM278_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '2', '7', '8'> >
 : textEncodingType<text_encoding_id_IBM278_t>
 {
 };
}
#endif
