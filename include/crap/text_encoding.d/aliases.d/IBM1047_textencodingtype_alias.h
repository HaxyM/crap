#include <type_traits>

#include "../IANA_encodings.d/IBM1047_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM1047TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM1047TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '1', '0', '4', '7'>
 : textEncodingType<text_encoding_id_IBM1047_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '1', '0', '4', '7'>
 : textEncodingType<text_encoding_id_IBM1047_t>
 {
 };
}
#endif
