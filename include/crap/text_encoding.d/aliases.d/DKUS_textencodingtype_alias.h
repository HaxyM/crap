#include <type_traits>

#include "../IANA_encodings.d/DKUS_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_DKUSTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_DKUSTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'd', 'k', 'u', 's'>
 : textEncodingType<text_encoding_id_DKUS_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'd', 'k', 'u', 's'>
 : textEncodingType<text_encoding_id_DKUS_t>
 {
 };
}
#endif
