#include <type_traits>

#include "../IANA_encodings.d/ISO6937Add_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO6937ADDTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO6937ADDTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '6', '9', '3', '7', 'a', 'd', 'd'>
 : textEncodingType<text_encoding_id_ISO6937Add_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '6', '9', '3', '7', '2', '2', '5'>
 : textEncodingType<text_encoding_id_ISO6937Add_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '5', '2'>
 : textEncodingType<text_encoding_id_ISO6937Add_t>
 {
 };
}
#endif
