#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO102T617BITTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO102T617BITTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO102T617bit_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO102T617bit>;

 template <>
 struct textEncodingType<text_encoding_id_ISO102T617bit_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO102T617bit_t;
  using name = string<char, 'T', '.', '6', '1', '-', '7', 'b', 'i', 't'>;
  using aliases = typeList<
      string<char, 'T', '.', '6', '1', '-', '7', 'b', 'i', 't'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '0', '2'>,
      string<char, 'c', 's', 'I', 'S', 'O', '1', '0', '2', 'T', '6', '1', '7', 'b', 'i', 't'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '0', '2', 'T', '6', '1', '7', 'b', 'i', 't'> >
 : textEncodingType<text_encoding_id_ISO102T617bit_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '0', '2'> >
 : textEncodingType<text_encoding_id_ISO102T617bit_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'T', '.', '6', '1', '-', '7', 'b', 'i', 't'> >
 : textEncodingType<text_encoding_id_ISO102T617bit_t>
 {
 };
}
#endif
