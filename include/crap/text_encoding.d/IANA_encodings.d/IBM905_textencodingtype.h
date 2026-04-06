#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_IBM905TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_IBM905TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_IBM905_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: IBM905>;

 template <>
 struct textEncodingType<text_encoding_id_IBM905_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_IBM905_t;
  using name = string<char, 'I', 'B', 'M', '9', '0', '5'>;
  using aliases = typeList<
      string<char, 'I', 'B', 'M', '9', '0', '5'>,
      string<char, 'C', 'P', '9', '0', '5'>,
      string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 't', 'r'>,
      string<char, 'c', 's', 'I', 'B', 'M', '9', '0', '5'> >;
 };

 template <>
 struct textEncodingType<string<char, 'C', 'P', '9', '0', '5'> >
 : textEncodingType<text_encoding_id_IBM905_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'B', 'M', '9', '0', '5'> >
 : textEncodingType<text_encoding_id_IBM905_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'e', 'b', 'c', 'd', 'i', 'c', '-', 'c', 'p', '-', 't', 'r'> >
 : textEncodingType<text_encoding_id_IBM905_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '9', '0', '5'> >
 : textEncodingType<text_encoding_id_IBM905_t>
 {
 };
}
#endif
