#include "../include/crap/algorithm.d/upperboundfortype.h"

#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>

#include "testutils.h"
#include "../include/crap/utility.d/valuelist.h"

bool test_upperBoundValueTrivialTest()
{
 using valueTestType = unsigned int;
 constexpr const static valueTestType Constrain = 42u;
 constexpr const static valueTestType Subject = 7u;
 static_assert(Subject < Constrain, "Subject should be smaller than Constrain so test may function.");

 //TODO: Make sequence random.
 using testList1 =
	 crap :: valueList<valueTestType, 0u, 1u, 2u, 3u, 4u, 5u, 6u, 7u, Subject, Subject + 1u, Constrain>;
 using testedFun = crap :: upperBoundForType<
	 valueTestType,
	 Subject,
	 lessConstrainedForType <valueTestType, Constrain> :: template type>;
 using testResult_t = typename testList1 :: copy <testedFun :: template type>;
 constexpr const static auto testResult = testResult_t :: value;
 static_assert(testResult < testList1 :: size + 1u, "Subject should be somewher!");
 static_assert(testList1 :: data()[testResult - 1u] == Subject, "Subject in wrong place");
 return true;
}

int main()
{
 const bool results[] = {
	 test_upperBoundValueTrivialTest()
 };
 return std :: accumulate(std :: begin(results), std :: end(results), true, std :: logical_and<bool>())
	 ? EXIT_SUCCESS
	 : EXIT_FAILURE;
}

