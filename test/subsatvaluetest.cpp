#include "../include/crap/numeric.d/subsatvalue.h"

#include <cstdlib>
#include <limits>

template <class Type> void test_subSatValue()
{
 constexpr const static auto max = std :: numeric_limits <Type> :: max();
 constexpr const static auto min = std :: numeric_limits <Type> :: min();
 static_assert(crap :: subSatValue <Type, min, min> :: value == (min - min),
		 "Min minus min should be something in range.");
 static_assert(crap :: subSatValue <Type, min, max> :: value == min,
		 "Min minus max should be min.");
 static_assert(crap :: subSatValue <Type, max, min> :: value == max,
		 "Max plus min should be max.");
 static_assert(crap :: subSatValue <Type, max, max> :: value == (max - max),
		 "Max plus max should be something in range.");

 static_assert(crap :: subSatValue <Type, max, max, max, max, max> :: value == min,
		 "Sum of all macies should be max.");
}

int main()
{
 test_subSatValue<signed char>();
 test_subSatValue<unsigned char>();
 test_subSatValue<signed short int>();
 test_subSatValue<unsigned short int>();
 test_subSatValue<signed int>();
 test_subSatValue<unsigned int>();
 test_subSatValue<signed long int>();
 test_subSatValue<unsigned long int>();
 test_subSatValue<signed long long int>();
 test_subSatValue<unsigned long long int>();
 return EXIT_SUCCESS;
}
