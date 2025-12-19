#include <type_traits>

#include "../IANA_encodings.d/OSDEBCDICDF0415_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_OSDEBCDICDF0415TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_OSDEBCDICDF0415TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'o', 's', 'd', 'e', 'b', 'c', 'd', 'i', 'c', 'd', 'f', '4', '1', '5'>
 : textEncodingType<text_encoding_id_OSDEBCDICDF0415_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'o', 's', 'd', 'e', 'b', 'c', 'd', 'i', 'c', 'd', 'f', '4', '1', '5'>
 : textEncodingType<text_encoding_id_OSDEBCDICDF0415_t>
 {
 };
}
#endif
