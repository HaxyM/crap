#include <type_traits>

#include "../IANA_encodings.d/ISOTextComm_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISOTEXTCOMMTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISOTEXTCOMMTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', 't', 'e', 'x', 't', 'c', 'o', 'm', 'm'>
 : textEncodingType<text_encoding_id_ISOTextComm_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '6', '9', '3', '7', '2', 'a', 'd', 'd'>
 : textEncodingType<text_encoding_id_ISOTextComm_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '4', '2'>
 : textEncodingType<text_encoding_id_ISOTextComm_t>
 {
 };
}
#endif
