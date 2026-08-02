#include <type_traits>

#include "../IANA_encodings.d/BIG5HKSCS_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_Big5HKSCSTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_Big5HKSCSTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'b', 'i', 'g', '5', 'h', 'k', 's', 'c', 's'>
 : textEncodingType<text_encoding_id_Big5HKSCS_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'b', 'i', 'g', '5', 'h', 'k', 's', 'c', 's'>
 : textEncodingType<text_encoding_id_Big5HKSCS_t>
 {
 };
}
#endif
