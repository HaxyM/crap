#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM500TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM500TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM500_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM500>;

 template <>
 struct textEncodingType<text_encoding_id_IBM500_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM500_t;
  using name = string<char, 'I', 'B', 'M', '5', '0', '0'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '5', '0', '0'>,
      string<char, 'C', 'P', '5', '0', '0'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'b', 'e'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'c', 'h'>,
      string<char, 'c', 's', 'I', 'B', 'M', '5', '0', '0'> >;
 };

 template <>
 struct textEncodingType<string<char, 'C', 'P', '5', '0', '0'> >
 : textEncodingType<text_encoding_id_IBM500_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '5', '0', '0'> >
 : textEncodingType<text_encoding_id_IBM500_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'b', 'e'> >
 : textEncodingType<text_encoding_id_IBM500_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'c', 'h'> >
 : textEncodingType<text_encoding_id_IBM500_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '5', '0', '0'> >
 : textEncodingType<text_encoding_id_IBM500_t>
 {
 };
}
#endif
