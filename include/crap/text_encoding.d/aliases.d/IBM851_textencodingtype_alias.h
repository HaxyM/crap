#include <type_traits>

#include "../IANA_encodings.d/IBM851_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM851TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM851TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, '8', '5', '1'>
 : textEncodingType<text_encoding_id_IBM851_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '8', '5', '1'>
 : textEncodingType<text_encoding_id_IBM851_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '8', '5', '1'>
 : textEncodingType<text_encoding_id_IBM851_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '8', '5', '1'>
 : textEncodingType<text_encoding_id_IBM851_t>
 {
 };
}
#endif
