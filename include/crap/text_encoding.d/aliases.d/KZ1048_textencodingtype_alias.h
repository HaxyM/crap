#include <type_traits>

#include "../IANA_encodings.d/KZ1048_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_KZ1048TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_KZ1048TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'k', 'z', '1', '0', '4', '8'>
 : textEncodingType<text_encoding_id_KZ1048_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'k', 'z', '1', '0', '4', '8'>
 : textEncodingType<text_encoding_id_KZ1048_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'r', 'k', '1', '0', '4', '8'>
 : textEncodingType<text_encoding_id_KZ1048_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 's', 't', 'r', 'k', '1', '0', '4', '8', '2', '0', '0', '2'>
 : textEncodingType<text_encoding_id_KZ1048_t>
 {
 };
}
#endif
