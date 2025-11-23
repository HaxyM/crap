#include <type_traits>

#include "../IANA_encodings.d/ISO2022JP2_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO2022JP2TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO2022JP2TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '2', '0', '2', '2', 'j', 'p', '2'>
 : textEncodingType<text_encoding_id_ISO2022JP2_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '2', '0', '2', '2', 'j', 'p', '2'>
 : textEncodingType<text_encoding_id_ISO2022JP2_t>
 {
 };
}
#endif
