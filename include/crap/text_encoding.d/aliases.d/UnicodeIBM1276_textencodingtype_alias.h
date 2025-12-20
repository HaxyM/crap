#include <type_traits>

#include "../IANA_encodings.d/UnicodeIBM1276_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_UNICODEIBM1276TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_UNICODEIBM1276TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'u', 'n', 'i', 'c', 'o', 'd', 'e', 'i', 'b', 'm', '1', '2', '7', '6'>
 : textEncodingType<text_encoding_id_UnicodeIBM1276_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'u', 'n', 'i', 'c', 'o', 'd', 'e', 'i', 'b', 'm', '1', '2', '7', '6'>
 : textEncodingType<text_encoding_id_UnicodeIBM1276_t>
 {
 };
}
#endif
