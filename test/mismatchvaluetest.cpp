#include "../include/crap/algorithm.d/mismatchfortype.h"

#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>

#include "../include/crap/utility.d/valuelist.h"
#include "../include/crap/functional.d/comparatorsfortype.h"

bool test_mismatchValueTrivialTest()
{
 using valueTestType = unsigned int;
 //TODO: Make sequence random.
 using testList1 = crap :: valueList <valueTestType, 0u, 1u, 2u, 3u, 4u, 5u, 6u, 7u>;
 using funToCall = crap :: mismatchForType<valueTestType,
       crap :: comparatorsForType <valueTestType> :: template EqualTo>;
 using testedFun =
	 typename testList1 :: copy <funToCall :: template type>;
 using testResult_t =
	 typename testList1 :: copy <testedFun :: template with>;
 constexpr const static auto testResult = testResult_t :: value;
 constexpr const static auto expectedResult = testResult_t :: npos;
 return (testResult == expectedResult);
}

int main()
{
 const bool results[] = {
	 test_mismatchValueTrivialTest()
 };
 return std :: accumulate(std :: begin(results), std :: end(results), true, std :: logical_and<bool>())
	 ? EXIT_SUCCESS
	 : EXIT_FAILURE;
}

