#include <type_traits>

#include "../IANA_encodings.d/VISCII_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_VISCIITEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_VISCIITEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'v', 'i', 's', 'c', 'i', 'i'>
 : textEncodingType<text_encoding_id_VISCII_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'v', 'i', 's', 'c', 'i', 'i'>
 : textEncodingType<text_encoding_id_VISCII_t>
 {
 };
}
#endif
