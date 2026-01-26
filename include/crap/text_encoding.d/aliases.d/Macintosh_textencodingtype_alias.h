#include <type_traits>

#include "../IANA_encodings.d/Macintosh_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_MACINTOSHTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_MACINTOSHTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'm', 'a', 'c', 'i', 'n', 't', 'o', 's', 'h'>
 : textEncodingType<text_encoding_id_Macintosh_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'm', 'a', 'c'>
 : textEncodingType<text_encoding_id_Macintosh_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'm', 'a', 'c', 'i', 'n', 't', 'o', 's', 'h'>
 : textEncodingType<text_encoding_id_Macintosh_t>
 {
 };
}
#endif
