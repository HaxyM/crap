#include <type_traits>

#include "../IANA_encodings.d/HalfWidthKatakana_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_HALFWIDTHKATAKANATEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_HALFWIDTHKATAKANATEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'h', 'a', 'l', 'f', 'w', 'i', 'd', 't', 'h', 'k', 'a', 't', 'a', 'k', 'a', 'n', 'a'>
 : textEncodingType<text_encoding_id_HalfWidthKatakana_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'j', 'i', 's', 'x', '2', '0', '1'>
 : textEncodingType<text_encoding_id_HalfWidthKatakana_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'x', '2', '0', '1'>
 : textEncodingType<text_encoding_id_HalfWidthKatakana_t>
 {
 };
}
#endif
