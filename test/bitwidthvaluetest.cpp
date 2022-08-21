#include "../include/crap/bit.d/bitwidthvalue.h"

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
 static_assert(crap :: bitWidthValue <std :: uint32_t, zeros32> :: value == 0u,
		 "BitWidth of 0x00000000 should be 0.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, ones32> :: value == 32u,
		 "BitWidth of 0xFFFFFFFF should be 32.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 0u> :: value == 1u,
		 "BitWidth of 0x00000001 should be 1.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 1u> :: value == 2u,
		 "BitWidth of 0x00000002 should be 2.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 2u> :: value == 3u,
		 "BitWidth of 0x00000004 should be 3.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 3u> :: value == 4u,
		 "BitWidth of 0x00000008 should be 4.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 4u> :: value == 5u,
		 "BitWidth of 0x00000010 should be 5.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 5u> :: value == 6u,
		 "BitWidth of 0x00000020 should be 6.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 6u> :: value == 7u,
		 "BitWidth of 0x00000040 should be 7.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 7u> :: value == 8u,
		 "BitWidth of 0x00000080 should be 8.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 8u> :: value == 9u,
		 "BitWidth of 0x00000100 should be 9.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 9u> :: value == 10u,
		 "BitWidth of 0x00000200 should be 10.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 10u> :: value == 11u,
		 "BitWidth of 0x00000400 should be 11.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 11u> :: value == 12u,
		 "BitWidth of 0x00000800 should be 12.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 12u> :: value == 13u,
		 "BitWidth of 0x00001000 should be 13.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 13u> :: value == 14u,
		 "BitWidth of 0x00002000 should be 14.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 14u> :: value == 15u,
		 "BitWidth of 0x00004000 should be 15.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 15u> :: value == 16u,
		 "BitWidth of 0x00008000 should be 16.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 16u> :: value == 17u,
		 "BitWidth of 0x00010000 should be 17.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 17u> :: value == 18u,
		 "BitWidth of 0x00020000 should be 18.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 18u> :: value == 19u,
		 "BitWidth of 0x00040000 should be 19.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 19u> :: value == 20u,
		 "BitWidth of 0x00080000 should be 20.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 20u> :: value == 21u,
		 "BitWidth of 0x00100000 should be 21.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 21u> :: value == 22u,
		 "BitWidth of 0x00200000 should be 22.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 22u> :: value == 23u,
		 "BitWidth of 0x00400000 should be 23.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 23u> :: value == 24u,
		 "BitWidth of 0x00800000 should be 24.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 24u> :: value == 25u,
		 "BitWidth of 0x01000000 should be 25.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 25u> :: value == 26u,
		 "BitWidth of 0x02000000 should be 26.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 26u> :: value == 27u,
		 "BitWidth of 0x04000000 should be 27.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 27u> :: value == 28u,
		 "BitWidth of 0x08000000 should be 28.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 28u> :: value == 29u,
		 "BitWidth of 0x10000000 should be 29.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 29u> :: value == 30u,
		 "BitWidth of 0x20000000 should be 30.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 30u> :: value == 31u,
		 "BitWidth of 0x40000000 should be 31.");
 static_assert(crap :: bitWidthValue <std :: uint32_t, one32 << 31u> :: value == 32u,
		 "BitWidth of 0x80000000 should be 32.");

 return EXIT_SUCCESS;
}
