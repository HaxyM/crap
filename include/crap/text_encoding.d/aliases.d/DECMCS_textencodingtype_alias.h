#include <type_traits>

#include "../IANA_encodings.d/DECMCS_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_DECMCSTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_DECMCSTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'd', 'e', 'c', 'm', 'c', 's'>
 : textEncodingType<text_encoding_id_DECMCS_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'd', 'e', 'c'>
 : textEncodingType<text_encoding_id_DECMCS_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'd', 'e', 'c', 'm', 'c', 's'>
 : textEncodingType<text_encoding_id_DECMCS_t>
 {
 };
}
#endif
