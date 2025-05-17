#include <type_traits>

#include "../IANA_encodings.d/ISO21German_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO21GERMANTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO21GERMANTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '2', '1', 'g', 'e', 'r', 'm', 'a', 'n'>
 : textEncodingType<text_encoding_id_ISO21German_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'd', 'e'>
 : textEncodingType<text_encoding_id_ISO21German_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'd', 'i', 'n', '6', '6', '0', '0', '3'>
 : textEncodingType<text_encoding_id_ISO21German_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '6', '4', '6', 'd', 'e'>
 : textEncodingType<text_encoding_id_ISO21German_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '2', '1'>
 : textEncodingType<text_encoding_id_ISO21German_t>
 {
 };
}
#endif
