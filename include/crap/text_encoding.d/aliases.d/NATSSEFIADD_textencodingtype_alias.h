#include <type_traits>

#include "../IANA_encodings.d/NATSSEFIADD_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_NATSSEFIADDTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_NATSSEFIADDTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'n', 'a', 't', 's', 's', 'e', 'f', 'i', 'a', 'd', 'd'>
 : textEncodingType<text_encoding_id_NATSSEFIADD_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '8', '2'>
 : textEncodingType<text_encoding_id_NATSSEFIADD_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'n', 'a', 't', 's', 's', 'e', 'f', 'i', 'a', 'd', 'd'>
 : textEncodingType<text_encoding_id_NATSSEFIADD_t>
 {
 };
}
#endif
