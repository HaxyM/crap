#include <type_traits>

#include "../IANA_encodings.d/ISO25French_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO25FRENCHTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO25FRENCHTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '2', '5', 'f', 'r', 'e', 'n', 'c', 'h'>
 : textEncodingType<text_encoding_id_ISO25French_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '6', '4', '6', 'f', 'r', '1'>
 : textEncodingType<text_encoding_id_ISO25French_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '2', '5'>
 : textEncodingType<text_encoding_id_ISO25French_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'n', 'f', 'z', '6', '2', '0', '1', '0','1', '9', '7', '3'>
 : textEncodingType<text_encoding_id_ISO25French_t>
 {
 };
}
#endif
