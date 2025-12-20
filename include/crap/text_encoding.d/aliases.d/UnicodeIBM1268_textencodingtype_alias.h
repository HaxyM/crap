#include <type_traits>

#include "../IANA_encodings.d/UnicodeIBM1268_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_UNICODEIBM1268TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_UNICODEIBM1268TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'u', 'n', 'i', 'c', 'o', 'd', 'e', 'i', 'b', 'm', '1', '2', '6', '8'>
 : textEncodingType<text_encoding_id_UnicodeIBM1268_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'u', 'n', 'i', 'c', 'o', 'd', 'e', 'i', 'b', 'm', '1', '2', '6', '8'>
 : textEncodingType<text_encoding_id_UnicodeIBM1268_t>
 {
 };
}
#endif
