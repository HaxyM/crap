#include <type_traits>

#include "../IANA_encodings.d/IBM284_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM284TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM284TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '2', '8', '4'>
 : textEncodingType<text_encoding_id_IBM284_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '2', '8', '4'>
 : textEncodingType<text_encoding_id_IBM284_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'c', 'p', 'e', 's'>
 : textEncodingType<text_encoding_id_IBM284_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '2', '8', '4'>
 : textEncodingType<text_encoding_id_IBM284_t>
 {
 };
}
#endif
