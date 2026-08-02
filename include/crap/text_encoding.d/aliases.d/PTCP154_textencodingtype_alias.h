#include <type_traits>

#include "../IANA_encodings.d/PTCP154_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_PTCP154TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_PTCP154TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'p', '1', '5', '4'>
 : textEncodingType<text_encoding_id_PTCP154_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'p', 't', 'c', 'p', '1', '5', '4'>
 : textEncodingType<text_encoding_id_PTCP154_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'y', 'r', 'i', 'l', 'l', 'i', 'c', 'a', 's', 'i', 'a', 'n'>
 : textEncodingType<text_encoding_id_PTCP154_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'p', 't', '1', '5', '4'>
 : textEncodingType<text_encoding_id_PTCP154_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'p', 't', 'c', 'p', '1', '5', '4'>
 : textEncodingType<text_encoding_id_PTCP154_t>
 {
 };
}
#endif
