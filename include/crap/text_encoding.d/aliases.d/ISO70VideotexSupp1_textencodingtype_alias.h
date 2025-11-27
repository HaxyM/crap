#include <type_traits>

#include "../IANA_encodings.d/ISO70VideotexSupp1_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO70VIDEOTEXSUPP1TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO70VIDEOTEXSUPP1TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '7', '0', 'v', 'i', 'd', 'e', 'o', 't', 'e', 'x', 's', 'u', 'p', 'p', '1'>
 : textEncodingType<text_encoding_id_ISO70VideotexSupp1_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '7', '0'>
 : textEncodingType<text_encoding_id_ISO70VideotexSupp1_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'v', 'i', 'd', 'e', 'o', 't', 'e', 'x', 's', 'u', 'p', 'p', 'l'>
 : textEncodingType<text_encoding_id_ISO70VideotexSupp1_t>
 {
 };
}
#endif
