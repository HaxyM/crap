#include <type_traits>

#include "../IANA_encodings.d/IBM281_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM281TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM281TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '2', '8', '1'>
 : textEncodingType<text_encoding_id_IBM281_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '2', '8', '1'>
 : textEncodingType<text_encoding_id_IBM281_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'j', 'p', 'e'>
 : textEncodingType<text_encoding_id_IBM281_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '2', '8', '1'>
 : textEncodingType<text_encoding_id_IBM281_t>
 {
 };
}
#endif
