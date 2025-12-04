#include <type_traits>

#include "../IANA_encodings.d/ISO103T618bit_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_ISO103T618BITTEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_ISO103T618BITTEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'i', 's', 'o', '1', '0', '3', 't', '6', '1', '8', 'b', 'i', 't'>
 : textEncodingType<text_encoding_id_ISO103T618bit_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', 'i', 'r', '1', '0', '3'>
 : textEncodingType<text_encoding_id_ISO103T618bit_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 't', '6', '1'>
 : textEncodingType<text_encoding_id_ISO103T618bit_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 't', '6', '1', '8', 'b', 'i', 't'>
 : textEncodingType<text_encoding_id_ISO103T618bit_t>
 {
 };
}
#endif
