#include <type_traits>

#include "../IANA_encodings.d/ISO94JIS62291984hand_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO94JIS62291984HANDTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO94JIS62291984HANDTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '9', '4', 'j', 'i', 's', '6', '2', '2', '9', '1', '9', '8', '4', 'h', 'a', 'n', 'd'>
 : textEncodingType<text_encoding_id_ISO94JIS62291984hand_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '9', '4'>
 : textEncodingType<text_encoding_id_ISO94JIS62291984hand_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'j', 'i', 's', 'c', '6', '2', '2', '9', '1', '9', '8', '4', 'h', 'a', 'n', 'd'>
 : textEncodingType<text_encoding_id_ISO94JIS62291984hand_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'j', 'p', 'o', 'c', 'r', 'h', 'a', 'n', 'd'>
 : textEncodingType<text_encoding_id_ISO94JIS62291984hand_t>
 {
 };
}
#endif
