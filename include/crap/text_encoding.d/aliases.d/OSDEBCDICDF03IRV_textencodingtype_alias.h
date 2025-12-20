#include <type_traits>

#include "../IANA_encodings.d/OSDEBCDICDF03IRV_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_OSDEBCDICDF03IRVTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_OSDEBCDICDF03IRVTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'o', 's', 'd', 'e', 'b', 'c', 'd', 'i', 'c', 'd', 'f', '3', 'i', 'r', 'v'>
 : textEncodingType<text_encoding_id_OSDEBCDICDF03IRV_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'o', 's', 'd', 'e', 'b', 'c', 'd', 'i', 'c', 'd', 'f', '3', 'i', 'r', 'v'>
 : textEncodingType<text_encoding_id_OSDEBCDICDF03IRV_t>
 {
 };
}
#endif
