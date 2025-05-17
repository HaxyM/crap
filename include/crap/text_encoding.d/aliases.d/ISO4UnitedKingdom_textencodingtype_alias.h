#include <type_traits>

#include "../IANA_encodings.d/ISO4UnitedKingdom_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO4UNITEDKINGDOMTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO4UNITEDKINGDOMTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'b', 's', '4', '7', '3', '0'>
 : textEncodingType<text_encoding_id_ISO4UnitedKingdom_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '4', 'u', 'n', 'i', 't', 'e', 'd', 'k', 'i', 'n', 'g', 'd', 'o', 'm'>
 : textEncodingType<text_encoding_id_ISO4UnitedKingdom_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'g', 'b'>
 : textEncodingType<text_encoding_id_ISO4UnitedKingdom_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '6', '4', '6', 'g', 'b'>
 : textEncodingType<text_encoding_id_ISO4UnitedKingdom_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '4'>
 : textEncodingType<text_encoding_id_ISO4UnitedKingdom_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'u', 'k'>
 : textEncodingType<text_encoding_id_ISO4UnitedKingdom_t>
 {
 };
}
#endif
