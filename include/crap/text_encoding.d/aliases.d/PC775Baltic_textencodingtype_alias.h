#include <type_traits>

#include "../IANA_encodings.d/PC775Baltic_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_PC775BALTICTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_PC775BALTICTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '7', '7', '5'>
 : textEncodingType<text_encoding_id_PC775Baltic_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'p', 'c', '7', '7', '5', 'b', 'a', 'l', 't', 'i', 'c'>
 : textEncodingType<text_encoding_id_PC775Baltic_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '7', '7', '5'>
 : textEncodingType<text_encoding_id_PC775Baltic_t>
 {
 };
}
#endif
