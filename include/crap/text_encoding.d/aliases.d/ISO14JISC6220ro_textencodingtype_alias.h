#include <type_traits>

#include "../IANA_encodings.d/ISO14JISC6220ro_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO14JISC6220ROTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO14JISC6220ROTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '4', 'j', 'i', 's', 'c', '6', '2', '2', '0', 'r', 'o'>
 : textEncodingType<text_encoding_id_ISO14JISC6220ro_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '6', '4', '6', 'j', 'p'>
 : textEncodingType<text_encoding_id_ISO14JISC6220ro_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '4'>
 : textEncodingType<text_encoding_id_ISO14JISC6220ro_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'j', 'i', 's', 'c', '6', '2', '2', '0', '1', '9', '6', '9', 'r', 'o'>
 : textEncodingType<text_encoding_id_ISO14JISC6220ro_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'j', 'p'>
 : textEncodingType<text_encoding_id_ISO14JISC6220ro_t>
 {
 };
}
#endif
