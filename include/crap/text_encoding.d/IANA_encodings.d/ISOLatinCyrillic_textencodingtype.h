#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISOLATINCYRILLICTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISOLATINCYRILLICTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISOLatinCyrillic_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISOLatinCyrillic>;

 template <>
 struct textEncodingType<text_encoding_id_ISOLatinCyrillic_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISOLatinCyrillic_t;
  using name = string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '5', ':', '1', '9', '8', '8'>;
  using aliases = typeList<
	  string<char 'i', 's', 'o', '-', 'i', 'r', '-', '1', '4', '4'>,
	  string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '5'>,
	  string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '5'>,
	  string<char, 'c', 'y', 'r', 'i', 'l', 'l', 'i', 'c'>,
	  string<char 'c', 's', 'I', 'S', 'O', 'L', 'a', 't', 'i', 'n', 'C', 'y', 'r', 'i', 'l', 'l', 'i', 'c'> >; //Libstdc++ adds alias "ISO-8859-5:1988" (name)
 };

 template <>
 struct textEncodingType<string<char 'c', 's', 'I', 'S', 'O', 'L', 'a', 't', 'i', 'n', 'C', 'y', 'r', 'i', 'l', 'l', 'i', 'c'> >
 : textEncodingType<text_encoding_id_ISOLatinCyrillic_t>
 {
 };

 template <>
 struct textEncodingType<string<char 'c', 'y', 'r', 'i', 'l', 'l', 'i', 'c'> >
 : textEncodingType<text_encoding_id_ISOLatinCyrillic_t>
 {
 };

 template <>
 struct textEncodingType<string<char 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '5'> >
 : textEncodingType<text_encoding_id_ISOLatinCyrillic_t>
 {
 };

 template <>
 struct textEncodingType<string<char 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '5'> >
 : textEncodingType<text_encoding_id_ISOLatinCyrillic_t>
 {
 };

 template <>
 struct textEncodingType<string<char 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '5', ':', '1', '9', '8', '8'> >
 : textEncodingType<text_encoding_id_ISOLatinCyrillic_t>
 {
 };

 template <>
 struct textEncodingType<string<char 'i', 's', 'o', '-', 'i', 'r', '-', '1', '4', '4'> >
 : textEncodingType<text_encoding_id_ISOLatinCyrillic_t>
 {
 };
}
#endif
