#include <type_traits>

#include "../IANA_encodings.d/UCS2_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_UCS2TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_UCS2TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'u', 'n', 'i', 'c', 'o', 'd', 'e'>
 : textEncodingType<text_encoding_id_UCS2_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '1', '0', '6', '4', '6', 'u', 'c', 's', '2'>
 : textEncodingType<text_encoding_id_UCS2_t>
 {
 };
}
#endif
