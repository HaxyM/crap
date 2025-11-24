#include <type_traits>

#include "../IANA_encodings.d/ISO47BSViewdata_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO47BSVIEWDATATEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO47BSVIEWDATATEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'b', 's', 'v', 'i', 'e', 'w', 'd', 'a', 't', 'a'>
 : textEncodingType<text_encoding_id_ISO47BSViewdata_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '4', '7', 'b', 's', 'v', 'i', 'e', 'w', 'd', 'a', 't', 'a'>
 : textEncodingType<text_encoding_id_ISO47BSViewdata_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '4', '7'>
 : textEncodingType<text_encoding_id_ISO47BSViewdata_t>
 {
 };
}
#endif
