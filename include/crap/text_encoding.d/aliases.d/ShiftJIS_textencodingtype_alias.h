#include <type_traits>

#include "../IANA_encodings.d/ShiftJIS_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_SHIFTJISTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_SHIFTJISTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 's', 'h', 'i', 'f', 't', 'j', 'i', 's'>
 : textEncodingType<text_encoding_id_ShiftJIS_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'm', 's', 'k', 'a', 'n', 'j', 'i'>
 : textEncodingType<text_encoding_id_ShiftJIS_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 's', 'h', 'i', 'f', 't', 'j', 'i', 's'>
 : textEncodingType<text_encoding_id_ShiftJIS_t>
 {
 };
}
#endif
