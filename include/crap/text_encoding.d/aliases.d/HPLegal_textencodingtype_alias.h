#include <type_traits>

#include "../IANA_encodings.d/HPLegal_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_HPLEGALTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_HPLEGALTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'h', 'p', 'l', 'e', 'g', 'a', 'l'>
 : textEncodingType<text_encoding_id_HPLegal_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'h', 'p', 'l', 'e', 'g', 'a', 'l'>
 : textEncodingType<text_encoding_id_HPLegal_t>
 {
 };
}
#endif
