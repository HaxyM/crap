#ifndef CRAP_LOCALE_HASFACET
#define CRAP_LOCALE_HASFACET

#include <locale>
#include <tuple>
#include <type_traits>
#include <utility>

#include "moneypunct.h"
#include "numpunct.h"
#include "../algorithm.d/countiftype.h"
#include "../type_traits.d/voidt.h"
#include "../utility.d/typelist.h"
#include "../utility.d/valuelist.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <class, class> struct hasFacet;

 template <class CharType, bool International, class Locale>
	 struct hasFacet<std :: moneypunct<CharType, International>, Locale>
 {
  private:
  template <class Type> struct isMoneypunct;
  template <bool, template <class> class> struct isLocaleHaving;
  template <template <class> class IsMoneypunct> struct isLocaleHaving<true, IsMoneypunct> : std :: true_type {};
  template <template <class> class IsMoneypunct> struct isLocaleHaving<false, IsMoneypunct>;
  public:
  constexpr const static bool value = isLocaleHaving <isMoneypunct <Locale> :: value, isMoneypunct> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class CharType, class Locale> struct hasFacet<std :: numpunct<CharType>, Locale>
 {
  private:
  template <class Type> struct isNumpunct;
  template <bool, template <class> class> struct isLocaleHaving;
  template <template <class> class IsNumpunct> struct isLocaleHaving<true, IsNumpunct> : std :: true_type {};
  template <template <class> class IsNumpunct> struct isLocaleHaving<false, IsNumpunct>;
  public:
  constexpr const static bool value = isLocaleHaving <isNumpunct <Locale> :: value, isNumpunct> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class CharType, bool International, class Locale>
	 struct hasFacet<moneypunct<CharType, International>, Locale> : hasFacet<std :: moneypunct<CharType, International>, Locale> {};

 template <class CharType, class Locale>
	 struct hasFacet<numpunct<CharType>, Locale> : hasFacet<std :: numpunct<CharType>, Locale> {};

 template <class CharType, bool International, class Locale>
	 template <class Type>
 struct hasFacet <std :: moneypunct<CharType, Internationl>, Locale> :: isMoneypunct
 { //Check if has moneypunct interface.
  private:
  //Type fields verifiers.
  template <class, class = void> struct hasDecimalPoint : std :: false_type {};
  template <class SubType> struct hasDecimalPoint<SubType, voidT<typename SubType :: decimalPoint_t> >
	  : std :: true_type {};
  template <class, class = void> struct hasThousandsSep : std :: false_type {};
  template <class SubType> struct hasThousandsSep<SubType, voidT<typename SubType :: thousandsSep_t> >
	  : std :: true_type {};
  template <class, class = void> struct hasGrouping : std :: false_type {};
  template <class SubType> struct hasGrouping<SubType, voidT<typename SubType :: grouping_t> >
	  : std :: true_type {};
  template <class, class = void> struct hasCurrSymbol : std :: false_type {};
  template <class SubType> struct hasCurrSymbol<SubType, voidT<typename SubType :: currSymbol_t> >
	  : std :: true_type {};
  template <class, class = void> struct hasFracDigits : std :: false_type {};
  template <class SubType> struct hasFracDigits<SubType, voidT<typename SubType :: fracDigits_t> >
	  : std :: true_type {};
  template <class, class = void> struct hasPositiveSign : std :: false_type {};
  template <class SubType> struct hasPositiveSign<SubType, voidT<typename SubType :: positiveSign_t> >
	  : std :: true_type {};
  template <class, class = void> struct hasNegativeSign : std :: false_type {};
  template <class SubType> struct hasNegativeSign<SubType, voidT<typename SubType :: negativeSign_t> >
	  : std :: true_type {};
  template <class, class = void> struct hasPosFormat : std :: false_type {};
  template <class SubType> struct hasPosformat<SubType, voidT<typename SubType :: posFormat_t> >
	  : std :: true_type {};
  template <class, class = void> struct hasNegFormat : std :: false_type {};
  template <class SubType> struct hasNegFormat<SubType, voidT<typename SubType :: negFormat_t> >
	  : std :: true_type {};
  //Generic type verifiers.
  template <class> struct isConstant : std :: false_type {};
  template <class SubCharType, SubCharType Char> struct isConstant<std :: integral_constant<SubCharType, Char> >
	  : std :: true_type {};
  template <class> struct isString : std :: false_type {};
  template <class SubCharType, SubCharType ... Chars> struct isString<string<SubCharType, Chars...> > : std :: true_type {};
  template <class> struct isValueList : std :: false_type {};
  template <class SubType, SubType ... Values> struct isValueList<valueList<SubType, Values...> > : std :: true_type {};
  //Detailed type verifiers.
  template <bool, class> struct isDecimalPointOkType : std :: false_type {};
  template <class SubType> struct isDecimalPointOkType <true, SubType>
	  : isConstant<typename SubType :: decimalPoint_t> {};
  template <bool, class> struct isThousandsSepOkType : std :: false_type {};
  template <class SubType> struct isThousandsSepOkType <true, SubType>
	  : isConstant<typename SubType :: thousandsSep_t> {};
  template <bool, class> struct isGroupingOkType : std :: false_type {};
  template <class SubType> struct isGroupingOkType <true, SubType>
	  : isString<typename SubType :: grouping_t> {};
  template <bool, class> struct isCurrSymbolOkType : std :: false_type {};
  template <class SubType> struct isCurrSymbolOkType <true, SubType>
	  : isString<typename SubType :: currSymbol_t> {};
  template <bool, class> struct isFracDigitsOkType : std :: false_type {};
  template <class SubType> struct isFracDigitsOkType <true, SubType>
	  : isConstant<typename SubType :: fracDigits_t> {};
  template <bool, class> struct isPositiveSignOkType : std :: false_type {};
  template <class SubType> struct isPositiveSignOkType <true, SubType>
	  : isString<typename SubType :: positiveSign_t> {};
  template <bool, class> struct isNegativeSignOkType : std :: false_type {};
  template <class SubType> struct isNegativeSignOkType <true, SubType>
	  : isString<typename SubType :: negativeSign_t> {};
  template <bool, class> struct isPosFormatOkType : std :: false_type {};
  template <class SubType> struct isPosFormatOkType <true, SubType>
	  : isValueList<typename SubType :: posFormat_t> {};
  template <bool, class> struct isNegFormatOkType : std :: false_type {};
  template <class SubType> struct isNegFormatOkType <true, SubType>
	  : isValueList<typename SubType :: negFormat_t> {};
  //Functionalities.
  constexpr const static auto decimalPointFine =
	  isDecimalPointOkType<hasDecimalPoint <Type> :: value, Type> :: value;
  constexpr const static auto thousandsSepFine =
	  isThousandsSepOkType<hasThousandsSep <Type> :: value, Type> :: value;
  constexpr const static auto groupingFine =
	  isGroupingOkType<hasGrouping <Type> :: value, Type> :: value;
  constexpr const static auto currSymbolFine =
	  isCurrSymbolOkType<hasCurrSymbol <Type> :: value, Type> :: value;
  constexpr const static auto fracDigitsFine =
	  isFracDigitsOkType<hasFracDigits <Type> :: value, Type> :: value;
  constexpr const static auto positiveSignFine =
	  isPositiveSignOkType<hasPositiveSign <Type> :: value, Type> :: value;
  constexpr const static auto negativeSignFine =
	  isNegativeSignOkType<hasNegativeSign <Type> :: value, Type> :: value;
  constexpr const static auto posFormatFine =
	  isPosFormatOkType<hasPosFormat <Type> :: value, Type> :: value;
  constexpr const static auto negFormatFine =
	  isNegFormatOkType<hasNegFormat <Type> :: value, Type> :: value;
  public:
  constexpr const static auto value =
	  decimalPointFine && thousandsSepFine && groupingFine && currSymbolFine && fracDigitsFine
	  && positiveSignFine && negativeSignFine && posFormatFine && negFormatFine;
 };

 template <class CharType, bool International, class Locale>
	 template <template <class> class IsMoneypunct>
 struct hasFacet <std :: moneypunct<CharType, International>, Locale> :: isLocaleHaving<false, IsMoneypunct>
 { //Check if has locale interface.
  private:
  //Check if has "facet" field.
  template <class, class = void> struct hasFacetField : std :: false_type {};
  template <class Type> struct hasFacetField<Type, voidT<typename Type :: facet> > : std :: true_type {};
  constexpr const static auto hasFacetField_v = hasFacetField <Locale> :: value;
  //Check possible "facet" field types.
  template <class Type> struct isProperFacet : IsMoneypunct<Type> {};
  template <class ... Types> struct isProperFacet<typeList<Types...> >
	  : std :: integral_constant<bool, (countIfType <IsMoneypunct, Types...> :: value == 1u)> {};
  template <class ... Types> struct isProperFacet<std :: tuple<Types...> >
	  : std :: integral_constant<bool, (countIfType <IsMoneypunct, Types...> :: value == 1u)> {};
  template <class Type1, class Type2> struct isProperFacet<std :: pair<Type1, Type2> >
	  : std :: integral_constant<bool, (countIfType <IsMoneypunct, Type1, Type2> :: value == 1u)> {};
  //Check if "facet" field is proper collection.
  template <bool, class> struct checkFacet : std :: false_type {};
  template <class Type> struct checkFacet<true, Type> : isProperFacet<typename Type :: facet> {};
  public:
  constexpr const static auto value = checkFacet <hasFacetField_v, Locale> :: value;
 };

 template <class CharType, class Locale>
	 template <class Type>
 struct hasFacet <std :: numpunct<CharType>, Locale> :: isNumpunct
 { //Check if has numpunct interface.
  private:
  //Type fields verifiers.
  template <class, class = void> struct hasDecimalPoint : std :: false_type {};
  template <class SubType> struct hasDecimalPoint<SubType, voidT<typename SubType :: decimalPoint_t> >
	  : std :: true_type {};
  template <class, class = void> struct hasThousandsSep : std :: false_type {};
  template <class SubType> struct hasThousandsSep<SubType, voidT<typename SubType :: thousandsSep_t> >
	  : std :: true_type {};
  template <class, class = void> struct hasGrouping : std :: false_type {};
  template <class SubType> struct hasGrouping<SubType, voidT<typename SubType :: grouping_t> >
	  : std :: true_type {};
  template <class, class = void> struct hasTruename : std :: false_type {};
  template <class SubType> struct hasTruename<SubType, voidT<typename SubType :: truename_t> >
	  : std :: true_type {};
  template <class, class = void> struct hasFalsename : std :: false_type {};
  template <class SubType> struct hasFalsename<SubType, voidT<typename SubType :: falsename_t> >
	  : std :: true_type {};
  //Generic type verifiers.
  template <class> struct isConstant : std :: false_type {};
  template <class SubCharType, SubCharType Char> struct isConstant<std :: integral_constant<SubCharType, Char> >
	  : std :: true_type {};
  template <class> struct isString : std :: false_type {};
  template <class SubCharType, SubCharType ... Chars> struct isString<string<SubCharType, Chars...> > : std :: true_type {};
  //Detailed type verifiers.
  template <bool, class> struct isDecimalPointOkType : std :: false_type {};
  template <class SubType> struct isDecimalPointOkType <true, SubType>
	  : isConstant<typename SubType :: decimalPoint_t> {};
  template <bool, class> struct isThousandsSepOkType : std :: false_type {};
  template <class SubType> struct isThousandsSepOkType <true, SubType>
	  : isConstant<typename SubType :: thousandsSep_t> {};
  template <bool, class> struct isGroupingOkType : std :: false_type {};
  template <class SubType> struct isGroupingOkType <true, SubType>
	  : isString<typename SubType :: grouping_t> {};
  template <bool, class> struct isTruenameOkType : std :: false_type {};
  template <class SubType> struct isTruenameOkType <true, SubType>
	  : isString<typename SubType :: truename_t> {};
  template <bool, class> struct isFalsenameOkType : std :: false_type {};
  template <class SubType> struct isFalsenameOkType <true, SubType>
	  : isString<typename SubType :: falsename_t> {};
  //Functionalities.
  constexpr const static auto decimalPointFine =
	  isDecimalPointOkType<hasDecimalPoint <Type> :: value, Type> :: value;
  constexpr const static auto thousandsSepFine =
	  isThousandsSepOkType<hasThousandsSep <Type> :: value, Type> :: value;
  constexpr const static auto groupingFine =
	  isGroupingOkType<hasGrouping <Type> :: value, Type> :: value;
  constexpr const static auto truenameFine =
	  isTruenameOkType<hasTruename <Type> :: value, Type> :: value;
  constexpr const static auto falsenameFine =
	  isFalsenameOkType<hasFalsename <Type> :: value, Type> :: value;
  public:
  constexpr const static auto value =
	  decimalPointFine && thousandsSepFine && groupingFine && truenameFine && falsenameFine;
 };

 template <class CharType, class Locale>
	 template <template <class> class IsNumpunct>
 struct hasFacet <std :: numpunct<CharType>, Locale> :: isLocaleHaving<false, IsNumpunct>
 { //Check if has locale interface.
  private:
  //Check if has "facet" field.
  template <class, class = void> struct hasFacetField : std :: false_type {};
  template <class Type> struct hasFacetField<Type, voidT<typename Type :: facet> > : std :: true_type {};
  constexpr const static auto hasFacetField_v = hasFacetField <Locale> :: value;
  //Check possible "facet" field types.
  template <class Type> struct isProperFacet : IsNumpunct<Type> {};
  template <class ... Types> struct isProperFacet<typeList<Types...> >
	  : std :: integral_constant<bool, (countIfType <IsNumpunct, Types...> :: value == 1u)> {};
  template <class ... Types> struct isProperFacet<std :: tuple<Types...> >
	  : std :: integral_constant<bool, (countIfType <IsNumpunct, Types...> :: value == 1u)> {};
  template <class Type1, class Type2> struct isProperFacet<std :: pair<Type1, Type2> >
	  : std :: integral_constant<bool, (countIfType <IsNumpunct, Type1, Type2> :: value == 1u)> {};
  //Check if "facet" field is proper collection.
  template <bool, class> struct checkFacet : std :: false_type {};
  template <class Type> struct checkFacet<true, Type> : isProperFacet<typename Type :: facet> {};
  public:
  constexpr const static auto value = checkFacet <hasFacetField_v, Locale> :: value;
 };
}

template <class CharType, class Locale>
	inline constexpr crap :: hasFacet <std :: numpunct<CharType>, Locale> :: operator
	typename crap :: hasFacet <std :: numpunct<CharType>, Locale> :: value_type () const noexcept
{
 return crap :: hasFacet <std :: numpunct<CharType>, Locale> :: value;
};
#if (crap_lib_integral_constant_callable >= 201304L)

template <class CharType, class Locale>
	inline constexpr typename crap :: hasFacet <std :: numpunct<CharType>, Locale> :: value_type
	crap :: hasFacet <std :: numpunct<CharType>, Locale> :: operator () () const noexcept
{
 return crap :: hasFacet <std :: numpunct<CharType>, Locale> :: value;
}
#endif
#endif

