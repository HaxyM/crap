#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_HPPSMATHTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_HPPSMATHTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_HPPSMath_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: HPPSMath>;

 template <>
 struct textEncodingType<text_encoding_id_HPPSMath_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_HPPSMath_t;
  using name = string<char, 'A', 'd', 'o', 'b', 'e', '-', 'S', 'y', 'm', 'b', 'o', 'l', '-', 'E', 'n', 'c', 'o', 'd', 'i', 'n', 'g'>;
  using aliases = typeList<
      string<char, 'A', 'd', 'o', 'b', 'e', '-', 'S', 'y', 'm', 'b', 'o', 'l', '-', 'E', 'n', 'c', 'o', 'd', 'i', 'n', 'g'>,
      string<char, 'c', 's', 'H', 'P', 'P', 'S', 'M', 'a', 't', 'h'> >;
 };

 template <>
 struct textEncodingType<string<char, 'A', 'd', 'o', 'b', 'e', '-', 'S', 'y', 'm', 'b', 'o', 'l', '-', 'E', 'n', 'c', 'o', 'd', 'i', 'n', 'g'> >
 : textEncodingType<text_encoding_id_HPPSMath_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'H', 'P', 'P', 'S', 'M', 'a', 't', 'h'> >
 : textEncodingType<text_encoding_id_HPPSMath_t>
 {
 };
}
#endif
