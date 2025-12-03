#include <type_traits>

#include "../IANA_encodings.d/ISO95JIS62291984handadd_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO95JIS62291984HANDADDTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO95JIS62291984HANDADDTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '9', '5', 'j', 'i', 's', '6', '2', '2', '9', '1', '9', '8', '4', 'h', 'a', 'n', 'd', 'a', 'd', 'd'>
 : textEncodingType<text_encoding_id_ISO95JIS62291984handadd_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '9', '5'>
 : textEncodingType<text_encoding_id_ISO95JIS62291984handadd_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'j', 'i', 's', 'c', '6', '2', '2', '9', '1', '9', '8', '4', 'h', 'a', 'n', 'd', 'a', 'd', 'd'>
 : textEncodingType<text_encoding_id_ISO95JIS62291984handadd_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'j', 'p', 'o', 'c', 'r', 'h', 'a', 'n', 'd', 'a', 'd', 'd'>
 : textEncodingType<text_encoding_id_ISO95JIS62291984handadd_t>
 {
 };
}
#endif
