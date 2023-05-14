#include <cstdint>
#include <type_traits>

#include "atantype.h"
#include "dividestype.h"
#include "identity.h"
#include "lesstype.h"
#include "pi.h"
#include "plustype.h"
#include "valueratio.h"
#include "zero.h"
#include "../cmath.d/atan2type.h"

#ifndef CRAP_RATIO_ATAN2TYPE
#define CRAP_RATIO_ATAN2TYPE

namespace crap
{
 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, char SignY, Type NumeratorY, Type DenominatorY>
	 struct atan2Type<valueRatio<Type, SignX, NumeratorX, DenominatorX>, valueRatio<Type, SignY, NumeratorY, DenominatorY> >
 {
  private:
  using x = valueRatio<Type, SignX, NumeratorX, DenominatorX>;
  using const0 = typename zero <x> :: type;
  constexpr const static bool gt0 = lessType <const0, x> :: value;
  constexpr const static bool lt0 = lessType <x, const0> :: value;
  template <bool, bool> struct XRange;
  template <bool Xlt0> struct XRange<true, Xlt0>;
  template <bool Xlt0> struct XRange<false, Xlt0>;
  public:
  using type = typename XRange <gt0, lt0> :: type;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, char SignY, Type NumeratorY, Type DenominatorY>
	 template <bool Xlt0>
 struct atan2Type<valueRatio<Type, SignX, NumeratorX, DenominatorX>, valueRatio<Type, SignY, NumeratorY, DenominatorY> > :: template
	 XRange<true, Xlt0>
 {
  private:
  using x = valueRatio<Type, SignX, NumeratorX, DenominatorX>;
  using y = valueRatio<Type, SignY, NumeratorY, DenominatorY>;
  using arg = typename dividesType <y, x> :: type;
  public:
  using type = typename atanType <arg> :: type;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, char SignY, Type NumeratorY, Type DenominatorY>
	 template <bool Xlt0>
 struct atan2Type<valueRatio<Type, SignX, NumeratorX, DenominatorX>, valueRatio<Type, SignY, NumeratorY, DenominatorY> > :: template
	 XRange<false, Xlt0>
 {
  private:
  using y = valueRatio<Type, SignX, NumeratorX, DenominatorX>;
  using const0 = typename zero <y> :: type;
  constexpr const static bool gt0 = lessType <const0, y> :: value;
  constexpr const static bool lt0 = lessType <y, const0> :: value;
  template <bool, bool, bool> struct YRange;
  template <bool Ylt0> struct YRange<true, true, Ylt0>;
  template <bool Ylt0> struct YRange<true, false, Ylt0>;
  template <bool Ylt0> struct YRange<false, true, Ylt0>;
  template <bool Ylt0> struct YRange<false, false, Ylt0>;
  public:
  using type = typename YRange <Xlt0, gt0, lt0> :: type;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, char SignY, Type NumeratorY, Type DenominatorY>
	 template <bool Xlt0>
	 template <bool Ylt0>
 struct atan2Type<valueRatio<Type, SignX, NumeratorX, DenominatorX>, valueRatio<Type, SignY, NumeratorY, DenominatorY> > :: template
	 XRange<false, Xlt0> :: template
	 YRange<true, true, Ylt0>
 {
  private:
  using x = valueRatio<Type, SignX, NumeratorX, DenominatorX>;
  using y = valueRatio<Type, SignY, NumeratorY, DenominatorY>;
  using arg = typename dividesType <y, x> :: type;
  using const1 = typename identity <x> :: type;
  using constPi = typename pi <const1> :: type;
  public:
  using type = typename plusType <typename atanType <arg> :: type, constPi> :: type;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, char SignY, Type NumeratorY, Type DenominatorY>
	 template <bool Xlt0>
	 template <bool Ylt0>
 struct atan2Type<valueRatio<Type, SignX, NumeratorX, DenominatorX>, valueRatio<Type, SignY, NumeratorY, DenominatorY> > :: template
	 XRange<false, Xlt0> :: template
	 YRange<true, false, Ylt0>
 {
  private:
  using x = valueRatio<Type, SignX, NumeratorX, DenominatorX>;
  using y = valueRatio<Type, SignY, NumeratorY, DenominatorY>;
  using arg = typename dividesType <y, x> :: type;
  using const1 = typename identity <x> :: type;
  using constPi = typename pi <const1> :: type;
  using shift = valueRatio<Type, (Ylt0 ? '-' : '+'), constPi :: num, constPi :: den>;
  public:
  using type = typename plusType <typename atanType <arg> :: type, shift> :: type;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, char SignY, Type NumeratorY, Type DenominatorY>
	 template <bool Xlt0>
	 template <bool Ylt0>
 struct atan2Type<valueRatio<Type, SignX, NumeratorX, DenominatorX>, valueRatio<Type, SignY, NumeratorY, DenominatorY> > :: template
	 XRange<false, Xlt0> :: template
	 YRange<false, true, Ylt0>
 {
  private:
  using x = valueRatio<Type, SignX, NumeratorX, DenominatorX>;
  using const1 = typename identity <x> :: type;
  using const2 = typename plusType <const1, const1> :: type;
  using constPi = typename pi <const1> :: type;
  public:
  using type = typename dividesType <constPi, const2> :: type;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, char SignY, Type NumeratorY, Type DenominatorY>
	 template <bool Xlt0>
	 template <bool Ylt0>
 struct atan2Type<valueRatio<Type, SignX, NumeratorX, DenominatorX>, valueRatio<Type, SignY, NumeratorY, DenominatorY> > :: template
	 XRange<false, Xlt0> :: template
	 YRange<false, false, Ylt0>
 {
  private:
  static_assert(Ylt0, "Function undefined for both x and y equal 0");
  using x = valueRatio<Type, SignX, NumeratorX, DenominatorX>;
  using const1 = typename identity <x> :: type;
  using const2 = typename plusType <const1, const1> :: type;
  using constPi = typename pi <const1> :: type;
  using result = typename dividesType <constPi, const2> :: type;
  public:
  using type = valueRatio<Type, '-', result :: num, result :: den>;
 };

 template <class TypeX, class TypeY, char SignX, TypeX NumeratorX, TypeX DenominatorX, char SignY, TypeY NumeratorY, TypeY DenominatorY>
	 struct atan2Type<valueRatio<TypeX, SignX, NumeratorX, DenominatorX>, valueRatio<TypeY, SignY, NumeratorY, DenominatorY> >
	 : atan2Type<
	 valueRatio<typename std :: common_type <TypeX, TypeY> :: type, SignX, static_cast<typename std :: common_type <TypeX, TypeY> :: type>(NumeratorX), static_cast<typename std :: common_type <TypeX, TypeY> :: type>(DenominatorX)>,
	 valueRatio<typename std :: common_type <TypeX, TypeY> :: type, SignY, static_cast<typename std :: common_type <TypeX, TypeY> :: type>(NumeratorY), static_cast<typename std :: common_type <TypeX, TypeY> :: type>(DenominatorY)> >
	 {};

 template <class TypeX, class TypeY, char SignX, TypeX NumeratorX, TypeX DenominatorX, char SignY, TypeY NumeratorY, TypeY DenominatorY>
	 constexpr typename atan2Type <valueRatio<TypeX, SignX, NumeratorX, DenominatorX>, valueRatio<TypeY, SignY, NumeratorY, DenominatorY> > :: type
	 atan2(valueRatio<TypeX, SignX, NumeratorX, DenominatorX>, valueRatio<TypeY, SignY, NumeratorY, DenominatorY>) noexcept;
}

template <class TypeX, class TypeY, char SignX, TypeX NumeratorX, TypeX DenominatorX, char SignY, TypeY NumeratorY, TypeY DenominatorY>
inline constexpr typename crap :: atan2Type <crap :: valueRatio<TypeX, SignX, NumeratorX, DenominatorX>, crap :: valueRatio<TypeY, SignY, NumeratorY, DenominatorY> > :: type
crap :: atan2(crap :: valueRatio<TypeX, SignX, NumeratorX, DenominatorX>, crap :: valueRatio<TypeY, SignY, NumeratorY, DenominatorY>) noexcept
{
 return {};
}
#endif

