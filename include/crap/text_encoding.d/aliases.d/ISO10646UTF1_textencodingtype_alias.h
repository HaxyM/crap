#include <type_traits>

#include "../IANA_encodings.d/ISO10646UTF1_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO10646UTF1TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO10646UTF1TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '0', '6', '4', '6', 'u', 't', 'f', '1'>
 : textEncodingType<text_encoding_id_ISO10646UTF1_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '1', '0', '6', '4', '6', 'u', 't', 'f', '1'>
 : textEncodingType<text_encoding_id_ISO10646UTF1_t>
 {
 };
}
#endif
