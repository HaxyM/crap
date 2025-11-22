#include <type_traits>

#include "../IANA_encodings.d/NATSSEFI_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_NATSSEFITEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_NATSSEFITEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'n', 'a', 't', 's', 's', 'e', 'f', 'i'>
 : textEncodingType<text_encoding_id_NATSSEFI_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '8', '1'>
 : textEncodingType<text_encoding_id_NATSSEFI_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'n', 'a', 't', 's', 's', 'e', 'f', 'i'>
 : textEncodingType<text_encoding_id_NATSSEFI_t>
 {
 };
}
#endif
