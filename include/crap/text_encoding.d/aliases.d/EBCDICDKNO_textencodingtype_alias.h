#include <type_traits>

#include "../IANA_encodings.d/EBCDICDKNO_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_EBCDICDKNOTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_EBCDICDKNOTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'e', 'b', 'c', 'd', 'i', 'c', 'd', 'k', 'n', 'o'>
 : textEncodingType<text_encoding_id_EBCDICDKNO_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'd', 'k', 'n', 'o'>
 : textEncodingType<text_encoding_id_EBCDICDKNO_t>
 {
 };
}
#endif
