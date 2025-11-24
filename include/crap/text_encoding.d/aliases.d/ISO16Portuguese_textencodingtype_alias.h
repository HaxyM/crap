#include <type_traits>

#include "../IANA_encodings.d/ISO16Portuguese_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO16PORTUGUESETEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO16PORTUGUESETEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '6', 'p', 'o', 'r', 't', 'u', 'g', 'u', 'e', 's', 'e'>
 : textEncodingType<text_encoding_id_ISO16Portuguese_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '6', '4', '6', 'p', 't'>
 : textEncodingType<text_encoding_id_ISO16Portuguese_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '6'>
 : textEncodingType<text_encoding_id_ISO16Portuguese_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'p', 't'>
 : textEncodingType<text_encoding_id_ISO16Portuguese_t>
 {
 };
}
#endif
