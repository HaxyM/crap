#include <type_traits>

#include "../IANA_encodings.d/ISO10Swedish_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO10SWEDISHTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO10SWEDISHTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '0', 's', 'w', 'e', 'd', 'i', 's', 'h'>
 : textEncodingType<text_encoding_id_ISO10Swedish_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'f', 'i'>
 : textEncodingType<text_encoding_id_ISO10Swedish_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '6', '4', '6', 'f', 'i'>
 : textEncodingType<text_encoding_id_ISO10Swedish_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '6', '4', '6', 's', 'e'>
 : textEncodingType<text_encoding_id_ISO10Swedish_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '0'>
 : textEncodingType<text_encoding_id_ISO10Swedish_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 's', 'e', 'n', '8', '5', '0', '2', '0', '0', 'b'>
 : textEncodingType<text_encoding_id_ISO10Swedish_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 's', 'e'>
 : textEncodingType<text_encoding_id_ISO10Swedish_t>
 {
 };
}
#endif
