#include <type_traits>

#include "../IANA_encodings.d/UCS4_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_UCS4TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_UCS4TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'u', 'c', 's', '4'>
 : textEncodingType<text_encoding_id_UCS4_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '1', '0', '6', '4', '6', 'u', 'c', 's', '4'>
 : textEncodingType<text_encoding_id_UCS4_t>
 {
 };
}
#endif
