#include <type_traits>

#include "../IANA_encodings.d/UTF32_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_UTF32TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_UTF32TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'u', 't', 'f', '3', '2'>
 : textEncodingType<text_encoding_id_UTF32_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'u', 't', 'f', '3', '2'>
 : textEncodingType<text_encoding_id_UTF32_t>
 {
 };
}
#endif
