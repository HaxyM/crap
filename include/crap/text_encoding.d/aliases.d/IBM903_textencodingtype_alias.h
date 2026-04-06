#include <type_traits>

#include "../IANA_encodings.d/IBM903_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM903TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM903TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '9', '0', '3'>
 : textEncodingType<text_encoding_id_IBM903_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '9', '0', '3'>
 : textEncodingType<text_encoding_id_IBM903_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '9', '0', '3'>
 : textEncodingType<text_encoding_id_IBM903_t>
 {
 };
}
#endif
