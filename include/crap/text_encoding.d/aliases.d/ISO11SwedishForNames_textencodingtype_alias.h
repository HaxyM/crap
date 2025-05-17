#include <type_traits>

#include "../IANA_encodings.d/ISO11SwedishForNames_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO11SWEDISHFORNAMESTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO11SWEDISHFORNAMESTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '1', 's', 'w', 'e', 'd', 'i', 's', 'h', 'f', 'o', 'r', 'n', 'a', 'm', 'e', 's'>
 : textEncodingType<text_encoding_id_ISO11SwedishForNames_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '6', '4', '6', 's', 'e', '2'>
 : textEncodingType<text_encoding_id_ISO11SwedishForNames_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '1'>
 : textEncodingType<text_encoding_id_ISO11SwedishForNames_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 's', 'e', 'n', '8', '5', '0', '2', '0', '0', 'c'>
 : textEncodingType<text_encoding_id_ISO11SwedishForNames_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 's', 'e', '2'>
 : textEncodingType<text_encoding_id_ISO11SwedishForNames_t>
 {
 };
}
#endif
