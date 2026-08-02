#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_PTCP154TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_PTCP154TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_PTCP154_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: PTCP154>;

 template <>    
 struct textEncodingType<text_encoding_id_PTCP154_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_PTCP154_t;
  using name = string<char, 'P', 'T', 'C', 'P', '1', '5', '4'>;
  using aliases = typeList<
      string<char, 'P', 'T', 'C', 'P', '1', '5', '4'>,
      string<char, 'c', 's', 'P', 'T', 'C', 'P', '1', '5', '4'>,
      string<char, 'P', 'T', '1', '5', '4'>,
      string<char, 'C', 'P', '1', '5', '4'>,
      string<char, 'C', 'y', 'r', 'i', 'l', 'l', 'i', 'c', '-', 'A', 's', 'i', 'a', 'n'> >;
 };

 template <>
 struct textEncodingType<string<char, 'C', 'P', '1', '5', '4'> >
 : textEncodingType<text_encoding_id_PTCP154_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'P', 'T', 'C', 'P', '1', '5', '4'> >
 : textEncodingType<text_encoding_id_PTCP154_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'C', 'y', 'r', 'i', 'l', 'l', 'i', 'c', '-', 'A', 's', 'i', 'a', 'n'> >
 : textEncodingType<text_encoding_id_PTCP154_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'P', 'T', '1', '5', '4'> >
 : textEncodingType<text_encoding_id_PTCP154_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'P', 'T', 'C', 'P', '1', '5', '4'> >
 : textEncodingType<text_encoding_id_PTCP154_t>
 {
 };
}
#endif
