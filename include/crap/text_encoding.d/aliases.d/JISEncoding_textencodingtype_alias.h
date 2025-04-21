#include <type_traits>

#include "../IANA_encodings.d/JISEncoding_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_JISENCODINGTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_JISENCODINGTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'j', 'i', 's', 'e', 'n', 'c', 'o', 'd', 'i', 'n', 'g'>
 : textEncodingType<text_encoding_id_JISEncoding_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'j', 'i', 's', 'e', 'n', 'c', 'o', 'd', 'i', 'n', 'g'>
 : textEncodingType<text_encoding_id_JISEncoding_t>
 {
 };
}
#endif
