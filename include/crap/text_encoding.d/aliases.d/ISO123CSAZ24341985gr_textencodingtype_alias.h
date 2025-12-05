#include <type_traits>

#include "../IANA_encodings.d/ISO123CSAZ24341985gr_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO123CSAZ24341985GRTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO123CSAZ24341985GRTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'a', 'z', '2', '4', '3', '4', '1', '9', '8', '5', 'g', 'r'>
 : textEncodingType<text_encoding_id_ISO123CSAZ24341985gr_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '2', '3', 'c', 's', 'a', 'z', '2', '4', '3', '4', '1', '9', '8', '5', 'g', 'r'>
 : textEncodingType<text_encoding_id_ISO123CSAZ24341985gr_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '2', '3'>
 : textEncodingType<text_encoding_id_ISO123CSAZ24341985gr_t>
 {
 };
}
#endif
