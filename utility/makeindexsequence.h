#ifndef CRAP_UTILITY_MAKEINDEXSEQUENCE
#define CRAP_UTILITY_MAKEINDEXSEQUENCE

#include <utility>

#include "language.h"

namespace crap
{
 #if CPP14
 template <std :: size_t ... Indices> using indexSequence = std :: index_sequence<Indices...>;
 template <std :: size_t N> using makeIndexSequence = std :: make_index_sequence<N>;
 #else
 template <std :: size_t ... Indices> struct indexSequence {};
 template <std :: size_t N> struct makeIndexSequence;
}

#include "../numeric/iotavalue.h"

namespace crap
{
 template <std :: size_t N> struct makeIndexSequence : iotaValue <N, std :: size_t> :: template type<indexSequence>{};
 #endif
}
#endif

