#include <type_traits>

#include "../IANA_encodings.d/ISO85Spanish2_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO85SPANISH2TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO85SPANISH2TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '8', '5', 's', 'p', 'a', 'n', 'i', 's', 'h', '2'>
 : textEncodingType<text_encoding_id_ISO85Spanish2_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 's', '2'>
 : textEncodingType<text_encoding_id_ISO85Spanish2_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '6', '4', '6', 'e', 's', '2'>
 : textEncodingType<text_encoding_id_ISO85Spanish2_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '8', '5'>
 : textEncodingType<text_encoding_id_ISO85Spanish2_t>
 {
 };
}
#endif
