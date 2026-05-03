#include <type_traits>

#include "../IANA_encodings.d/VIQR_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_VIQRTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_VIQRTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'v', 'i', 'q', 'r'>
 : textEncodingType<text_encoding_id_VIQR_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'v', 'i', 'q', 'r'>
 : textEncodingType<text_encoding_id_VIQR_t>
 {
 };
}
#endif
