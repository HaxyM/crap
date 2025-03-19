#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_ISO4UNITEDKINGDOMTEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_ISO4UNITEDKINGDOMTEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_ISO4UnitedKingdom_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: ISO4UnitedKingdom>;

 template <>
 struct textEncodingType<text_encoding_id_ISO4UnitedKingdom_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_ISO4UnitedKingdom_t;
  using name = string<char, 'B', 'S', '_', '4', '7', '3', '0'>;
  using aliases = typeList<
	  string<char, 'B', 'S', '_', '4', '7', '3', '0'>,
	  string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '4'>,
	  string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'G', 'B'>,
      string<char, 'g', 'b'>,
      string<char, 'u', 'k'>,
	  string<char, 'c', 's', 'I', 'S', 'O', '4', 'U', 'n', 'i', 't', 'e', 'd', 'K', 'i', 'n', 'g', 'd', 'o', 'm'> >;
 };

 template <>
 struct textEncodingType<string<char, 'B', 'S', '_', '4', '7', '3', '0'> >
 : textEncodingType<text_encoding_id_ISO4UnitedKingdom_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'I', 'S', 'O', '4', 'U', 'n', 'i', 't', 'e', 'd', 'K', 'i', 'n', 'g', 'd', 'o', 'm'> >
 : textEncodingType<text_encoding_id_ISO4UnitedKingdom_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'g', 'b'> >
 : textEncodingType<text_encoding_id_ISO4UnitedKingdom_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'I', 'S', 'O', '6', '4', '6', '-', 'G', 'B'> >
 : textEncodingType<text_encoding_id_ISO4UnitedKingdom_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '4'> >
 : textEncodingType<text_encoding_id_ISO4UnitedKingdom_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'u', 'k'> >
 : textEncodingType<text_encoding_id_ISO4UnitedKingdom_t>
 {
 };
}
#endif
