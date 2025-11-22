#include <type_traits>

#include "../IANA_encodings.d/ISO2IntlRefVersion_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO2INTLREFVERSIONTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO2INTLREFVERSIONTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '2', 'i', 'n', 't', 'l', 'r', 'e', 'f', 'v', 'e', 'r', 's', 'i', 'o', 'n'>
 : textEncodingType<text_encoding_id_ISO2IntlRefVersion_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '6', '4', '6', 'i', 'r', 'v', '1', '9', '8', '3'>
 : textEncodingType<text_encoding_id_ISO2IntlRefVersion_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 'r', 'v'>
 : textEncodingType<text_encoding_id_ISO2IntlRefVersion_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '2'>
 : textEncodingType<text_encoding_id_ISO2IntlRefVersion_t>
 {
 };
}
#endif
