#ifndef CRAP_TYPEINFO_TYPEID
#define CRAP_TYPEINFO_TYPEID

#include <utility>

#include "../utility/makeindexsequence.h"
#include "../utility/valuecontaineridentity.h"
#include "../string/stringfortype.h"

namespace crap
{
 template <class Type> struct typeId
 {
  private:
  template <class Element, std :: size_t N> constexpr static std :: size_t elements(Element (&)[N]);
  template <class ... Types> constexpr static std :: size_t wholeSize();
  constexpr static std :: size_t size();
  constexpr const static char tail[] = "]";
  constexpr static std :: size_t tailLength();
  template <std :: size_t Index, class RepeatType> constexpr static char at();
#ifdef __clang__
  template <std :: size_t N> using atConstant = std :: integral_constant<char, at<N, Type>()>;
  template <template <char...> class Container, template <std :: size_t> class Function, std :: size_t N>
	  struct generator;
  public:
  template <template <char...> class Container = stringForType <char> :: template type>
	  using type = typename generator <Container, atConstant, size()> :: type;
#else
  template <template <char...> class Container, std :: size_t ... Indices>
	  static Container<at<Indices, Type>()...>
	  generate(valueContainerIdentity<char, Container>, indexSequence<Indices...>);
  public:
  template <template <char...> class Container = stringForType <char> :: template type>
	  using type = decltype(generate(valueContainerIdentity<char, Container>{}, makeIndexSequence<size()>{}));
#endif
 };

#ifdef __clang__
 template <class Type>
	 template <template <char...> class Container, template <std :: size_t> class Function, std :: size_t N>
	 struct typeId <Type> :: generator
 {
  template <std :: size_t ... Indices>
	  static Container<Function <Indices> :: value...>
	  generate(indexSequence<Indices...>);
  using type = decltype(generate(makeIndexSequence<N>()));
 };
#endif
}

template <class Type> constexpr const char crap :: typeId <Type> :: tail[];

template <class Type> template <class Element, std :: size_t N> inline constexpr std :: size_t crap :: typeId <Type> :: elements(Element (&)[N])
{
 return N;
}

template <class Type> template <class ... Types> inline constexpr std :: size_t crap :: typeId <Type> :: wholeSize()
{
 return elements(__PRETTY_FUNCTION__);
}

template <class Type> inline constexpr std :: size_t crap :: typeId <Type> :: size()
{
 return wholeSize<Type>() - wholeSize<>();
}

template <class Type> inline constexpr std :: size_t crap :: typeId <Type> :: tailLength()
{
 return elements(tail);
}

template <class Type> template <std :: size_t Index, class RepeatType> inline constexpr char crap :: typeId <Type> :: at()
{
 return __PRETTY_FUNCTION__[elements(__PRETTY_FUNCTION__) + Index - size() - tailLength()];
}
#endif

