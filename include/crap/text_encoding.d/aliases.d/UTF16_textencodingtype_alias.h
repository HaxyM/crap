#include <type_traits>

#include "../IANA_encodings.d/UTF16_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_UTF16TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_UTF16TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'u', 't', 'f', '1', '6'>
 : textEncodingType<text_encoding_id_UTF16_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'u', 't', 'f', '1', '6'>
 : textEncodingType<text_encoding_id_UTF16_t>
 {
 };
}
#endif
