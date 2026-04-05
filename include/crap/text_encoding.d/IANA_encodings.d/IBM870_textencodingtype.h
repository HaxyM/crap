#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM870TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM870TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM870_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM870>;

 template <>
 struct textEncodingType<text_encoding_id_IBM870_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM870_t;
  using name = string<char, 'I', 'B', 'M', '8', '7', '0'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '8', '7', '0'>,
      string<char, 'C', 'P', '8', '7', '0'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'r', 'o', 'e', 'c', 'e'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'y', 'u'>,
      string<char, 'c', 's', 'I', 'B', 'M', '8', '7', '0'> >;
 };

 template <>
 struct textEncodingType<string<char, 'C', 'P', '8', '7', '0'> >
 : textEncodingType<text_encoding_id_IBM870_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '8', '7', '0'> >
 : textEncodingType<text_encoding_id_IBM870_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'r', 'o', 'e', 'c', 'e'> >
 : textEncodingType<text_encoding_id_IBM870_t>
 {
 };


 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 'y', 'u'> >
 : textEncodingType<text_encoding_id_IBM870_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '8', '7', '0'> >
 : textEncodingType<text_encoding_id_IBM870_t>
 {
 };
}
#endif
