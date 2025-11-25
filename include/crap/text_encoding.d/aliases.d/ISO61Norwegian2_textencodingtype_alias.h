#include <type_traits>

#include "../IANA_encodings.d/ISO61Norwegian2_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO61NORWEGIAN2TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO61NORWEGIAN2TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '6', '1', 'n', 'o', 'r', 'w', 'e', 'g', 'i', 'a', 'n', '2'>
 : textEncodingType<text_encoding_id_ISO61Norwegian2_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '6', '4', '6', 'n', 'o', '2'>
 : textEncodingType<text_encoding_id_ISO61Norwegian2_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '6', '1'>
 : textEncodingType<text_encoding_id_ISO61Norwegian2_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'n', 's', '4', '5', '5', '1', '2'>
 : textEncodingType<text_encoding_id_ISO61Norwegian2_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'n', 'o', '2'>
 : textEncodingType<text_encoding_id_ISO61Norwegian2_t>
 {
 };
}
#endif
