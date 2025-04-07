#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO25FRENCHTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO25FRENCHTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO25French_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO25French>;

 template <>
 struct textEncodingType<text_encoding_id_ISO25French_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO25French_t;
  using name = string<char, 'N', 'F', '_', 'Z', '_', '6', '2', '-', '0', '1', '0', '_', '(', '1', '9', '7', '3', ')'>;
  using aliases = typeList<
      string<char, 'N', 'F', '_', 'Z', '_', '6', '2', '-', '0', '1', '0', '_', '(', '1', '9', '7', '3', ')'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '2', '5'>,
      string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'F', 'R', '1'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '2', '5', 'F', 'r', 'e', 'n', 'c', 'h'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '2', '5', 'F', 'r', 'e', 'n', 'c', 'h'> >
 : textEncodingType<text_encoding_id_ISO25French_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'F', 'R', '1'> >
 : textEncodingType<text_encoding_id_ISO25French_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '2', '5'> >
 : textEncodingType<text_encoding_id_ISO25French_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'N', 'F', '_', 'Z', '_', '6', '2', '-', '0', '1', '0', '_', '(', '1', '9', '7', '3', ')'> >
 : textEncodingType<text_encoding_id_ISO25French_t>
 {
 };
}
#endif
