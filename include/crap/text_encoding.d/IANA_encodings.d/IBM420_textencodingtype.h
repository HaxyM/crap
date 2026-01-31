#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM420TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM420TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM420_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM420>;

 template <>
 struct textEncodingType<text_encoding_id_IBM420_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM420_t;
  using name = string<char, 'I', 'B', 'M', '4', '2', '0'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '4', '2', '0'>,
      string<char, 'c', 'p', '4', '2', '0'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'a', 'r', '1'>,
      string<char, 'c', 's', 'I', 'B', 'M', '4', '2', '0'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 'p', '4', '2', '0'> >
 : textEncodingType<text_encoding_id_IBM420_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '4', '2', '0'> >
 : textEncodingType<text_encoding_id_IBM420_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'a', 'r', '1'> >
 : textEncodingType<text_encoding_id_IBM420_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '4', '2', '0'> >
 : textEncodingType<text_encoding_id_IBM420_t>
 {
 };
}
#endif
