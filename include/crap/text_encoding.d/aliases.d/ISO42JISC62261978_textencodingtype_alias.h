#include <type_traits>

#include "../IANA_encodings.d/ISO42JISC62261978_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO42JISC62261978TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO42JISC62261978TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '4', '2', 'j', 'i', 's', 'c', '6', '2', '2', '6', '1', '9', '7', '8'>
 : textEncodingType<text_encoding_id_ISO42JISC62261978_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '4', '2'>
 : textEncodingType<text_encoding_id_ISO42JISC62261978_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'j', 'i', 's', 'c', '6', '2', '2', '6', '1', '9', '7', '8'>
 : textEncodingType<text_encoding_id_ISO42JISC62261978_t>
 {
 };
}
#endif
