#include <type_traits>

#include "../IANA_encodings.d/HPPSMath_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_HPPSMATHTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_HPPSMATHTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'a', 'd', 'o', 'b', 'e', 's', 'y', 'm', 'b', 'o', 'l', 'e', 'n', 'c', 'o', 'd', 'i', 'n', 'g'>
 : textEncodingType<text_encoding_id_HPPSMath_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'h', 'p', 'p', 's', 'm', 'a', 't', 'h'>
 : textEncodingType<text_encoding_id_HPPSMath_t>
 {
 };
}
#endif
