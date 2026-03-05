#include <type_traits>

#include "../IANA_encodings.d/IBM424_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM424TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM424TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '4', '2', '4'>
 : textEncodingType<text_encoding_id_IBM424_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '4', '2', '4'>
 : textEncodingType<text_encoding_id_IBM424_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'c', 'p', 'h', 'e'>
 : textEncodingType<text_encoding_id_IBM424_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '4', '2', '4'>
 : textEncodingType<text_encoding_id_IBM424_t>
 {
 };
}
#endif
