#include <type_traits>

#include "../IANA_encodings.d/INVARIANT_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_INVARIANTTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_INVARIANTTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'n', 'v', 'a', 'r', 'i', 'a', 'n', 't'>
 : textEncodingType<text_encoding_id_INVARIANT_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'n', 'v', 'a', 'r', 'i', 'a', 'n', 't'>
 : textEncodingType<text_encoding_id_INVARIANT_t>
 {
 };
}
#endif
