#include <type_traits>

#include "../IANA_encodings.d/UTF7IMAP_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_UTF7IMAPTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_UTF7IMAPTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'u', 't', 'f', '7', 'i', 'm', 'a', 'p'>
 : textEncodingType<text_encoding_id_UTF7IMAP_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'u', 't', 'f', '7', 'i', 'm', 'a', 'p'>
 : textEncodingType<text_encoding_id_UTF7IMAP_t>
 {
 };
}
#endif
