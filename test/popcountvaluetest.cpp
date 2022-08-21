#include "../include/crap/bit.d/popcountvalue.h"

#include "iscompletetype.h"
#include <cstdint>
#include <cstdlib>
#include <limits>
#include <type_traits>

int main()
{
 constexpr const static std :: uint32_t any32 = {};
 constexpr const static std :: uint32_t zeros32 = any32 ^ any32;
 constexpr const static std :: uint32_t ones32 = ~zeros32;
 constexpr const static std :: uint32_t one32 = ~(ones32 << 1u);
 static_assert(crap :: popcountValue <std :: uint32_t, zeros32> :: value == 0u, "Popcount of 32 0s should be 0.");
 static_assert(crap :: popcountValue <std :: uint32_t, ones32> :: value == 32u, "Popcount of 32 1s should be 32.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 0u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 1u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 2u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 3u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 4u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 5u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 6u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 7u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 8u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 9u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 10u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 11u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 12u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 13u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 14u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 15u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 16u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 17u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 18u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 19u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 20u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 21u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 22u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 23u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 24u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 25u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 26u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 27u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 28u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 29u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 30u> :: value == 1u,
		 "Popcount of single 1 should be 1.");
 static_assert(crap :: popcountValue <std :: uint32_t, one32 << 31u> :: value == 1u,
		 "Popcount of single 1 should be 1.");

 return EXIT_SUCCESS;
}
