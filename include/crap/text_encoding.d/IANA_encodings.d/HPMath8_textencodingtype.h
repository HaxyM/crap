#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_HPMATH8TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_HPMATH8TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_HPMath8_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: HPMath8>;

 template <>
 struct textEncodingType<text_encoding_id_HPMath8_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_HPMath8_t;
  using name = string<char, 'H', 'P', '-', 'M', 'a', 't', 'h', '8'>;
  using aliases = typeList<
      string<char, 'H', 'P', '-', 'M', 'a', 't', 'h', '8'>,
      string<char, 'c', 's', 'H', 'P', 'M', 'a', 't', 'h', '8'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'H', 'P', 'M', 'a', 't', 'h', '8'> >
 : textEncodingType<text_encoding_id_HPMath8_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'H', 'P', '-', 'M', 'a', 't', 'h', '8'> >
 : textEncodingType<text_encoding_id_HPMath8_t>
 {
 };
}
#endif
