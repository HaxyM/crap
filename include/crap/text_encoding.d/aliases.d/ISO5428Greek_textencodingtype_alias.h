#include <type_traits>

#include "../IANA_encodings.d/ISO5428Greek_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO5428GREEKTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO5428GREEKTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '5', '4', '2', '8', 'g', 'r', 'e', 'e', 'k'>
 : textEncodingType<text_encoding_id_ISO5428Greek_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '5', '4', '2', '8', '1', '9', '8', '0'>
 : textEncodingType<text_encoding_id_ISO5428Greek_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '5', '5'>
 : textEncodingType<text_encoding_id_ISO5428Greek_t>
 {
 };
}
#endif
