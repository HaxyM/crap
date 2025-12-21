#include <type_traits>

#include "../IANA_encodings.d/BOCU1_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_BOCU1TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_BOCU1TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'b', 'o', 'c', 'u', '1'>
 : textEncodingType<text_encoding_id_BOCU1_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'b', 'o', 'c', 'u', '1'>
 : textEncodingType<text_encoding_id_BOCU1_t>
 {
 };
}
#endif
