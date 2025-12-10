#include <type_traits>

#include "../IANA_encodings.d/ISO143IECP271_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO143IECP271TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO143IECP271TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '4', '3', 'i', 'e', 'c', 'p', '2', '7', '1'>
 : textEncodingType<text_encoding_id_ISO143IECP271_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'e', 'c', 'p', '2', '7', '1'>
 : textEncodingType<text_encoding_id_ISO143IECP271_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '4', '3'>
 : textEncodingType<text_encoding_id_ISO143IECP271_t>
 {
 };
}
#endif
