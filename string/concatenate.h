#ifndef CRAP_STRING_CONCATENATE
#define CRAP_STRING_CONCATENATE

#include "string.h"

namespace crap
{
 template <class Type, Type ... Letters1, Type ... Letters2>
	 constexpr string<Type, Letters1..., Letters2...> operator + (string<Type, Letters1...>, string<Type, Letters2...>) noexcept;
}

template <class Type, Type ... Letters1, Type ... Letters2>
	inline constexpr crap :: string<Type, Letters1..., Letters2...>
	crap :: operator + (crap :: string<Type, Letters1...>, crap :: string<Type, Letters2...>) noexcept
{
 return {};
}
#endif

