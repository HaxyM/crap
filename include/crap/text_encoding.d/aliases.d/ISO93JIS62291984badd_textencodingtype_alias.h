#include <type_traits>

#include "../IANA_encodings.d/ISO93JIS62291984badd_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO93JIS62291984BADDTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO93JIS62291984BADDTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '9', '3', 'j', 'i', 's', '6', '2', '2', '9', '1', '9', '8', '4', 'b', 'a', 'd', 'd'>
 : textEncodingType<text_encoding_id_ISO93JIS62291984badd_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '9', '3'>
 : textEncodingType<text_encoding_id_ISO93JIS62291984badd_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'j', 'i', 's', 'c', '6', '2', '2', '9', '1', '9', '8', '4', 'b', 'a', 'd', 'd'>
 : textEncodingType<text_encoding_id_ISO93JIS62291984badd_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'j', 'p', 'o', 'c', 'r', 'b', 'a', 'd', 'd'>
 : textEncodingType<text_encoding_id_ISO93JIS62291984badd_t>
 {
 };
}
#endif
