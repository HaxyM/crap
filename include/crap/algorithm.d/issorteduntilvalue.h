#ifndef CRAP_ALGORITHM_ISSORTEDUNTILVALUE
#define CRAP_ALGORITHM_ISSORTEDUNTILVALUE

#include "../utility.d/valuelist.h"
#include "../version.d/libintegralconstantcallable.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct isSortedUntilValue;

 template <class Type, template <Type, Type> class Operator> struct isSortedUntilValue<Type, Operator>
 {
  constexpr const static std :: size_t value = 0u;
  constexpr const static std :: size_t npos = 0u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type Value1> struct isSortedUntilValue<Type, Operator, Value1>
 {
  constexpr const static std :: size_t value = 1u;
  constexpr const static std :: size_t npos = 1u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2> struct isSortedUntilValue<Type, Operator, Value1, Value2>
 {
  constexpr const static std :: size_t value = ((Operator <Value2, Value1> :: value) ? 1u : 2u);
  constexpr const static std :: size_t npos = 2u;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> struct isSortedUntilValue
 {
  private:
  using values = valueList<Type, Values...>;
  constexpr const static std :: size_t half = (values :: size) / 2u;
  template <Type ... SubValues> using This = isSortedUntilValue<Type, Operator, SubValues...>;
  using lower = typename values :: template till<half, This>;
  using upper = typename values :: template since<half, This>;
  constexpr const static Type lowerLast = values :: template at<half - 1u>;
  constexpr const static Type upperFirst = values :: template at<half>;
  constexpr const static bool borderUnsorted = Operator <upperFirst, lowerLast> :: value;
  constexpr const static bool lowerUnsorted = ((lower :: value) != (lower :: npos));
  constexpr const static std :: size_t upperValue = (borderUnsorted ? 0u : (upper :: value));
  public:
  constexpr const static std :: size_t value = (lowerUnsorted ? (lower :: value) : ((lower :: value) + upperValue));
  constexpr const static std :: size_t npos = (values :: size);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };
}

template <class Type, template <Type, Type> class Operator>
        inline constexpr crap :: isSortedUntilValue <Type, Operator> :: operator
        typename crap :: isSortedUntilValue <Type, Operator> :: value_type () const noexcept
{
 return crap :: isSortedUntilValue <Type, Operator> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator>
        inline constexpr typename crap :: isSortedUntilValue <Type, Operator> :: value_type
        crap :: isSortedUntilValue <Type, Operator> :: operator () () const noexcept
{
 return crap :: isSortedUntilValue <Type, Operator> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type Value1>
        inline constexpr crap :: isSortedUntilValue <Type, Operator, Value1> :: operator
        typename crap :: isSortedUntilValue <Type, Operator, Value1> :: value_type () const noexcept
{
 return crap :: isSortedUntilValue <Type, Operator, Value1> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type Value1>
        inline constexpr typename crap :: isSortedUntilValue <Type, Operator, Value1> :: value_type
        crap :: isSortedUntilValue <Type, Operator, Value1> :: operator () () const noexcept
{
 return crap :: isSortedUntilValue <Type, Operator, Value1> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
        inline constexpr crap :: isSortedUntilValue <Type, Operator, Value1, Value2> :: operator
        typename crap :: isSortedUntilValue <Type, Operator, Value1, Value2> :: value_type () const noexcept
{
 return crap :: isSortedUntilValue <Type, Operator, Value1, Value2> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
        inline constexpr typename crap :: isSortedUntilValue <Type, Operator, Value1, Value2> :: value_type
        crap :: isSortedUntilValue <Type, Operator, Value1, Value2> :: operator () () const noexcept
{
 return crap :: isSortedUntilValue <Type, Operator, Value1, Value2> :: value;
}
#endif

template <class Type, template <Type, Type> class Operator, Type ... Values>
        inline constexpr crap :: isSortedUntilValue <Type, Operator, Values...> :: operator
        typename crap :: isSortedUntilValue <Type, Operator, Values...> :: value_type () const noexcept
{
 return crap :: isSortedUntilValue <Type, Operator, Values...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type, Type> class Operator, Type ... Values>
        inline constexpr typename crap :: isSortedUntilValue <Type, Operator, Values...> :: value_type
        crap :: isSortedUntilValue <Type, Operator, Values...> :: operator () () const noexcept
{
 return crap :: isSortedUntilValue <Type, Operator, Values...> :: value;
}
#endif
#endif

