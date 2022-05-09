#include "../include/crap/algorithm.d/isheapuntillvalue.h"

#include <type_traits>

template <unsigned int A, unsigned int B> using cmp = std :: integral_constant<bool, (A < B)>;

using test = crap :: isHeapUntillValue<unsigned int, cmp, 9u, 8u, 7u, 7u, 7u, 7u, 5u, 42u, 2u, 7u>;

int main()
{
 static_assert(test :: value == 7u, "42 is first value failing heap.");
}

