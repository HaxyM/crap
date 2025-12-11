#include <type_traits>

#include "../IANA_encodings.d/ISO158Lap_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO158LAPTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO158LAPTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '5', '8', 'l', 'a', 'p'>
 : textEncodingType<text_encoding_id_ISO158Lap_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '5', '8'>
 : textEncodingType<text_encoding_id_ISO158Lap_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'l', 'a', 'p'>
 : textEncodingType<text_encoding_id_ISO158Lap_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'l', 'a', 't', 'i', 'n', 'l', 'a', 'p'>
 : textEncodingType<text_encoding_id_ISO158Lap_t>
 {
 };
}
#endif
