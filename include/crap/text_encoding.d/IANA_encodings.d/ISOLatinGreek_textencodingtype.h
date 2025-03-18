#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISOLATINGREEKTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISOLATINGREEKTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISOLatinGreek_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISOLatinGreek>;

 template <>
 struct textEncodingType<text_encoding_id_ISOLatinGreek_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISOLatinGreek_t;
  using name = string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '7', ':', '1', '9', '8', '7'>;
  using aliases = typeList<
	  string<char 'i', 's', 'o', '-', 'i', 'r', '-', '1', '2', '6'>,
	  string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '7'>,
	  string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '7'>,
	  string<char, 'E', 'L', 'O', 'T', '_', '9', '2', '8'>,
	  string<char, 'E', 'C', 'M', 'A', '-', '1', '1', '8'>,
	  string<char, 'g', 'r', 'e', 'e', 'k'>,
	  string<char, 'g', 'r', 'e', 'e', 'k', '8'>,
	  string<char 'c', 's', 'I', 'S', 'O', 'L', 'a', 't', 'i', 'n', 'G', 'r', 'e', 'e', 'k'> >; //Libstdc++ adds alias "ISO-8859-7:1987" (name)
 };

 template <>
 struct textEncodingType<string<char 'c', 's', 'I', 'S', 'O', 'L', 'a', 't', 'i', 'n', 'G', 'r', 'e', 'e', 'k'> >
 : textEncodingType<text_encoding_id_ISOLatinGreek_t>
 {
 };

 template <>
 struct textEncodingType<string<char 'E', 'C', 'M', 'A', '-', '1', '1', '8'> >
 : textEncodingType<text_encoding_id_ISOLatinGreek_t>
 {
 };

 template <>
 struct textEncodingType<string<char 'E', 'L', 'O', 'T', '_', '9', '2', '8'> >
 : textEncodingType<text_encoding_id_ISOLatinGreek_t>
 {
 };

 template <>
 struct textEncodingType<string<char 'g', 'r', 'e', 'e', 'k'> >
 : textEncodingType<text_encoding_id_ISOLatinGreek_t>
 {
 };

 template <>
 struct textEncodingType<string<char 'g', 'r', 'e', 'e', 'k', '8'> >
 : textEncodingType<text_encoding_id_ISOLatinGreek_t>
 {
 };

 template <>
 struct textEncodingType<string<char 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '7'> >
 : textEncodingType<text_encoding_id_ISOLatinGreek_t>
 {
 };

 template <>
 struct textEncodingType<string<char 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '7'> >
 : textEncodingType<text_encoding_id_ISOLatinGreek_t>
 {
 };

 template <>
 struct textEncodingType<string<char 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '7', ':', '1', '9', '8', '7'> >
 : textEncodingType<text_encoding_id_ISOLatinGreek_t>
 {
 };

 template <>
 struct textEncodingType<string<char 'i', 's', 'o', '-', 'i', 'r', '-', '1', '2', '8'> >
 : textEncodingType<text_encoding_id_ISOLatinGreek_t>
 {
 };
}
#endif
