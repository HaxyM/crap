//#include "../include/crap/ratio.d/e.h"
#include "../include/crap/numbers.d/e.h"

#include <iostream>

int main()
{
 using test1 = typename crap :: e <crap :: valueRatio<std :: uint64_t, '+', 1u, 1u> > :: type;
 std :: cout.precision(std :: numeric_limits <long double> :: max_digits10);
 std :: cout << "test1: " << static_cast<std :: uint64_t>(test1 :: num) << '/' << static_cast<std :: uint64_t>(test1 :: den) << '=' << std :: fixed << (static_cast<long double>(test1 :: num) / static_cast<long double>(test1 :: den)) << " expected: " << crap :: e <long double> :: value << std :: endl;

 using test2 = typename crap :: e <std :: ratio<1, 1> > :: type;
 std :: cout << "test2: " << static_cast<std :: intmax_t>(test2 :: num) << '/' << static_cast<std :: intmax_t>(test2 :: den) << '=' << std :: fixed << (static_cast<long double>(test2 :: num) / static_cast<long double>(test2 :: den)) << " expected: " << crap :: e <long double> :: value << std :: endl;
}

