#include <type_traits>

#include "../IANA_encodings.d/IBM864_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM864TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM864TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '8', '6', '4'>
 : textEncodingType<text_encoding_id_IBM864_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '8', '6', '4'>
 : textEncodingType<text_encoding_id_IBM864_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '8', '6', '4'>
 : textEncodingType<text_encoding_id_IBM864_t>
 {
 };
}
#endif
