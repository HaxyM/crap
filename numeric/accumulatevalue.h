#ifndef CRAP_NUMERIC_ACCUMULATEVALUE
#define CRAP_NUMERIC_ACCUMULATEVALUE

namespace crap
{
 template <class Type, Type, template <Type, Type> class, Type...> struct accumulateValue;

 template <class Type, Type Initial, template <Type, Type> class Operator> struct accumulateValue<Type, Initial, Operator>
 {
  constexpr const static Type value = Initial;
 };

 template <class Type, Type Initial, template <Type, Type> class Operator, Type FirstValue, Type ... Rest>
	 struct accumulateValue<Type, Initial, Operator, FirstValue, Rest...>
 {
  private:
  constexpr const static auto newInitial = Operator <Initial, FirstValue> :: value;
  public:
  constexpr const static auto value = accumulateValue <Type, newInitial, Operator, Rest...> :: value;
 };
}
#endif

