#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO10SWEDISHTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO10SWEDISHTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO10Swedish_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO10Swedish>;

 template <>
 struct textEncodingType<text_encoding_id_ISO10Swedish_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO10Swedish_t;
  using name = string<char, 'S', 'E', 'N', '_', '8', '5', '0', '2', '0', '0', '_', 'B'>;
  using aliases = typeList<
	  string<char, 'S', 'E', 'N', '_', '8', '5', '0', '2', '0', '0'. '_', 'B'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '0'>,
      string<char, 'F', 'I'>,
	  string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'F', 'I'>,
	  string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'S', 'E'>,
	  string<char, 's', 'e'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '1', '0', 'S', 'w', 'e', 'd', 'i', 's', 'h'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '1', '0', 'S', 'w', 'e', 'd', 'i', 's', 'h'> >
 : textEncodingType<text_encoding_id_ISO10Swedish_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'F', 'I'> >
 : textEncodingType<text_encoding_id_ISO10Swedish_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'F', 'I'> >
 : textEncodingType<text_encoding_id_ISO10Swedish_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'S', 'E'> >
 : textEncodingType<text_encoding_id_ISO10Swedish_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '0'> >
 : textEncodingType<text_encoding_id_ISO10Swedish_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'S', 'E', 'N', '_', '8', '5', '0', '2', '0', '0', '_', 'B'> >
 : textEncodingType<text_encoding_id_ISO10Swedish_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 's', 'e'> >
 : textEncodingType<text_encoding_id_ISO10Swedish_t>
 {
 };
}
#endif
