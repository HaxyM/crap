#ifndef CRAP_TEXTENCODING_TEXTENCODINGTYPE
#define CRAP_TEXTENCODING_TEXTENCODINGTYPE

#include "../algorithm.d/removeifvalue.h"
#include "../algorithm.d/transformfortype.h"
#include "../string.d/string.h"
#include "../utility.d/backvalue.h"
#include "../utility.d/bisectvalue.h"
#include "../utility.d/concatenatefortype.h"
#include "../utility.d/valuelist.h"
#include "../version.d/libtextencoding.h"

#include <utility>
#include <type_traits>

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
  enum class id : std :: int_least32_t;
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
#include "IANA_encodings.d/KSC56011987_textencodingtype.h"
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
#include "IANA_encodings.d/ISO51INISCyrillic_textencodingtype.h"
#include "IANA_encodings.d/ISO54271981_textencodingtype.h"
#include "IANA_encodings.d/ISO5428Greek_textencodingtype.h"
#include "IANA_encodings.d/ISO57GB1988_textencodingtype.h"
#include "IANA_encodings.d/ISO58GB231280_textencodingtype.h"
#include "IANA_encodings.d/ISO61Norwegian2_textencodingtype.h"
#include "IANA_encodings.d/ISO70VideotexSupp1_textencodingtype.h"
#include "IANA_encodings.d/ISO84Portuguese2_textencodingtype.h"
#include "IANA_encodings.d/ISO85Spanish2_textencodingtype.h"
#include "IANA_encodings.d/ISO86Hungarian_textencodingtype.h"
#include "IANA_encodings.d/ISO87JISX0208_textencodingtype.h"
#include "IANA_encodings.d/ISO88Greek7_textencodingtype.h"
#include "IANA_encodings.d/ISO89ASMO449_textencodingtype.h"
#include "IANA_encodings.d/ISO90_textencodingtype.h"
#include "IANA_encodings.d/ISO91JISC62291984a_textencodingtype.h"
#include "IANA_encodings.d/ISO92JISC62991984b_textencodingtype.h"
#include "IANA_encodings.d/ISO93JIS62291984badd_textencodingtype.h"
#include "IANA_encodings.d/ISO94JIS62291984hand_textencodingtype.h"
#include "IANA_encodings.d/ISO95JIS62291984handadd_textencodingtype.h"
#include "IANA_encodings.d/ISO96JISC62291984kana_textencodingtype.h"
#include "IANA_encodings.d/ISO2033_textencodingtype.h"
#include "IANA_encodings.d/ISO99NAPLPS_textencodingtype.h"
#include "IANA_encodings.d/ISO102T617bit_textencodingtype.h"
#include "IANA_encodings.d/ISO103T618bit_textencodingtype.h"
#include "IANA_encodings.d/ISO111ECMACyrillic_textencodingtype.h"
#include "IANA_encodings.d/ISO121Canadian1_textencodingtype.h"
#include "IANA_encodings.d/ISO122Canadian2_textencodingtype.h"
#include "IANA_encodings.d/ISO123CSAZ24341985gr_textencodingtype.h"
#include "IANA_encodings.d/ISO88596E_textencodingtype.h"
#include "IANA_encodings.d/ISO88596I_textencodingtype.h"
#include "IANA_encodings.d/ISO128T101G2_textencodingtype.h"
#include "IANA_encodings.d/ISO88598E_textencodingtype.h"
#include "IANA_encodings.d/ISO88598I_textencodingtype.h"
#include "IANA_encodings.d/ISO139CSN369103_textencodingtype.h"
#include "IANA_encodings.d/ISO141JUSIB1002_textencodingtype.h"
#include "IANA_encodings.d/ISO143IECP271_textencodingtype.h"
#include "IANA_encodings.d/ISO146Serbian_textencodingtype.h"
#include "IANA_encodings.d/ISO147Macedonian_textencodingtype.h"
#include "IANA_encodings.d/ISO150_textencodingtype.h"
#include "IANA_encodings.d/ISO151Cuba_textencodingtype.h"
#include "IANA_encodings.d/ISO6937Add_textencodingtype.h"
#include "IANA_encodings.d/ISO153GOST1976874_textencodingtype.h"
#include "IANA_encodings.d/ISO8859Supp_textencodingtype.h"
#include "IANA_encodings.d/ISO10367Box_textencodingtype.h"
#include "IANA_encodings.d/ISO158Lap_textencodingtype.h"
#include "IANA_encodings.d/ISO159JISX02121990_textencodingtype.h"
#include "IANA_encodings.d/ISO646Danish_textencodingtype.h"
#include "IANA_encodings.d/USDK_textencodingtype.h"
#include "IANA_encodings.d/DKUS_textencodingtype.h"
#include "IANA_encodings.d/KSC5636_textencodingtype.h"
#include "IANA_encodings.d/Unicode11UTF7_textencodingtype.h"
#include "IANA_encodings.d/ISO2022CN_textencodingtype.h"
#include "IANA_encodings.d/ISO2022CNEXT_textencodingtype.h"
#include "IANA_encodings.d/UTF8_textencodingtype.h"
#include "IANA_encodings.d/ISO885913_textencodingtype.h"
#include "IANA_encodings.d/ISO885914_textencodingtype.h"
#include "IANA_encodings.d/ISO885915_textencodingtype.h"
#include "IANA_encodings.d/ISO885916_textencodingtype.h"
#include "IANA_encodings.d/GBK_textencodingtype.h"
#include "IANA_encodings.d/GB18030_textencodingtype.h"
#include "IANA_encodings.d/OSDEBCDICDF0415_textencodingtype.h"
#include "IANA_encodings.d/OSDEBCDICDF03IRV_textencodingtype.h"
#include "IANA_encodings.d/OSDEBCDICDF041_textencodingtype.h"
#include "IANA_encodings.d/ISO115481_textencodingtype.h"
#include "IANA_encodings.d/KZ1048_textencodingtype.h"
#include "IANA_encodings.d/UCS2_textencodingtype.h"
#include "IANA_encodings.d/UCS4_textencodingtype.h"
#include "IANA_encodings.d/UnicodeASCII_textencodingtype.h"
#include "IANA_encodings.d/UnicodeLatin1_textencodingtype.h"
#include "IANA_encodings.d/UnicodeJapanese_textencodingtype.h"
#include "IANA_encodings.d/UnicodeIBM1261_textencodingtype.h"
#include "IANA_encodings.d/UnicodeIBM1268_textencodingtype.h"
#include "IANA_encodings.d/UnicodeIBM1276_textencodingtype.h"
#include "IANA_encodings.d/UnicodeIBM1264_textencodingtype.h"
#include "IANA_encodings.d/UnicodeIBM1265_textencodingtype.h"
#include "IANA_encodings.d/Unicode11_textencodingtype.h"
#include "IANA_encodings.d/SCSU_textencodingtype.h"
#include "IANA_encodings.d/UTF7_textencodingtype.h"
#include "IANA_encodings.d/UTF16BE_textencodingtype.h"
#include "IANA_encodings.d/UTF16LE_textencodingtype.h"
#include "IANA_encodings.d/UTF16_textencodingtype.h"
#include "IANA_encodings.d/CESU8_textencodingtype.h"
#include "IANA_encodings.d/UTF32_textencodingtype.h"
#include "IANA_encodings.d/UTF32BE_textencodingtype.h"
#include "IANA_encodings.d/UTF32LE_textencodingtype.h"
#include "IANA_encodings.d/BOCU1_textencodingtype.h"
#include "IANA_encodings.d/UTF7IMAP_textencodingtype.h"
#include "IANA_encodings.d/Windows30Latin1_textencodingtype.h"
#include "IANA_encodings.d/Windows31Latin1_textencodingtype.h"
#include "IANA_encodings.d/Windows31Latin2_textencodingtype.h"
#include "IANA_encodings.d/Windows31Latin5_textencodingtype.h"
#include "IANA_encodings.d/HPRoman8_textencodingtype.h"
#include "IANA_encodings.d/AdobeStandardEncoding_textencodingtype.h"

namespace crap
{
 template <class CharType, CharType ... Letters>
 struct textEncodingType<string<CharType, Letters...> > : textEncodingType<void>
 {
  private:
  //Delete all characters except a-z, A-Z, and 0-9.
  template <class SubCharType, SubCharType Letter> struct isExtraImpl;
  template <char Letter>
	  struct isExtraImpl<char, Letter> : std :: integral_constant<bool,
	  (Letter != 'a') &&
	  (Letter != 'b') &&
	  (Letter != 'c') &&
	  (Letter != 'd') &&
	  (Letter != 'e') &&
	  (Letter != 'f') &&
	  (Letter != 'g') &&
	  (Letter != 'h') &&
	  (Letter != 'i') &&
	  (Letter != 'j') &&
	  (Letter != 'k') &&
	  (Letter != 'l') &&
	  (Letter != 'm') &&
	  (Letter != 'n') &&
	  (Letter != 'o') &&
	  (Letter != 'p') &&
	  (Letter != 'q') &&
	  (Letter != 'r') &&
	  (Letter != 's') &&
	  (Letter != 't') &&
	  (Letter != 'u') &&
	  (Letter != 'v') &&
	  (Letter != 'w') &&
	  (Letter != 'x') &&
	  (Letter != 'y') &&
	  (Letter != 'z') &&
	  (Letter != 'A') &&
	  (Letter != 'B') &&
	  (Letter != 'C') &&
	  (Letter != 'D') &&
	  (Letter != 'E') &&
	  (Letter != 'F') &&
	  (Letter != 'G') &&
	  (Letter != 'H') &&
	  (Letter != 'I') &&
	  (Letter != 'J') &&
	  (Letter != 'K') &&
	  (Letter != 'L') &&
	  (Letter != 'M') &&
	  (Letter != 'N') &&
	  (Letter != 'O') &&
	  (Letter != 'P') &&
	  (Letter != 'Q') &&
	  (Letter != 'R') &&
	  (Letter != 'S') &&
	  (Letter != 'T') &&
	  (Letter != 'U') &&
	  (Letter != 'V') &&
	  (Letter != 'W') &&
	  (Letter != 'X') &&
	  (Letter != 'Y') &&
	  (Letter != 'Z') &&
	  (Letter != '0') &&
	  (Letter != '1') &&
	  (Letter != '2') &&
	  (Letter != '3') &&
	  (Letter != '4') &&
	  (Letter != '5') &&
	  (Letter != '6') &&
	  (Letter != '7') &&
	  (Letter != '8') &&
	  (Letter != '9')> {};
  template <wchar_t Letter>
	  struct isExtraImpl<wchar_t, Letter> : std :: integral_constant<bool,
	  (Letter != L'a') &&
	  (Letter != L'b') &&
	  (Letter != L'c') &&
	  (Letter != L'd') &&
	  (Letter != L'e') &&
	  (Letter != L'f') &&
	  (Letter != L'g') &&
	  (Letter != L'h') &&
	  (Letter != L'i') &&
	  (Letter != L'j') &&
	  (Letter != L'k') &&
	  (Letter != L'l') &&
	  (Letter != L'm') &&
	  (Letter != L'n') &&
	  (Letter != L'o') &&
	  (Letter != L'p') &&
	  (Letter != L'q') &&
	  (Letter != L'r') &&
	  (Letter != L's') &&
	  (Letter != L't') &&
	  (Letter != L'u') &&
	  (Letter != L'v') &&
	  (Letter != L'w') &&
	  (Letter != L'x') &&
	  (Letter != L'y') &&
	  (Letter != L'z') &&
	  (Letter != L'A') &&
	  (Letter != L'B') &&
	  (Letter != L'C') &&
	  (Letter != L'D') &&
	  (Letter != L'E') &&
	  (Letter != L'F') &&
	  (Letter != L'G') &&
	  (Letter != L'H') &&
	  (Letter != L'I') &&
	  (Letter != L'J') &&
	  (Letter != L'K') &&
	  (Letter != L'L') &&
	  (Letter != L'M') &&
	  (Letter != L'N') &&
	  (Letter != L'O') &&
	  (Letter != L'P') &&
	  (Letter != L'Q') &&
	  (Letter != L'R') &&
	  (Letter != L'S') &&
	  (Letter != L'T') &&
	  (Letter != L'U') &&
	  (Letter != L'V') &&
	  (Letter != L'W') &&
	  (Letter != L'X') &&
	  (Letter != L'Y') &&
	  (Letter != L'Z') &&
	  (Letter != L'0') &&
	  (Letter != L'1') &&
	  (Letter != L'2') &&
	  (Letter != L'3') &&
	  (Letter != L'4') &&
	  (Letter != L'5') &&
	  (Letter != L'6') &&
	  (Letter != L'7') &&
	  (Letter != L'8') &&
	  (Letter != L'9')> {};
  template <CharType Letter> using isExtra = isExtraImpl<CharType, Letter>;
  template <template <CharType...> class Container> using removeExtra =
	  typename removeIfValue <CharType, isExtra, Letters...> :: template
	  type<Container>;
  //Map uppercase A-Z to the corresponding lowercase a-z.
  template <class SubCharType, SubCharType ... SubLetters> struct toLowerImpl;
  template <char ... Ignored>
	  struct toLowerImpl<char, 'A', Ignored...>
	  : std :: integral_constant<char, 'a'> {};
  template <char ... Ignored>
	  struct toLowerImpl<char, 'B', Ignored...>
	  : std :: integral_constant<char, 'b'> {};
  template <char ... Ignored>
	  struct toLowerImpl<char, 'C', Ignored...>
	  : std :: integral_constant<char, 'c'> {};
  template <char ... Ignored>
	  struct toLowerImpl<char, 'D', Ignored...>
	  : std :: integral_constant<char, 'd'> {};
  template <char ... Ignored>
	  struct toLowerImpl<char, 'E', Ignored...>
	  : std :: integral_constant<char, 'e'> {};
  template <char ... Ignored>
	  struct toLowerImpl<char, 'F', Ignored...>
	  : std :: integral_constant<char, 'f'> {};
  template <char ... Ignored>
	  struct toLowerImpl<char, 'G', Ignored...>
	  : std :: integral_constant<char, 'g'> {};
  template <char ... Ignored>
	  struct toLowerImpl<char, 'H', Ignored...>
	  : std :: integral_constant<char, 'h'> {};
  template <char ... Ignored>
	  struct toLowerImpl<char, 'I', Ignored...>
	  : std :: integral_constant<char, 'i'> {};
  template <char ... Ignored>
	  struct toLowerImpl<char, 'J', Ignored...>
	  : std :: integral_constant<char, 'j'> {};
  template <char ... Ignored>
	  struct toLowerImpl<char, 'K', Ignored...>
	  : std :: integral_constant<char, 'k'> {};
  template <char ... Ignored>
	  struct toLowerImpl<char, 'L', Ignored...>
	  : std :: integral_constant<char, 'l'> {};
  template <char ... Ignored>
	  struct toLowerImpl<char, 'M', Ignored...>
	  : std :: integral_constant<char, 'm'> {};
  template <char ... Ignored>
	  struct toLowerImpl<char, 'N', Ignored...>
	  : std :: integral_constant<char, 'n'> {};
  template <char ... Ignored>
	  struct toLowerImpl<char, 'O', Ignored...>
	  : std :: integral_constant<char, 'o'> {};
  template <char ... Ignored>
	  struct toLowerImpl<char, 'P', Ignored...>
	  : std :: integral_constant<char, 'p'> {};
  template <char ... Ignored>
	  struct toLowerImpl<char, 'Q', Ignored...>
	  : std :: integral_constant<char, 'q'> {};
  template <char ... Ignored>
	  struct toLowerImpl<char, 'S', Ignored...>
	  : std :: integral_constant<char, 's'> {};
  template <char ... Ignored>
	  struct toLowerImpl<char, 'T', Ignored...>
	  : std :: integral_constant<char, 't'> {};
  template <char ... Ignored>
	  struct toLowerImpl<char, 'U', Ignored...>
	  : std :: integral_constant<char, 'u'> {};
  template <char ... Ignored>
	  struct toLowerImpl<char, 'V', Ignored...>
	  : std :: integral_constant<char, 'v'> {};
  template <char ... Ignored>
	  struct toLowerImpl<char, 'W', Ignored...>
	  : std :: integral_constant<char, 'w'> {};
  template <char ... Ignored>
	  struct toLowerImpl<char, 'X', Ignored...>
	  : std :: integral_constant<char, 'x'> {};
  template <char ... Ignored>
	  struct toLowerImpl<char, 'Y', Ignored...>
	  : std :: integral_constant<char, 'y'> {};
  template <char ... Ignored>
	  struct toLowerImpl<char, 'Z', Ignored...>
	  : std :: integral_constant<char, 'z'> {};
  template <wchar_t ... Ignored>
	  struct toLowerImpl<wchar_t, L'A', Ignored...>
	  : std :: integral_constant<wchar_t, L'a'> {};
  template <wchar_t ... Ignored>
	  struct toLowerImpl<wchar_t, L'B', Ignored...>
	  : std :: integral_constant<wchar_t, L'b'> {};
  template <wchar_t ... Ignored>
	  struct toLowerImpl<wchar_t, L'C', Ignored...>
	  : std :: integral_constant<wchar_t, L'c'> {};
  template <wchar_t ... Ignored>
	  struct toLowerImpl<wchar_t, L'D', Ignored...>
	  : std :: integral_constant<wchar_t, L'd'> {};
  template <wchar_t ... Ignored>
	  struct toLowerImpl<wchar_t, L'E', Ignored...>
	  : std :: integral_constant<wchar_t, L'e'> {};
  template <wchar_t ... Ignored>
	  struct toLowerImpl<wchar_t, L'F', Ignored...>
	  : std :: integral_constant<wchar_t, L'f'> {};
  template <wchar_t ... Ignored>
	  struct toLowerImpl<wchar_t, L'G', Ignored...>
	  : std :: integral_constant<wchar_t, L'g'> {};
  template <wchar_t ... Ignored>
	  struct toLowerImpl<wchar_t, L'H', Ignored...>
	  : std :: integral_constant<wchar_t, L'h'> {};
  template <wchar_t ... Ignored>
	  struct toLowerImpl<wchar_t, L'I', Ignored...>
	  : std :: integral_constant<wchar_t, L'i'> {};
  template <wchar_t ... Ignored>
	  struct toLowerImpl<wchar_t, L'J', Ignored...>
	  : std :: integral_constant<wchar_t, L'j'> {};
  template <wchar_t ... Ignored>
	  struct toLowerImpl<wchar_t, L'K', Ignored...>
	  : std :: integral_constant<wchar_t, L'k'> {};
  template <wchar_t ... Ignored>
	  struct toLowerImpl<wchar_t, L'L', Ignored...>
	  : std :: integral_constant<wchar_t, L'l'> {};
  template <wchar_t ... Ignored>
	  struct toLowerImpl<wchar_t, L'M', Ignored...>
	  : std :: integral_constant<wchar_t, L'm'> {};
  template <wchar_t ... Ignored>
	  struct toLowerImpl<wchar_t, L'N', Ignored...>
	  : std :: integral_constant<wchar_t, L'n'> {};
  template <wchar_t ... Ignored>
	  struct toLowerImpl<wchar_t, L'O', Ignored...>
	  : std :: integral_constant<wchar_t, L'o'> {};
  template <wchar_t ... Ignored>
	  struct toLowerImpl<wchar_t, L'P', Ignored...>
	  : std :: integral_constant<wchar_t, L'p'> {};
  template <wchar_t ... Ignored>
	  struct toLowerImpl<wchar_t, L'Q', Ignored...>
	  : std :: integral_constant<wchar_t, L'q'> {};
  template <wchar_t ... Ignored>
	  struct toLowerImpl<wchar_t, L'S', Ignored...>
	  : std :: integral_constant<wchar_t, L's'> {};
  template <wchar_t ... Ignored>
	  struct toLowerImpl<wchar_t, L'T', Ignored...>
	  : std :: integral_constant<wchar_t, L't'> {};
  template <wchar_t ... Ignored>
	  struct toLowerImpl<wchar_t, L'U', Ignored...>
	  : std :: integral_constant<wchar_t, L'u'> {};
  template <wchar_t ... Ignored>
	  struct toLowerImpl<wchar_t, L'V', Ignored...>
	  : std :: integral_constant<wchar_t, L'v'> {};
  template <wchar_t ... Ignored>
	  struct toLowerImpl<wchar_t, L'W', Ignored...>
	  : std :: integral_constant<wchar_t, L'w'> {};
  template <wchar_t ... Ignored>
	  struct toLowerImpl<wchar_t, L'X', Ignored...>
	  : std :: integral_constant<wchar_t, L'x'> {};
  template <wchar_t ... Ignored>
	  struct toLowerImpl<wchar_t, L'Y', Ignored...>
	  : std :: integral_constant<wchar_t, L'y'> {};
  template <wchar_t ... Ignored>
	  struct toLowerImpl<wchar_t, L'Z', Ignored...>
	  : std :: integral_constant<wchar_t, L'z'> {};
  template <class SubCharType, SubCharType Letter, SubCharType ... Ignored>
	  struct toLowerImpl<SubCharType, Letter, Ignored...>
	  : std :: integral_constant<SubCharType, Letter> {}; 
  template <CharType Letter> using toLower = toLowerImpl<CharType, Letter>;
  template <template <CharType...> class Container> using makeLower =
	  typename removeExtra<transformForType <CharType, toLower> :: template
	  type> :: template type<Container>;
  //From left to right, delete each 0 that is not preceded by a digit.
  template <CharType ... Empty> struct delete0;
  template <CharType Only> struct delete0<Only>;
  template <CharType First, CharType ... Rest> struct delete0<First, Rest...>;
  template <template <CharType...> class Container>
	  using makeAlias = typename makeLower <delete0> :: template
	  type<Container>;
  template <class PlaceHolder, class SubCharType, SubCharType...> struct alias;
  //Possible aliases declarations
  //(fixing issue wth clang not seeing spesialisations even placed before generic template)
  #include "aliases_declarations.d/ASCII_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISOLatin1_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISOLatin2_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISOLatin3_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISOLatin4_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISOLatinCyrillic_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISOLatinArabic_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISOLatinGreek_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISOLatinHebrew_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISOLatin5_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISOLatin6_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISOTextComm_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/HalfWidthKatakana_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/JISEncoding_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ShiftJIS_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/EUCPkdFmtJapanese_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/EUCFixWidJapanese_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO4UnitedKingdom_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO11SwedishForNames_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO15Italian_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO17Spanish_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO21German_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO60DanishNorwegian_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO69French_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO10646UTF1_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO646basic1983_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/INVARIANT_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO2IntlRefVersion_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/NATSSEFI_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/NATSSEFIADD_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO10Swedish_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/KSC56011987_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO2022KR_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/EUCKR_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO2022JP_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO2022JP2_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO13JISC6220jp_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO14JISC6220ro_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO16Portuguese_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO18Greek7Old_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO19LatinGreek_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO25French_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO27LatinGreek1_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO5427Cyrillic_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO42JISC62261978_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO47BSViewdata_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO49INIS_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO50INIS8_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO51INISCyrillic_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO54271981_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO5428Greek_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO57GB1988_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO58GB231280_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO61Norwegian2_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO70VideotexSupp1_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO84Portuguese2_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO85Spanish2_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO86Hungarian_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO87JISX0208_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO88Greek7_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO89ASMO449_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO90_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO91JISC62291984a_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO92JISC62991984b_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO93JIS62291984badd_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO94JIS62291984hand_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO95JIS62291984handadd_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO96JISC62291984kana_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO2033_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO99NAPLPS_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO102T617bit_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO103T618bit_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO111ECMACyrillic_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO121Canadian1_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO122Canadian2_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO123CSAZ24341985gr_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO88596E_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO88596I_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO128T101G2_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO88598E_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO88598I_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO139CSN369103_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO141JUSIB1002_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO143IECP271_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO146Serbian_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO147Macedonian_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO150_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO151Cuba_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO6937Add_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO153GOST1976874_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO8859Supp_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO10367Box_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO158Lap_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO159JISX02121990_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO646Danish_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/USDK_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/DKUS_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/KSC5636_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/Unicode11UTF7_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO2022CN_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO2022CNEXT_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/UTF8_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO885913_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO885914_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO885915_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO885916_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/GBK_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/GB18030_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/OSDEBCDICDF0415_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/OSDEBCDICDF03IRV_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/OSDEBCDICDF041_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/ISO115481_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/KZ1048_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/UCS2_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/UCS4_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/UnicodeASCII_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/UnicodeLatin1_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/UnicodeJapanese_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/UnicodeIBM1261_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/UnicodeIBM1268_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/UnicodeIBM1276_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/UnicodeIBM1264_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/UnicodeIBM1265_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/Unicode11_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/SCSU_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/UTF7_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/UTF16BE_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/UTF16LE_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/UTF16_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/CESU8_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/UTF32_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/UTF32BE_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/UTF32LE_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/BOCU1_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/UTF7IMAP_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/Windows30Latin1_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/Windows31Latin1_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/Windows31Latin2_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/Windows31Latin5_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/HPRoman8_textencodingtype_aliasesdeclaration.h"
  #include "aliases_declarations.d/AdobeStandardEncoding_textencodingtype_aliasesdeclaration.h"
  //
  template <CharType ... SubLetters>
	  using aliasMaker = alias<CharType, CharType, SubLetters...>; 
  public:
  using mib = typename makeAlias <aliasMaker> :: mib;
  using name = typename makeAlias <aliasMaker> :: name;
  using aliases = typename makeAlias <aliasMaker> :: aliases;
 };

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

 //From left to right, delete each 0 that is not preceded by a digit.
 template <class CharType, CharType ... Letters>
 template <CharType Only>
 struct textEncodingType <string<CharType, Letters...> > :: delete0<Only>
 {
  private:
  template <class SubCharType, SubCharType Letter> struct isZero;
  template <char Letter>
	  struct isZero<char, Letter>
	  : std :: integral_constant<bool, Letter == '0'> {};
  template <wchar_t Letter>
	  struct isZero<wchar_t, Letter>
	  : std :: integral_constant<bool, Letter == L'0'> {}; 
  public:
  template <template <CharType...> class Container>
    using type = typename valueList <CharType, Only> :: template
    since<(isZero <CharType, Only> :: value ? 1u : 0u), Container>;
 };

 template <class CharType, CharType ... Letters>
 template <CharType First, CharType ... Rest>
 struct textEncodingType <string<CharType, Letters...> > :: delete0<First, Rest...>
 {
  private:
  template <bool KeepInitial0s, CharType ... Empty> struct Implementation;
  template <CharType Only> struct Implementation<true, Only>;
  template <CharType Only> struct Implementation<false, Only>;
  template <bool KeepInitial0s, CharType SubFirst, CharType ... SubRest>
	  struct Implementation<KeepInitial0s, SubFirst, SubRest...>;
  template <CharType ... Empty>
	  struct EndsWithDigit : std :: integral_constant<bool, false> {};
  template <CharType SubFirst, CharType ... SubRest>
	  struct EndsWithDigit<SubFirst, SubRest...>;
  template <CharType ... SubLetters>
	  using lowerParser = Implementation<false, SubLetters...>;
  using values = bisectValue<CharType, First, Rest...>;
  template <template <CharType...> class Container>
	  using lower = typename values :: template
	  lower <lowerParser> :: template type<Container>;
  constexpr const static bool lowerEndsWithDigit = lower <EndsWithDigit> :: value;
  template <CharType ... SubLetters>
	  using upperParser = Implementation<lower <EndsWithDigit> :: value, SubLetters...>;
  template <template <CharType...> class Container>
	  using upper = typename values :: template
	  upper <upperParser> :: template type<Container>;
  public:
  template <template <CharType...> class Container>
	  using type = typename upper <lower <concatenateForType <CharType> :: template
	  type> :: template with> :: template type<Container>;
 };

 template <class CharType, CharType ... Letters>
 template <CharType ... Empty>
 struct textEncodingType <string<CharType, Letters...> > :: delete0
 {
  template <template <CharType...> class Container>
    using type = Container<>;
 };
}

#include "aliases.d/ASCII_textencodingtype_alias.h"
#include "aliases.d/ISOLatin1_textencodingtype_alias.h"
#include "aliases.d/ISOLatin2_textencodingtype_alias.h"
#include "aliases.d/ISOLatin3_textencodingtype_alias.h"
#include "aliases.d/ISOLatin4_textencodingtype_alias.h"
#include "aliases.d/ISOLatinCyrillic_textencodingtype_alias.h"
#include "aliases.d/ISOLatinArabic_textencodingtype_alias.h"
#include "aliases.d/ISOLatinGreek_textencodingtype_alias.h"
#include "aliases.d/ISOLatinHebrew_textencodingtype_alias.h"
#include "aliases.d/ISOLatin5_textencodingtype_alias.h"
#include "aliases.d/ISOLatin6_textencodingtype_alias.h"
#include "aliases.d/ISOTextComm_textencodingtype_alias.h"
#include "aliases.d/HalfWidthKatakana_textencodingtype_alias.h"
#include "aliases.d/JISEncoding_textencodingtype_alias.h"
#include "aliases.d/ShiftJIS_textencodingtype_alias.h"
#include "aliases.d/EUCPkdFmtJapanese_textencodingtype_alias.h"
#include "aliases.d/EUCFixWidJapanese_textencodingtype_alias.h"
#include "aliases.d/ISO4UnitedKingdom_textencodingtype_alias.h"
#include "aliases.d/ISO11SwedishForNames_textencodingtype_alias.h"
#include "aliases.d/ISO15Italian_textencodingtype_alias.h"
#include "aliases.d/ISO17Spanish_textencodingtype_alias.h"
#include "aliases.d/ISO21German_textencodingtype_alias.h"
#include "aliases.d/ISO60DanishNorwegian_textencodingtype_alias.h"
#include "aliases.d/ISO69French_textencodingtype_alias.h"
#include "aliases.d/ISO10646UTF1_textencodingtype_alias.h"
#include "aliases.d/ISO646basic1983_textencodingtype_alias.h"
#include "aliases.d/INVARIANT_textencodingtype_alias.h"
#include "aliases.d/ISO2IntlRefVersion_textencodingtype_alias.h"
#include "aliases.d/NATSSEFI_textencodingtype_alias.h"
#include "aliases.d/NATSSEFIADD_textencodingtype_alias.h"
#include "aliases.d/ISO10Swedish_textencodingtype_alias.h"
#include "aliases.d/KSC56011987_textencodingtype_alias.h"
#include "aliases.d/ISO2022KR_textencodingtype_alias.h"
#include "aliases.d/EUCKR_textencodingtype_alias.h"
#include "aliases.d/ISO2022JP_textencodingtype_alias.h"
#include "aliases.d/ISO2022JP2_textencodingtype_alias.h"
#include "aliases.d/ISO13JISC6220jp_textencodingtype_alias.h"
#include "aliases.d/ISO14JISC6220ro_textencodingtype_alias.h"
#include "aliases.d/ISO16Portuguese_textencodingtype_alias.h"
#include "aliases.d/ISO18Greek7Old_textencodingtype_alias.h"
#include "aliases.d/ISO19LatinGreek_textencodingtype_alias.h"
#include "aliases.d/ISO25French_textencodingtype_alias.h"
#include "aliases.d/ISO27LatinGreek1_textencodingtype_alias.h"
#include "aliases.d/ISO5427Cyrillic_textencodingtype_alias.h"
#include "aliases.d/ISO42JISC62261978_textencodingtype_alias.h"
#include "aliases.d/ISO47BSViewdata_textencodingtype_alias.h"
#include "aliases.d/ISO49INIS_textencodingtype_alias.h"
#include "aliases.d/ISO50INIS8_textencodingtype_alias.h"
#include "aliases.d/ISO51INISCyrillic_textencodingtype_alias.h"
#include "aliases.d/ISO54271981_textencodingtype_alias.h"
#include "aliases.d/ISO5428Greek_textencodingtype_alias.h"
#include "aliases.d/ISO57GB1988_textencodingtype_alias.h"
#include "aliases.d/ISO58GB231280_textencodingtype_alias.h"
#include "aliases.d/ISO61Norwegian2_textencodingtype_alias.h"
#include "aliases.d/ISO70VideotexSupp1_textencodingtype_alias.h"
#include "aliases.d/ISO84Portuguese2_textencodingtype_alias.h"
#include "aliases.d/ISO85Spanish2_textencodingtype_alias.h"
#include "aliases.d/ISO86Hungarian_textencodingtype_alias.h"
#include "aliases.d/ISO87JISX0208_textencodingtype_alias.h"
#include "aliases.d/ISO88Greek7_textencodingtype_alias.h"
#include "aliases.d/ISO89ASMO449_textencodingtype_alias.h"
#include "aliases.d/ISO90_textencodingtype_alias.h"
#include "aliases.d/ISO91JISC62291984a_textencodingtype_alias.h"
#include "aliases.d/ISO92JISC62991984b_textencodingtype_alias.h"
#include "aliases.d/ISO93JIS62291984badd_textencodingtype_alias.h"
#include "aliases.d/ISO94JIS62291984hand_textencodingtype_alias.h"
#include "aliases.d/ISO95JIS62291984handadd_textencodingtype_alias.h"
#include "aliases.d/ISO96JISC62291984kana_textencodingtype_alias.h"
#include "aliases.d/ISO2033_textencodingtype_alias.h"
#include "aliases.d/ISO99NAPLPS_textencodingtype_alias.h"
#include "aliases.d/ISO102T617bit_textencodingtype_alias.h"
#include "aliases.d/ISO103T618bit_textencodingtype_alias.h"
#include "aliases.d/ISO111ECMACyrillic_textencodingtype_alias.h"
#include "aliases.d/ISO121Canadian1_textencodingtype_alias.h"
#include "aliases.d/ISO122Canadian2_textencodingtype_alias.h"
#include "aliases.d/ISO123CSAZ24341985gr_textencodingtype_alias.h"
#include "aliases.d/ISO88596E_textencodingtype_alias.h"
#include "aliases.d/ISO88596I_textencodingtype_alias.h"
#include "aliases.d/ISO128T101G2_textencodingtype_alias.h"
#include "aliases.d/ISO88598E_textencodingtype_alias.h"
#include "aliases.d/ISO88598I_textencodingtype_alias.h"
#include "aliases.d/ISO139CSN369103_textencodingtype_alias.h"
#include "aliases.d/ISO141JUSIB1002_textencodingtype_alias.h"
#include "aliases.d/ISO143IECP271_textencodingtype_alias.h"
#include "aliases.d/ISO146Serbian_textencodingtype_alias.h"
#include "aliases.d/ISO147Macedonian_textencodingtype_alias.h"
#include "aliases.d/ISO150_textencodingtype_alias.h"
#include "aliases.d/ISO151Cuba_textencodingtype_alias.h"
#include "aliases.d/ISO6937Add_textencodingtype_alias.h"
#include "aliases.d/ISO153GOST1976874_textencodingtype_alias.h"
#include "aliases.d/ISO8859Supp_textencodingtype_alias.h"
#include "aliases.d/ISO10367Box_textencodingtype_alias.h"
#include "aliases.d/ISO158Lap_textencodingtype_alias.h"
#include "aliases.d/ISO159JISX02121990_textencodingtype_alias.h"
#include "aliases.d/ISO646Danish_textencodingtype_alias.h"
#include "aliases.d/USDK_textencodingtype_alias.h"
#include "aliases.d/DKUS_textencodingtype_alias.h"
#include "aliases.d/KSC5636_textencodingtype_alias.h"
#include "aliases.d/Unicode11UTF7_textencodingtype_alias.h"
#include "aliases.d/ISO2022CN_textencodingtype_alias.h"
#include "aliases.d/ISO2022CNEXT_textencodingtype_alias.h"
#include "aliases.d/UTF8_textencodingtype_alias.h"
#include "aliases.d/ISO885913_textencodingtype_alias.h"
#include "aliases.d/ISO885914_textencodingtype_alias.h"
#include "aliases.d/ISO885915_textencodingtype_alias.h"
#include "aliases.d/ISO885916_textencodingtype_alias.h"
#include "aliases.d/GBK_textencodingtype_alias.h"
#include "aliases.d/GB18030_textencodingtype_alias.h"
#include "aliases.d/OSDEBCDICDF0415_textencodingtype_alias.h"
#include "aliases.d/OSDEBCDICDF03IRV_textencodingtype_alias.h"
#include "aliases.d/OSDEBCDICDF041_textencodingtype_alias.h"
#include "aliases.d/ISO115481_textencodingtype_alias.h"
#include "aliases.d/KZ1048_textencodingtype_alias.h"
#include "aliases.d/UCS2_textencodingtype_alias.h"
#include "aliases.d/UCS4_textencodingtype_alias.h"
#include "aliases.d/UnicodeASCII_textencodingtype_alias.h"
#include "aliases.d/UnicodeLatin1_textencodingtype_alias.h"
#include "aliases.d/UnicodeJapanese_textencodingtype_alias.h"
#include "aliases.d/UnicodeIBM1261_textencodingtype_alias.h"
#include "aliases.d/UnicodeIBM1268_textencodingtype_alias.h"
#include "aliases.d/UnicodeIBM1276_textencodingtype_alias.h"
#include "aliases.d/UnicodeIBM1264_textencodingtype_alias.h"
#include "aliases.d/UnicodeIBM1265_textencodingtype_alias.h"
#include "aliases.d/Unicode11_textencodingtype_alias.h"
#include "aliases.d/SCSU_textencodingtype_alias.h"
#include "aliases.d/UTF7_textencodingtype_alias.h"
#include "aliases.d/UTF16BE_textencodingtype_alias.h"
#include "aliases.d/UTF16LE_textencodingtype_alias.h"
#include "aliases.d/UTF16_textencodingtype_alias.h"
#include "aliases.d/CESU8_textencodingtype_alias.h"
#include "aliases.d/UTF32_textencodingtype_alias.h"
#include "aliases.d/UTF32BE_textencodingtype_alias.h"
#include "aliases.d/UTF32LE_textencodingtype_alias.h"
#include "aliases.d/BOCU1_textencodingtype_alias.h"
#include "aliases.d/UTF7IMAP_textencodingtype_alias.h"
#include "aliases.d/Windows30Latin1_textencodingtype_alias.h"
#include "aliases.d/Windows31Latin1_textencodingtype_alias.h"
#include "aliases.d/Windows31Latin2_textencodingtype_alias.h"
#include "aliases.d/Windows31Latin5_textencodingtype_alias.h"
#include "aliases.d/HPRoman8_textencodingtype_alias.h"
#include "aliases.d/AdobeStandardEncoding_textencodingtype_alias.h"

namespace crap
{
 template <class CharType, CharType ... Letters>
 template <class, class SubCharType, SubCharType...>
 struct textEncodingType <string<CharType, Letters...> > :: alias
 {
  using mib = std :: integral_constant<textEncodingType <void> :: id,
	textEncodingType <void> :: id :: other>;
  using name = string<CharType, Letters...>;
  using aliases = typeList<>;
 };
 
 template <class CharType, CharType ... Letters>
	 template <CharType First, CharType ... Rest>
	 template <CharType Only>
 struct textEncodingType <string<CharType, Letters...> > ::
	delete0 <First, Rest...> ::
  Implementation<true, Only>
 {
  template <template <CharType...> class Container>
    using type = Container<Only>;
 };

 template <class CharType, CharType ... Letters>
	 template <CharType First, CharType ... Rest>
	 template <CharType Only>
 struct textEncodingType <string<CharType, Letters...> > ::
	delete0 <First, Rest...> ::
  Implementation<false, Only>
 {
  private:
  template <class SubCharType, SubCharType Letter> struct isZero;
  template <char Letter>
	  struct isZero<char, Letter>
	  : std :: integral_constant<bool, Letter == '0'> {};
  template <wchar_t Letter>
	  struct isZero<wchar_t, Letter>
	  : std :: integral_constant<bool, Letter == L'0'> {}; 
  public:
  template <template <CharType...> class Container>
    using type = typename valueList <CharType, Only> :: template
    since<(isZero <CharType, Only> :: value ? 1u : 0u), Container>;  
 };

 template <class CharType, CharType ... Letters>
	 template <CharType First, CharType ... Rest>
	 template <bool KeepInitial0s, CharType SubFirst, CharType ... SubRest>
 struct textEncodingType <string<CharType, Letters...> > ::
	delete0 <First, Rest...> ::
  Implementation<KeepInitial0s, SubFirst, SubRest...>
 {
  private:
  template <CharType ... Empty>
	  struct EndsWithDigit
	  : std :: integral_constant<bool, false> {};
  template <CharType SubSubFirst, CharType ... SubSubRest>
	  struct EndsWithDigit<SubSubFirst, SubSubRest...>;
  template <CharType ... SubLetters>
	  using lowerParser = Implementation<KeepInitial0s, SubLetters...>;
  using values = bisectValue<CharType, SubFirst, SubRest...>;
  template <template <CharType...> class Container>
	  using lower = typename values :: template
	  lower <lowerParser> :: template type<Container>;
  constexpr const static bool lowerEndsWithDigit = lower <EndsWithDigit> :: value;
  template <CharType ... SubLetters>
	  using upperParser = Implementation<lower <EndsWithDigit> :: value, SubLetters...>;
  template <template <CharType...> class Container>
	  using upper = typename values :: template
	  upper <upperParser> :: template type<Container>;
  public:
  template <template <CharType...> class Container>
	  using type = typename upper <lower <concatenateForType <CharType> :: template
	  type> :: template with> :: template type<Container>;
 };
 template <class CharType, CharType ... Letters>
	 template <CharType First, CharType ... Rest>
	 template <CharType SubFirst, CharType ... SubRest>
 struct textEncodingType <string<CharType, Letters...> > ::
	delete0 <First, Rest...> ::
  EndsWithDigit<SubFirst, SubRest...>
 {
  private:
  template <class SubCharType, SubCharType Letter> struct isDigit;
  template <char Letter>
	  struct isDigit<char, Letter> : std :: integral_constant<bool,
	  (Letter == '0') ||
	  (Letter == '1') ||
	  (Letter == '2') ||
	  (Letter == '3') ||
	  (Letter == '4') ||
	  (Letter == '5') ||
	  (Letter == '6') ||
	  (Letter == '7') ||
	  (Letter == '8') ||
	  (Letter == '9')> {}; 
  template <wchar_t Letter>
	  struct isDigit<wchar_t, Letter> : std :: integral_constant<bool,
	  (Letter == L'0') ||
	  (Letter == L'1') ||
	  (Letter == L'2') ||
	  (Letter == L'3') ||
	  (Letter == L'4') ||
	  (Letter == L'5') ||
	  (Letter == L'6') ||
	  (Letter == L'7') ||
	  (Letter == L'8') ||
	  (Letter == L'9')> {}; 
  public:
  constexpr const static bool value =
	  isDigit <CharType, backValue <CharType, SubFirst, SubRest...> :: value> :: value; 
 };

 template <class CharType, CharType ... Letters>
	 template <CharType First, CharType ... Rest>
	 template <bool KeepInitial0s, CharType SubFirst, CharType ... SubRest>
   template <CharType SubSubFirst, CharType ... SubSubRest>
 struct textEncodingType <string<CharType, Letters...> > ::
	delete0 <First, Rest...> ::
  Implementation <KeepInitial0s, SubFirst, SubRest...> ::
  EndsWithDigit<SubSubFirst, SubSubRest...>
 {
  private:
  template <class SubCharType, SubCharType Letter> struct isDigit;
  template <char Letter>
	  struct isDigit<char, Letter> : std :: integral_constant<bool,
	  (Letter == '0') ||
	  (Letter == '1') ||
	  (Letter == '2') ||
	  (Letter == '3') ||
	  (Letter == '4') ||
	  (Letter == '5') ||
	  (Letter == '6') ||
	  (Letter == '7') ||
	  (Letter == '8') ||
	  (Letter == '9')> {}; 
  template <wchar_t Letter>
	  struct isDigit<wchar_t, Letter> : std :: integral_constant<bool,
	  (Letter == L'0') ||
	  (Letter == L'1') ||
	  (Letter == L'2') ||
	  (Letter == L'3') ||
	  (Letter == L'4') ||
	  (Letter == L'5') ||
	  (Letter == L'6') ||
	  (Letter == L'7') ||
	  (Letter == L'8') ||
	  (Letter == L'9')> {}; 
  public:
  constexpr const static bool value =
	  isDigit <CharType, backValue <CharType, SubSubFirst, SubSubRest...> :: value> :: value; 
 };
}
#endif
