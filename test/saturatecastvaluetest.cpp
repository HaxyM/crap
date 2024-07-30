#include "../include/crap/numeric.d/saturatecastvalue.h"

#include <cstdint>
#include <cstdlib>
#include <limits>

constexpr const static auto min_s8 = std :: numeric_limits <std :: int8_t> :: min();
constexpr const static auto max_s8 = std :: numeric_limits <std :: int8_t> :: max();
constexpr const static auto min_u8 = std :: numeric_limits <std :: uint8_t> :: min();
constexpr const static auto max_u8 = std :: numeric_limits <std :: uint8_t> :: max();
constexpr const static auto min_s16 = std :: numeric_limits <std :: int16_t> :: min();
constexpr const static auto max_s16 = std :: numeric_limits <std :: int16_t> :: max();
constexpr const static auto min_u16 = std :: numeric_limits <std :: uint16_t> :: min();
constexpr const static auto max_u16 = std :: numeric_limits <std :: uint16_t> :: max();
constexpr const static auto min_s32 = std :: numeric_limits <std :: int32_t> :: min();
constexpr const static auto max_s32 = std :: numeric_limits <std :: int32_t> :: max();
constexpr const static auto min_u32 = std :: numeric_limits <std :: uint32_t> :: min();
constexpr const static auto max_u32 = std :: numeric_limits <std :: uint32_t> :: max();
constexpr const static auto min_s64 = std :: numeric_limits <std :: int64_t> :: min();
constexpr const static auto max_s64 = std :: numeric_limits <std :: int64_t> :: max();
constexpr const static auto min_u64 = std :: numeric_limits <std :: uint64_t> :: min();
constexpr const static auto max_u64 = std :: numeric_limits <std :: uint64_t> :: max();

template <class Type, Type Value>
void test_saturateCastValue_same_to_same_t()
{
 static_assert(crap :: saturateCastValue <Type, Type, Value> :: value == Value,
		 "No change in value expected.");
}

void test_saturateCastValue_same_to_same()
{
 test_saturateCastValue_same_to_same_t<decltype(min_s8), min_s8>();
 test_saturateCastValue_same_to_same_t<decltype(max_s8), max_s8>();
 test_saturateCastValue_same_to_same_t<decltype(min_u8), min_u8>();
 test_saturateCastValue_same_to_same_t<decltype(max_u8), max_u8>();
 test_saturateCastValue_same_to_same_t<decltype(min_s16), min_s16>();
 test_saturateCastValue_same_to_same_t<decltype(max_s16), max_s16>();
 test_saturateCastValue_same_to_same_t<decltype(min_u16), min_u16>();
 test_saturateCastValue_same_to_same_t<decltype(max_u16), max_u16>();
 test_saturateCastValue_same_to_same_t<decltype(min_s32), min_s32>();
 test_saturateCastValue_same_to_same_t<decltype(max_s32), max_s32>();
 test_saturateCastValue_same_to_same_t<decltype(min_u32), min_u32>();
 test_saturateCastValue_same_to_same_t<decltype(max_u32), max_u32>();
 test_saturateCastValue_same_to_same_t<decltype(min_s64), min_s64>();
 test_saturateCastValue_same_to_same_t<decltype(max_s64), max_s64>();
 test_saturateCastValue_same_to_same_t<decltype(min_u64), min_u64>();
 test_saturateCastValue_same_to_same_t<decltype(max_u64), max_u64>();
}

void test_saturateCastValue_sign_changed()
{
 // 8-bit integers
 static_assert(crap :: saturateCastValue <decltype(min_u8), decltype(min_s8), min_s8> :: value == min_u8,
		 "Range shifted.");
 static_assert(crap :: saturateCastValue <decltype(max_u8), decltype(max_s8), max_s8> :: value == max_s8,
		 "No change in value expected.");
 static_assert(crap :: saturateCastValue <decltype(min_s8), decltype(min_u8), min_u8> :: value == min_u8,
		 "No change in value expected.");
 static_assert(crap :: saturateCastValue <decltype(max_s8), decltype(max_u8), max_u8> :: value == max_s8,
		 "Range shifted.");

 // 16-bit integers
 static_assert(crap :: saturateCastValue <decltype(min_u16), decltype(min_s16), min_s16> :: value == min_u16,
		 "Range shifted.");
 static_assert(crap :: saturateCastValue <decltype(max_u16), decltype(max_s16), max_s16> :: value == max_s16,
		 "No change in value expected.");
 static_assert(crap :: saturateCastValue <decltype(min_s16), decltype(min_u16), min_u16> :: value == min_u16,
		 "No change in value expected.");
 static_assert(crap :: saturateCastValue <decltype(max_s16), decltype(max_u16), max_u16> :: value == max_s16,
		 "Range shifted.");

 // 32-bit integers
 static_assert(crap :: saturateCastValue <decltype(min_u32), decltype(min_s32), min_s32> :: value == min_u32,
		 "Range shifted.");
 static_assert(crap :: saturateCastValue <decltype(max_u32), decltype(max_s32), max_s32> :: value == max_s32,
		 "No change in value expected.");
 static_assert(crap :: saturateCastValue <decltype(min_s32), decltype(min_u32), min_u32> :: value == min_u32,
		 "No change in value expected.");
 static_assert(crap :: saturateCastValue <decltype(max_s32), decltype(max_u32), max_u32> :: value == max_s32,
		 "Range shifted.");

 // 64-bit integers
 static_assert(crap :: saturateCastValue <decltype(min_u64), decltype(min_s64), min_s64> :: value == min_u64,
		 "Range shifted.");
 static_assert(crap :: saturateCastValue <decltype(max_u64), decltype(max_s64), max_s64> :: value == max_s64,
		 "No change in value expected.");
 static_assert(crap :: saturateCastValue <decltype(min_s64), decltype(min_u64), min_u64> :: value == min_u64,
		 "No change in value expected.");
 static_assert(crap :: saturateCastValue <decltype(max_s64), decltype(max_u64), max_u64> :: value == max_s64,
		 "Range shifted.");
}

void test_saturateCastValue_range_increased()
{
 // 8-bit integers
 static_assert(crap :: saturateCastValue <decltype(min_s16), decltype(min_s8), min_s8> :: value == min_s8,
		 "No change in value expected.");
 static_assert(crap :: saturateCastValue <decltype(max_s16), decltype(max_s8), max_s8> :: value == max_s8,
		 "No change in value expected.");
 static_assert(crap :: saturateCastValue <decltype(min_u16), decltype(min_u8), min_u8> :: value == min_u8,
		 "No change in value expected.");
 static_assert(crap :: saturateCastValue <decltype(max_u16), decltype(max_u8), max_u8> :: value == max_u8,
		 "No change in value expected.");

 // 16-bit integers
 static_assert(crap :: saturateCastValue <decltype(min_s32), decltype(min_s16), min_s16> :: value == min_s16,
		 "No change in value expected.");
 static_assert(crap :: saturateCastValue <decltype(max_s32), decltype(max_s16), max_s16> :: value == max_s16,
		 "No change in value expected.");
 static_assert(crap :: saturateCastValue <decltype(min_u32), decltype(min_u16), min_u16> :: value == min_u16,
		 "No change in value expected.");
 static_assert(crap :: saturateCastValue <decltype(max_u32), decltype(max_u16), max_u16> :: value == max_u16,
		 "No change in value expected.");

 // 32-bit integers
 static_assert(crap :: saturateCastValue <decltype(min_s64), decltype(min_s32), min_s32> :: value == min_s32,
		 "No change in value expected.");
 static_assert(crap :: saturateCastValue <decltype(max_s64), decltype(max_s32), max_s32> :: value == max_s32,
		 "No change in value expected.");
 static_assert(crap :: saturateCastValue <decltype(min_u64), decltype(min_u32), min_u32> :: value == min_u32,
		 "No change in value expected.");
 static_assert(crap :: saturateCastValue <decltype(max_u64), decltype(max_u32), max_u32> :: value == max_u32,
		 "No change in value expected.");
}

void test_saturateCastValue_range_decreased()
{
 // 16-bit integers
 static_assert(crap :: saturateCastValue <decltype(min_s8), decltype(min_s16), min_s16> :: value == min_s8,
		 "Range decreased.");
 static_assert(crap :: saturateCastValue <decltype(max_s8), decltype(max_s16), max_s16> :: value == max_s8,
		 "Range decreased.");
 static_assert(crap :: saturateCastValue <decltype(min_u8), decltype(min_u16), min_u16> :: value == min_u8,
		 "Range decreased.");
 static_assert(crap :: saturateCastValue <decltype(max_u8), decltype(max_u16), max_u16> :: value == max_u8,
		 "Range decreased.");

 // 32-bit integers
 static_assert(crap :: saturateCastValue <decltype(min_s16), decltype(min_s32), min_s32> :: value == min_s16,
		 "Range decreased.");
 static_assert(crap :: saturateCastValue <decltype(max_s16), decltype(max_s32), max_s32> :: value == max_s16,
		 "Range decreased.");
 static_assert(crap :: saturateCastValue <decltype(min_u16), decltype(min_u32), min_u32> :: value == min_u16,
		 "Range decreased.");
 static_assert(crap :: saturateCastValue <decltype(max_u16), decltype(max_u32), max_u32> :: value == max_u16,
		 "Range decreased.");

 // 64-bit integers
 static_assert(crap :: saturateCastValue <decltype(min_s32), decltype(min_s64), min_s64> :: value == min_s32,
		 "Range decreased.");
 static_assert(crap :: saturateCastValue <decltype(max_s32), decltype(max_s64), max_s64> :: value == max_s32,
		 "Range decreased.");
 static_assert(crap :: saturateCastValue <decltype(min_u32), decltype(min_u64), min_u64> :: value == min_u32,
		 "Range decreased.");
 static_assert(crap :: saturateCastValue <decltype(max_u32), decltype(max_u64), max_u64> :: value == max_u32,
		 "Range decreased.");
}

int main()
{
 test_saturateCastValue_same_to_same();
 test_saturateCastValue_sign_changed();
 test_saturateCastValue_range_increased();
 test_saturateCastValue_range_decreased();
 return EXIT_SUCCESS;
}
