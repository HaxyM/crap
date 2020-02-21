#ifndef CRAP_ALGORITHM_COUNTVALUE
#define CRAP_ALGORITHM_COUNTVALUE

#include <type_traits>
#include <utility>

namespace crap
{
 template <class Type, Type ... Values> using countValue = std :: integral_constant<std :: size_t, sizeof...(Values)>;
}
#endif

