#include <type_traits>

#include "../IANA_encodings.d/ISO102T617bit_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO102T617BITTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO102T617BITTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '0', '2', 't', '6', '1', '7', 'b', 'i', 't'>
 : textEncodingType<text_encoding_id_ISO102T617bit_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '0', '2'>
 : textEncodingType<text_encoding_id_ISO102T617bit_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 't', '6', '1', '7', 'b', 'i', 't'>
 : textEncodingType<text_encoding_id_ISO102T617bit_t>
 {
 };
}
#endif
