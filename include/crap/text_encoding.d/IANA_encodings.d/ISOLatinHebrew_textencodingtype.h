#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISOLATINHEBREWTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISOLATINHEBREWTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISOLatinHebrew_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISOLatinHebrew>;

 template <>
 struct textEncodingType<text_encoding_id_ISOLatinHebrew_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISOLatinHebrew_t;
  using name = string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '8', ':', '1', '9', '8', '8'>;
  using aliases = typeList<
	  string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '8', ':', '1', '9', '8', '8'>,
	  string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '3', '8'>,
	  string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '8'>,
	  string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '8'>,
	  string<char, 'h', 'e', 'b', 'r', 'e', 'w'>,
	  string<char, 'c', 's', 'I', 'S', 'O', 'L', 'a', 't', 'i', 'n', 'H', 'e', 'b', 'r', 'e', 'w'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', 'L', 'a', 't', 'i', 'n', 'H', 'e', 'b', 'r', 'e', 'w'> >
 : textEncodingType<text_encoding_id_ISOLatinHebrew_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'h', 'e', 'b', 'r', 'e', 'w'> >
 : textEncodingType<text_encoding_id_ISOLatinHebrew_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '_', '8', '8', '5', '9', '-', '8'> >
 : textEncodingType<text_encoding_id_ISOLatinHebrew_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '8'> >
 : textEncodingType<text_encoding_id_ISOLatinHebrew_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '-', '8', '8', '5', '9', '-', '8', ':', '1', '9', '8', '8'> >
 : textEncodingType<text_encoding_id_ISOLatinHebrew_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '3', '8'> >
 : textEncodingType<text_encoding_id_ISOLatinHebrew_t>
 {
 };
}
#endif
