#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO11SWEDISHFORNAMESTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO11SWEDISHFORNAMESTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO11SwedishForNames_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO11SwedishForNames>;

 template <>
 struct textEncodingType<text_encoding_id_ISO11SwedishForNames_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO11SwedishForNames_t;
  using name = string<char, 'S', 'E', 'N', '_', '8', '5', '0', '2', '0', '0', '_', 'C'>;
  using aliases = typeList<
	  string<char, 'S', 'E', 'N', '_', '8', '5', '0', '2', '0', '0', '_', 'C'>,
	  string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '1'>,
	  string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'S', 'E', '2'>,
      string<char, 's', 'e', '2'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '1', '1', 'S', 'w', 'e', 'd', 'i', 's', 'h', 'F', 'o', 'r', 'N', 'a', 'm', 'e', 's'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '1', 'S', 'w', 'e', 'd', 'i', 's', 'h', 'F', 'o', 'r', 'N', 'a', 'm', 'e', 's'> >
 : textEncodingType<text_encoding_id_ISO11SwedishForNames_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'S', 'E', '2'> >
 : textEncodingType<text_encoding_id_ISO11SwedishForNames_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '1'> >
 : textEncodingType<text_encoding_id_ISO11SwedishForNames_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'S', 'E', 'N', '_', '8', '5', '0', '2', '0', '0', '_', 'C'> >
 : textEncodingType<text_encoding_id_ISO11SwedishForNames_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 's', 'e', '2'> >
 : textEncodingType<text_encoding_id_ISO11SwedishForNames_t>
 {
 };
}
#endif
