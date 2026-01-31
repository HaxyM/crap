#include <type_traits>

#include "../IANA_encodings.d/IBM420_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM420TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM420TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '4', '2', '0'>
 : textEncodingType<text_encoding_id_IBM420_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '4', '2', '0'>
 : textEncodingType<text_encoding_id_IBM420_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'c', 'p', 'a', 'r', '1'>
 : textEncodingType<text_encoding_id_IBM420_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '4', '2', '0'>
 : textEncodingType<text_encoding_id_IBM420_t>
 {
 };
}
#endif
