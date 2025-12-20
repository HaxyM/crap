#include <type_traits>

#include "../IANA_encodings.d/UTF16BE_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_UTF16BETEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_UTF16BETEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'u', 't', 'f', '1', '6', 'b', 'e'>
 : textEncodingType<text_encoding_id_UTF16BE_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'u', 't', 'f', '1', '6', 'b', 'e'>
 : textEncodingType<text_encoding_id_UTF16BE_t>
 {
 };
}
#endif
