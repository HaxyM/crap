#include <type_traits>

#include "../IANA_encodings.d/SCSU_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_SCSUTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_SCSUTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 's', 'c', 's', 'u'>
 : textEncodingType<text_encoding_id_SCSU_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 's', 'c', 's', 'u', 'o', 'd', 'e', '1', '1'>
 : textEncodingType<text_encoding_id_SCSU_t>
 {
 };
}
#endif
