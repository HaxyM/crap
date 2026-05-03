#include <type_traits>

#include "../IANA_encodings.d/HZGB2312_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_HZGB2312TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_HZGB2312TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'h', 'z', 'g', 'b', '2', '3', '1', '2'>
 : textEncodingType<text_encoding_id_HZGB2312_t>
 {
 };
}
#endif
