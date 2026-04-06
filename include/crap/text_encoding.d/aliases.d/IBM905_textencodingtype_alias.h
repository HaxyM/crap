#include <type_traits>

#include "../IANA_encodings.d/IBM905_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_IBM905TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_IBM905TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '9', '0', '5'>
 : textEncodingType<text_encoding_id_IBM905_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 'b', 'm', '9', '0', '5'>
 : textEncodingType<text_encoding_id_IBM905_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'b', 'c', 'd', 'i', 'c', 'c', 'p', 't', 'r'>
 : textEncodingType<text_encoding_id_IBM905_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'b', 'm', '9', '0', '5'>
 : textEncodingType<text_encoding_id_IBM905_t>
 {
 };
}
#endif
