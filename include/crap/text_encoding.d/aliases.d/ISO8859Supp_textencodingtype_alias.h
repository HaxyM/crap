#include <type_traits>

#include "../IANA_encodings.d/ISO8859Supp_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO8859SUPPTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO8859SUPPTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '8', '8', '5', '9', 's', 'u', 'p', 'p'>
 : textEncodingType<text_encoding_id_ISO8859Supp_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '8', '8', '5', '9', 's', 'u', 'p', 'p'>
 : textEncodingType<text_encoding_id_ISO8859Supp_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '5', '4'>
 : textEncodingType<text_encoding_id_ISO8859Supp_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'l', 'a', 't', 'i', 'n', '1', '2', '5'>
 : textEncodingType<text_encoding_id_ISO8859Supp_t>
 {
 };
}
#endif
