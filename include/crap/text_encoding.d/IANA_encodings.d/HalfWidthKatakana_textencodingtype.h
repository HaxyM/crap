#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_HALFWIDTHKATAKANATEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_HALFWIDTHKATAKANATEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_HalfWidthKatakana_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: HalfWidthKatakana>;

 template <>
 struct textEncodingType<text_encoding_id_HalfWidthKatakana_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_HalfWidthKatakana_t;
  using name = string<char, 'J', 'I', 'S', '_', 'X', '0', '2', '0', '1'>;
  using aliases = typeList<
	  string<char, 'J', 'I', 'S', '_', 'X', '0', '2', '0', '1'>,
	  string<char, 'X', '0', '2', '0', '1'>,
      string<char, 'c', 's', 'H', 'a', 'l', 'f', 'W', 'i', 'd', 't', 'h', 'K', 'a', 't', 'a', 'k', 'a', 'n', 'a'> >;
	  
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'H', 'a', 'l', 'f', 'W', 'i', 'd', 'h', 'K', 'a', 't', 'a', 'k', 'a', 'n', 'a'> >
 : textEncodingType<text_encoding_id_HalfWidthKatakana_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'J', 'I', 'S', '_', 'X', '0', '2', '0', '1'> >
 : textEncodingType<text_encoding_id_HalfWidthKatakana_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'X', '0', '2', '0', '1'> >
 : textEncodingType<text_encoding_id_HalfWidthKatakana_t>
 {
 };
}
#endif
