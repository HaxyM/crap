#include <type_traits>

#include "../IANA_encodings.d/CESU8_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_CESU8TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_CESU8TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'c', 'e', 's', 'u', '8'>
 : textEncodingType<text_encoding_id_CESU8_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'e', 's', 'u', '8'>
 : textEncodingType<text_encoding_id_CESU8_t>
 {
 };
}
#endif
