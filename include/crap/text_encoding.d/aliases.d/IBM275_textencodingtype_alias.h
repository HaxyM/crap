#include <type_traits>

#include "../IANA_encodings.d/IBM275_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM275TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM275TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '2', '7', '5'>
 : textEncodingType<text_encoding_id_IBM275_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '2', '7', '5'>
 : textEncodingType<text_encoding_id_IBM275_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'b', 'r'>
 : textEncodingType<text_encoding_id_IBM275_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '2', '7', '5'>
 : textEncodingType<text_encoding_id_IBM275_t>
 {
 };
}
#endif
