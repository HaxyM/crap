#ifndef CRAP_LOCALE_LOCALE
#define CRAP_LOCALE_LOCALE

#include <cstdint>
#include <type_traits>
#include <utility>

#include "../type_traits.d/voidt.h"

namespace crap
{
 enum class locale_category : std :: uint32_t
 {
  none = (std :: uint32_t{} ^ std :: uint32_t{}),
  collate = ~((~none) << 1),
  ctype = collate << 1,
  monetary = ctype << 1,
  numeric = monetary << 1,
  time = numeric << 1,
  messages = time << 1,
  all = collate | ctype | monetary | numeric | time | messages
 };

 template <class, locale_category = locale_category :: all> struct locale;

 template <class Facet1, class Facet2, locale_category Cat>
	 struct locale <std :: pair<Facet1, Facet2>, Cat>
 {
  private:
  template <class, class = void> struct hasFacet : std :: false_type {};
  template <class Type> struct hasFacet<Type, voidT<typename Type :: facet> > : std :: true_type {};
  template <class Type> struct isNumeric;
  public:
 };

 template <class Facet1, class Facet2, locale_category Cat>
	 template <class Type>
 struct locale <std :: pair<Facet1, Facet2>, Cat> :: isNmeric
 {
  private:
  //Type fields verifiers.
  template <class, class = void> struct hasDecimalPoint : std :: false_type {};
  template <class SubType> struct hasDecimalPoint<Type, voidT<typename SubType :: decimalPoint> >
	  : std :: true_type {};
  template <class, class = void> struct hasThousandsSep : std :: false_type {};
  template <class SubType> struct hasThousandsSep<Type, voidT<typename SubType :: thousandsSep> >
	  : std :: true_type {};
  template <class, class = void> struct hasGrouping : std :: false_type {};
  template <class SubType> struct hasGrouping<Type, voidT<typename SubType :: grouping> >
	  : std :: true_type {};
  template <class, class = void> struct hasTruename : std :: false_type {};
  template <class SubType> struct hasTruename<Type, voidT<typename SubType :: truename> >
	  : std :: true_type {};
  template <class, class = void> struct hasFalsename : std :: false_type {};
  template <class SubType> struct hasFalsename<Type, voidT<typename SubType :: falsename> >
	  : std :: true_type {};
  //Generic type verifiers.
  template <class> struct isConstant : std :: false_type {};
  template <class CharType, CharType Char> struct isConstant<std :: integral_constant<CharType, Char> >
	  : std :: true_type {};
  template <class> struct isString : std :: false_type {};
  template <class CharType, CharType ... Chars> struct isString<string<CharType, Chars...> > : std :: true_type {};
  //Detailed type verifiers.
  template <bool, class> struct isDecimalPointOkType : std :: false_type {};
  template <class SubType> struct isDecimalPointOkType <true, SubType> : isConstant<SubType :: decimalPoint> {};
  template <bool, class> struct isThousandsSepOkType : std :: false_type {};
  template <class SubType> struct isThousandsSepOkType <true, SubType> : isConstant<SubType :: thousandsSep> {};
  template <bool, class> struct isThousandsSepOkType : std :: false_type {};
  template <class SubType> struct isThousandsSepOkType <true, SubType> : isConstant<SubType :: thousandsSep> {};
  template <bool, class> struct isGroupingOkType : std :: false_type {};
  template <class SubType> struct isGroupingOkType <true, SubType> : isString<SubType :: grouping> {};
  template <bool, class> struct isTruenameOkType : std :: false_type {};
  template <class SubType> struct isTruenameOkType <true, SubType> : isString<SubType :: truename> {};
  template <bool, class> struct isFalsenameOkType : std :: false_type {};
  template <class SubType> struct isFalsenameOkType <true, SubType> : isString<SubType :: falsename> {};
  //Functionalities.
  constexpr const static auto decimalPiontFine =
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
	  decimalPointFine || thousandsSepFine || groupingFine || truenameFine || falsenameFine;
 };
}
#endif

