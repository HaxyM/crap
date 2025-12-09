#include <type_traits>

#include "../IANA_encodings.d/ISO139CSN369103_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO139CSN369103TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO139CSN369103TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '3', '9', 'c', 's', 'n', '3', '6', '9', '1', '0', '3'>
 : textEncodingType<text_encoding_id_ISO139CSN369103_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'n', '3', '6', '9', '1', '0', '3'>
 : textEncodingType<text_encoding_id_ISO139CSN369103_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '3', '9'>
 : textEncodingType<text_encoding_id_ISO139CSN369103_t>
 {
 };
}
#endif
