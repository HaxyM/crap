#include <type_traits>

#include "../IANA_encodings.d/EBCDICDKNOA_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_EBCDICDKNOATEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_EBCDICDKNOATEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'e', 'b', 'c', 'd', 'i', 'c', 'd', 'k', 'n', 'o', 'a'>
 : textEncodingType<text_encoding_id_EBCDICDKNOA_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'd', 'k', 'n', 'o', 'a'>
 : textEncodingType<text_encoding_id_EBCDICDKNOA_t>
 {
 };
}
#endif
