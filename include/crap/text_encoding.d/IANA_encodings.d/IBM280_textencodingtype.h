#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM280TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM280TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM280_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM280>;

 template <>
 struct textEncodingType<text_encoding_id_IBM280_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM280_t;
  using name = string<char, 'I', 'B', 'M', '2', '8', '0'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '2', '8', '0'>,
      string<char, 'C', 'P', '2', '8', '0'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'i', 't'>,
      string<char, 'c', 's', 'I', 'B', 'M', '2', '8', '0'> >;
 };

 template <>
 struct textEncodingType<string<char, 'C', 'P', '2', '8', '0'> >
 : textEncodingType<text_encoding_id_IBM280_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '2', '8', '0'> >
 : textEncodingType<text_encoding_id_IBM280_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'i', 't'> >
 : textEncodingType<text_encoding_id_IBM280_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '2', '8', '0'> >
 : textEncodingType<text_encoding_id_IBM280_t>
 {
 };
}
#endif
