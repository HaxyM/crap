#include <type_traits>

#include "../IANA_encodings.d/ISO111ECMACyrillic_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO111ECMACYRILLICTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO111ECMACYRILLICTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '1', '1', 'e', 'c', 'm', 'a', 'c', 'y', 'r', 'i', 'l', 'l', 'i', 'c'>
 : textEncodingType<text_encoding_id_ISO111ECMACyrillic_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'e', 'c', 'm', 'a', 'c', 'y', 'r', 'i', 'l', 'i', 'c'>
 : textEncodingType<text_encoding_id_ISO111ECMACyrillic_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '1', '1'>
 : textEncodingType<text_encoding_id_ISO111ECMACyrillic_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'k', 'o', 'i', '8', 'e'>
 : textEncodingType<text_encoding_id_ISO111ECMACyrillic_t>
 {
 };
}
#endif
