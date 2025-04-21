#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO87JISX0208TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO87JISX0208TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO87JISX0208_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO87JISX0208>;

 template <>
 struct textEncodingType<text_encoding_id_ISO87JISX0208_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO87JISX0208_t;
  using name = string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '6', '-', '1', '9', '8', '3'>;
  using aliases = typeList<
	  string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '6', '-', '1', '9', '8', '3'>,
	  string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '8', '7'>,
      string<char, 'x', '0', '2', '0', '8'>,
      string<char, 'J', 'I', 'S', '_', 'X', '0', '2', '0', '8', '-', '1', '9', '8', '3'>,
      string<char, 'c', 's', 'I', 'S', 'O', '8', '7', 'J', 'I', 'S', 'X', '0', '2', '0', '8'> >;
	  
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '8', '7', 'J', 'I', 'S', 'X', '0', '2', '0', '8'> >
 : textEncodingType<text_encoding_id_ISO87JISX0208_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '8', '7'> >
 : textEncodingType<text_encoding_id_ISO87JISX0208_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'J', 'I', 'S', '_', 'C', '6', '2', '2', '6', '-', '1', '9', '8', '3'> >
 : textEncodingType<text_encoding_id_ISO87JISX0208_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'J', 'I', 'S', '_', 'X', '0', '2', '0', '8', '-', '1', '9', '8', '3'> >
 : textEncodingType<text_encoding_id_ISO87JISX0208_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'x', '0', '2', '0', '8'> >
 : textEncodingType<text_encoding_id_ISO87JISX0208_t>
 {
 };
}
#endif
