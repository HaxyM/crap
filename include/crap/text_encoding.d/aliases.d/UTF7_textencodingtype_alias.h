#include <type_traits>

#include "../IANA_encodings.d/UTF7_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_UTF7TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_UTF7TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'u', 't', 'f', '7'>
 : textEncodingType<text_encoding_id_UTF7_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'u', 't', 'f', '7'>
 : textEncodingType<text_encoding_id_UTF7_t>
 {
 };
}
#endif
