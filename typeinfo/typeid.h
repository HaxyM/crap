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
#if defined(__GNUC__) || defined(__GNUG__) //both g++ and clang++
  using Char = char;
#elif defined(_MSC_VER) //microsoft
  using Char = wchar_t;
#else
#error Unsupported compiler!
#endif
  private:
  template <class Element, std :: size_t N> constexpr static std :: size_t elements(Element (&)[N]);
  template <class ... Types> constexpr static std :: size_t wholeSize();
  constexpr static std :: size_t size();
#if defined(__GNUC__) || defined(__GNUG__)
  constexpr const static Char tail[] = "]";
#elif defined(_MSC_VER)
  constexpr const static Char tail[] = L">(void)";
#else
#error Unsupported compiler!
#endif
  constexpr static std :: size_t tailLength();
  template <std :: size_t Index, class CharType, class RepeatType> constexpr static CharType at();
#ifdef __clang__
  template <std :: size_t N> using atConstant = std :: integral_constant<Char, at<N, Char, Type>()>;
  template <template <Char...> class Container, template <std :: size_t> class Function, std :: size_t N>
	  struct generator;
  public:
  template <template <Char...> class Container = stringForType <Char> :: template type>
	  using type = typename generator <Container, atConstant, size()> :: type;
#else
  template <template <Char...> class Container, std :: size_t ... Indices>
	  static Container<at<Indices, Char, Type>()...>
	  generate(valueContainerIdentity<Char, Container>, indexSequence<Indices...>);
  public:
  template <template <Char...> class Container = stringForType <Char> :: template type>
	  using type = decltype(generate(valueContainerIdentity<Char, Container>{}, makeIndexSequence<size()>{}));
#endif
 };

#ifdef __clang__
 template <class Type>
	 template <template <typename typeId <Type> :: Char...> class Container, template <std :: size_t> class Function, std :: size_t N>
	 struct typeId <Type> :: generator
 {
  template <std :: size_t ... Indices>
	  static Container<Function <Indices> :: value...>
	  generate(indexSequence<Indices...>);
  using type = decltype(generate(makeIndexSequence<N>()));
 };
#endif
}

template <class Type> constexpr const typename crap :: typeId <Type> :: Char crap :: typeId <Type> :: tail[];

template <class Type> template <class Element, std :: size_t N> inline constexpr std :: size_t crap :: typeId <Type> :: elements(Element (&)[N])
{
 return N;
}

template <class Type> template <class ... Types> inline constexpr std :: size_t crap :: typeId <Type> :: wholeSize()
{
#if defined(__GNUC__) || defined(__GNUG__)
 return elements(__PRETTY_FUNCTION__);
#elif defined(_MSC_VER)
 return elements(__FUNCSIG__);
#else
#error Unsupported compiler!
#endif
}

template <class Type> inline constexpr std :: size_t crap :: typeId <Type> :: size()
{
 return wholeSize<Type>() - wholeSize<>();
}

template <class Type> inline constexpr std :: size_t crap :: typeId <Type> :: tailLength()
{
 return elements(tail);
}

template <class Type> template <std :: size_t Index, class CharType, class RepeatType> inline constexpr CharType crap :: typeId <Type> :: at()
{
#if defined(__GNUC__) || defined(__GNUG__)
 return __PRETTY_FUNCTION__[elements(__PRETTY_FUNCTION__) + Index - size() - tailLength()];
#elif defined(_MSC_VER)
 return __FUNCSIG__[elements(__FUNCSIG__) + Index - size() - tailLength()];
#else
#error Unsupported compiler!
#endif
}
#endif

