#include <type_traits>

#include "../IANA_encodings.d/EUCFixWidJapanese_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_EUCFIXWIDJAPANESETEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_EUCFIXWIDJAPANESETEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'e', 'u', 'c', 'f', 'i', 'x', 'w', 'i', 'd', 'j', 'a', 'p', 'a', 'n', 'e', 's', 'e'>
 : textEncodingType<text_encoding_id_EUCFixWidJapanese_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'x', 't', 'e', 'n', 'd', 'e', 'd', 'u', 'n', 'i', 'x', 'c', 'o', 'd', 'e', 'f', 'i', 'x', 'e', 'd', 'w', 'i', 'd', 't', 'h', 'f', 'o', 'r', 'j', 'a', 'p', 'a', 'n', 'e', 's', 'e'>
 : textEncodingType<text_encoding_id_EUCFixWidJapanese_t>
 {
 };
}
#endif
