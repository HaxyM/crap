#include <type_traits>

#include "../IANA_encodings.d/UnicodeASCII_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_UNICODEASCIITEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_UNICODEASCIITEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'u', 'n', 'i', 'c', 'o', 'd', 'e', 'a', 's', 'c', 'i', 'i'>
 : textEncodingType<text_encoding_id_UnicodeASCII_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '1', '0', '6', '4', '6', 'u', 'c', 's', 'b', 'a', 's', 'i', 'c'>
 : textEncodingType<text_encoding_id_UnicodeASCII_t>
 {
 };
}
#endif
