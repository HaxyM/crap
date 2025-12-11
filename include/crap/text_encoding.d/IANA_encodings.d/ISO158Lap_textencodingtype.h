#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO158LAPTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO158LAPTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO158Lap_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO158Lap>;

 template <>
 struct textEncodingType<text_encoding_id_ISO158Lap_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO158Lap_t;
  using name = string<char, 'l', 'a', 't', 'i', 'n', '-', 'l', 'a', 'p'>;
  using aliases = typeList<
      string<char, 'l', 'a', 't', 'i', 'n', '-', 'l', 'a', 'p'>,
      string<char, 'l', 'a', 'p'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '5', '8'>,
      string<char, 'c', 's', 'I', 'S', 'O', '1', '5', '8', 'L', 'a', 'p'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '5', '8', 'L', 'a', 'p'> >
 : textEncodingType<text_encoding_id_ISO158Lap_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '5', '8'> >
 : textEncodingType<text_encoding_id_ISO158Lap_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'l', 'a', 'p'> >
 : textEncodingType<text_encoding_id_ISO158Lap_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'l', 'a', 't', 'i', 'n', '-', 'l', 'a', 'p'> >
 : textEncodingType<text_encoding_id_ISO158Lap_t>
 {
 };
}
#endif
