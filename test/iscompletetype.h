#ifndef ISCOMPLETETYPE
#define ISCOMPLETETYPE

#include <type_traits>

#if __cplusplus < 201703
template <class...> using void_t = void;
#endif

template <class, class = void> struct isCompleteType : std :: false_type {};
#if __cplusplus < 201703
#else
template <class Type> struct isCompleteType <Type, void_t<decltype(sizeof(Type))> > : std :: true_type {};
#endif
template <class Type> struct isCompleteType <Type, std :: void_t<decltype(sizeof(Type))> > : std :: true_type {};
#endif
