#include "../include/crap/algorithm.d/isheapuntilltype.h"
#include "testutils.h"

#include <type_traits>

template <class Value1, class Value2>
	 using cmp1 = lessConstrainedType<Value1, Value2, u<0u> >;

using test1 = crap :: isHeapUntillType<cmp1, u<9u>, u<8u>, u<7u>, u<7u>, u<7u>, u<7u>, u<5u>, u<42u>, u<0u>, u<7u> >;

using test2 = crap :: isHeapUntillType<lessType, u<9u>, u<8u>, u<7u>, u<7u>, u<7u>, u<7u>, u<5u>, u<0u>, u<7u> >;

int main()
{
 static_assert((test1 :: value != test1 :: npos) && (test1 :: value == 7u),
		 "42 is first value failing heap.");
 static_assert((test2 :: value == test2 :: npos), "Is heap untill end.");
}

