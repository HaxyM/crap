#include <type_traits>

#include "../IANA_encodings.d/IBM273_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM273TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM273TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '2', '7', '3'>
 : textEncodingType<text_encoding_id_IBM273_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '2', '7', '3'>
 : textEncodingType<text_encoding_id_IBM273_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '2', '7', '3'>
 : textEncodingType<text_encoding_id_IBM273_t>
 {
 };
}
#endif
