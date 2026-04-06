#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM918TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM918TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM918_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM918>;

 template <>
 struct textEncodingType<text_encoding_id_IBM918_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM918_t;
  using name = string<char, 'I', 'B', 'M', '9', '1', '8'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '9', '1', '8'>,
      string<char, 'C', 'P', '9', '1', '8'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'a', 'r', '2'>,
      string<char, 'c', 's', 'I', 'B', 'M', '9', '1', '8'> >;
 };

 template <>
 struct textEncodingType<string<char, 'C', 'P', '9', '1', '8'> >
 : textEncodingType<text_encoding_id_IBM918_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '9', '1', '8'> >
 : textEncodingType<text_encoding_id_IBM918_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'a', 'r', '2'> >
 : textEncodingType<text_encoding_id_IBM918_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '9', '1', '8'> >
 : textEncodingType<text_encoding_id_IBM918_t>
 {
 };
}
#endif
