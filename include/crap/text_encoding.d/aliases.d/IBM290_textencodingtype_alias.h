#include <type_traits>

#include "../IANA_encodings.d/IBM290_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM290TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM290TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '2', '9', '0'>
 : textEncodingType<text_encoding_id_IBM290_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '2', '9', '0'>
 : textEncodingType<text_encoding_id_IBM290_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'j', 'p', 'k', 'a', 'n', 'a'>
 : textEncodingType<text_encoding_id_IBM290_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '2', '9', '0'>
 : textEncodingType<text_encoding_id_IBM290_t>
 {
 };
}
#endif
