#include <type_traits>

#include "../IANA_encodings.d/AdobeStandardEncoding_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ADOBESTANDARDENCODINGTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ADOBESTANDARDENCODINGTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'a', 'd', 'o', 'b', 'e', 's', 't', 'a', 'n', 'd', 'a', 'r', 'd', 'e', 'n', 'c', 'o', 'd', 'i', 'n', 'g'>
 : textEncodingType<text_encoding_id_AdobeStandardEncoding_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'a', 'd', 'o', 'b', 'e', 's', 't', 'a', 'n', 'd', 'a', 'r', 'd', 'e', 'n', 'c', 'o', 'd', 'i', 'n', 'g'>
 : textEncodingType<text_encoding_id_AdobeStandardEncoding_t>
 {
 };
}
#endif
