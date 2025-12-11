#include <type_traits>

#include "../IANA_encodings.d/Unicode11UTF7_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_UNICODE11UTF7TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_UNICODE11UTF7TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'u', 'n', 'i', 'c', 'o', 'd', 'e', '1', '1', 'u', 't', 'f', '7'>
 : textEncodingType<text_encoding_id_Unicode11UTF7_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'u', 'n', 'i', 'c', 'o', 'd', 'e', '1', '1', 'u', 't', 'f', '7'>
 : textEncodingType<text_encoding_id_Unicode11UTF7_t>
 {
 };
}
#endif
