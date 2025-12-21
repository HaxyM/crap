#include <type_traits>

#include "../IANA_encodings.d/Windows30Latin1_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_WINDOWS30LATIN1TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_WINDOWS30LATIN1TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'w', 'i', 'n', 'd', 'o', 'w', 's', '3', '0', 'l', 'a', 't', 'i', 'n', '1'>
 : textEncodingType<text_encoding_id_Windows30Latin1_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '8', '8', '5', '9', '1', 'w', 'i', 'n', 'd', 'o', 'w', 's', '3', '0', 'l', 'a', 't', 'i', 'n', '1'>
 : textEncodingType<text_encoding_id_Windows30Latin1_t>
 {
 };
}
#endif
