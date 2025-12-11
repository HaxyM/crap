#include <type_traits>

#include "../IANA_encodings.d/USDK_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_USDKTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_USDKTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'u', 's', 'd', 'k'>
 : textEncodingType<text_encoding_id_USDK_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'u', 's', 'd', 'k'>
 : textEncodingType<text_encoding_id_USDK_t>
 {
 };
}
#endif
