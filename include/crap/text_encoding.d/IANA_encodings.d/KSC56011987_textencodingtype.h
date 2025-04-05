#include <type_traits>

#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_IANAENCODINGS_KSC56011987TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_IANAENCODINGS_KSC56011987TEXTENCODINGTYPE

namespace crap
{
 using text_encoding_id_KSC56011987_t =
	  std :: integral_constant<textEncodingType <void> :: id, textEncodingType <void> :: id :: KSC56011987>;

 template <>
 struct textEncodingType<text_encoding_id_KSC56011987_t> : textEncodingType<void>
 {
  using mib = text_encoding_id_KSC56011987_t;
  using name = string<char, 'K', 'S', '_', 'C', '_', '5', '6', '0', '1', '-', '1', '9', '8', '7'>;
  using aliases = typeList<
	  string<char, 'K', 'S', '_', 'C', '_', '5', '6', '0', '1', '-'. '1', '9', '8', '7'>,
      string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '4', '9'>,
      string<char, 'K', 'S', '_', 'C', '_', '5', '6', '0', '1', '-', '1', '9', '8', '9'>,
	  string<char, 'K', 'S', 'C', '_', '5', '6', '0', '1'>,
	  string<char, 'k', 'o', 'r', 'e', 'a', 'n'>,
	  string<char, 'c', 's', 'K', 'S', 'C', '5', '6', '0', '1', '1', '9', '8', '7'> >;
 };

 template <>
 struct textEncodingType<string<char, 'c', 's', 'K', 'S', 'C', '5', '6', '0', '1', '1', '9', '8', '7'> >
 : textEncodingType<text_encoding_id_KSC56011987_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'i', 's', 'o', '-', 'i', 'r', '-', '1', '4', '9'> >
 : textEncodingType<text_encoding_id_KSC56011987_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'K', 'S', 'C', '_', '5', '6', '0', '1'> >
 : textEncodingType<text_encoding_id_KSC56011987_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'K', 'S', '_', 'C', '_', '5', '6', '0', '1', '-', '1', '9', '8', '7'> >
 : textEncodingType<text_encoding_id_KSC56011987_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'K', 'S', '_', 'C', '_', '5', '6', '0', '1', '-', '1', '9', '8', '9'> >
 : textEncodingType<text_encoding_id_KSC56011987_t>
 {
 };

 template <>
 struct textEncodingType<string<char, 'k', 'o', 'r', 'e', 'a', 'n'> >
 : textEncodingType<text_encoding_id_KSC56011987_t>
 {
 };
}
#endif
