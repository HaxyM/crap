#ifndef CRAP_LOCALE_ISUPPERVALUE
#define CRAP_LOCALE_ISUPPERVALUE

#include <cstdint>
#include <type_traits>

#include "locale.h"
#include "../utility.d/cmpgreaterequalvalue.h"
#include "../utility.d/cmplessequalvalue.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <class CharType, CharType, locale = locale :: C> struct isupperValue;

 template <class CharType, CharType Char> struct isupperValue<CharType, Char, locale :: C>
	 : std :: integral_constant<bool, (cmpGreaterEqualValue <CharType, Char, std :: uint32_t, UINT32_C(65)> :: value)
	 && (cmpLessEqualValue <CharType, Char, std :: uint32_t, UINT32_C(90)> :: value)>
	 {};

 template <class CharType, CharType Char, locale Locale> struct isupperValue
 {
  private:
  //Encoding detectors.
  template <locale, class...> struct encoding;
  template <class ... Empty> struct encoding <locale :: C, Empty...> : std :: integral_constant<int, 0/*ASCII*/> {};
  template <class ... Empty> struct encoding <locale :: af_ZA_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: br_FR_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: ca_AD_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: ca_ES_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: ca_FR_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: ca_IT_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: cy_GB_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: da_DK_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: de_AT_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: de_BE_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: de_CH_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: de_DE_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: de_LU_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: en_AU_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: en_BE_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: en_BW_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: en_CA_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: en_DK_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: en_GB_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: en_HK_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: en_IE_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: en_IN_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: en_NZ_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: en_PH_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: en_SG_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: en_US_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: en_ZA_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: en_ZW_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: es_AR_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: es_BO_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: es_CL_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: es_CO_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: es_CR_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: es_DO_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: es_EC_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: es_ES_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: es_GT_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: es_HN_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: es_MX_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: es_NI_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: es_PA_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: es_PE_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: es_PR_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: es_PY_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: es_SV_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: es_US_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: es_UY_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: es_VE_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: et_EE_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: eu_ES_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: fi_FI_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: fo_FO_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: fr_BE_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: fr_CA_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: fr_CH_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: fr_FR_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: fr_LU_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: ga_IE_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: gd_GB_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: gl_ES_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: gv_GB_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: id_ID_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: is_IS_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: it_CH_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: it_IT_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: kl_GL_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: kw_GB_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: mi_NZ_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: ms_MY_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: nb_NO_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: nl_BE_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: nl_NL_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: nn_NO_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: no_NO_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: nr_ZA_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: ny_NO_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: oc_FR_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: pd_DE_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: pd_US_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: ph_PH_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: pp_AN_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: pt_BR_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: pt_PT_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: rw_RW_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: ss_ZA_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: st_ZA_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: sv_FI_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: sv_SE_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: tl_PH_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: ts_ZA_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: uz_UZ_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: wa_BE_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: xh_ZA_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  template <class ... Empty> struct encoding <locale :: zu_ZA_ISO_8859_1, Empty...> : std :: integral_constant<int, 1/*ISO/IEC 8859-1*/> {};
  //Implementations based on detected encoding.
  template <int, class...> struct Implementation;
  template <class ... Empty> struct Implementation<0/*ASCII*/, Empty...>;
  template <class ... Empty> struct Implementation<1/*ISO/IEC 8859-1*/, Empty...>;
  public:
  constexpr const static bool value = Implementation <encoding <Locale> :: value> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class CharType, CharType Char, locale Locale> template <class ... Empty>
 struct isupperValue<CharType, Char, Locale> :: Implementation<0 /*ASCII*/, Empty...>
 {
  constexpr const static bool value =
  (cmpGreaterEqualValue <CharType, Char, std :: uint32_t, UINT32_C(65)> :: value)
  && (cmpLessEqualValue <CharType, Char, std :: uint32_t, UINT32_C(90)> :: value);
 };
 
 template <class CharType, CharType Char, locale Locale> template <class ... Empty>
 struct isupperValue<CharType, Char, Locale> :: Implementation<1 /*ISO/IEC 8859-1*/, Empty...>
 {
  constexpr const static bool value =
  ((cmpGreaterEqualValue <CharType, Char, std :: uint32_t, UINT32_C(65)> :: value)
  && (cmpLessEqualValue <CharType, Char, std :: uint32_t, UINT32_C(90)> :: value))
  ||
  ((cmpGreaterEqualValue <CharType, Char, std :: uint32_t, UINT32_C(0xC0)> :: value)
   && (cmpLessEqualValue <CharType, Char, std :: uint32_t, UINT32_C(0xD6)> :: value))
  ||
  ((cmpGreaterEqualValue <CharType, Char, std :: uint32_t, UINT32_C(0xD8)> :: value)
  && (cmpLessEqualValue <CharType, Char, std :: uint32_t, UINT32_C(0xDE)> :: value));
 };
}
template <class CharType, CharType Char, crap :: locale Locale>
inline constexpr crap :: isupperValue <CharType, Char, Locale> :: operator
typename crap :: isupperValue <CharType, Char, Locale> :: value_type () const noexcept
{
 return crap :: isupperValue <CharType, Char, Locale> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class CharType, CharType Char, crap :: locale Locale>
inline constexpr typename crap :: isupperValue <CharType, Char, Locale> :: value_type
crap :: isupperValue <CharType, Char, Locale> :: operator () () const noexcept
{
 return crap :: isupperValue <CharType, Char, Locale> :: value;
}
#endif
#endif

