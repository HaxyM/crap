#include <type_traits>

#include "../IANA_encodings.d/ASCII_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ASCIITEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ASCIITEXTENCODINGTYPEALIAS

namespace crap
{
 //TODO: Libstdc++ adds alias "ASCII"

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, CharType ... Letters> > ::
 alias<PlaceHolder, char, 'a', 'n', 's', 'i', 'x', '3', '4', '1', '9', '6', '8'>
 : textEncodingType<text_encoding_id_ASCII_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, CharType ... Letters> > ::
 alias<PlaceHolder, char, 'a', 'n', 's', 'i', 'x', '3', '4', '1', '9', '8', '6'>
 : textEncodingType<text_encoding_id_ASCII_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, CharType ... Letters> > ::
 alias<PlaceHolder, char, 'c', 'p', '3', '6', '7'>
 : textEncodingType<text_encoding_id_ASCII_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, CharType ... Letters> > ::
 alias<PlaceHolder, char, 'c', 's', 'a', 's', 'c', 'i', 'i'>
 : textEncodingType<text_encoding_id_ASCII_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, CharType ... Letters> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '3', '6', '7'>
 : textEncodingType<text_encoding_id_ASCII_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, CharType ... Letters> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '6', '4', '6', 'u', 's'>
 : textEncodingType<text_encoding_id_ASCII_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, CharType ... Letters> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '6', '4', '6', 'i', 'r', 'v', '1', '9', '9', '1'>
 : textEncodingType<text_encoding_id_ASCII_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, CharType ... Letters> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '6'>
 : textEncodingType<text_encoding_id_ASCII_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, CharType ... Letters> > ::
 alias<PlaceHolder, char, 'u', 's'>
 : textEncodingType<text_encoding_id_ASCII_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, CharType ... Letters> > ::
 alias<PlaceHolder, char, 'u', 's', 'a', 's', 'c', 'i', 'i'>
 : textEncodingType<text_encoding_id_ASCII_t>
 {
 };
}
#endif
