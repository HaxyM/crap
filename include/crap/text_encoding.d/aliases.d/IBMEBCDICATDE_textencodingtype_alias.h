#include <type_traits>

#include "../IANA_encodings.d/IBMEBCDICATDE_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBMEBCDICATDETEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBMEBCDICATDETEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', 'e', 'b', 'c', 'd', 'i', 'c', 'a', 't', 'd', 'e'>
 : textEncodingType<text_encoding_id_IBMEBCDICATDE_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'a', 't', 'd', 'e'>
 : textEncodingType<text_encoding_id_IBMEBCDICATDE_t>
 {
 };
}
#endif
