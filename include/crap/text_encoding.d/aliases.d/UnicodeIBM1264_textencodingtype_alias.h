#include <type_traits>

#include "../IANA_encodings.d/UnicodeIBM1264_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_UNICODEIBM1264TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_UNICODEIBM1264TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'u', 'n', 'i', 'c', 'o', 'd', 'e', 'i', 'b', 'm', '1', '2', '6', '4'>
 : textEncodingType<text_encoding_id_UnicodeIBM1264_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'u', 'n', 'i', 'c', 'o', 'd', 'e', 'i', 'b', 'm', '1', '2', '6', '4'>
 : textEncodingType<text_encoding_id_UnicodeIBM1264_t>
 {
 };
}
#endif
