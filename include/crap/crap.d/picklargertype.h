#ifndef CRAP_CRAP_PICKLARGERTYPE
#define CRAP_CRAP_PICKLARGERTYPE

#include <limits>
#include <type_traits>

#include "../numbers.d/identity.h"
#include "../numbers.d/zero.h"
#include "../numeric.d/reducetype.h"
#include "../ratio.d/lesstype.h"
#include "../ratio.d/logtype.h"
#include "../ratio.d/multipliestype.h"
#include "../ratio.d/valueratio.h"
#include "../utility.d/typeidentity.h"

namespace crap
{
 template <class...> struct pickLargerType;

 template <class Type> struct pickLargerType<Type> : typeIdentity<Type> {};

 template <class Type1, class Type2>
 struct pickLargerType<Type1, Type2>
 {
  private:
  static_assert(std :: numeric_limits <Type1> :: is_specialized &&
		  std :: numeric_limits <Type2> :: is_specialized,
		  "Missing numeric limits.");
  template <int Digits, int OtherDigits, int Radix, int OtherRadix>
	  struct Implementation;
  template <int Digits, int OtherDigits, int Radix>
	  struct Implementation<Digits, OtherDigits, Radix, Radix>;
  public:
  using type = typename Implementation <std :: numeric_limits <Type1> :: digits,
	std :: numeric_limits <Type2> :: digits,
	std :: numeric_limits <Type1> :: radix,
	std :: numeric_limits <Type2> :: radix> :: type;
 };

 template <class ... Types>
 struct pickLargerType : reduceType<pickLargerType, Types...> {};

 template <class Type1, class Type2>
	 template <int Digits, int OtherDigits, int Radix, int OtherRadix>
 struct pickLargerType <Type1, Type2> :: Implementation
 {
  private:
  static_assert((Radix > 0) && (OtherRadix > 0), "No negative radix supported yet.");
  constexpr const static unsigned int const0 = zero <int> :: value;
  constexpr const static unsigned int const1 = identity <unsigned int> :: value;
  constexpr const static unsigned int otherDigitsNum = secureAbsValue <int, OtherDigits> :: value;
  constexpr const static unsigned int otherRadixNum = secureAbsValue <int, OtherRadix> :: value;
  constexpr const static unsigned int digitsNum = secureAbsValue <int, Digits> :: value;
  constexpr const static unsigned int radixNum = secureAbsValue <int, Radix> :: value;
  constexpr const static char otherDigitsSign = ((OtherDigits < const0) ? '-' : '+');
  constexpr const static char otherRadixSign = ((OtherRadix < const0) ? '-' : '+');
  constexpr const static char digitsSign = ((Digits < const0) ? '-' : '+');
  constexpr const static char radixSign = ((Radix < const0) ? '-' : '+');
  using otherRadixLog = typename logType <valueRatio<unsigned int, otherRadixSign, otherRadixNum, const1> > :: type;
  using radixLog = typename logType <valueRatio<unsigned int, radixSign, radixNum, const1> > :: type;
  using otherSize = typename
	  multipliesType <otherRadixLog, valueRatio<unsigned int, otherDigitsSign, otherDigitsNum, const1> > ::
	  type;
  using size = typename
	  multipliesType <radixLog, valueRatio<unsigned int, digitsSign, digitsNum, const1> > ::
	  type;
  constexpr const static bool otherLess = lessType <otherSize, size> :: value;
  public:
  using type = typename std :: conditional <otherLess, Type1, Type2> :: type;
 };

 template <class Type1, class Type2>
	 template <int Digit, int OtherDigit, int Radix>
 struct pickLargerType <Type1, Type2> :: template
	 Implementation<Digit, OtherDigit, Radix, Radix>
 {
  using type = typename std :: conditional <(OtherDigit < Digit), Type1, Type2> :: type;
 };
}
#endif

