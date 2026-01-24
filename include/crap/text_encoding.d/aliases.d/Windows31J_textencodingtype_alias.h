#include <type_traits>

#include "../IANA_encodings.d/Windows31J_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_WINDOWS31JTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_WINDOWS31JTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'w', 'i', 'n', 'd', 'o', 'w', 's', '3', '1', 'j'>
 : textEncodingType<text_encoding_id_Windows31J_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'w', 'i', 'n', 'd', 'o', 'w', 's', '3', '1', 'j'>
 : textEncodingType<text_encoding_id_Windows31J_t>
 {
 };
}
#endif
