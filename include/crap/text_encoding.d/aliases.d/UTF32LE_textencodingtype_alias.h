#include <type_traits>

#include "../IANA_encodings.d/UTF32LE_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_UTF32LETEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_UTF32LETEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'u', 't', 'f', '3', '2', 'l', 'e'>
 : textEncodingType<text_encoding_id_UTF32LE_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'u', 't', 'f', '3', '2', 'l', 'e'>
 : textEncodingType<text_encoding_id_UTF32LE_t>
 {
 };
}
#endif
