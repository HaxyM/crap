#include <type_traits>

#include "../IANA_encodings.d/MicrosoftPublishing_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_MICROSOFTPUBLISHINGTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_MICROSOFTPUBLISHINGTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'm', 'i', 'c', 'r', 'o', 's', 'o', 'f', 't', 'p', 'u', 'b', 'l', 'i', 's', 'h', 'i', 'n', 'g'>
 : textEncodingType<text_encoding_id_MicrosoftPublishing_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'm', 'i', 'c', 'r', 'o', 's', 'o', 'f', 't', 'p', 'u', 'b', 'l', 'i', 's', 'h', 'i', 'n', 'g'>
 : textEncodingType<text_encoding_id_MicrosoftPublishing_t>
 {
 };
}
#endif
