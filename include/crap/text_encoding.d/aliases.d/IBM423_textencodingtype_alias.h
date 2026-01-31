#include <type_traits>

#include "../IANA_encodings.d/IBM423_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM423TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM423TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '4', '2', '3'>
 : textEncodingType<text_encoding_id_IBM423_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '4', '2', '3'>
 : textEncodingType<text_encoding_id_IBM423_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'c', 'p', 'g', 'r'>
 : textEncodingType<text_encoding_id_IBM423_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '4', '2', '3'>
 : textEncodingType<text_encoding_id_IBM423_t>
 {
 };
}
#endif
