#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ASCIITEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ASCIITEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ASCII_t =
    std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ASCII>;

 template <>
 struct textEncodingType<text_encoding_id_ASCII_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ASCII_t;
  using name = string<char, 'U', 'S', '-', 'A', 'S', 'C', 'I', 'I'>;
  using aliases = typeList<
	  string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '6'>,
	  string<char, 'A', 'N', 'S', 'I', '_', 'X', '3', '.', '4', '-', '1', '9', '6', '8'>,
	  string<char, 'A', 'N', 'S', 'I', '_', 'X', '3', '.', '4', '-', '1', '9', '8', '6'>,
	  string<char, 'I', 'S', 'O', '_', '6', '4', '6', '.', 'i', 'r', 'v', ':', '1', '9', '9', '1'>,
	  string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'U', 'S'>,
	  string<char, 'U', 'S', '-', 'A', 'S', 'C', 'I', 'I'>,
	  string<char, 'u', 's'>,
	  string<char, 'I', 'B', 'M', '3', '6', '7'>,
	  string<char, 'c', 'p', '3', '6', '7'>,
	  string<char, 'c', 's', 'A', 'S', 'C', 'I', 'I'> >; //Libstdc++ adds alias "ASCII"
 };
 
 template <>
 struct textEncodingType<string<char, 'A', 'N', 'S', 'I', '_', 'X', '3', '.', '4', '-', '1', '9', '6', '8'> >
 : textEncodingType<text_encoding_id_ASCII_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'A', 'N', 'S', 'I', '_', 'X', '3', '.', '4', '-', '1', '9', '8', '6'> >
 : textEncodingType<text_encoding_id_ASCII_t>
 {
 };
 
 template <>
 struct textEncodingType<string<char, 'c', 'p', '3', '6', '7'> >
 : textEncodingType<text_encoding_id_ASCII_t>
 {
 };
 
 template <>
 struct textEncodingType<string<char, 'c', 's', 'A', 'S', 'C', 'I', 'I'> >
 : textEncodingType<text_encoding_id_ASCII_t>
 {
 };
 
 template <>
 struct textEncodingType<string<char, 'I', 'B', 'M', '3', '6', '7'> >
 : textEncodingType<text_encoding_id_ASCII_t>
 {
 };
 
 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'U', 'S'>, >
 : textEncodingType<text_encoding_id_ASCII_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '_', '6', '4', '6', '.', 'i', 'r', 'v', ':', '1', '9', '9', '1'> >
 : textEncodingType<text_encoding_id_ASCII_t>
 {
 };
 
 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '6'> >
 : textEncodingType<text_encoding_id_ASCII_t>
 {
 };
 
 template <>
 struct textEncodingType<string<char, 'u', 's'> >
 : textEncodingType<text_encoding_id_ASCII_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'U', 'S', '-', 'A', 'S', 'C', 'I', 'I'> >
 : textEncodingType<text_encoding_id_ASCII_t>
 {
 };
}
#endif