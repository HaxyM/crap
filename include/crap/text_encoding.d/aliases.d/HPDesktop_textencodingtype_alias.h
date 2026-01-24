#include <type_traits>

#include "../IANA_encodings.d/HPDesktop_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_HPDESKTOPTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_HPDESKTOPTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'h', 'p', 'd', 'e', 's', 'k', 't', 'o', 'p'>
 : textEncodingType<text_encoding_id_HPDesktop_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'h', 'p', 'd', 'e', 's', 'k', 't', 'o', 'p'>
 : textEncodingType<text_encoding_id_HPDesktop_t>
 {
 };
}
#endif
