#ifndef RANDOMSEQUENCEVALUE
#define RANDOMSEQUENCEVALU 

#include "../include/crap/numeric.d/iotavalue.h"
#include "../include/crap/random.d/randomdevicevalue.h"

#include <cstddef>

template <std::size_t Size, std::size_t Seed, template <std :: size_t> class Rand = crap :: randomDeviceValue>
using randomSequenceValue = typename crap :: iotaValue <Size, std :: size_t, Rand <Seed> :: value> :: template
type <crap :: transformForType <std :: size_t, Rand> :: template type>;
#endif

