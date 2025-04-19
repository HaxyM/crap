#include <type_traits>

#include "../IANA_encodings.d/ISOLatinCyrillic_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISOLATINCYRILLICTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISOLATINCYRILLICTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', 'l', 'a', 't', 'i', 'n', 'c', 'y', 'r', 'i', 'l', 'l', 'i', 'c'>
 : textEncodingType<text_encoding_id_ISOLatinCyrillic_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'y', 'r', 'i', 'l', 'l', 'i', 'c'>
 : textEncodingType<text_encoding_id_ISOLatinCyrillic_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '8', '8', '5', '9', '5'>
 : textEncodingType<text_encoding_id_ISOLatinCyrillic_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '8', '8', '5', '9', '5', '1', '9', '8', '8'>
 : textEncodingType<text_encoding_id_ISOLatinCyrillic_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '4', '4'>
 : textEncodingType<text_encoding_id_ISOLatinCyrillic_t>
 {
 };
}
#endif
