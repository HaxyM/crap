#include <type_traits>

#include "../IANA_encodings.d/UTF8_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_UTF8TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_UTF8TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'u', 't', 'f', '8'>
 : textEncodingType<text_encoding_id_UTF8_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'u', 't', 'f', '8'>
 : textEncodingType<text_encoding_id_UTF8_t>
 {
 };
}
#endif
