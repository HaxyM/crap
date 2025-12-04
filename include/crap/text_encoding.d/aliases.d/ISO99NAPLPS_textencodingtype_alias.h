#include <type_traits>

#include "../IANA_encodings.d/ISO99NAPLPS_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO99NAPLPSTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO99NAPLPSTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'a', 'n', 's', 'i', 'x', '3', '1', '1', '0', '1', '9', '8', '3'>
 : textEncodingType<text_encoding_id_ISO99NAPLPS_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'a', 't', '5', '0', '0', '1', '9', '8', '3'>
 : textEncodingType<text_encoding_id_ISO99NAPLPS_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '9', '9', 'n', 'a', 'p', 'l', 'p', 's'>
 : textEncodingType<text_encoding_id_ISO99NAPLPS_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '9', '9'>
 : textEncodingType<text_encoding_id_ISO99NAPLPS_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'n', 'a', 'p', 'l', 'p', 's'>
 : textEncodingType<text_encoding_id_ISO99NAPLPS_t>
 {
 };
}
#endif
