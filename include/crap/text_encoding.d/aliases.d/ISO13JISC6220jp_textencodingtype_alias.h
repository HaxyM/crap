#include <type_traits>

#include "../IANA_encodings.d/ISO13JISC6220jp_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO13JISC6220JPTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO13JISC6220JPTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '3', 'j', 'i', 's', 'c', '6', '2', '2', '0', 'j', 'p'>
 : textEncodingType<text_encoding_id_ISO13JISC6220jp_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '3'>
 : textEncodingType<text_encoding_id_ISO13JISC6220jp_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'j', 'i', 's', 'c', '6', '2', '2', '0', '1', '9', '6', '9'>
 : textEncodingType<text_encoding_id_ISO13JISC6220jp_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'j', 'i', 's', 'c', '6', '2', '2', '0', '1', '9', '6', '9', 'j', 'p'>
 : textEncodingType<text_encoding_id_ISO13JISC6220jp_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'k', 'a', 't', 'a', 'k', 'a', 'n', 'a'>
 : textEncodingType<text_encoding_id_ISO13JISC6220jp_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'x', '2', '0', '1', '7'>
 : textEncodingType<text_encoding_id_ISO13JISC6220jp_t>
 {
 };
}
#endif
