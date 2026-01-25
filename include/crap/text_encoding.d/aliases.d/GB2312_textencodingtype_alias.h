#include <type_traits>

#include "../IANA_encodings.d/GB2312_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_GB2312TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_GB2312TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'g', 'b', '2', '3', '1', '2'>
 : textEncodingType<text_encoding_id_GB2312_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'g', 'b', '2', '3', '1', '2'>
 : textEncodingType<text_encoding_id_GB2312_t>
 {
 };
}
#endif
