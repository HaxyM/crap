#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISOLATINARABICTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISOLATINARABICTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISOLatinArabic_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISOLatinArabic>;

 template <>
 struct textEncodingType<text_encoding_id_ISOLatinArabic_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISOLatinArabic_t;
  using name = string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '6', ':', '1', '9', '8', '7'>;
  using aliases = typeList<
	  string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '2', '7'>,
	  string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '6'>,
	  string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '6'>,
	  string<char, 'E', 'C', 'M', 'A', '-', '1', '1', '4'>,
	  string<char, 'A', 'S', 'M', 'O', '-', '7', '0', '8'>,
	  string<char, 'a', 'r', 'a', 'b', 'i', 'c'>,
	  string<char, 'c', 's', 'I', 'S', 'O', 'L', 'a', 't', 'i', 'n', 'A', 'r', 'a', 'b', 'i', 'c'> >; //Libstdc++ adds alias "ISO-8859-6:1987" (name)
 };

 template <>
 struct textEncodingType<string<char, 'a', 'r', 'a', 'b', 'i', 'c'> >
 : textEncodingType<text_encoding_id_ISOLatinArabic_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'A', 'S', 'M', 'O', '-', '7', '0', '8'> >
 : textEncodingType<text_encoding_id_ISOLatinArabic_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', 'L', 'a', 't', 'i', 'n', 'A', 'r', 'a', 'b', 'i', 'c'> >
 : textEncodingType<text_encoding_id_ISOLatinArabic_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'E', 'C', 'M', 'A', '-', '1', '1', '4'> >
 : textEncodingType<text_encoding_id_ISOLatinArabic_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '6'> >
 : textEncodingType<text_encoding_id_ISOLatinArabic_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '6'> >
 : textEncodingType<text_encoding_id_ISOLatinArabic_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '6', ':', '1', '9', '8', '7'> >
 : textEncodingType<text_encoding_id_ISOLatinArabic_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '2', '7'> >
 : textEncodingType<text_encoding_id_ISOLatinArabic_t>
 {
 };
}
#endif
