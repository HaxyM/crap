#include <type_traits>

#include "../IANA_encodings.d/IBM891_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM891TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM891TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '8', '9', '1'>
 : textEncodingType<text_encoding_id_IBM891_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '8', '9', '1'>
 : textEncodingType<text_encoding_id_IBM891_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '8', '9', '1'>
 : textEncodingType<text_encoding_id_IBM891_t>
 {
 };
}
#endif
