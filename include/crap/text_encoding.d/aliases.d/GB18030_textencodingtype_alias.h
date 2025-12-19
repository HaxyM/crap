#include <type_traits>

#include "../IANA_encodings.d/GB18030_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_GB18030TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_GB18030TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'g', 'b', '1', '8', '0', '3', '0'>
 : textEncodingType<text_encoding_id_GB18030_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'g', 'b', '1', '8', '0', '3', '0'>
 : textEncodingType<text_encoding_id_GB18030_t>
 {
 };
}
#endif
