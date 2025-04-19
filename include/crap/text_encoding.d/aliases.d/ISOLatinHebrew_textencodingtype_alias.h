#include <type_traits>

#include "../IANA_encodings.d/ISOLatinHebrew_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISOLATINHEBREWTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISOLATINHEBREWTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', 'l', 'a', 't', 'i', 'n', 'h', 'e', 'b', 'r', 'e', 'w'>
 : textEncodingType<text_encoding_id_ISOLatinHebrew_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'h', 'e', 'b', 'r', 'e', 'w'>
 : textEncodingType<text_encoding_id_ISOLatinHebrew_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '8', '8', '5', '9', '8'>
 : textEncodingType<text_encoding_id_ISOLatinHebrew_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '8', '8', '5', '9', '8', '1', '9', '8', '8'>
 : textEncodingType<text_encoding_id_ISOLatinHebrew_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '3', '8'>
 : textEncodingType<text_encoding_id_ISOLatinHebrew_t>
 {
 };
}
#endif
