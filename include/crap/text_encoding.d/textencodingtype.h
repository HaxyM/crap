#ifndef CRAP_TEXTENCODING_TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_TEXTENCODINGTYPE

#include "../string.d/string.h"
#include "../utility.d/typelist.h"
#include "../version.d/libtextencoding.h"

#include <utility>

#if (crap_lib_text_encoding >= 202306L)
#include <text_encoding>
#else
#include <cstdint>
#endif

namespace crap
{
 template <class = void> struct textEncodingType;

 template <> struct textEncodingType<void>
 {
#if (crap_lib_text_encoding >= 202306L)
  using id = std :: text_encoding :: id;
#else
  enum class id : std :: int_least32_t
#endif
  template <class, class...> struct literal;
  template <class ... Ignored> struct literal<char, Ignored...>;
  template <class ... Ignored> struct literal<wchar_t, Ignored...>;
 };

#if (crap_lib_text_encoding >= 202306L)
#else
#if defined(__GNUC__) && !defined(__clang__)
 template <>
#endif
 enum class textEncodingType<void> :: id : std :: int_least32_t
 {
  other = INT32_C(1),
  unknown = INT32_C(2),
  ASCII = INT32_C(3),
  ISOLatin1 = INT32_C(4),
  ISOLatin2 = INT32_C(5),
  ISOLatin3 = INT32_C(6),
  ISOLatin4 = INT32_C(7),
  ISOLatinCyrillic = INT32_C(8),
  ISOLatinArabic = INT32_C(9),
  ISOLatinGreek = INT32_C(10),
  ISOLatinHebrew = INT32_C(11),
  ISOLatin5 = INT32_C(12),
  ISOLatin6 = INT32_C(13),
  ISOTextComm = INT32_C(14),
  HalfWidthKatakana = INT32_C(15),
  JISEncoding = INT32_C(16),
  ShiftJIS = INT32_C(17),
  EUCPkdFmtJapanese = INT32_C(18),
  EUCFixWidJapanese = INT32_C(19),
  ISO4UnitedKingdom = INT32_C(20),
  ISO11SwedishForNames = INT32_C(21),
  ISO15Italian = INT32_C(22),
  ISO17Spanish = INT32_C(23),
  ISO21German = INT32_C(24),
  ISO60DanishNorwegian = INT32_C(25),
  ISO69French = INT32_C(26),
  ISO10646UTF1 = INT32_C(27),
  ISO646basic1983 = INT32_C(28),
  INVARIANT = INT32_C(29),
  ISO2IntlRefVersion = INT32_C(30),
  NATSSEFI = INT32_C(31),
  NATSSEFIADD = INT32_C(32),
  //NATSDYNO = INT32_C(33), //Excluded from standard
  //NATSDYNOADD = INT32_C(34), //Excluded from standard
  ISO10Swedish = INT32_C(35),
  KSC56011987 = INT32_C(36),
  ISO2022KR = INT32_C(37),
  EUCKR = INT32_C(38),
  ISO2022JP = INT32_C(39),
  ISO2022JP2 = INT32_C(40),
  ISO13JISC6220jp = INT32_C(41),
  ISO14JISC6220ro = INT32_C(42),
  ISO16Portuguese = INT32_C(43),
  ISO18Greek7Old = INT32_C(44),
  ISO19LatinGreek = INT32_C(45),
  ISO25French = INT32_C(46),
  ISO27LatinGreek1 = INT32_C(47),
  ISO5427Cyrillic = INT32_C(48),
  ISO42JISC62261978 = INT32_C(49),
  ISO47BSViewdata = INT32_C(50),
  ISO49INIS = INT32_C(51),
  ISO50INIS8 = INT32_C(52),
  ISO51INISCyrillic = INT32_C(53),
  ISO54271981 = INT32_C(54),
  ISO5428Greek = INT32_C(55),
  ISO57GB1988 = INT32_C(56),
  ISO58GB231280 = INT32_C(57),
  ISO61Norwegian2 = INT32_C(58),
  ISO70VideotexSupp1 = INT32_C(59),
  ISO84Portuguese2 = INT32_C(60),
  ISO85Spanish2 = INT32_C(61),
  ISO86Hungarian = INT32_C(62),
  ISO87JISX0208 = INT32_C(63),
  ISO88Greek7 = INT32_C(64),
  ISO89ASMO449 = INT32_C(65),
  ISO90 = INT32_C(66),
  ISO91JISC62291984a = INT32_C(67),
  ISO92JISC62991984b = INT32_C(68),
  ISO93JIS62291984badd = INT32_C(69),
  ISO94JIS62291984hand = INT32_C(70),
  ISO95JIS62291984handadd = INT32_C(71),
  ISO96JISC62291984kana = INT32_C(72),
  ISO2033 = INT32_C(73),
  ISO99NAPLPS = INT32_C(74),
  ISO102T617bit = INT32_C(75),
  ISO103T618bit = INT32_C(76),
  ISO111ECMACyrillic = INT32_C(77),
  ISO121Canadian1 = INT32_C(78),
  ISO122Canadian2 = INT32_C(79),
  ISO123CSAZ24341985gr = INT32_C(80),
  ISO88596E = INT32_C(81),
  ISO88596I = INT32_C(82),
  ISO128T101G2 = INT32_C(83),
  ISO88598E = INT32_C(84),
  ISO88598I = INT32_C(85),
  ISO139CSN369103 = INT32_C(86),
  ISO141JUSIB1002 = INT32_C(87),
  ISO143IECP271 = INT32_C(88),
  ISO146Serbian = INT32_C(89),
  ISO147Macedonian = INT32_C(90),
  ISO150 = INT32_C(91),
  ISO151Cuba = INT32_C(92),
  ISO6937Add = INT32_C(93),
  ISO153GOST1976874 = INT32_C(94),
  ISO8859Supp = INT32_C(95),
  ISO10367Box = INT32_C(96),
  ISO158Lap = INT32_C(97),
  ISO159JISX02121990 = INT32_C(98),
  ISO646Danish = INT32_C(99),
  USDK = INT32_C(100),
  DKUS = INT32_C(101),
  KSC5636 = INT32_C(102),
  Unicode11UTF7 = INT32_C(103),
  ISO2022CN = INT32_C(104),
  ISO2022CNEXT = INT32_C(105),
  UTF8 = INT32_C(106),
  ISO885913 = INT32_C(109),
  ISO885914 = INT32_C(110),
  ISO885915 = INT32_C(111),
  ISO885916 = INT32_C(112),
  GBK = INT32_C(113),
  GB18030 = INT32_C(114),
  OSDEBCDICDF0415 = INT32_C(115),
  OSDEBCDICDF03IRV = INT32_C(116),
  OSDEBCDICDF041 = INT32_C(117),
  ISO115481 = INT32_C(118),
  KZ1048 = INT32_C(119),
  UCS2 = INT32_C(1000),
  UCS4 = INT32_C(1001),
  UnicodeASCII = INT32_C(1002),
  UnicodeLatin1 = INT32_C(1003),
  UnicodeJapanese = INT32_C(1004),
  UnicodeIBM1261 = INT32_C(1005),
  UnicodeIBM1268 = INT32_C(1006),
  UnicodeIBM1276 = INT32_C(1007),
  UnicodeIBM1264 = INT32_C(1008),
  UnicodeIBM1265 = INT32_C(1009),
  Unicode11 = INT32_C(1010),
  SCSU = INT32_C(1011),
  UTF7 = INT32_C(1012),
  UTF16BE = INT32_C(1013),
  UTF16LE = INT32_C(1014),
  UTF16 = INT32_C(1015),
  CESU8 = INT32_C(1016),
  UTF32 = INT32_C(1017),
  UTF32BE = INT32_C(1018),
  UTF32LE = INT32_C(1019),
  BOCU1 = INT32_C(1020),
  UTF7IMAP = INT32_C(1021),
  Windows30Latin1 = INT32_C(2000),
  Windows31Latin1 = INT32_C(2001),
  Windows31Latin2 = INT32_C(2002),
  Windows31Latin5 = INT32_C(2003),
  HPRoman8 = INT32_C(2004),
  AdobeStandardEncoding = INT32_C(2005),
  VenturaUS = INT32_C(2006),
  VenturaInternational = INT32_C(2007),
  DECMCS = INT32_C(2008),
  PC850Multilingual = INT32_C(2009),
  PC8DanishNorwegian = INT32_C(2012),
  PC862LatinHebrew = INT32_C(2013),
  PC8Turkish = INT32_C(2014),
  IBMSymbols = INT32_C(2015),
  IBMThai = INT32_C(2016),
  HPLegal = INT32_C(2017),
  HPPiFont = INT32_C(2018),
  HPMath8 = INT32_C(2019),
  HPPSMath = INT32_C(2020),
  HPDesktop = INT32_C(2021),
  VenturaMath = INT32_C(2022),
  MicrosoftPublishing = INT32_C(2023),
  Windows31J = INT32_C(2024),
  GB2312 = INT32_C(2025),
  Big5 = INT32_C(2026),
  Macintosh = INT32_C(2027),
  IBM037 = INT32_C(2028),
  IBM038 = INT32_C(2029),
  IBM273 = INT32_C(2030),
  IBM274 = INT32_C(2031),
  IBM275 = INT32_C(2032),
  IBM277 = INT32_C(2033),
  IBM278 = INT32_C(2034),
  IBM280 = INT32_C(2035),
  IBM281 = INT32_C(2036),
  IBM284 = INT32_C(2037),
  IBM285 = INT32_C(2038),
  IBM290 = INT32_C(2039),
  IBM297 = INT32_C(2040),
  IBM420 = INT32_C(2041),
  IBM423 = INT32_C(2042),
  IBM424 = INT32_C(2043),
  PC8CodePage437 = INT32_C(2011),
  IBM500 = INT32_C(2044),
  IBM851 = INT32_C(2045),
  PCp852 = INT32_C(2010),
  IBM855 = INT32_C(2046),
  IBM857 = INT32_C(2047),
  IBM860 = INT32_C(2048),
  IBM861 = INT32_C(2049),
  IBM863 = INT32_C(2050),
  IBM864 = INT32_C(2051),
  IBM865 = INT32_C(2052),
  IBM868 = INT32_C(2053),
  IBM869 = INT32_C(2054),
  IBM870 = INT32_C(2055),
  IBM871 = INT32_C(2056),
  IBM880 = INT32_C(2057),
  IBM891 = INT32_C(2058),
  IBM903 = INT32_C(2059),
  IBM904 = INT32_C(2060),
  IBM905 = INT32_C(2061),
  IBM918 = INT32_C(2062),
  IBM1026 = INT32_C(2063),
  IBMEBCDICATDE = INT32_C(2064),
  EBCDICATDEA = INT32_C(2065),
  EBCDICCAFR = INT32_C(2066),
  EBCDICDKNO = INT32_C(2067),
  EBCDICDKNOA = INT32_C(2068),
  EBCDICFISE = INT32_C(2069),
  EBCDICFISEA = INT32_C(2070),
  EBCDICFR = INT32_C(2071),
  EBCDICIT = INT32_C(2072),
  EBCDICPT = INT32_C(2073),
  EBCDICES = INT32_C(2074),
  EBCDICESA = INT32_C(2075),
  EBCDICESS = INT32_C(2076),
  EBCDICUK = INT32_C(2077),
  EBCDICUS = INT32_C(2078),
  Unknown8BiT = INT32_C(2079),
  Mnemonic = INT32_C(2080),
  Mnem = INT32_C(2081),
  VISCII = INT32_C(2082),
  VIQR = INT32_C(2083),
  KOI8R = INT32_C(2084),
  HZGB2312 = INT32_C(2085),
  IBM866 = INT32_C(2086),
  PC775Baltic = INT32_C(2087),
  KOI8U = INT32_C(2088),
  IBM00858 = INT32_C(2089),
  IBM00924 = INT32_C(2090),
  IBM01140 = INT32_C(2091),
  IBM01141 = INT32_C(2092),
  IBM01142 = INT32_C(2093),
  IBM01143 = INT32_C(2094),
  IBM01144 = INT32_C(2095),
  IBM01145 = INT32_C(2096),
  IBM01146 = INT32_C(2097),
  IBM01147 = INT32_C(2098),
  IBM01148 = INT32_C(2099),
  IBM01149 = INT32_C(2100),
  Big5HKSCS = INT32_C(2101),
  IBM1047 = INT32_C(2102),
  PTCP154 = INT32_C(2103),
  Amiga1251 = INT32_C(2104),
  KOI7switched = INT32_C(2105),
  BRF = INT32_C(2106),
  TSCII = INT32_C(2107),
  CP51932 = INT32_C(2108),
  windows874 = INT32_C(2109),
  windows1250 = INT32_C(2250),
  windows1251 = INT32_C(2251),
  windows1252 = INT32_C(2252),
  windows1253 = INT32_C(2253),
  windows1254 = INT32_C(2254),
  windows1255 = INT32_C(2255),
  windows1256 = INT32_C(2256),
  windows1257 = INT32_C(2257),
  windows1258 = INT32_C(2258),
  TIS620 = INT32_C(2259),
  CP50220 = INT32_C(2260)
 };
#endif
}

#include "IANA_encodings.d/ASCII_textencodingtype.h"
#include "IANA_encodings.d/ISOLatin1_textencodingtype.h"
#include "IANA_encodings.d/ISOLatin2_textencodingtype.h"
#include "IANA_encodings.d/ISOLatin3_textencodingtype.h"
#include "IANA_encodings.d/ISOLatin4_textencodingtype.h"
#include "IANA_encodings.d/ISOLatinCyrillic_textencodingtype.h"
#include "IANA_encodings.d/ISOLatinArabic_textencodingtype.h"
#include "IANA_encodings.d/ISOLatinGreek_textencodingtype.h"
#include "IANA_encodings.d/ISOLatinHebrew_textencodingtype.h"
#include "IANA_encodings.d/ISOLatin5_textencodingtype.h"
#include "IANA_encodings.d/ISOLatin6_textencodingtype.h"
#include "IANA_encodings.d/ISOTextComm_textencodingtype.h"
#include "IANA_encodings.d/HalfWidthKatakana_textencodingtype.h"
#include "IANA_encodings.d/JISEncoding_textencodingtype.h"
#include "IANA_encodings.d/ShiftJIS_textencodingtype.h"
#include "IANA_encodings.d/EUCPkdFmtJapanese_textencodingtype.h"
#include "IANA_encodings.d/EUCFixWidJapanese_textencodingtype.h"
#include "IANA_encodings.d/ISO4UnitedKingdom_textencodingtype.h"
#include "IANA_encodings.d/ISO11SwedishForNames_textencodingtype.h"
#include "IANA_encodings.d/ISO15Italian_textencodingtype.h"
#include "IANA_encodings.d/ISO17Spanish_textencodingtype.h"
#include "IANA_encodings.d/ISO21German_textencodingtype.h"
#include "IANA_encodings.d/ISO60DanishNorwegian_textencodingtype.h"
#include "IANA_encodings.d/ISO69French_textencodingtype.h"
#include "IANA_encodings.d/ISO10646UTF1_textencodingtype.h"
#include "IANA_encodings.d/ISO646basic1983_textencodingtype.h"
#include "IANA_encodings.d/INVARIANT_textencodingtype.h"
#include "IANA_encodings.d/ISO2IntlRefVersion_textencodingtype.h"
#include "IANA_encodings.d/NATSSEFI_textencodingtype.h"
#include "IANA_encodings.d/NATSSEFIADD_textencodingtype.h"
//NATS-DYNO excluded form standard
//NATS-DYNO-ADD excluded form standard
#include "IANA_encodings.d/ISO10Swedish_textencodingtype.h"
#include "IANA_encodings.d/KSC5601187_textencodingtype.h"
#include "IANA_encodings.d/ISO2022KR_textencodingtype.h"
#include "IANA_encodings.d/EUCKR_textencodingtype.h"
#include "IANA_encodings.d/ISO2022JP_textencodingtype.h"
#include "IANA_encodings.d/ISO2022JP2_textencodingtype.h"
#include "IANA_encodings.d/ISO13JISC6220jp_textencodingtype.h"
#include "IANA_encodings.d/ISO14JISC6220ro_textencodingtype.h"
#include "IANA_encodings.d/ISO16Portuguese_textencodingtype.h"
#include "IANA_encodings.d/ISO18Greek7Old_textencodingtype.h"
#include "IANA_encodings.d/ISO19LatinGreek_textencodingtype.h"
#include "IANA_encodings.d/ISO25French_textencodingtype.h"
#include "IANA_encodings.d/ISO27LatinGreek1_textencodingtype.h"
#include "IANA_encodings.d/ISO5427Cyrillic_textencodingtype.h"
#include "IANA_encodings.d/ISO42JISC62261978_textencodingtype.h"
#include "IANA_encodings.d/ISO47BSViewdata_textencodingtype.h"
#include "IANA_encodings.d/ISO49INIS_textencodingtype.h"
#include "IANA_encodings.d/ISO50INIS8_textencodingtype.h"
#include "IANA_encodings.d/ISO50INISCyrillic_textencodingtype.h"
#include "IANA_encodings.d/ISO54271981_textencodingtype.h"
#include "IANA_encodings.d/ISO5428Greek_textencodingtype.h"
#include "IANA_encodings.d/ISO57GB1988_textencodingtype.h"
#include "IANA_encodings.d/ISO58GB231280_textencodingtype.h"

namespace crap
{
 template <class ... Ignored>
 struct textEncodingType <void> :: literal<char, Ignored...>
 {
#if (crap_lib_text_encoding >= 202306L)
#else
  private:
#if defined(__GNUC_EXECUTION_CHARSET_NAME)
  constexpr const static char name[] = __GNUC_EXECUTION_CHARSET_NAME;
#elif defined(__clang_literal_encoding__)
  constexpr const static char name[] = __clang_literal_encoding__;
#else
#warning "No known way to get execution encoding. Assuming Unknown."
#endif
#endif
 };

 template <class ... Ignored>
 struct textEncodingType <void> :: literal<wchar_t, Ignored...>
 {
#if defined(__GNUC_WIDE_EXECUTION_CHARSET_NAME)
  constexpr const static char name[] = __GNUC_WIDE_EXECUTION_CHARSET_NAME;
#elif defined(__clang_wide_literal_encoding__)
  constexpr const static char name[] = __clang_wide_literal_encoding__;
#else
#warning "No known way to get execution encoding. Assuming Unknown."
#endif
 };
}
#endif
