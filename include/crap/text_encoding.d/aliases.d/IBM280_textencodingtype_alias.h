#include <type_traits>

#include "../IANA_encodings.d/IBM280_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM280TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM280TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '2', '8', '0'>
 : textEncodingType<text_encoding_id_IBM280_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '2', '8', '0'>
 : textEncodingType<text_encoding_id_IBM280_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'c', 'p', 'i', 't'>
 : textEncodingType<text_encoding_id_IBM280_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '2', '8', '0'>
 : textEncodingType<text_encoding_id_IBM280_t>
 {
 };
}
#endif
