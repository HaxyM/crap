#include "../include/crap/bit.d/bitfloorvalue.h"

#include <cstdint>
#include <cstdlib>

void test_uint8_t()
{
 constexpr const static std :: uint8_t any8 = {};
 constexpr const static std :: uint8_t x00_8 = any8 ^ any8;
 constexpr const static std :: uint8_t ones = ~x00_8;
 constexpr const static std :: uint8_t x01_8 = (~(ones << 1u)) & ones;
 constexpr const static std :: uint8_t x02_8 = x01_8 << 1u;
 constexpr const static std :: uint8_t x03_8 = x02_8 | x01_8;
 constexpr const static std :: uint8_t x04_8 = x01_8 << 2u;
 constexpr const static std :: uint8_t x05_8 = x04_8 | x01_8;
 constexpr const static std :: uint8_t x06_8 = x04_8 | x02_8;
 constexpr const static std :: uint8_t x07_8 = x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x08_8 = x01_8 << 3u;
 constexpr const static std :: uint8_t x09_8 = x08_8 | x01_8;
 constexpr const static std :: uint8_t x0A_8 = x08_8 | x02_8;
 constexpr const static std :: uint8_t x0B_8 = x08_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x0C_8 = x08_8 | x04_8;
 constexpr const static std :: uint8_t x0D_8 = x08_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t x0E_8 = x08_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t x0F_8 = x08_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x10_8 = x01_8 << 4u;
 constexpr const static std :: uint8_t x11_8 = x10_8 | x01_8;
 constexpr const static std :: uint8_t x12_8 = x10_8 | x02_8;
 constexpr const static std :: uint8_t x13_8 = x10_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x14_8 = x10_8 | x04_8;
 constexpr const static std :: uint8_t x15_8 = x10_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t x16_8 = x10_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t x17_8 = x10_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x18_8 = x10_8 | x08_8;
 constexpr const static std :: uint8_t x19_8 = x10_8 | x08_8 | x01_8;
 constexpr const static std :: uint8_t x1A_8 = x10_8 | x08_8 | x02_8;
 constexpr const static std :: uint8_t x1B_8 = x10_8 | x08_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x1C_8 = x10_8 | x08_8 | x04_8;
 constexpr const static std :: uint8_t x1D_8 = x10_8 | x08_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t x1E_8 = x10_8 | x08_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t x1F_8 = x10_8 | x08_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x20_8 = x01_8 << 5u;
 constexpr const static std :: uint8_t x21_8 = x20_8 | x01_8;
 constexpr const static std :: uint8_t x22_8 = x20_8 | x02_8;
 constexpr const static std :: uint8_t x23_8 = x20_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x24_8 = x20_8 | x04_8;
 constexpr const static std :: uint8_t x25_8 = x20_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t x26_8 = x20_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t x27_8 = x20_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x28_8 = x20_8 | x08_8;
 constexpr const static std :: uint8_t x29_8 = x20_8 | x08_8 | x01_8;
 constexpr const static std :: uint8_t x2A_8 = x20_8 | x08_8 | x02_8;
 constexpr const static std :: uint8_t x2B_8 = x20_8 | x08_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x2C_8 = x20_8 | x08_8 | x04_8;
 constexpr const static std :: uint8_t x2D_8 = x20_8 | x08_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t x2E_8 = x20_8 | x08_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t x2F_8 = x20_8 | x08_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x30_8 = x20_8 | x10_8;
 constexpr const static std :: uint8_t x31_8 = x20_8 | x10_8 | x01_8;
 constexpr const static std :: uint8_t x32_8 = x20_8 | x10_8 | x02_8;
 constexpr const static std :: uint8_t x33_8 = x20_8 | x10_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x34_8 = x20_8 | x10_8 | x04_8;
 constexpr const static std :: uint8_t x35_8 = x20_8 | x10_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t x36_8 = x20_8 | x10_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t x37_8 = x20_8 | x10_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x38_8 = x20_8 | x10_8 | x08_8;
 constexpr const static std :: uint8_t x39_8 = x20_8 | x10_8 | x08_8 | x01_8;
 constexpr const static std :: uint8_t x3A_8 = x20_8 | x10_8 | x08_8 | x02_8;
 constexpr const static std :: uint8_t x3B_8 = x20_8 | x10_8 | x08_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x3C_8 = x20_8 | x10_8 | x08_8 | x04_8;
 constexpr const static std :: uint8_t x3D_8 = x20_8 | x10_8 | x08_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t x3E_8 = x20_8 | x10_8 | x08_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t x3F_8 = x20_8 | x10_8 | x08_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x40_8 = x01_8 << 6u;
 constexpr const static std :: uint8_t x41_8 = x40_8 | x01_8;
 constexpr const static std :: uint8_t x42_8 = x40_8 | x02_8;
 constexpr const static std :: uint8_t x43_8 = x40_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x44_8 = x40_8 | x04_8;
 constexpr const static std :: uint8_t x45_8 = x40_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t x46_8 = x40_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t x47_8 = x40_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x48_8 = x40_8 | x08_8;
 constexpr const static std :: uint8_t x49_8 = x40_8 | x08_8 | x01_8;
 constexpr const static std :: uint8_t x4A_8 = x40_8 | x08_8 | x02_8;
 constexpr const static std :: uint8_t x4B_8 = x40_8 | x08_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x4C_8 = x40_8 | x08_8 | x04_8;
 constexpr const static std :: uint8_t x4D_8 = x40_8 | x08_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t x4E_8 = x40_8 | x08_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t x4F_8 = x40_8 | x08_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x50_8 = x40_8 | x10_8;
 constexpr const static std :: uint8_t x51_8 = x40_8 | x10_8 | x01_8;
 constexpr const static std :: uint8_t x52_8 = x40_8 | x10_8 | x02_8;
 constexpr const static std :: uint8_t x53_8 = x40_8 | x10_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x54_8 = x40_8 | x10_8 | x04_8;
 constexpr const static std :: uint8_t x55_8 = x40_8 | x10_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t x56_8 = x40_8 | x10_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t x57_8 = x40_8 | x10_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x58_8 = x40_8 | x10_8 | x08_8;
 constexpr const static std :: uint8_t x59_8 = x40_8 | x10_8 | x08_8 | x01_8;
 constexpr const static std :: uint8_t x5A_8 = x40_8 | x10_8 | x08_8 | x02_8;
 constexpr const static std :: uint8_t x5B_8 = x40_8 | x10_8 | x08_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x5C_8 = x40_8 | x10_8 | x08_8 | x04_8;
 constexpr const static std :: uint8_t x5D_8 = x40_8 | x10_8 | x08_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t x5E_8 = x40_8 | x10_8 | x08_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t x5F_8 = x40_8 | x10_8 | x08_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x60_8 = x40_8 | x20_8;
 constexpr const static std :: uint8_t x61_8 = x40_8 | x20_8 | x01_8;
 constexpr const static std :: uint8_t x62_8 = x40_8 | x20_8 | x02_8;
 constexpr const static std :: uint8_t x63_8 = x40_8 | x20_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x64_8 = x40_8 | x20_8 | x04_8;
 constexpr const static std :: uint8_t x65_8 = x40_8 | x20_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t x66_8 = x40_8 | x20_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t x67_8 = x40_8 | x20_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x68_8 = x40_8 | x20_8 | x08_8;
 constexpr const static std :: uint8_t x69_8 = x40_8 | x20_8 | x08_8 | x01_8;
 constexpr const static std :: uint8_t x6A_8 = x40_8 | x20_8 | x08_8 | x02_8;
 constexpr const static std :: uint8_t x6B_8 = x40_8 | x20_8 | x08_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x6C_8 = x40_8 | x20_8 | x08_8 | x04_8;
 constexpr const static std :: uint8_t x6D_8 = x40_8 | x20_8 | x08_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t x6E_8 = x40_8 | x20_8 | x08_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t x6F_8 = x40_8 | x20_8 | x08_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x70_8 = x40_8 | x20_8 | x10_8;
 constexpr const static std :: uint8_t x71_8 = x40_8 | x20_8 | x10_8 | x01_8;
 constexpr const static std :: uint8_t x72_8 = x40_8 | x20_8 | x10_8 | x02_8;
 constexpr const static std :: uint8_t x73_8 = x40_8 | x20_8 | x10_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x74_8 = x40_8 | x20_8 | x10_8 | x04_8;
 constexpr const static std :: uint8_t x75_8 = x40_8 | x20_8 | x10_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t x76_8 = x40_8 | x20_8 | x10_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t x77_8 = x40_8 | x20_8 | x10_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x78_8 = x40_8 | x20_8 | x10_8 | x08_8;
 constexpr const static std :: uint8_t x79_8 = x40_8 | x20_8 | x10_8 | x08_8 | x01_8;
 constexpr const static std :: uint8_t x7A_8 = x40_8 | x20_8 | x10_8 | x08_8 | x02_8;
 constexpr const static std :: uint8_t x7B_8 = x40_8 | x20_8 | x10_8 | x08_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x7C_8 = x40_8 | x20_8 | x10_8 | x08_8 | x04_8;
 constexpr const static std :: uint8_t x7D_8 = x40_8 | x20_8 | x10_8 | x08_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t x7E_8 = x40_8 | x20_8 | x10_8 | x08_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t x7F_8 = x40_8 | x20_8 | x10_8 | x08_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x80_8 = x01_8 << 7u;
 constexpr const static std :: uint8_t x81_8 = x80_8 | x01_8;
 constexpr const static std :: uint8_t x82_8 = x80_8 | x02_8;
 constexpr const static std :: uint8_t x83_8 = x80_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x84_8 = x80_8 | x04_8;
 constexpr const static std :: uint8_t x85_8 = x80_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t x86_8 = x80_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t x87_8 = x80_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x88_8 = x80_8 | x08_8;
 constexpr const static std :: uint8_t x89_8 = x80_8 | x08_8 | x01_8;
 constexpr const static std :: uint8_t x8A_8 = x80_8 | x08_8 | x02_8;
 constexpr const static std :: uint8_t x8B_8 = x80_8 | x08_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x8C_8 = x80_8 | x08_8 | x04_8;
 constexpr const static std :: uint8_t x8D_8 = x80_8 | x08_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t x8E_8 = x80_8 | x08_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t x8F_8 = x80_8 | x08_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x90_8 = x80_8 | x10_8;
 constexpr const static std :: uint8_t x91_8 = x80_8 | x10_8 | x01_8;
 constexpr const static std :: uint8_t x92_8 = x80_8 | x10_8 | x02_8;
 constexpr const static std :: uint8_t x93_8 = x80_8 | x10_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x94_8 = x80_8 | x10_8 | x04_8;
 constexpr const static std :: uint8_t x95_8 = x80_8 | x10_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t x96_8 = x80_8 | x10_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t x97_8 = x80_8 | x10_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x98_8 = x80_8 | x10_8 | x08_8;
 constexpr const static std :: uint8_t x99_8 = x80_8 | x10_8 | x08_8 | x01_8;
 constexpr const static std :: uint8_t x9A_8 = x80_8 | x10_8 | x08_8 | x02_8;
 constexpr const static std :: uint8_t x9B_8 = x80_8 | x10_8 | x08_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t x9C_8 = x80_8 | x10_8 | x08_8 | x04_8;
 constexpr const static std :: uint8_t x9D_8 = x80_8 | x10_8 | x08_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t x9E_8 = x80_8 | x10_8 | x08_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t x9F_8 = x80_8 | x10_8 | x08_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t xA0_8 = x80_8 | x20_8;
 constexpr const static std :: uint8_t xA1_8 = x80_8 | x20_8 | x01_8;
 constexpr const static std :: uint8_t xA2_8 = x80_8 | x20_8 | x02_8;
 constexpr const static std :: uint8_t xA3_8 = x80_8 | x20_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t xA4_8 = x80_8 | x20_8 | x04_8;
 constexpr const static std :: uint8_t xA5_8 = x80_8 | x20_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t xA6_8 = x80_8 | x20_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t xA7_8 = x80_8 | x20_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t xA8_8 = x80_8 | x20_8 | x08_8;
 constexpr const static std :: uint8_t xA9_8 = x80_8 | x20_8 | x08_8 | x01_8;
 constexpr const static std :: uint8_t xAA_8 = x80_8 | x20_8 | x08_8 | x02_8;
 constexpr const static std :: uint8_t xAB_8 = x80_8 | x20_8 | x08_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t xAC_8 = x80_8 | x20_8 | x08_8 | x04_8;
 constexpr const static std :: uint8_t xAD_8 = x80_8 | x20_8 | x08_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t xAE_8 = x80_8 | x20_8 | x08_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t xAF_8 = x80_8 | x20_8 | x08_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t xB0_8 = x80_8 | x20_8 | x10_8;
 constexpr const static std :: uint8_t xB1_8 = x80_8 | x20_8 | x10_8 | x01_8;
 constexpr const static std :: uint8_t xB2_8 = x80_8 | x20_8 | x10_8 | x02_8;
 constexpr const static std :: uint8_t xB3_8 = x80_8 | x20_8 | x10_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t xB4_8 = x80_8 | x20_8 | x10_8 | x04_8;
 constexpr const static std :: uint8_t xB5_8 = x80_8 | x20_8 | x10_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t xB6_8 = x80_8 | x20_8 | x10_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t xB7_8 = x80_8 | x20_8 | x10_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t xB8_8 = x80_8 | x20_8 | x10_8 | x08_8;
 constexpr const static std :: uint8_t xB9_8 = x80_8 | x20_8 | x10_8 | x08_8 | x01_8;
 constexpr const static std :: uint8_t xBA_8 = x80_8 | x20_8 | x10_8 | x08_8 | x02_8;
 constexpr const static std :: uint8_t xBB_8 = x80_8 | x20_8 | x10_8 | x08_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t xBC_8 = x80_8 | x20_8 | x10_8 | x08_8 | x04_8;
 constexpr const static std :: uint8_t xBD_8 = x80_8 | x20_8 | x10_8 | x08_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t xBE_8 = x80_8 | x20_8 | x10_8 | x08_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t xBF_8 = x80_8 | x20_8 | x10_8 | x08_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t xC0_8 = x80_8 | x40_8;
 constexpr const static std :: uint8_t xC1_8 = x80_8 | x40_8 | x01_8;
 constexpr const static std :: uint8_t xC2_8 = x80_8 | x40_8 | x02_8;
 constexpr const static std :: uint8_t xC3_8 = x80_8 | x40_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t xC4_8 = x80_8 | x40_8 | x04_8;
 constexpr const static std :: uint8_t xC5_8 = x80_8 | x40_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t xC6_8 = x80_8 | x40_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t xC7_8 = x80_8 | x40_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t xC8_8 = x80_8 | x40_8 | x08_8;
 constexpr const static std :: uint8_t xC9_8 = x80_8 | x40_8 | x08_8 | x01_8;
 constexpr const static std :: uint8_t xCA_8 = x80_8 | x40_8 | x08_8 | x02_8;
 constexpr const static std :: uint8_t xCB_8 = x80_8 | x40_8 | x08_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t xCC_8 = x80_8 | x40_8 | x08_8 | x04_8;
 constexpr const static std :: uint8_t xCD_8 = x80_8 | x40_8 | x08_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t xCE_8 = x80_8 | x40_8 | x08_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t xCF_8 = x80_8 | x40_8 | x08_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t xD0_8 = x80_8 | x40_8 | x10_8;
 constexpr const static std :: uint8_t xD1_8 = x80_8 | x40_8 | x10_8 | x01_8;
 constexpr const static std :: uint8_t xD2_8 = x80_8 | x40_8 | x10_8 | x02_8;
 constexpr const static std :: uint8_t xD3_8 = x80_8 | x40_8 | x10_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t xD4_8 = x80_8 | x40_8 | x10_8 | x04_8;
 constexpr const static std :: uint8_t xD5_8 = x80_8 | x40_8 | x10_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t xD6_8 = x80_8 | x40_8 | x10_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t xD7_8 = x80_8 | x40_8 | x10_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t xD8_8 = x80_8 | x40_8 | x10_8 | x08_8;
 constexpr const static std :: uint8_t xD9_8 = x80_8 | x40_8 | x10_8 | x08_8 | x01_8;
 constexpr const static std :: uint8_t xDA_8 = x80_8 | x40_8 | x10_8 | x08_8 | x02_8;
 constexpr const static std :: uint8_t xDB_8 = x80_8 | x40_8 | x10_8 | x08_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t xDC_8 = x80_8 | x40_8 | x10_8 | x08_8 | x04_8;
 constexpr const static std :: uint8_t xDD_8 = x80_8 | x40_8 | x10_8 | x08_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t xDE_8 = x80_8 | x40_8 | x10_8 | x08_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t xDF_8 = x80_8 | x40_8 | x10_8 | x08_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t xE0_8 = x80_8 | x40_8 | x20_8;
 constexpr const static std :: uint8_t xE1_8 = x80_8 | x40_8 | x20_8 | x01_8;
 constexpr const static std :: uint8_t xE2_8 = x80_8 | x40_8 | x20_8 | x02_8;
 constexpr const static std :: uint8_t xE3_8 = x80_8 | x40_8 | x20_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t xE4_8 = x80_8 | x40_8 | x20_8 | x04_8;
 constexpr const static std :: uint8_t xE5_8 = x80_8 | x40_8 | x20_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t xE6_8 = x80_8 | x40_8 | x20_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t xE7_8 = x80_8 | x40_8 | x20_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t xE8_8 = x80_8 | x40_8 | x20_8 | x08_8;
 constexpr const static std :: uint8_t xE9_8 = x80_8 | x40_8 | x20_8 | x08_8 | x01_8;
 constexpr const static std :: uint8_t xEA_8 = x80_8 | x40_8 | x20_8 | x08_8 | x02_8;
 constexpr const static std :: uint8_t xEB_8 = x80_8 | x40_8 | x20_8 | x08_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t xEC_8 = x80_8 | x40_8 | x20_8 | x08_8 | x04_8;
 constexpr const static std :: uint8_t xED_8 = x80_8 | x40_8 | x20_8 | x08_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t xEE_8 = x80_8 | x40_8 | x20_8 | x08_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t xEF_8 = x80_8 | x40_8 | x20_8 | x08_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t xF0_8 = x80_8 | x40_8 | x20_8 | x10_8;
 constexpr const static std :: uint8_t xF1_8 = x80_8 | x40_8 | x20_8 | x10_8 | x01_8;
 constexpr const static std :: uint8_t xF2_8 = x80_8 | x40_8 | x20_8 | x10_8 | x02_8;
 constexpr const static std :: uint8_t xF3_8 = x80_8 | x40_8 | x20_8 | x10_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t xF4_8 = x80_8 | x40_8 | x20_8 | x10_8 | x04_8;
 constexpr const static std :: uint8_t xF5_8 = x80_8 | x40_8 | x20_8 | x10_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t xF6_8 = x80_8 | x40_8 | x20_8 | x10_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t xF7_8 = x80_8 | x40_8 | x20_8 | x10_8 | x04_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t xF8_8 = x80_8 | x40_8 | x20_8 | x10_8 | x08_8;
 constexpr const static std :: uint8_t xF9_8 = x80_8 | x40_8 | x20_8 | x10_8 | x08_8 | x01_8;
 constexpr const static std :: uint8_t xFA_8 = x80_8 | x40_8 | x20_8 | x10_8 | x08_8 | x02_8;
 constexpr const static std :: uint8_t xFB_8 = x80_8 | x40_8 | x20_8 | x10_8 | x08_8 | x02_8 | x01_8;
 constexpr const static std :: uint8_t xFC_8 = x80_8 | x40_8 | x20_8 | x10_8 | x08_8 | x04_8;
 constexpr const static std :: uint8_t xFD_8 = x80_8 | x40_8 | x20_8 | x10_8 | x08_8 | x04_8 | x01_8;
 constexpr const static std :: uint8_t xFE_8 = x80_8 | x40_8 | x20_8 | x10_8 | x08_8 | x04_8 | x02_8;
 constexpr const static std :: uint8_t xFF_8 = x80_8 | x40_8 | x20_8 | x10_8 | x08_8 | x04_8 | x02_8 | x01_8;
 static_assert(crap :: bitFloorValue <std :: uint8_t, x00_8> :: value == 0u,
		 "BitFloor of 0x00 should be 0.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x01_8> :: value == 1u,
		 "BitFloor of 0x01 should be 1.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x02_8> :: value == 2u,
		 "BitFloor of 0x02 should be 2.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x03_8> :: value == 2u,
		 "BitFloor of 0x03 should be 2.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x04_8> :: value == 4u,
		 "BitFloor of 0x04 should be 4.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x05_8> :: value == 4u,
		 "BitFloor of 0x05 should be 4.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x06_8> :: value == 4u,
		 "BitFloor of 0x06 should be 4.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x07_8> :: value == 4u,
		 "BitFloor of 0x07 should be 4.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x08_8> :: value == 8u,
		 "BitFloor of 0x08 should be 8.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x09_8> :: value == 8u,
		 "BitFloor of 0x09 should be 8.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x0A_8> :: value == 8u,
		 "BitFloor of 0x0A should be 8.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x0B_8> :: value == 8u,
		 "BitFloor of 0x0B should be 8.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x0C_8> :: value == 8u,
		 "BitFloor of 0x0C should be 8.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x0D_8> :: value == 8u,
		 "BitFloor of 0x0D should be 8.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x0E_8> :: value == 8u,
		 "BitFloor of 0x0E should be 8.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x0F_8> :: value == 8u,
		 "BitFloor of 0x0F should be 8.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x10_8> :: value == 16u,
		 "BitFloor of 0x10 should be 16.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x11_8> :: value == 16u,
		 "BitFloor of 0x11 should be 16.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x12_8> :: value == 16u,
		 "BitFloor of 0x12 should be 16.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x13_8> :: value == 16u,
		 "BitFloor of 0x13 should be 16.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x14_8> :: value == 16u,
		 "BitFloor of 0x14 should be 16.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x15_8> :: value == 16u,
		 "BitFloor of 0x15 should be 16.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x16_8> :: value == 16u,
		 "BitFloor of 0x16 should be 16.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x17_8> :: value == 16u,
		 "BitFloor of 0x17 should be 16.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x18_8> :: value == 16u,
		 "BitFloor of 0x18 should be 16.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x19_8> :: value == 16u,
		 "BitFloor of 0x19 should be 16.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x1A_8> :: value == 16u,
		 "BitFloor of 0x1A should be 16.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x1B_8> :: value == 16u,
		 "BitFloor of 0x1B should be 16.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x1C_8> :: value == 16u,
		 "BitFloor of 0x1C should be 16.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x1D_8> :: value == 16u,
		 "BitFloor of 0x1D should be 16.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x1E_8> :: value == 16u,
		 "BitFloor of 0x1E should be 16.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x1F_8> :: value == 16u,
		 "BitFloor of 0x1F should be 16.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x20_8> :: value == 32u,
		 "BitFloor of 0x20 should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x21_8> :: value == 32u,
		 "BitFloor of 0x21 should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x22_8> :: value == 32u,
		 "BitFloor of 0x22 should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x23_8> :: value == 32u,
		 "BitFloor of 0x23 should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x24_8> :: value == 32u,
		 "BitFloor of 0x24 should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x25_8> :: value == 32u,
		 "BitFloor of 0x25 should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x26_8> :: value == 32u,
		 "BitFloor of 0x26 should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x27_8> :: value == 32u,
		 "BitFloor of 0x27 should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x28_8> :: value == 32u,
		 "BitFloor of 0x28 should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x29_8> :: value == 32u,
		 "BitFloor of 0x29 should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x2A_8> :: value == 32u,
		 "BitFloor of 0x2A should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x2B_8> :: value == 32u,
		 "BitFloor of 0x2B should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x2C_8> :: value == 32u,
		 "BitFloor of 0x2C should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x2D_8> :: value == 32u,
		 "BitFloor of 0x2D should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x2E_8> :: value == 32u,
		 "BitFloor of 0x2E should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x2F_8> :: value == 32u,
		 "BitFloor of 0x2F should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x30_8> :: value == 32u,
		 "BitFloor of 0x30 should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x31_8> :: value == 32u,
		 "BitFloor of 0x31 should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x32_8> :: value == 32u,
		 "BitFloor of 0x32 should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x33_8> :: value == 32u,
		 "BitFloor of 0x33 should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x34_8> :: value == 32u,
		 "BitFloor of 0x34 should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x35_8> :: value == 32u,
		 "BitFloor of 0x35 should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x36_8> :: value == 32u,
		 "BitFloor of 0x36 should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x37_8> :: value == 32u,
		 "BitFloor of 0x37 should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x38_8> :: value == 32u,
		 "BitFloor of 0x38 should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x39_8> :: value == 32u,
		 "BitFloor of 0x39 should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x3A_8> :: value == 32u,
		 "BitFloor of 0x3A should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x3B_8> :: value == 32u,
		 "BitFloor of 0x3B should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x3C_8> :: value == 32u,
		 "BitFloor of 0x3C should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x3D_8> :: value == 32u,
		 "BitFloor of 0x3D should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x3E_8> :: value == 32u,
		 "BitFloor of 0x3E should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x3F_8> :: value == 32u,
		 "BitFloor of 0x3F should be 32.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x40_8> :: value == 64u,
		 "BitFloor of 0x40 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x41_8> :: value == 64u,
		 "BitFloor of 0x41 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x42_8> :: value == 64u,
		 "BitFloor of 0x42 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x43_8> :: value == 64u,
		 "BitFloor of 0x43 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x44_8> :: value == 64u,
		 "BitFloor of 0x44 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x45_8> :: value == 64u,
		 "BitFloor of 0x45 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x46_8> :: value == 64u,
		 "BitFloor of 0x46 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x47_8> :: value == 64u,
		 "BitFloor of 0x47 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x48_8> :: value == 64u,
		 "BitFloor of 0x48 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x49_8> :: value == 64u,
		 "BitFloor of 0x49 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x4A_8> :: value == 64u,
		 "BitFloor of 0x4A should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x4B_8> :: value == 64u,
		 "BitFloor of 0x4B should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x4C_8> :: value == 64u,
		 "BitFloor of 0x4C should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x4D_8> :: value == 64u,
		 "BitFloor of 0x4D should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x4E_8> :: value == 64u,
		 "BitFloor of 0x4E should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x4F_8> :: value == 64u,
		 "BitFloor of 0x4F should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x50_8> :: value == 64u,
		 "BitFloor of 0x50 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x51_8> :: value == 64u,
		 "BitFloor of 0x51 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x52_8> :: value == 64u,
		 "BitFloor of 0x52 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x53_8> :: value == 64u,
		 "BitFloor of 0x53 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x54_8> :: value == 64u,
		 "BitFloor of 0x54 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x55_8> :: value == 64u,
		 "BitFloor of 0x55 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x56_8> :: value == 64u,
		 "BitFloor of 0x56 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x57_8> :: value == 64u,
		 "BitFloor of 0x57 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x58_8> :: value == 64u,
		 "BitFloor of 0x58 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x59_8> :: value == 64u,
		 "BitFloor of 0x59 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x5A_8> :: value == 64u,
		 "BitFloor of 0x5A should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x5B_8> :: value == 64u,
		 "BitFloor of 0x5B should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x5C_8> :: value == 64u,
		 "BitFloor of 0x5C should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x5D_8> :: value == 64u,
		 "BitFloor of 0x5D should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x5E_8> :: value == 64u,
		 "BitFloor of 0x5E should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x5F_8> :: value == 64u,
		 "BitFloor of 0x5F should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x60_8> :: value == 64u,
		 "BitFloor of 0x60 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x61_8> :: value == 64u,
		 "BitFloor of 0x61 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x62_8> :: value == 64u,
		 "BitFloor of 0x62 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x63_8> :: value == 64u,
		 "BitFloor of 0x63 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x64_8> :: value == 64u,
		 "BitFloor of 0x64 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x65_8> :: value == 64u,
		 "BitFloor of 0x65 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x66_8> :: value == 64u,
		 "BitFloor of 0x66 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x67_8> :: value == 64u,
		 "BitFloor of 0x67 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x68_8> :: value == 64u,
		 "BitFloor of 0x68 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x69_8> :: value == 64u,
		 "BitFloor of 0x69 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x6A_8> :: value == 64u,
		 "BitFloor of 0x6A should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x6B_8> :: value == 64u,
		 "BitFloor of 0x6B should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x6C_8> :: value == 64u,
		 "BitFloor of 0x6C should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x6D_8> :: value == 64u,
		 "BitFloor of 0x6D should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x6E_8> :: value == 64u,
		 "BitFloor of 0x6E should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x6F_8> :: value == 64u,
		 "BitFloor of 0x6F should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x70_8> :: value == 64u,
		 "BitFloor of 0x70 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x71_8> :: value == 64u,
		 "BitFloor of 0x71 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x72_8> :: value == 64u,
		 "BitFloor of 0x72 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x73_8> :: value == 64u,
		 "BitFloor of 0x73 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x74_8> :: value == 64u,
		 "BitFloor of 0x74 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x75_8> :: value == 64u,
		 "BitFloor of 0x75 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x76_8> :: value == 64u,
		 "BitFloor of 0x76 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x77_8> :: value == 64u,
		 "BitFloor of 0x77 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x78_8> :: value == 64u,
		 "BitFloor of 0x78 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x79_8> :: value == 64u,
		 "BitFloor of 0x79 should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x7A_8> :: value == 64u,
		 "BitFloor of 0x7A should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x7B_8> :: value == 64u,
		 "BitFloor of 0x7B should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x7C_8> :: value == 64u,
		 "BitFloor of 0x7C should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x7D_8> :: value == 64u,
		 "BitFloor of 0x7D should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x7E_8> :: value == 64u,
		 "BitFloor of 0x7E should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x7F_8> :: value == 64u,
		 "BitFloor of 0x7F should be 64.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x80_8> :: value == 128u,
		 "BitFloor of 0x80 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x81_8> :: value == 128u,
		 "BitFloor of 0x81 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x82_8> :: value == 128u,
		 "BitFloor of 0x82 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x83_8> :: value == 128u,
		 "BitFloor of 0x83 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x84_8> :: value == 128u,
		 "BitFloor of 0x84 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x85_8> :: value == 128u,
		 "BitFloor of 0x85 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x86_8> :: value == 128u,
		 "BitFloor of 0x86 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x87_8> :: value == 128u,
		 "BitFloor of 0x87 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x88_8> :: value == 128u,
		 "BitFloor of 0x88 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x89_8> :: value == 128u,
		 "BitFloor of 0x89 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x8A_8> :: value == 128u,
		 "BitFloor of 0x8A should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x8B_8> :: value == 128u,
		 "BitFloor of 0x8B should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x8C_8> :: value == 128u,
		 "BitFloor of 0x8C should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x8D_8> :: value == 128u,
		 "BitFloor of 0x8D should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x8E_8> :: value == 128u,
		 "BitFloor of 0x8E should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x8F_8> :: value == 128u,
		 "BitFloor of 0x8F should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x90_8> :: value == 128u,
		 "BitFloor of 0x90 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x91_8> :: value == 128u,
		 "BitFloor of 0x91 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x92_8> :: value == 128u,
		 "BitFloor of 0x92 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x93_8> :: value == 128u,
		 "BitFloor of 0x93 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x94_8> :: value == 128u,
		 "BitFloor of 0x94 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x95_8> :: value == 128u,
		 "BitFloor of 0x95 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x96_8> :: value == 128u,
		 "BitFloor of 0x96 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x97_8> :: value == 128u,
		 "BitFloor of 0x97 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x98_8> :: value == 128u,
		 "BitFloor of 0x98 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x99_8> :: value == 128u,
		 "BitFloor of 0x99 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x9A_8> :: value == 128u,
		 "BitFloor of 0x9A should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x9B_8> :: value == 128u,
		 "BitFloor of 0x9B should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x9C_8> :: value == 128u,
		 "BitFloor of 0x9C should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x9D_8> :: value == 128u,
		 "BitFloor of 0x9D should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x9E_8> :: value == 128u,
		 "BitFloor of 0x9E should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, x9F_8> :: value == 128u,
		 "BitFloor of 0x9F should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xA0_8> :: value == 128u,
		 "BitFloor of 0xA0 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xA1_8> :: value == 128u,
		 "BitFloor of 0xA1 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xA2_8> :: value == 128u,
		 "BitFloor of 0xA2 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xA3_8> :: value == 128u,
		 "BitFloor of 0xA3 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xA4_8> :: value == 128u,
		 "BitFloor of 0xA4 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xA5_8> :: value == 128u,
		 "BitFloor of 0xA5 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xA6_8> :: value == 128u,
		 "BitFloor of 0xA6 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xA7_8> :: value == 128u,
		 "BitFloor of 0xA7 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xA8_8> :: value == 128u,
		 "BitFloor of 0xA8 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xA9_8> :: value == 128u,
		 "BitFloor of 0xA9 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xAA_8> :: value == 128u,
		 "BitFloor of 0xAA should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xAB_8> :: value == 128u,
		 "BitFloor of 0xAB should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xAC_8> :: value == 128u,
		 "BitFloor of 0xAC should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xAD_8> :: value == 128u,
		 "BitFloor of 0xAD should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xAE_8> :: value == 128u,
		 "BitFloor of 0xAE should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xAF_8> :: value == 128u,
		 "BitFloor of 0xAF should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xB0_8> :: value == 128u,
		 "BitFloor of 0xB0 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xB1_8> :: value == 128u,
		 "BitFloor of 0xB1 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xB2_8> :: value == 128u,
		 "BitFloor of 0xB2 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xB3_8> :: value == 128u,
		 "BitFloor of 0xB3 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xB4_8> :: value == 128u,
		 "BitFloor of 0xB4 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xB5_8> :: value == 128u,
		 "BitFloor of 0xB5 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xB6_8> :: value == 128u,
		 "BitFloor of 0xB6 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xB7_8> :: value == 128u,
		 "BitFloor of 0xB7 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xB8_8> :: value == 128u,
		 "BitFloor of 0xB8 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xB9_8> :: value == 128u,
		 "BitFloor of 0xB9 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xBA_8> :: value == 128u,
		 "BitFloor of 0xBA should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xBB_8> :: value == 128u,
		 "BitFloor of 0xBB should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xBC_8> :: value == 128u,
		 "BitFloor of 0xBC should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xBD_8> :: value == 128u,
		 "BitFloor of 0xBD should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xBE_8> :: value == 128u,
		 "BitFloor of 0xBE should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xBF_8> :: value == 128u,
		 "BitFloor of 0xBF should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xC0_8> :: value == 128u,
		 "BitFloor of 0xC0 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xC1_8> :: value == 128u,
		 "BitFloor of 0xC1 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xC2_8> :: value == 128u,
		 "BitFloor of 0xC2 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xC3_8> :: value == 128u,
		 "BitFloor of 0xC3 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xC4_8> :: value == 128u,
		 "BitFloor of 0xC4 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xC5_8> :: value == 128u,
		 "BitFloor of 0xC5 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xC6_8> :: value == 128u,
		 "BitFloor of 0xC6 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xC7_8> :: value == 128u,
		 "BitFloor of 0xC7 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xC8_8> :: value == 128u,
		 "BitFloor of 0xC8 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xC9_8> :: value == 128u,
		 "BitFloor of 0xC9 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xCA_8> :: value == 128u,
		 "BitFloor of 0xCA should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xCB_8> :: value == 128u,
		 "BitFloor of 0xCB should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xCC_8> :: value == 128u,
		 "BitFloor of 0xCC should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xCD_8> :: value == 128u,
		 "BitFloor of 0xCD should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xCE_8> :: value == 128u,
		 "BitFloor of 0xCE should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xCF_8> :: value == 128u,
		 "BitFloor of 0xCF should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xD0_8> :: value == 128u,
		 "BitFloor of 0xD0 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xD1_8> :: value == 128u,
		 "BitFloor of 0xD1 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xD2_8> :: value == 128u,
		 "BitFloor of 0xD2 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xD3_8> :: value == 128u,
		 "BitFloor of 0xD3 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xD4_8> :: value == 128u,
		 "BitFloor of 0xD4 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xD5_8> :: value == 128u,
		 "BitFloor of 0xD5 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xD6_8> :: value == 128u,
		 "BitFloor of 0xD6 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xD7_8> :: value == 128u,
		 "BitFloor of 0xD7 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xD8_8> :: value == 128u,
		 "BitFloor of 0xD8 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xD9_8> :: value == 128u,
		 "BitFloor of 0xD9 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xDA_8> :: value == 128u,
		 "BitFloor of 0xDA should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xDB_8> :: value == 128u,
		 "BitFloor of 0xDB should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xDC_8> :: value == 128u,
		 "BitFloor of 0xDC should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xDD_8> :: value == 128u,
		 "BitFloor of 0xDD should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xDE_8> :: value == 128u,
		 "BitFloor of 0xDE should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xDF_8> :: value == 128u,
		 "BitFloor of 0xDF should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xE0_8> :: value == 128u,
		 "BitFloor of 0xE0 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xE1_8> :: value == 128u,
		 "BitFloor of 0xE1 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xE2_8> :: value == 128u,
		 "BitFloor of 0xE2 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xE3_8> :: value == 128u,
		 "BitFloor of 0xE3 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xE4_8> :: value == 128u,
		 "BitFloor of 0xE4 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xE5_8> :: value == 128u,
		 "BitFloor of 0xE5 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xE6_8> :: value == 128u,
		 "BitFloor of 0xE6 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xE7_8> :: value == 128u,
		 "BitFloor of 0xE7 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xE8_8> :: value == 128u,
		 "BitFloor of 0xE8 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xE9_8> :: value == 128u,
		 "BitFloor of 0xE9 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xEA_8> :: value == 128u,
		 "BitFloor of 0xEA should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xEB_8> :: value == 128u,
		 "BitFloor of 0xEB should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xEC_8> :: value == 128u,
		 "BitFloor of 0xEC should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xED_8> :: value == 128u,
		 "BitFloor of 0xED should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xEE_8> :: value == 128u,
		 "BitFloor of 0xEE should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xEF_8> :: value == 128u,
		 "BitFloor of 0xEF should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xF0_8> :: value == 128u,
		 "BitFloor of 0xF0 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xF1_8> :: value == 128u,
		 "BitFloor of 0xF1 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xF2_8> :: value == 128u,
		 "BitFloor of 0xF2 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xF3_8> :: value == 128u,
		 "BitFloor of 0xF3 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xF4_8> :: value == 128u,
		 "BitFloor of 0xF4 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xF5_8> :: value == 128u,
		 "BitFloor of 0xF5 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xF6_8> :: value == 128u,
		 "BitFloor of 0xF6 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xF7_8> :: value == 128u,
		 "BitFloor of 0xF7 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xF8_8> :: value == 128u,
		 "BitFloor of 0xF8 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xF9_8> :: value == 128u,
		 "BitFloor of 0xF9 should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xFA_8> :: value == 128u,
		 "BitFloor of 0xFA should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xFB_8> :: value == 128u,
		 "BitFloor of 0xFB should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xFC_8> :: value == 128u,
		 "BitFloor of 0xFC should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xFD_8> :: value == 128u,
		 "BitFloor of 0xFD should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xFE_8> :: value == 128u,
		 "BitFloor of 0xFE should be 128.");
 static_assert(crap :: bitFloorValue <std :: uint8_t, xFF_8> :: value == 128u,
		 "BitFloor of 0xFF should be 128.");
}

void test_uint32_t_2_to_n()
{
 constexpr const static std :: uint32_t any32 = {};
 constexpr const static std :: uint32_t zeros32 = any32 ^ any32;
 constexpr const static std :: uint32_t ones32 = ~zeros32;
 constexpr const static std :: uint32_t one32 = ~(ones32 << 1u);
 static_assert(crap :: bitFloorValue <std :: uint32_t, zeros32> :: value == 0x00000000u,
		 "BitFloor of 0x00000000 should be 0x00000000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ones32> :: value == 0x80000000u,
		 "BitFloor of 0xFFFFFFFF should be 0x80000000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 0u> :: value == 0x00000001u,
		 "BitFloor of 0x00000001 should be 0x00000001.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 1u> :: value == 0x00000002u,
		 "BitFloor of 0x00000002 should be 0x00000002.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 2u> :: value == 0x00000004u,
		 "BitFloor of 0x00000004 should be 0x00000004.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 3u> :: value == 0x00000008u,
		 "BitFloor of 0x00000008 should be 0x00000008.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 4u> :: value == 0x00000010u,
		 "BitFloor of 0x00000010 should be 0x00000010.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 5u> :: value == 0x00000020u,
		 "BitFloor of 0x00000020 should be 0x00000020.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 6u> :: value == 0x00000040u,
		 "BitFloor of 0x00000040 should be 0x00000040.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 7u> :: value == 0x00000080u,
		 "BitFloor of 0x00000080 should be 0x00000080.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 8u> :: value == 0x00000100u,
		 "BitFloor of 0x00000100 should be 0x00000100.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 9u> :: value == 0x00000200u,
		 "BitFloor of 0x00000200 should be 0x00000200.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 10u> :: value == 0x00000400u,
		 "BitFloor of 0x00000400 should be 0x00000400.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 11u> :: value == 0x00000800u,
		 "BitFloor of 0x00000800 should be 0x00000800.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 12u> :: value == 0x00001000u,
		 "BitFloor of 0x00001000 should be 0x00001000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 13u> :: value == 0x00002000u,
		 "BitFloor of 0x00002000 should be 0x00002000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 14u> :: value == 0x00004000u,
		 "BitFloor of 0x00004000 should be 0x00004000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 15u> :: value == 0x00008000u,
		 "BitFloor of 0x00008000 should be 0x00008000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 16u> :: value == 0x00010000u,
		 "BitFloor of 0x00010000 should be 0x00010000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 17u> :: value == 0x00020000u,
		 "BitFloor of 0x00020000 should be 0x00020000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 18u> :: value == 0x00040000u,
		 "BitFloor of 0x00040000 should be 0x00040000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 19u> :: value == 0x00080000u,
		 "BitFloor of 0x00080000 should be 0x00080000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 20u> :: value == 0x00100000u,
		 "BitFloor of 0x00100000 should be 0x00100000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 21u> :: value == 0x00200000u,
		 "BitFloor of 0x00200000 should be 0x00200000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 22u> :: value == 0x00400000u,
		 "BitFloor of 0x00400000 should be 0x00400000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 23u> :: value == 0x00800000u,
		 "BitFloor of 0x00800000 should be 0x00800000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 24u> :: value == 0x01000000u,
		 "BitFloor of 0x01000000 should be 0x01000000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 25u> :: value == 0x02000000u,
		 "BitFloor of 0x02000000 should be 0x02000000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 26u> :: value == 0x04000000u,
		 "BitFloor of 0x04000000 should be 0x04000000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 27u> :: value == 0x08000000u,
		 "BitFloor of 0x08000000 should be 0x08000000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 28u> :: value == 0x10000000u,
		 "BitFloor of 0x10000000 should be 0x10000000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 29u> :: value == 0x20000000u,
		 "BitFloor of 0x20000000 should be 0x20000000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 30u> :: value == 0x40000000u,
		 "BitFloor of 0x40000000 should be 0x40000000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, one32 << 31u> :: value == 0x80000000u,
		 "BitFloor of 0x80000000 should be 0x80000000.");
}

void test_uint32_t_marching_ones()
{
 constexpr const static std :: uint32_t any32 = {};
 constexpr const static std :: uint32_t zeros32 = any32 ^ any32;
 constexpr const static std :: uint32_t ones32 = ~zeros32;
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 0u)> :: value == 0x00000000u,
		 "BitFloor of 0x00000000 should be 0x00000000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 1u)> :: value == 0x00000001u,
		 "BitFloor of 0x00000001 should be 0x00000001.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 2u)> :: value == 0x00000002u,
		 "BitFloor of 0x00000003 should be 0x00000002.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 3u)> :: value == 0x00000004u,
		 "BitFloor of 0x00000007 should be 0x00000004.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 4u)> :: value == 0x00000008u,
		 "BitFloor of 0x0000000F should be 0x00000008.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 5u)> :: value == 0x00000010u,
		 "BitFloor of 0x0000001F should be 0x00000010.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 6u)> :: value == 0x00000020u,
		 "BitFloor of 0x0000003F should be 0x00000020.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 7u)> :: value == 0x00000040u,
		 "BitFloor of 0x0000007F should be 0x00000040.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 8u)> :: value == 0x00000080u,
		 "BitFloor of 0x000000FF should be 0x00000080.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 9u)> :: value == 0x00000100u,
		 "BitFloor of 0x000001FF should be 0x00000100.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 10u)> :: value == 0x00000200u,
		 "BitFloor of 0x000003FF should be 0x00000200.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 11u)> :: value == 0x00000400u,
		 "BitFloor of 0x000007FF should be 0x00000400.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 12u)> :: value == 0x00000800u,
		 "BitFloor of 0x00000FFF should be 0x00000800.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 13u)> :: value == 0x00001000u,
		 "BitFloor of 0x00001FFF should be 0x00001000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 14u)> :: value == 0x00002000u,
		 "BitFloor of 0x00003FFF should be 0x00002000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 15u)> :: value == 0x00004000u,
		 "BitFloor of 0x00007FFF should be 0x00004000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 16u)> :: value == 0x00008000u,
		 "BitFloor of 0x0000FFFF should be 0x00008000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 17u)> :: value == 0x00010000u,
		 "BitFloor of 0x0001FFFF should be 0x00010000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 18u)> :: value == 0x00020000u,
		 "BitFloor of 0x0003FFFF should be 0x00020000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 19u)> :: value == 0x00040000u,
		 "BitFloor of 0x0007FFFF should be 0x00040000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 20u)> :: value == 0x00080000u,
		 "BitFloor of 0x000FFFFF should be 0x00080000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 21u)> :: value == 0x00100000u,
		 "BitFloor of 0x001FFFFF should be 0x00100000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 22u)> :: value == 0x00200000u,
		 "BitFloor of 0x003FFFFF should be 0x00200000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 23u)> :: value == 0x00400000u,
		 "BitFloor of 0x007FFFFF should be 0x00400000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 24u)> :: value == 0x00800000u,
		 "BitFloor of 0x00FFFFFF should be 0x00800000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 25u)> :: value == 0x01000000u,
		 "BitFloor of 0x01FFFFFF should be 0x01000000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 26u)> :: value == 0x02000000u,
		 "BitFloor of 0x03FFFFFF should be 0x02000000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 27u)> :: value == 0x04000000u,
		 "BitFloor of 0x07FFFFFF should be 0x04000000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 28u)> :: value == 0x08000000u,
		 "BitFloor of 0x0FFFFFFF should be 0x08000000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 29u)> :: value == 0x10000000u,
		 "BitFloor of 0x1FFFFFFF should be 0x10000000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 30u)> :: value == 0x20000000u,
		 "BitFloor of 0x3FFFFFFF should be 0x20000000.");
 static_assert(crap :: bitFloorValue <std :: uint32_t, ~(ones32 << 31u)> :: value == 0x40000000u,
		 "BitFloor of 0x7FFFFFFF should be 0x40000000.");
}

int main()
{
 test_uint8_t();
 test_uint32_t_2_to_n();
 test_uint32_t_marching_ones();

 return EXIT_SUCCESS;
}
