#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_HPPIFONTTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_HPPIFONTTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_HPPiFont_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: HPPiFont>;

 template <>
 struct textEncodingType<text_encoding_id_HPPiFont_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_HPPiFont_t;
  using name = string<char, 'H', 'P', '-', 'P', 'i', '-', 'f', 'o', 'n', 't'>;
  using aliases = typeList<
      string<char, 'H', 'P', '-', 'P', 'i', '-', 'f', 'o', 'n', 't'>,
      string<char, 'c', 's', 'H', 'P', 'P', 'i', 'F', 'o', 'n', 't'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'H', 'P', 'P', 'i', 'F', 'o', 'n', 't'> >
 : textEncodingType<text_encoding_id_HPPiFont_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'H', 'P', '-', 'P', 'i', '-', 'f', 'o', 'n', 't'> >
 : textEncodingType<text_encoding_id_HPPiFont_t>
 {
 };
}
#endif
