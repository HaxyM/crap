#include <type_traits>

#include "../IANA_encodings.d/ISO15Italian_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO15ITALIANTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO15ITALIANTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '5', 'i', 't', 'a', 'l', 'i', 'a', 'n'>
 : textEncodingType<text_encoding_id_ISO15Italian_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '6', '4', '6', 'i', 't'>
 : textEncodingType<text_encoding_id_ISO15Italian_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '5'>
 : textEncodingType<text_encoding_id_ISO15Italian_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 't'>
 : textEncodingType<text_encoding_id_ISO15Italian_t>
 {
 };
}
#endif
