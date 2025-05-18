#include <type_traits>

#include "../IANA_encodings.d/ISO69French_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO69FRENCHTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO69FRENCHTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '6', '9', 'f', 'r', 'e', 'n', 'c', 'h'>
 : textEncodingType<text_encoding_id_ISO69French_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'f', 'r'>
 : textEncodingType<text_encoding_id_ISO69French_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '6', '4', '6', 'f', 'r'>
 : textEncodingType<text_encoding_id_ISO69French_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '6', '9'>
 : textEncodingType<text_encoding_id_ISO69French_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'n', 'f', 'z', '6', '2', '0', '1', '0'>
 : textEncodingType<text_encoding_id_ISO69French_t>
 {
 };
}
#endif
