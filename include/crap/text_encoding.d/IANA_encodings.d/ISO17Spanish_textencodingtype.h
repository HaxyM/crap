#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO17SPANISHTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO17SPANISHTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO17Spanish_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO17Spanish>;

 template <>
 struct textEncodingType<text_encoding_id_ISO17Spanish_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO17Spanish_t;
  using name = string<char, 'E', 'S'>;
  using aliases = typeList<
	  string<char, 'E', 'S'>,
	  string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '7'>,
	  string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'E', 'S'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '1', '7', 'S', 'p', 'a', 'n', 'i', 's', 'h'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '7', 'S', 'p', 'a', 'n', 'i', 's', 'h'> >
 : textEncodingType<text_encoding_id_ISO17Spanish_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'S'> >
 : textEncodingType<text_encoding_id_ISO17Spanish_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'E', 'S'> >
 : textEncodingType<text_encoding_id_ISO17Spanish_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '7'> >
 : textEncodingType<text_encoding_id_ISO17Spanish_t>
 {
 };
}
#endif
