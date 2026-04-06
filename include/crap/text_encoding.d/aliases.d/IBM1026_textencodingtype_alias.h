#include <type_traits>

#include "../IANA_encodings.d/IBM1026_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM1026TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM1026TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '1', '0', '2', '6'>
 : textEncodingType<text_encoding_id_IBM1026_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '1', '0', '2', '6'>
 : textEncodingType<text_encoding_id_IBM1026_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '1', '0', '2', '6'>
 : textEncodingType<text_encoding_id_IBM1026_t>
 {
 };
}
#endif
