#include <type_traits>

#include "../IANA_encodings.d/UnicodeIBM1261_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_UNICODEIBM1261TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_UNICODEIBM1261TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'u', 'n', 'i', 'c', 'o', 'd', 'e', 'i', 'b', 'm', '1', '2', '6', '1'>
 : textEncodingType<text_encoding_id_UnicodeIBM1261_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'u', 'n', 'i', 'c', 'o', 'd', 'e', 'i', 'b', 'm', '1', '2', '6', '1'>
 : textEncodingType<text_encoding_id_UnicodeIBM1261_t>
 {
 };
}
#endif
