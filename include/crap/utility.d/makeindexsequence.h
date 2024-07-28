#ifndef CRAP_UTILITY_MAKEINDEXSEQUENCE
#define CRAP_UTILITY_MAKEINDEXSEQUENCE

#include <utility>

#include "../version.d/libintegersequence.h"

namespace crap
{
#if (crap_lib_integer_sequence >= 201304L)
 template <std :: size_t ... Indices> using indexSequence = std :: index_sequence<Indices...>;
 template <std :: size_t N> using makeIndexSequence = std :: make_index_sequence<N>;
#else
 template <std :: size_t ... Indices> struct indexSequence {};
}

#include "../numeric.d/iotavalue.h"

namespace crap
{
 template <std :: size_t N>
	 using makeIndexSequence = typename iotaValue <N, std :: size_t> :: template type<indexSequence>;
#endif
}
#endif
