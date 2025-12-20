#include <type_traits>

#include "../IANA_encodings.d/UTF16LE_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_UTF16LETEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_UTF16LETEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'u', 't', 'f', '1', '6', 'l', 'e'>
 : textEncodingType<text_encoding_id_UTF16LE_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'u', 't', 'f', '1', '6', 'l', 'e'>
 : textEncodingType<text_encoding_id_UTF16LE_t>
 {
 };
}
#endif
