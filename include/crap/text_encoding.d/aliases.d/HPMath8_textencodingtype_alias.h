#include <type_traits>

#include "../IANA_encodings.d/HPMath8_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_HPMATH8TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_HPMATH8TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'h', 'p', 'm', 'a', 't', 'h', '8'>
 : textEncodingType<text_encoding_id_HPMath8_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'h', 'p', 'm', 'a', 't', 'h', '8'>
 : textEncodingType<text_encoding_id_HPMath8_t>
 {
 };
}
#endif
