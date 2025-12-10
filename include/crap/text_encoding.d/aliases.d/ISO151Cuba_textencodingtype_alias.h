#include <type_traits>

#include "../IANA_encodings.d/ISO151Cuba_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO151CUBATEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO151CUBATEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '5', '1', 'c', 'u', 'b', 'a'>
 : textEncodingType<text_encoding_id_ISO151Cuba_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 'u', 'b', 'a'>
 : textEncodingType<text_encoding_id_ISO151Cuba_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '6', '4', '6', 'c', 'u'>
 : textEncodingType<text_encoding_id_ISO151Cuba_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '5', '1'>
 : textEncodingType<text_encoding_id_ISO151Cuba_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'n', 'c', 'n', 'c', '1', '0', '8', '1'>
 : textEncodingType<text_encoding_id_ISO151Cuba_t>
 {
 };
}
#endif
