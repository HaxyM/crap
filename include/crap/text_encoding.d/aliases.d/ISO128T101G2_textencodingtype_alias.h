#include <type_traits>

#include "../IANA_encodings.d/ISO128T101G2_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO128T101G2TEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO128T101G2TEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '2', '8', 't', '1', '0', '1', 'g', '2'>
 : textEncodingType<text_encoding_id_ISO128T101G2_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '2', '8'>
 : textEncodingType<text_encoding_id_ISO128T101G2_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 't', '1', '0', '1', 'g', '2'>
 : textEncodingType<text_encoding_id_ISO128T101G2_t>
 {
 };
}
#endif
