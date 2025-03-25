#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO69FRENCHTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO69FRENCHTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO69French_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO69French>;

 template <>
 struct textEncodingType<text_encoding_id_ISO69French_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO69French_t;
  using name = string<char, 'N', 'F', '_', 'Z', '_', '6', '2', '-', '0', '1', '0'>;
  using aliases = typeList<
  	  string<char, 'N', 'F', '_', 'Z', '_', '6', '2', '-', '0', '1', '0'>,
	  string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '6', '9'>,
      string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'F', 'R'>,
      string<char, 'f', 'r'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '6', '9', 'F', 'r', 'e', 'n', 'c', 'h'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '6', '9', 'F', 'r', 'e', 'n', 'c', 'h'> >
 : textEncodingType<text_encoding_id_ISO69French_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'f', 'r'> >
 : textEncodingType<text_encoding_id_ISO69French_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'F', 'R'> >
 : textEncodingType<text_encoding_id_ISO69French_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '6', '9'> >
 : textEncodingType<text_encoding_id_ISO69French_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'N', 'F', '_', 'Z', '_', '6', '2', '-', '0', '1', '0'> >
 : textEncodingType<text_encoding_id_ISO69French_t>
 {
 };
}
#endif
