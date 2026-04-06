#include <type_traits>

#include "../IANA_encodings.d/IBM880_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM880TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM880TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '8', '8', '0'>
 : textEncodingType<text_encoding_id_IBM880_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '8', '8', '0'>
 : textEncodingType<text_encoding_id_IBM880_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'c', 'y', 'r', 'i', 'l', 'l', 'i', 'c'>
 : textEncodingType<text_encoding_id_IBM880_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '8', '8', '0'>
 : textEncodingType<text_encoding_id_IBM880_t>
 {
 };
}
#endif
