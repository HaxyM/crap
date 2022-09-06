#include "../include/crap/bit.d/rotrvalue.h"

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
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x00_8> :: value == x00_8,
		 "Rotr of 0x00 by 0 should be 0x00.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x01_8> :: value == x01_8,
		 "Rotr of 0x01 by 0 should be 0x01.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x02_8> :: value == x02_8,
		 "Rotr of 0x02 by 0 should be 0x02.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x03_8> :: value == x03_8,
		 "Rotr of 0x03 by 0 should be 0x03.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x04_8> :: value == x04_8,
		 "Rotr of 0x04 by 0 should be 0x04.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x05_8> :: value == x05_8,
		 "Rotr of 0x05 by 0 should be 0x05.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x06_8> :: value == x06_8,
		 "Rotr of 0x06 by 0 should be 0x06.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x07_8> :: value == x07_8,
		 "Rotr of 0x07 by 0 should be 0x07.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x08_8> :: value == x08_8,
		 "Rotr of 0x08 by 0 should be 0x08.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x09_8> :: value == x09_8,
		 "Rotr of 0x09 by 0 should be 0x09.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x0A_8> :: value == x0A_8,
		 "Rotr of 0x0A by 0 should be 0x0A.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x0B_8> :: value == x0B_8,
		 "Rotr of 0x0B by 0 should be 0x0B.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x0C_8> :: value == x0C_8,
		 "Rotr of 0x0C by 0 should be 0x0C.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x0D_8> :: value == x0D_8,
		 "Rotr of 0x0D by 0 should be 0x0D.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x0E_8> :: value == x0E_8,
		 "Rotr of 0x0E by 0 should be 0x0E.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x0F_8> :: value == x0F_8,
		 "Rotr of 0x0F by 0 should be 0x0F.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x10_8> :: value == x10_8,
		 "Rotr of 0x10 by 0 should be 0x10.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x11_8> :: value == x11_8,
		 "Rotr of 0x11 by 0 should be 0x11.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x12_8> :: value == x12_8,
		 "Rotr of 0x12 by 0 should be 0x12.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x13_8> :: value == x13_8,
		 "Rotr of 0x13 by 0 should be 0x13.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x14_8> :: value == x14_8,
		 "Rotr of 0x14 by 0 should be 0x14.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x15_8> :: value == x15_8,
		 "Rotr of 0x15 by 0 should be 0x15.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x16_8> :: value == x16_8,
		 "Rotr of 0x16 by 0 should be 0x16.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x17_8> :: value == x17_8,
		 "Rotr of 0x17 by 0 should be 0x17.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x18_8> :: value == x18_8,
		 "Rotr of 0x18 by 0 should be 0x18.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x19_8> :: value == x19_8,
		 "Rotr of 0x19 by 0 should be 0x19.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x1A_8> :: value == x1A_8,
		 "Rotr of 0x1A by 0 should be 0x1A.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x1B_8> :: value == x1B_8,
		 "Rotr of 0x1B by 0 should be 0x1B.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x1C_8> :: value == x1C_8,
		 "Rotr of 0x1C by 0 should be 0x1C.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x1D_8> :: value == x1D_8,
		 "Rotr of 0x1D by 0 should be 0x1D.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x1E_8> :: value == x1E_8,
		 "Rotr of 0x1E by 0 should be 0x1E.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x1F_8> :: value == x1F_8,
		 "Rotr of 0x1F by 0 should be 0x1F.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x20_8> :: value == x20_8,
		 "Rotr of 0x20 by 0 should be 0x20.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x21_8> :: value == x21_8,
		 "Rotr of 0x21 by 0 should be 0x21.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x22_8> :: value == x22_8,
		 "Rotr of 0x22 by 0 should be 0x22.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x23_8> :: value == x23_8,
		 "Rotr of 0x23 by 0 should be 0x23.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x24_8> :: value == x24_8,
		 "Rotr of 0x24 by 0 should be 0x24.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x25_8> :: value == x25_8,
		 "Rotr of 0x25 by 0 should be 0x25.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x26_8> :: value == x26_8,
		 "Rotr of 0x26 by 0 should be 0x26.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x27_8> :: value == x27_8,
		 "Rotr of 0x27 by 0 should be 0x27.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x28_8> :: value == x28_8,
		 "Rotr of 0x28 by 0 should be 0x28.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x29_8> :: value == x29_8,
		 "Rotr of 0x29 by 0 should be 0x29.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x2A_8> :: value == x2A_8,
		 "Rotr of 0x2A by 0 should be 0x2A.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x2B_8> :: value == x2B_8,
		 "Rotr of 0x2B by 0 should be 0x2B.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x2C_8> :: value == x2C_8,
		 "Rotr of 0x2C by 0 should be 0x2C.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x2D_8> :: value == x2D_8,
		 "Rotr of 0x2D by 0 should be 0x2D.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x2E_8> :: value == x2E_8,
		 "Rotr of 0x2E by 0 should be 0x2E.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x2F_8> :: value == x2F_8,
		 "Rotr of 0x2F by 0 should be 0x2F.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x30_8> :: value == x30_8,
		 "Rotr of 0x30 by 0 should be 0x30.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x31_8> :: value == x31_8,
		 "Rotr of 0x31 by 0 should be 0x31.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x32_8> :: value == x32_8,
		 "Rotr of 0x32 by 0 should be 0x32.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x33_8> :: value == x33_8,
		 "Rotr of 0x33 by 0 should be 0x33.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x34_8> :: value == x34_8,
		 "Rotr of 0x34 by 0 should be 0x34.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x35_8> :: value == x35_8,
		 "Rotr of 0x35 by 0 should be 0x35.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x36_8> :: value == x36_8,
		 "Rotr of 0x36 by 0 should be 0x36.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x37_8> :: value == x37_8,
		 "Rotr of 0x37 by 0 should be 0x37.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x38_8> :: value == x38_8,
		 "Rotr of 0x38 by 0 should be 0x38.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x39_8> :: value == x39_8,
		 "Rotr of 0x39 by 0 should be 0x39.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x3A_8> :: value == x3A_8,
		 "Rotr of 0x3A by 0 should be 0x3A.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x3B_8> :: value == x3B_8,
		 "Rotr of 0x3B by 0 should be 0x3B.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x3C_8> :: value == x3C_8,
		 "Rotr of 0x3C by 0 should be 0x3C.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x3D_8> :: value == x3D_8,
		 "Rotr of 0x3D by 0 should be 0x3D.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x3E_8> :: value == x3E_8,
		 "Rotr of 0x3E by 0 should be 0x3E.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x3F_8> :: value == x3F_8,
		 "Rotr of 0x3F by 0 should be 0x3F.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x40_8> :: value == x40_8,
		 "Rotr of 0x40 by 0 should be 0x40.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x41_8> :: value == x41_8,
		 "Rotr of 0x41 by 0 should be 0x41.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x42_8> :: value == x42_8,
		 "Rotr of 0x42 by 0 should be 0x42.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x43_8> :: value == x43_8,
		 "Rotr of 0x43 by 0 should be 0x43.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x44_8> :: value == x44_8,
		 "Rotr of 0x44 by 0 should be 0x44.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x45_8> :: value == x45_8,
		 "Rotr of 0x45 by 0 should be 0x45.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x46_8> :: value == x46_8,
		 "Rotr of 0x46 by 0 should be 0x46.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x47_8> :: value == x47_8,
		 "Rotr of 0x47 by 0 should be 0x47.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x48_8> :: value == x48_8,
		 "Rotr of 0x48 by 0 should be 0x48.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x49_8> :: value == x49_8,
		 "Rotr of 0x49 by 0 should be 0x49.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x4A_8> :: value == x4A_8,
		 "Rotr of 0x4A by 0 should be 0x4A.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x4B_8> :: value == x4B_8,
		 "Rotr of 0x4B by 0 should be 0x4B.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x4C_8> :: value == x4C_8,
		 "Rotr of 0x4C by 0 should be 0x4C.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x4D_8> :: value == x4D_8,
		 "Rotr of 0x4D by 0 should be 0x4D.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x4E_8> :: value == x4E_8,
		 "Rotr of 0x4E by 0 should be 0x4E.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x4F_8> :: value == x4F_8,
		 "Rotr of 0x4F by 0 should be 0x4F.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x50_8> :: value == x50_8,
		 "Rotr of 0x50 by 0 should be 0x50.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x51_8> :: value == x51_8,
		 "Rotr of 0x51 by 0 should be 0x51.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x52_8> :: value == x52_8,
		 "Rotr of 0x52 by 0 should be 0x52.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x53_8> :: value == x53_8,
		 "Rotr of 0x53 by 0 should be 0x53.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x54_8> :: value == x54_8,
		 "Rotr of 0x54 by 0 should be 0x54.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x55_8> :: value == x55_8,
		 "Rotr of 0x55 by 0 should be 0x55.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x56_8> :: value == x56_8,
		 "Rotr of 0x56 by 0 should be 0x56.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x57_8> :: value == x57_8,
		 "Rotr of 0x57 by 0 should be 0x57.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x58_8> :: value == x58_8,
		 "Rotr of 0x58 by 0 should be 0x58.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x59_8> :: value == x59_8,
		 "Rotr of 0x59 by 0 should be 0x59.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x5A_8> :: value == x5A_8,
		 "Rotr of 0x5A by 0 should be 0x5A.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x5B_8> :: value == x5B_8,
		 "Rotr of 0x5B by 0 should be 0x5B.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x5C_8> :: value == x5C_8,
		 "Rotr of 0x5C by 0 should be 0x5C.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x5D_8> :: value == x5D_8,
		 "Rotr of 0x5D by 0 should be 0x5D.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x5E_8> :: value == x5E_8,
		 "Rotr of 0x5E by 0 should be 0x5E.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x5F_8> :: value == x5F_8,
		 "Rotr of 0x5F by 0 should be 0x5F.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x60_8> :: value == x60_8,
		 "Rotr of 0x60 by 0 should be 0x60.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x61_8> :: value == x61_8,
		 "Rotr of 0x61 by 0 should be 0x61.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x62_8> :: value == x62_8,
		 "Rotr of 0x62 by 0 should be 0x62.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x63_8> :: value == x63_8,
		 "Rotr of 0x63 by 0 should be 0x63.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x64_8> :: value == x64_8,
		 "Rotr of 0x64 by 0 should be 0x64.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x65_8> :: value == x65_8,
		 "Rotr of 0x65 by 0 should be 0x65.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x66_8> :: value == x66_8,
		 "Rotr of 0x66 by 0 should be 0x66.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x67_8> :: value == x67_8,
		 "Rotr of 0x67 by 0 should be 0x67.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x68_8> :: value == x68_8,
		 "Rotr of 0x68 by 0 should be 0x68.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x69_8> :: value == x69_8,
		 "Rotr of 0x69 by 0 should be 0x69.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x6A_8> :: value == x6A_8,
		 "Rotr of 0x6A by 0 should be 0x6A.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x6B_8> :: value == x6B_8,
		 "Rotr of 0x6B by 0 should be 0x6B.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x6C_8> :: value == x6C_8,
		 "Rotr of 0x6C by 0 should be 0x6C.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x6D_8> :: value == x6D_8,
		 "Rotr of 0x6D by 0 should be 0x6D.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x6E_8> :: value == x6E_8,
		 "Rotr of 0x6E by 0 should be 0x6E.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x6F_8> :: value == x6F_8,
		 "Rotr of 0x6F by 0 should be 0x6F.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x70_8> :: value == x70_8,
		 "Rotr of 0x70 by 0 should be 0x70.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x71_8> :: value == x71_8,
		 "Rotr of 0x71 by 0 should be 0x71.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x72_8> :: value == x72_8,
		 "Rotr of 0x72 by 0 should be 0x72.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x73_8> :: value == x73_8,
		 "Rotr of 0x73 by 0 should be 0x73.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x74_8> :: value == x74_8,
		 "Rotr of 0x74 by 0 should be 0x74.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x75_8> :: value == x75_8,
		 "Rotr of 0x75 by 0 should be 0x75.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x76_8> :: value == x76_8,
		 "Rotr of 0x76 by 0 should be 0x76.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x77_8> :: value == x77_8,
		 "Rotr of 0x77 by 0 should be 0x77.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x78_8> :: value == x78_8,
		 "Rotr of 0x78 by 0 should be 0x78.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x79_8> :: value == x79_8,
		 "Rotr of 0x79 by 0 should be 0x79.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x7A_8> :: value == x7A_8,
		 "Rotr of 0x7A by 0 should be 0x7A.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x7B_8> :: value == x7B_8,
		 "Rotr of 0x7B by 0 should be 0x7B.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x7C_8> :: value == x7C_8,
		 "Rotr of 0x7C by 0 should be 0x7C.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x7D_8> :: value == x7D_8,
		 "Rotr of 0x7D by 0 should be 0x7D.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x7E_8> :: value == x7E_8,
		 "Rotr of 0x7E by 0 should be 0x7E.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x7F_8> :: value == x7F_8,
		 "Rotr of 0x7F by 0 should be 0x7F.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x80_8> :: value == x80_8,
		 "Rotr of 0x80 by 0 should be 0x80.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x81_8> :: value == x81_8,
		 "Rotr of 0x81 by 0 should be 0x81.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x82_8> :: value == x82_8,
		 "Rotr of 0x82 by 0 should be 0x82.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x83_8> :: value == x83_8,
		 "Rotr of 0x83 by 0 should be 0x83.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x84_8> :: value == x84_8,
		 "Rotr of 0x84 by 0 should be 0x84.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x85_8> :: value == x85_8,
		 "Rotr of 0x85 by 0 should be 0x85.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x86_8> :: value == x86_8,
		 "Rotr of 0x86 by 0 should be 0x86.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x87_8> :: value == x87_8,
		 "Rotr of 0x87 by 0 should be 0x87.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x88_8> :: value == x88_8,
		 "Rotr of 0x88 by 0 should be 0x88.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x89_8> :: value == x89_8,
		 "Rotr of 0x89 by 0 should be 0x89.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x8A_8> :: value == x8A_8,
		 "Rotr of 0x8A by 0 should be 0x8A.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x8B_8> :: value == x8B_8,
		 "Rotr of 0x8B by 0 should be 0x8B.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x8C_8> :: value == x8C_8,
		 "Rotr of 0x8C by 0 should be 0x8C.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x8D_8> :: value == x8D_8,
		 "Rotr of 0x8D by 0 should be 0x8D.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x8E_8> :: value == x8E_8,
		 "Rotr of 0x8E by 0 should be 0x8E.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x8F_8> :: value == x8F_8,
		 "Rotr of 0x8F by 0 should be 0x8F.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x90_8> :: value == x90_8,
		 "Rotr of 0x90 by 0 should be 0x90.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x91_8> :: value == x91_8,
		 "Rotr of 0x91 by 0 should be 0x91.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x92_8> :: value == x92_8,
		 "Rotr of 0x92 by 0 should be 0x92.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x93_8> :: value == x93_8,
		 "Rotr of 0x93 by 0 should be 0x93.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x94_8> :: value == x94_8,
		 "Rotr of 0x94 by 0 should be 0x94.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x95_8> :: value == x95_8,
		 "Rotr of 0x95 by 0 should be 0x95.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x96_8> :: value == x96_8,
		 "Rotr of 0x96 by 0 should be 0x96.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x97_8> :: value == x97_8,
		 "Rotr of 0x97 by 0 should be 0x97.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x98_8> :: value == x98_8,
		 "Rotr of 0x98 by 0 should be 0x98.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x99_8> :: value == x99_8,
		 "Rotr of 0x99 by 0 should be 0x99.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x9A_8> :: value == x9A_8,
		 "Rotr of 0x9A by 0 should be 0x9A.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x9B_8> :: value == x9B_8,
		 "Rotr of 0x9B by 0 should be 0x9B.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x9C_8> :: value == x9C_8,
		 "Rotr of 0x9C by 0 should be 0x9C.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x9D_8> :: value == x9D_8,
		 "Rotr of 0x9D by 0 should be 0x9D.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x9E_8> :: value == x9E_8,
		 "Rotr of 0x9E by 0 should be 0x9E.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, x9F_8> :: value == x9F_8,
		 "Rotr of 0x9F by 0 should be 0x9F.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xA0_8> :: value == xA0_8,
		 "Rotr of 0xA0 by 0 should be 0xA0.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xA1_8> :: value == xA1_8,
		 "Rotr of 0xA1 by 0 should be 0xA1.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xA2_8> :: value == xA2_8,
		 "Rotr of 0xA2 by 0 should be 0xA2.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xA3_8> :: value == xA3_8,
		 "Rotr of 0xA3 by 0 should be 0xA3.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xA4_8> :: value == xA4_8,
		 "Rotr of 0xA4 by 0 should be 0xA4.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xA5_8> :: value == xA5_8,
		 "Rotr of 0xA5 by 0 should be 0xA5.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xA6_8> :: value == xA6_8,
		 "Rotr of 0xA6 by 0 should be 0xA6.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xA7_8> :: value == xA7_8,
		 "Rotr of 0xA7 by 0 should be 0xA7.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xA8_8> :: value == xA8_8,
		 "Rotr of 0xA8 by 0 should be 0xA8.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xA9_8> :: value == xA9_8,
		 "Rotr of 0xA9 by 0 should be 0xA9.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xAA_8> :: value == xAA_8,
		 "Rotr of 0xAA by 0 should be 0xAA.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xAB_8> :: value == xAB_8,
		 "Rotr of 0xAB by 0 should be 0xAB.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xAC_8> :: value == xAC_8,
		 "Rotr of 0xAC by 0 should be 0xAC.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xAD_8> :: value == xAD_8,
		 "Rotr of 0xAD by 0 should be 0xAD.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xAE_8> :: value == xAE_8,
		 "Rotr of 0xAE by 0 should be 0xAE.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xAF_8> :: value == xAF_8,
		 "Rotr of 0xAF by 0 should be 0xAF.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xB0_8> :: value == xB0_8,
		 "Rotr of 0xB0 by 0 should be 0xB0.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xB1_8> :: value == xB1_8,
		 "Rotr of 0xB1 by 0 should be 0xB1.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xB2_8> :: value == xB2_8,
		 "Rotr of 0xB2 by 0 should be 0xB2.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xB3_8> :: value == xB3_8,
		 "Rotr of 0xB3 by 0 should be 0xB3.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xB4_8> :: value == xB4_8,
		 "Rotr of 0xB4 by 0 should be 0xB4.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xB5_8> :: value == xB5_8,
		 "Rotr of 0xB5 by 0 should be 0xB5.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xB6_8> :: value == xB6_8,
		 "Rotr of 0xB6 by 0 should be 0xB6.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xB7_8> :: value == xB7_8,
		 "Rotr of 0xB7 by 0 should be 0xB7.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xB8_8> :: value == xB8_8,
		 "Rotr of 0xB8 by 0 should be 0xB8.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xB9_8> :: value == xB9_8,
		 "Rotr of 0xB9 by 0 should be 0xB9.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xBA_8> :: value == xBA_8,
		 "Rotr of 0xBA by 0 should be 0xBA.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xBB_8> :: value == xBB_8,
		 "Rotr of 0xBB by 0 should be 0xBB.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xBC_8> :: value == xBC_8,
		 "Rotr of 0xBC by 0 should be 0xBC.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xBD_8> :: value == xBD_8,
		 "Rotr of 0xBD by 0 should be 0xBD.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xBE_8> :: value == xBE_8,
		 "Rotr of 0xBE by 0 should be 0xBE.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xBF_8> :: value == xBF_8,
		 "Rotr of 0xBF by 0 should be 0xBF.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xC0_8> :: value == xC0_8,
		 "Rotr of 0xC0 by 0 should be 0xC0.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xC1_8> :: value == xC1_8,
		 "Rotr of 0xC1 by 0 should be 0xC1.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xC2_8> :: value == xC2_8,
		 "Rotr of 0xC2 by 0 should be 0xC2.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xC3_8> :: value == xC3_8,
		 "Rotr of 0xC3 by 0 should be 0xC3.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xC4_8> :: value == xC4_8,
		 "Rotr of 0xC4 by 0 should be 0xC4.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xC5_8> :: value == xC5_8,
		 "Rotr of 0xC5 by 0 should be 0xC5.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xC6_8> :: value == xC6_8,
		 "Rotr of 0xC6 by 0 should be 0xC6.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xC7_8> :: value == xC7_8,
		 "Rotr of 0xC7 by 0 should be 0xC7.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xC8_8> :: value == xC8_8,
		 "Rotr of 0xC8 by 0 should be 0xC8.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xC9_8> :: value == xC9_8,
		 "Rotr of 0xC9 by 0 should be 0xC9.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xCA_8> :: value == xCA_8,
		 "Rotr of 0xCA by 0 should be 0xCA.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xCB_8> :: value == xCB_8,
		 "Rotr of 0xCB by 0 should be 0xCB.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xCC_8> :: value == xCC_8,
		 "Rotr of 0xCC by 0 should be 0xCC.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xCD_8> :: value == xCD_8,
		 "Rotr of 0xCD by 0 should be 0xCD.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xCE_8> :: value == xCE_8,
		 "Rotr of 0xCE by 0 should be 0xCE.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xCF_8> :: value == xCF_8,
		 "Rotr of 0xCF by 0 should be 0xCF.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xD0_8> :: value == xD0_8,
		 "Rotr of 0xD0 by 0 should be 0xD0.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xD1_8> :: value == xD1_8,
		 "Rotr of 0xD1 by 0 should be 0xD1.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xD2_8> :: value == xD2_8,
		 "Rotr of 0xD2 by 0 should be 0xD2.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xD3_8> :: value == xD3_8,
		 "Rotr of 0xD3 by 0 should be 0xD3.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xD4_8> :: value == xD4_8,
		 "Rotr of 0xD4 by 0 should be 0xD4.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xD5_8> :: value == xD5_8,
		 "Rotr of 0xD5 by 0 should be 0xD5.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xD6_8> :: value == xD6_8,
		 "Rotr of 0xD6 by 0 should be 0xD6.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xD7_8> :: value == xD7_8,
		 "Rotr of 0xD7 by 0 should be 0xD7.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xD8_8> :: value == xD8_8,
		 "Rotr of 0xD8 by 0 should be 0xD8.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xD9_8> :: value == xD9_8,
		 "Rotr of 0xD9 by 0 should be 0xD9.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xDA_8> :: value == xDA_8,
		 "Rotr of 0xDA by 0 should be 0xDA.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xDB_8> :: value == xDB_8,
		 "Rotr of 0xDB by 0 should be 0xDB.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xDC_8> :: value == xDC_8,
		 "Rotr of 0xDC by 0 should be 0xDC.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xDD_8> :: value == xDD_8,
		 "Rotr of 0xDD by 0 should be 0xDD.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xDE_8> :: value == xDE_8,
		 "Rotr of 0xDE by 0 should be 0xDE.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xDF_8> :: value == xDF_8,
		 "Rotr of 0xDF by 0 should be 0xDF.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xE0_8> :: value == xE0_8,
		 "Rotr of 0xE0 by 0 should be 0xE0.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xE1_8> :: value == xE1_8,
		 "Rotr of 0xE1 by 0 should be 0xE1.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xE2_8> :: value == xE2_8,
		 "Rotr of 0xE2 by 0 should be 0xE2.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xE3_8> :: value == xE3_8,
		 "Rotr of 0xE3 by 0 should be 0xE3.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xE4_8> :: value == xE4_8,
		 "Rotr of 0xE4 by 0 should be 0xE4.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xE5_8> :: value == xE5_8,
		 "Rotr of 0xE5 by 0 should be 0xE5.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xE6_8> :: value == xE6_8,
		 "Rotr of 0xE6 by 0 should be 0xE6.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xE7_8> :: value == xE7_8,
		 "Rotr of 0xE7 by 0 should be 0xE7.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xE8_8> :: value == xE8_8,
		 "Rotr of 0xE8 by 0 should be 0xE8.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xE9_8> :: value == xE9_8,
		 "Rotr of 0xE9 by 0 should be 0xE9.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xEA_8> :: value == xEA_8,
		 "Rotr of 0xEA by 0 should be 0xEA.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xEB_8> :: value == xEB_8,
		 "Rotr of 0xEB by 0 should be 0xEB.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xEC_8> :: value == xEC_8,
		 "Rotr of 0xEC by 0 should be 0xEC.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xED_8> :: value == xED_8,
		 "Rotr of 0xED by 0 should be 0xED.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xEE_8> :: value == xEE_8,
		 "Rotr of 0xEE by 0 should be 0xEE.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xEF_8> :: value == xEF_8,
		 "Rotr of 0xEF by 0 should be 0xEF.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xF0_8> :: value == xF0_8,
		 "Rotr of 0xF0 by 0 should be 0xF0.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xF1_8> :: value == xF1_8,
		 "Rotr of 0xF1 by 0 should be 0xF1.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xF2_8> :: value == xF2_8,
		 "Rotr of 0xF2 by 0 should be 0xF2.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xF3_8> :: value == xF3_8,
		 "Rotr of 0xF3 by 0 should be 0xF3.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xF4_8> :: value == xF4_8,
		 "Rotr of 0xF4 by 0 should be 0xF4.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xF5_8> :: value == xF5_8,
		 "Rotr of 0xF5 by 0 should be 0xF5.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xF6_8> :: value == xF6_8,
		 "Rotr of 0xF6 by 0 should be 0xF6.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xF7_8> :: value == xF7_8,
		 "Rotr of 0xF7 by 0 should be 0xF7.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xF8_8> :: value == xF8_8,
		 "Rotr of 0xF8 by 0 should be 0xF8.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xF9_8> :: value == xF9_8,
		 "Rotr of 0xF9 by 0 should be 0xF9.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xFA_8> :: value == xFA_8,
		 "Rotr of 0xFA by 0 should be 0xFA.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xFB_8> :: value == xFB_8,
		 "Rotr of 0xFB by 0 should be 0xFB.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xFC_8> :: value == xFC_8,
		 "Rotr of 0xFC by 0 should be 0xFC.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xFD_8> :: value == xFD_8,
		 "Rotr of 0xFD by 0 should be 0xFD.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xFE_8> :: value == xFE_8,
		 "Rotr of 0xFE by 0 should be 0xFE.");
 static_assert(crap :: rotrValue <0u, std :: uint8_t, xFF_8> :: value == xFF_8,
		 "Rotr of 0xFF by 0 should be 0xFF.");

 //shift by 1
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x00_8> :: value == x00_8,
		 "Rotr of 0x00 by 1 should be 0x00.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x01_8> :: value == x80_8,
		 "Rotr of 0x01 by 1 should be 0x80.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x02_8> :: value == x01_8,
		 "Rotr of 0x02 by 1 should be 0x01.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x03_8> :: value == x81_8,
		 "Rotr of 0x03 by 1 should be 0x81.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x04_8> :: value == x02_8,
		 "Rotr of 0x04 by 1 should be 0x02.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x05_8> :: value == x82_8,
		 "Rotr of 0x05 by 1 should be 0x82.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x06_8> :: value == x03_8,
		 "Rotr of 0x06 by 1 should be 0x03.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x07_8> :: value == x83_8,
		 "Rotr of 0x07 by 1 should be 0x83.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x08_8> :: value == x04_8,
		 "Rotr of 0x08 by 1 should be 0x04.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x09_8> :: value == x84_8,
		 "Rotr of 0x09 by 1 should be 0x84.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x0A_8> :: value == x05_8,
		 "Rotr of 0x0A by 1 should be 0x05.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x0B_8> :: value == x85_8,
		 "Rotr of 0x0B by 1 should be 0x85.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x0C_8> :: value == x06_8,
		 "Rotr of 0x0C by 1 should be 0x06.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x0D_8> :: value == x86_8,
		 "Rotr of 0x0D by 1 should be 0x86.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x0E_8> :: value == x07_8,
		 "Rotr of 0x0E by 1 should be 0x07.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x0F_8> :: value == x87_8,
		 "Rotr of 0x0F by 1 should be 0x87.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x10_8> :: value == x08_8,
		 "Rotr of 0x10 by 1 should be 0x08.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x11_8> :: value == x88_8,
		 "Rotr of 0x11 by 1 should be 0x88.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x12_8> :: value == x09_8,
		 "Rotr of 0x12 by 1 should be 0x09.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x13_8> :: value == x89_8,
		 "Rotr of 0x13 by 1 should be 0x89.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x14_8> :: value == x0A_8,
		 "Rotr of 0x14 by 1 should be 0x0A.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x15_8> :: value == x8A_8,
		 "Rotr of 0x15 by 1 should be 0x8A.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x16_8> :: value == x0B_8,
		 "Rotr of 0x16 by 1 should be 0x0B.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x17_8> :: value == x8B_8,
		 "Rotr of 0x17 by 1 should be 0x8B.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x18_8> :: value == x0C_8,
		 "Rotr of 0x18 by 1 should be 0x0C.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x19_8> :: value == x8C_8,
		 "Rotr of 0x19 by 1 should be 0x8C.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x1A_8> :: value == x0D_8,
		 "Rotr of 0x1A by 1 should be 0x0D.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x1B_8> :: value == x8D_8,
		 "Rotr of 0x1B by 1 should be 0x8D.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x1C_8> :: value == x0E_8,
		 "Rotr of 0x1C by 1 should be 0x0E.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x1D_8> :: value == x8E_8,
		 "Rotr of 0x1D by 1 should be 0x8E.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x1E_8> :: value == x0F_8,
		 "Rotr of 0x1E by 1 should be 0x0F.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x1F_8> :: value == x8F_8,
		 "Rotr of 0x1F by 1 should be 0x8F.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x20_8> :: value == x10_8,
		 "Rotr of 0x20 by 1 should be 0x10.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x21_8> :: value == x90_8,
		 "Rotr of 0x21 by 1 should be 0x90.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x22_8> :: value == x11_8,
		 "Rotr of 0x22 by 1 should be 0x11.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x23_8> :: value == x91_8,
		 "Rotr of 0x23 by 1 should be 0x91.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x24_8> :: value == x12_8,
		 "Rotr of 0x24 by 1 should be 0x12.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x25_8> :: value == x92_8,
		 "Rotr of 0x25 by 1 should be 0x92.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x26_8> :: value == x13_8,
		 "Rotr of 0x26 by 1 should be 0x13.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x27_8> :: value == x93_8,
		 "Rotr of 0x27 by 1 should be 0x93.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x28_8> :: value == x14_8,
		 "Rotr of 0x28 by 1 should be 0x14.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x29_8> :: value == x94_8,
		 "Rotr of 0x29 by 1 should be 0x94.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x2A_8> :: value == x15_8,
		 "Rotr of 0x2A by 1 should be 0x15.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x2B_8> :: value == x95_8,
		 "Rotr of 0x2B by 1 should be 0x95.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x2C_8> :: value == x16_8,
		 "Rotr of 0x2C by 1 should be 0x16.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x2D_8> :: value == x96_8,
		 "Rotr of 0x2D by 1 should be 0x96.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x2E_8> :: value == x17_8,
		 "Rotr of 0x2E by 1 should be 0x17.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x2F_8> :: value == x97_8,
		 "Rotr of 0x2F by 1 should be 0x97.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x30_8> :: value == x18_8,
		 "Rotr of 0x30 by 1 should be 0x18.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x31_8> :: value == x98_8,
		 "Rotr of 0x31 by 1 should be 0x98.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x32_8> :: value == x19_8,
		 "Rotr of 0x32 by 1 should be 0x19.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x33_8> :: value == x99_8,
		 "Rotr of 0x33 by 1 should be 0x99.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x34_8> :: value == x1A_8,
		 "Rotr of 0x34 by 1 should be 0x1A.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x35_8> :: value == x9A_8,
		 "Rotr of 0x35 by 1 should be 0x9A.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x36_8> :: value == x1B_8,
		 "Rotr of 0x36 by 1 should be 0x1B.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x37_8> :: value == x9B_8,
		 "Rotr of 0x37 by 1 should be 0x9B.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x38_8> :: value == x1C_8,
		 "Rotr of 0x38 by 1 should be 0x1C.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x39_8> :: value == x9C_8,
		 "Rotr of 0x39 by 1 should be 0x9C.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x3A_8> :: value == x1D_8,
		 "Rotr of 0x3A by 1 should be 0x1D.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x3B_8> :: value == x9D_8,
		 "Rotr of 0x3B by 1 should be 0x9D.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x3C_8> :: value == x1E_8,
		 "Rotr of 0x3C by 1 should be 0x1E.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x3D_8> :: value == x9E_8,
		 "Rotr of 0x3D by 1 should be 0x9E.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x3E_8> :: value == x1F_8,
		 "Rotr of 0x3E by 1 should be 0x1F.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x3F_8> :: value == x9F_8,
		 "Rotr of 0x3F by 1 should be 0x9F.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x40_8> :: value == x20_8,
		 "Rotr of 0x40 by 1 should be 0x20.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x41_8> :: value == xA0_8,
		 "Rotr of 0x41 by 1 should be 0xA0.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x42_8> :: value == x21_8,
		 "Rotr of 0x42 by 1 should be 0x21.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x43_8> :: value == xA1_8,
		 "Rotr of 0x43 by 1 should be 0xA1.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x44_8> :: value == x22_8,
		 "Rotr of 0x44 by 1 should be 0x22.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x45_8> :: value == xA2_8,
		 "Rotr of 0x45 by 1 should be 0xA2.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x46_8> :: value == x23_8,
		 "Rotr of 0x46 by 1 should be 0x23.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x47_8> :: value == xA3_8,
		 "Rotr of 0x47 by 1 should be 0xA3.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x48_8> :: value == x24_8,
		 "Rotr of 0x48 by 1 should be 0x24.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x49_8> :: value == xA4_8,
		 "Rotr of 0x49 by 1 should be 0xA4.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x4A_8> :: value == x25_8,
		 "Rotr of 0x4A by 1 should be 0x25.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x4B_8> :: value == xA5_8,
		 "Rotr of 0x4B by 1 should be 0xA5.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x4C_8> :: value == x26_8,
		 "Rotr of 0x4C by 1 should be 0x26.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x4D_8> :: value == xA6_8,
		 "Rotr of 0x4D by 1 should be 0xA6.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x4E_8> :: value == x27_8,
		 "Rotr of 0x4E by 1 should be 0x27.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x4F_8> :: value == xA7_8,
		 "Rotr of 0x4F by 1 should be 0xA7.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x50_8> :: value == x28_8,
		 "Rotr of 0x50 by 1 should be 0x28.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x51_8> :: value == xA8_8,
		 "Rotr of 0x51 by 1 should be 0xA8.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x52_8> :: value == x29_8,
		 "Rotr of 0x52 by 1 should be 0x29.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x53_8> :: value == xA9_8,
		 "Rotr of 0x53 by 1 should be 0xA9.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x54_8> :: value == x2A_8,
		 "Rotr of 0x54 by 1 should be 0x2A.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x55_8> :: value == xAA_8,
		 "Rotr of 0x55 by 1 should be 0xAA.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x56_8> :: value == x2B_8,
		 "Rotr of 0x56 by 1 should be 0x2B.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x57_8> :: value == xAB_8,
		 "Rotr of 0x57 by 1 should be 0xAB.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x58_8> :: value == x2C_8,
		 "Rotr of 0x58 by 1 should be 0x2C.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x59_8> :: value == xAC_8,
		 "Rotr of 0x59 by 1 should be 0xAC.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x5A_8> :: value == x2D_8,
		 "Rotr of 0x5A by 1 should be 0x2D.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x5B_8> :: value == xAD_8,
		 "Rotr of 0x5B by 1 should be 0xAD.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x5C_8> :: value == x2E_8,
		 "Rotr of 0x5C by 1 should be 0x2E.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x5D_8> :: value == xAE_8,
		 "Rotr of 0x5D by 1 should be 0xAE.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x5E_8> :: value == x2F_8,
		 "Rotr of 0x5E by 1 should be 0x2F.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x5F_8> :: value == xAF_8,
		 "Rotr of 0x5F by 1 should be 0xAF.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x60_8> :: value == x30_8,
		 "Rotr of 0x60 by 1 should be 0x30.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x61_8> :: value == xB0_8,
		 "Rotr of 0x61 by 1 should be 0xB0.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x62_8> :: value == x31_8,
		 "Rotr of 0x62 by 1 should be 0x31.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x63_8> :: value == xB1_8,
		 "Rotr of 0x63 by 1 should be 0xB1.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x64_8> :: value == x32_8,
		 "Rotr of 0x64 by 1 should be 0x32.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x65_8> :: value == xB2_8,
		 "Rotr of 0x65 by 1 should be 0xB2.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x66_8> :: value == x33_8,
		 "Rotr of 0x66 by 1 should be 0x33.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x67_8> :: value == xB3_8,
		 "Rotr of 0x67 by 1 should be 0xB3.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x68_8> :: value == x34_8,
		 "Rotr of 0x68 by 1 should be 0x34.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x69_8> :: value == xB4_8,
		 "Rotr of 0x69 by 1 should be 0xB4.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x6A_8> :: value == x35_8,
		 "Rotr of 0x6A by 1 should be 0x35.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x6B_8> :: value == xB5_8,
		 "Rotr of 0x6B by 1 should be 0xB5.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x6C_8> :: value == x36_8,
		 "Rotr of 0x6C by 1 should be 0x36.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x6D_8> :: value == xB6_8,
		 "Rotr of 0x6D by 1 should be 0xB6.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x6E_8> :: value == x37_8,
		 "Rotr of 0x6E by 1 should be 0x37.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x6F_8> :: value == xB7_8,
		 "Rotr of 0x6F by 1 should be 0xB7.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x70_8> :: value == x38_8,
		 "Rotr of 0x70 by 1 should be 0x38.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x71_8> :: value == xB8_8,
		 "Rotr of 0x71 by 1 should be 0xB8.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x72_8> :: value == x39_8,
		 "Rotr of 0x72 by 1 should be 0x39.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x73_8> :: value == xB9_8,
		 "Rotr of 0x73 by 1 should be 0xB9.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x74_8> :: value == x3A_8,
		 "Rotr of 0x74 by 1 should be 0x3A.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x75_8> :: value == xBA_8,
		 "Rotr of 0x75 by 1 should be 0xBA.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x76_8> :: value == x3B_8,
		 "Rotr of 0x76 by 1 should be 0x3B.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x77_8> :: value == xBB_8,
		 "Rotr of 0x77 by 1 should be 0xBB.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x78_8> :: value == x3C_8,
		 "Rotr of 0x78 by 1 should be 0x3C.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x79_8> :: value == xBC_8,
		 "Rotr of 0x79 by 1 should be 0xBC.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x7A_8> :: value == x3D_8,
		 "Rotr of 0x7A by 1 should be 0x3D.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x7B_8> :: value == xBD_8,
		 "Rotr of 0x7B by 1 should be 0xBD.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x7C_8> :: value == x3E_8,
		 "Rotr of 0x7C by 1 should be 0x3E.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x7D_8> :: value == xBE_8,
		 "Rotr of 0x7D by 1 should be 0xBE.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x7E_8> :: value == x3F_8,
		 "Rotr of 0x7E by 1 should be 0x3F.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x7F_8> :: value == xBF_8,
		 "Rotr of 0x7F by 1 should be 0xBF.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x80_8> :: value == x40_8,
		 "Rotr of 0x80 by 1 should be 0x40.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x81_8> :: value == xC0_8,
		 "Rotr of 0x81 by 1 should be 0xC0.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x82_8> :: value == x41_8,
		 "Rotr of 0x82 by 1 should be 0x41.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x83_8> :: value == xC1_8,
		 "Rotr of 0x83 by 1 should be 0xC1.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x84_8> :: value == x42_8,
		 "Rotr of 0x84 by 1 should be 0x42.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x85_8> :: value == xC2_8,
		 "Rotr of 0x85 by 1 should be 0xC2.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x86_8> :: value == x43_8,
		 "Rotr of 0x86 by 1 should be 0x43.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x87_8> :: value == xC3_8,
		 "Rotr of 0x87 by 1 should be 0xC3.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x88_8> :: value == x44_8,
		 "Rotr of 0x88 by 1 should be 0x44.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x89_8> :: value == xC4_8,
		 "Rotr of 0x89 by 1 should be 0xC4.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x8A_8> :: value == x45_8,
		 "Rotr of 0x8A by 1 should be 0x45.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x8B_8> :: value == xC5_8,
		 "Rotr of 0x8B by 1 should be 0xC5.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x8C_8> :: value == x46_8,
		 "Rotr of 0x8C by 1 should be 0x46.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x8D_8> :: value == xC6_8,
		 "Rotr of 0x8D by 1 should be 0xC6.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x8E_8> :: value == x47_8,
		 "Rotr of 0x8E by 1 should be 0x47.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x8F_8> :: value == xC7_8,
		 "Rotr of 0x8F by 1 should be 0xC7.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x90_8> :: value == x48_8,
		 "Rotr of 0x90 by 1 should be 0x48.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x91_8> :: value == xC8_8,
		 "Rotr of 0x91 by 1 should be 0xC8.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x92_8> :: value == x49_8,
		 "Rotr of 0x92 by 1 should be 0x49.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x93_8> :: value == xC9_8,
		 "Rotr of 0x93 by 1 should be 0xC9.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x94_8> :: value == x4A_8,
		 "Rotr of 0x94 by 1 should be 0x4A.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x95_8> :: value == xCA_8,
		 "Rotr of 0x95 by 1 should be 0xCA.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x96_8> :: value == x4B_8,
		 "Rotr of 0x96 by 1 should be 0x4B.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x97_8> :: value == xCB_8,
		 "Rotr of 0x97 by 1 should be 0xCB.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x98_8> :: value == x4C_8,
		 "Rotr of 0x98 by 1 should be 0x4C.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x99_8> :: value == xCC_8,
		 "Rotr of 0x99 by 1 should be 0xCC.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x9A_8> :: value == x4D_8,
		 "Rotr of 0x9A by 1 should be 0x4D.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x9B_8> :: value == xCD_8,
		 "Rotr of 0x9B by 1 should be 0xCD.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x9C_8> :: value == x4E_8,
		 "Rotr of 0x9C by 1 should be 0x4E.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x9D_8> :: value == xCE_8,
		 "Rotr of 0x9D by 1 should be 0xCE.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x9E_8> :: value == x4F_8,
		 "Rotr of 0x9E by 1 should be 0x4F.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, x9F_8> :: value == xCF_8,
		 "Rotr of 0x9F by 1 should be 0xCF.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xA0_8> :: value == x50_8,
		 "Rotr of 0xA0 by 1 should be 0x50.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xA1_8> :: value == xD0_8,
		 "Rotr of 0xA1 by 1 should be 0xD0.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xA2_8> :: value == x51_8,
		 "Rotr of 0xA2 by 1 should be 0x51.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xA3_8> :: value == xD1_8,
		 "Rotr of 0xA3 by 1 should be 0xD1.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xA4_8> :: value == x52_8,
		 "Rotr of 0xA4 by 1 should be 0x52.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xA5_8> :: value == xD2_8,
		 "Rotr of 0xA5 by 1 should be 0xD2.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xA6_8> :: value == x53_8,
		 "Rotr of 0xA6 by 1 should be 0x53.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xA7_8> :: value == xD3_8,
		 "Rotr of 0xA7 by 1 should be 0xD3.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xA8_8> :: value == x54_8,
		 "Rotr of 0xA8 by 1 should be 0x54.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xA9_8> :: value == xD4_8,
		 "Rotr of 0xA9 by 1 should be 0xD4.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xAA_8> :: value == x55_8,
		 "Rotr of 0xAA by 1 should be 0x55.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xAB_8> :: value == xD5_8,
		 "Rotr of 0xAB by 1 should be 0xD5.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xAC_8> :: value == x56_8,
		 "Rotr of 0xAC by 1 should be 0x56.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xAD_8> :: value == xD6_8,
		 "Rotr of 0xAD by 1 should be 0xD6.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xAE_8> :: value == x57_8,
		 "Rotr of 0xAE by 1 should be 0x57.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xAF_8> :: value == xD7_8,
		 "Rotr of 0xAF by 1 should be 0xD7.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xB0_8> :: value == x58_8,
		 "Rotr of 0xB0 by 1 should be 0x58.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xB1_8> :: value == xD8_8,
		 "Rotr of 0xB1 by 1 should be 0xD8.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xB2_8> :: value == x59_8,
		 "Rotr of 0xB2 by 1 should be 0x59.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xB3_8> :: value == xD9_8,
		 "Rotr of 0xB3 by 1 should be 0xD9.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xB4_8> :: value == x5A_8,
		 "Rotr of 0xB4 by 1 should be 0x5A.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xB5_8> :: value == xDA_8,
		 "Rotr of 0xB5 by 1 should be 0xDA.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xB6_8> :: value == x5B_8,
		 "Rotr of 0xB6 by 1 should be 0x5B.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xB7_8> :: value == xDB_8,
		 "Rotr of 0xB7 by 1 should be 0xDB.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xB8_8> :: value == x5C_8,
		 "Rotr of 0xB8 by 1 should be 0x5C.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xB9_8> :: value == xDC_8,
		 "Rotr of 0xB9 by 1 should be 0xDC.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xBA_8> :: value == x5D_8,
		 "Rotr of 0xBA by 1 should be 0x5D.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xBB_8> :: value == xDD_8,
		 "Rotr of 0xBB by 1 should be 0xDD.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xBC_8> :: value == x5E_8,
		 "Rotr of 0xBC by 1 should be 0x5E.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xBD_8> :: value == xDE_8,
		 "Rotr of 0xBD by 1 should be 0xDE.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xBE_8> :: value == x5F_8,
		 "Rotr of 0xBE by 1 should be 0x5F.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xBF_8> :: value == xDF_8,
		 "Rotr of 0xBF by 1 should be 0xDF.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xC0_8> :: value == x60_8,
		 "Rotr of 0xC0 by 1 should be 0x60.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xC1_8> :: value == xE0_8,
		 "Rotr of 0xC1 by 1 should be 0xE0.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xC2_8> :: value == x61_8,
		 "Rotr of 0xC2 by 1 should be 0x61.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xC3_8> :: value == xE1_8,
		 "Rotr of 0xC3 by 1 should be 0xE1.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xC4_8> :: value == x62_8,
		 "Rotr of 0xC4 by 1 should be 0x62.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xC5_8> :: value == xE2_8,
		 "Rotr of 0xC5 by 1 should be 0xE2.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xC6_8> :: value == x63_8,
		 "Rotr of 0xC6 by 1 should be 0x63.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xC7_8> :: value == xE3_8,
		 "Rotr of 0xC7 by 1 should be 0xE3.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xC8_8> :: value == x64_8,
		 "Rotr of 0xC8 by 1 should be 0x64.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xC9_8> :: value == xE4_8,
		 "Rotr of 0xC9 by 1 should be 0xE4.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xCA_8> :: value == x65_8,
		 "Rotr of 0xCA by 1 should be 0x65.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xCB_8> :: value == xE5_8,
		 "Rotr of 0xCB by 1 should be 0xE5.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xCC_8> :: value == x66_8,
		 "Rotr of 0xCC by 1 should be 0x66.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xCD_8> :: value == xE6_8,
		 "Rotr of 0xCD by 1 should be 0xE6.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xCE_8> :: value == x67_8,
		 "Rotr of 0xCE by 1 should be 0x67.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xCF_8> :: value == xE7_8,
		 "Rotr of 0xCF by 1 should be 0xE7.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xD0_8> :: value == x68_8,
		 "Rotr of 0xD0 by 1 should be 0x68.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xD1_8> :: value == xE8_8,
		 "Rotr of 0xD1 by 1 should be 0xE8.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xD2_8> :: value == x69_8,
		 "Rotr of 0xD2 by 1 should be 0x69.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xD3_8> :: value == xE9_8,
		 "Rotr of 0xD3 by 1 should be 0xE9.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xD4_8> :: value == x6A_8,
		 "Rotr of 0xD4 by 1 should be 0x6A.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xD5_8> :: value == xEA_8,
		 "Rotr of 0xD5 by 1 should be 0xEA.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xD6_8> :: value == x6B_8,
		 "Rotr of 0xD6 by 1 should be 0x6B.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xD7_8> :: value == xEB_8,
		 "Rotr of 0xD7 by 1 should be 0xEB.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xD8_8> :: value == x6C_8,
		 "Rotr of 0xD8 by 1 should be 0x6C.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xD9_8> :: value == xEC_8,
		 "Rotr of 0xD9 by 1 should be 0xEC.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xDA_8> :: value == x6D_8,
		 "Rotr of 0xDA by 1 should be 0x6D.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xDB_8> :: value == xED_8,
		 "Rotr of 0xDB by 1 should be 0xED.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xDC_8> :: value == x6E_8,
		 "Rotr of 0xDC by 1 should be 0x6E.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xDD_8> :: value == xEE_8,
		 "Rotr of 0xDD by 1 should be 0xEE.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xDE_8> :: value == x6F_8,
		 "Rotr of 0xDE by 1 should be 0x6F.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xDF_8> :: value == xEF_8,
		 "Rotr of 0xDF by 1 should be 0xEF.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xE0_8> :: value == x70_8,
		 "Rotr of 0xE0 by 1 should be 0x70.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xE1_8> :: value == xF0_8,
		 "Rotr of 0xE1 by 1 should be 0xF0.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xE2_8> :: value == x71_8,
		 "Rotr of 0xE2 by 1 should be 0x71.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xE3_8> :: value == xF1_8,
		 "Rotr of 0xE3 by 1 should be 0xF1.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xE4_8> :: value == x72_8,
		 "Rotr of 0xE4 by 1 should be 0x72.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xE5_8> :: value == xF2_8,
		 "Rotr of 0xE5 by 1 should be 0xF2.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xE6_8> :: value == x73_8,
		 "Rotr of 0xE6 by 1 should be 0x73.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xE7_8> :: value == xF3_8,
		 "Rotr of 0xE7 by 1 should be 0xF3.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xE8_8> :: value == x74_8,
		 "Rotr of 0xE8 by 1 should be 0x74.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xE9_8> :: value == xF4_8,
		 "Rotr of 0xE9 by 1 should be 0xF4.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xEA_8> :: value == x75_8,
		 "Rotr of 0xEA by 1 should be 0x75.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xEB_8> :: value == xF5_8,
		 "Rotr of 0xEB by 1 should be 0xF5.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xEC_8> :: value == x76_8,
		 "Rotr of 0xEC by 1 should be 0x76.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xED_8> :: value == xF6_8,
		 "Rotr of 0xED by 1 should be 0xF6.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xEE_8> :: value == x77_8,
		 "Rotr of 0xEE by 1 should be 0x77.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xEF_8> :: value == xF7_8,
		 "Rotr of 0xEF by 1 should be 0F7.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xF0_8> :: value == x78_8,
		 "Rotr of 0xF0 by 1 should be 0x78.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xF1_8> :: value == xF8_8,
		 "Rotr of 0xF1 by 1 should be 0xF8.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xF2_8> :: value == x79_8,
		 "Rotr of 0xF2 by 1 should be 0x79.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xF3_8> :: value == xF9_8,
		 "Rotr of 0xF3 by 1 should be 0xF9.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xF4_8> :: value == x7A_8,
		 "Rotr of 0xF4 by 1 should be 0x7A.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xF5_8> :: value == xFA_8,
		 "Rotr of 0xF5 by 1 should be 0xFA.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xF6_8> :: value == x7B_8,
		 "Rotr of 0xF6 by 1 should be 0x7B.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xF7_8> :: value == xFB_8,
		 "Rotr of 0xF7 by 1 should be 0xFB.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xF8_8> :: value == x7C_8,
		 "Rotr of 0xF8 by 1 should be 0x7C.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xF9_8> :: value == xFC_8,
		 "Rotr of 0xF9 by 1 should be 0xFC.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xFA_8> :: value == x7D_8,
		 "Rotr of 0xFA by 1 should be 0x7D.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xFB_8> :: value == xFD_8,
		 "Rotr of 0xFB by 1 should be 0xFD.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xFC_8> :: value == x7E_8,
		 "Rotr of 0xFC by 1 should be 0x7E.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xFD_8> :: value == xFE_8,
		 "Rotr of 0xFD by 1 should be 0xFE.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xFE_8> :: value == x7F_8,
		 "Rotr of 0xFE by 1 should be 0x7F.");
 static_assert(crap :: rotrValue <1u, std :: uint8_t, xFF_8> :: value == xFF_8,
		 "Rotr of 0xFF by 1 should be 0xFF.");

 //shift by 2
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x00_8> :: value == x00_8,
		 "Rotr of 0x00 by 2 should be 0x00.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x01_8> :: value == x40_8,
		 "Rotr of 0x01 by 2 should be 0x40.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x02_8> :: value == x80_8,
		 "Rotr of 0x02 by 2 should be 0x80.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x03_8> :: value == xC0_8,
		 "Rotr of 0x03 by 2 should be 0xC0.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x04_8> :: value == x01_8,
		 "Rotr of 0x04 by 2 should be 0x01.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x05_8> :: value == x41_8,
		 "Rotr of 0x05 by 2 should be 0x41.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x06_8> :: value == x81_8,
		 "Rotr of 0x06 by 2 should be 0x81.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x07_8> :: value == xC1_8,
		 "Rotr of 0x07 by 2 should be 0xC1.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x08_8> :: value == x02_8,
		 "Rotr of 0x08 by 2 should be 0x02.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x09_8> :: value == x42_8,
		 "Rotr of 0x09 by 2 should be 0x42.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x0A_8> :: value == x82_8,
		 "Rotr of 0x0A by 2 should be 0x82.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x0B_8> :: value == xC2_8,
		 "Rotr of 0x0B by 2 should be 0xC2.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x0C_8> :: value == x03_8,
		 "Rotr of 0x0C by 2 should be 0x03.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x0D_8> :: value == x43_8,
		 "Rotr of 0x0D by 2 should be 0x43.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x0E_8> :: value == x83_8,
		 "Rotr of 0x0E by 2 should be 0x83.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x0F_8> :: value == xC3_8,
		 "Rotr of 0x0F by 2 should be 0xC3.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x10_8> :: value == x04_8,
		 "Rotr of 0x10 by 2 should be 0x04.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x11_8> :: value == x44_8,
		 "Rotr of 0x11 by 2 should be 0x44.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x12_8> :: value == x84_8,
		 "Rotr of 0x12 by 2 should be 0x84.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x13_8> :: value == xC4_8,
		 "Rotr of 0x13 by 2 should be 0xC4.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x14_8> :: value == x05_8,
		 "Rotr of 0x14 by 2 should be 0x05.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x15_8> :: value == x45_8,
		 "Rotr of 0x15 by 2 should be 0x45.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x16_8> :: value == x85_8,
		 "Rotr of 0x16 by 2 should be 0x85.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x17_8> :: value == xC5_8,
		 "Rotr of 0x17 by 2 should be 0xC5.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x18_8> :: value == x06_8,
		 "Rotr of 0x18 by 2 should be 0x06.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x19_8> :: value == x46_8,
		 "Rotr of 0x19 by 2 should be 0x46.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x1A_8> :: value == x86_8,
		 "Rotr of 0x1A by 2 should be 0x86.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x1B_8> :: value == xC6_8,
		 "Rotr of 0x1B by 2 should be 0xC6.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x1C_8> :: value == x07_8,
		 "Rotr of 0x1C by 2 should be 0x07.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x1D_8> :: value == x47_8,
		 "Rotr of 0x1D by 2 should be 0x47.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x1E_8> :: value == x87_8,
		 "Rotr of 0x1E by 2 should be 0x87.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x1F_8> :: value == xC7_8,
		 "Rotr of 0x1F by 2 should be 0xC7.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x20_8> :: value == x08_8,
		 "Rotr of 0x20 by 2 should be 0x08.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x21_8> :: value == x48_8,
		 "Rotr of 0x21 by 2 should be 0x48.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x22_8> :: value == x88_8,
		 "Rotr of 0x22 by 2 should be 0x88.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x23_8> :: value == xC8_8,
		 "Rotr of 0x23 by 2 should be 0xC8.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x24_8> :: value == x09_8,
		 "Rotr of 0x24 by 2 should be 0x09.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x25_8> :: value == x49_8,
		 "Rotr of 0x25 by 2 should be 0x49.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x26_8> :: value == x89_8,
		 "Rotr of 0x26 by 2 should be 0x89.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x27_8> :: value == xC9_8,
		 "Rotr of 0x27 by 2 should be 0xC9.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x28_8> :: value == x0A_8,
		 "Rotr of 0x28 by 2 should be 0x0A.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x29_8> :: value == x4A_8,
		 "Rotr of 0x29 by 2 should be 0x4A.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x2A_8> :: value == x8A_8,
		 "Rotr of 0x2A by 2 should be 0x8A.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x2B_8> :: value == xCA_8,
		 "Rotr of 0x2B by 2 should be 0xCA.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x2C_8> :: value == x0B_8,
		 "Rotr of 0x2C by 2 should be 0x0B.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x2D_8> :: value == x4B_8,
		 "Rotr of 0x2D by 2 should be 0x4B.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x2E_8> :: value == x8B_8,
		 "Rotr of 0x2E by 2 should be 0x8B.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x2F_8> :: value == xCB_8,
		 "Rotr of 0x2F by 2 should be 0xCB.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x30_8> :: value == x0C_8,
		 "Rotr of 0x30 by 2 should be 0x0C.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x31_8> :: value == x4C_8,
		 "Rotr of 0x31 by 2 should be 0x4C.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x32_8> :: value == x8C_8,
		 "Rotr of 0x32 by 2 should be 0x8C.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x33_8> :: value == xCC_8,
		 "Rotr of 0x33 by 2 should be 0xCC.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x34_8> :: value == x0D_8,
		 "Rotr of 0x34 by 2 should be 0x0D.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x35_8> :: value == x4D_8,
		 "Rotr of 0x35 by 2 should be 0x4D.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x36_8> :: value == x8D_8,
		 "Rotr of 0x36 by 2 should be 0x8D.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x37_8> :: value == xCD_8,
		 "Rotr of 0x37 by 2 should be 0xCD.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x38_8> :: value == x0E_8,
		 "Rotr of 0x38 by 2 should be 0x0E.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x39_8> :: value == x4E_8,
		 "Rotr of 0x39 by 2 should be 0x4E.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x3A_8> :: value == x8E_8,
		 "Rotr of 0x3A by 2 should be 0x8E.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x3B_8> :: value == xCE_8,
		 "Rotr of 0x3B by 2 should be 0xCE.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x3C_8> :: value == x0F_8,
		 "Rotr of 0x3C by 2 should be 0x0F.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x3D_8> :: value == x4F_8,
		 "Rotr of 0x3D by 2 should be 0x4F.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x3E_8> :: value == x8F_8,
		 "Rotr of 0x3E by 2 should be 0x8F.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x3F_8> :: value == xCF_8,
		 "Rotr of 0x3F by 2 should be 0xCF.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x40_8> :: value == x10_8,
		 "Rotr of 0x40 by 2 should be 0x10.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x41_8> :: value == x50_8,
		 "Rotr of 0x41 by 2 should be 0x50.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x42_8> :: value == x90_8,
		 "Rotr of 0x42 by 2 should be 0x90.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x43_8> :: value == xD0_8,
		 "Rotr of 0x43 by 2 should be 0xD0.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x44_8> :: value == x11_8,
		 "Rotr of 0x44 by 2 should be 0x22.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x45_8> :: value == x51_8,
		 "Rotr of 0x45 by 2 should be 0x51.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x46_8> :: value == x91_8,
		 "Rotr of 0x46 by 2 should be 0x91.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x47_8> :: value == xD1_8,
		 "Rotr of 0x47 by 2 should be 0xD1.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x48_8> :: value == x12_8,
		 "Rotr of 0x48 by 2 should be 0x12.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x49_8> :: value == x52_8,
		 "Rotr of 0x49 by 2 should be 0x52.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x4A_8> :: value == x92_8,
		 "Rotr of 0x4A by 2 should be 0x25.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x4B_8> :: value == xD2_8,
		 "Rotr of 0x4B by 2 should be 0x92.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x4C_8> :: value == x13_8,
		 "Rotr of 0x4C by 2 should be 0x13.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x4D_8> :: value == x53_8,
		 "Rotr of 0x4D by 2 should be 0x53.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x4E_8> :: value == x93_8,
		 "Rotr of 0x4E by 2 should be 0x93.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x4F_8> :: value == xD3_8,
		 "Rotr of 0x4F by 2 should be 0xD3.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x50_8> :: value == x14_8,
		 "Rotr of 0x50 by 2 should be 0x14.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x51_8> :: value == x54_8,
		 "Rotr of 0x51 by 2 should be 0x54.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x52_8> :: value == x94_8,
		 "Rotr of 0x52 by 2 should be 0x94.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x53_8> :: value == xD4_8,
		 "Rotr of 0x53 by 2 should be 0xD4.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x54_8> :: value == x15_8,
		 "Rotr of 0x54 by 2 should be 0x15.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x55_8> :: value == x55_8,
		 "Rotr of 0x55 by 2 should be 0x55.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x56_8> :: value == x95_8,
		 "Rotr of 0x56 by 2 should be 0x95.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x57_8> :: value == xD5_8,
		 "Rotr of 0x57 by 2 should be 0xD5.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x58_8> :: value == x16_8,
		 "Rotr of 0x58 by 2 should be 0x16.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x59_8> :: value == x56_8,
		 "Rotr of 0x59 by 2 should be 0x56.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x5A_8> :: value == x96_8,
		 "Rotr of 0x5A by 2 should be 0x96.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x5B_8> :: value == xD6_8,
		 "Rotr of 0x5B by 2 should be 0xD6.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x5C_8> :: value == x17_8,
		 "Rotr of 0x5C by 2 should be 0x17.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x5D_8> :: value == x57_8,
		 "Rotr of 0x5D by 2 should be 0x57.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x5E_8> :: value == x97_8,
		 "Rotr of 0x5E by 2 should be 0x97.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x5F_8> :: value == xD7_8,
		 "Rotr of 0x5F by 2 should be 0xD7.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x60_8> :: value == x18_8,
		 "Rotr of 0x60 by 2 should be 0x18.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x61_8> :: value == x58_8,
		 "Rotr of 0x61 by 2 should be 0x58.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x62_8> :: value == x98_8,
		 "Rotr of 0x62 by 2 should be 0x98.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x63_8> :: value == xD8_8,
		 "Rotr of 0x63 by 2 should be 0xD8.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x64_8> :: value == x19_8,
		 "Rotr of 0x64 by 2 should be 0x19.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x65_8> :: value == x59_8,
		 "Rotr of 0x65 by 2 should be 0x59.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x66_8> :: value == x99_8,
		 "Rotr of 0x66 by 2 should be 0x99.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x67_8> :: value == xD9_8,
		 "Rotr of 0x67 by 2 should be 0xD9.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x68_8> :: value == x1A_8,
		 "Rotr of 0x68 by 2 should be 0x1A.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x69_8> :: value == x5A_8,
		 "Rotr of 0x69 by 2 should be 0x5A.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x6A_8> :: value == x9A_8,
		 "Rotr of 0x6A by 2 should be 0x9A.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x6B_8> :: value == xDA_8,
		 "Rotr of 0x6B by 2 should be 0xDA.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x6C_8> :: value == x1B_8,
		 "Rotr of 0x6C by 2 should be 0x1B.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x6D_8> :: value == x5B_8,
		 "Rotr of 0x6D by 2 should be 0x5B.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x6E_8> :: value == x9B_8,
		 "Rotr of 0x6E by 2 should be 0x9B.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x6F_8> :: value == xDB_8,
		 "Rotr of 0x6F by 2 should be 0xDB.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x70_8> :: value == x1C_8,
		 "Rotr of 0x70 by 2 should be 0x1C.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x71_8> :: value == x5C_8,
		 "Rotr of 0x71 by 2 should be 0x5C.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x72_8> :: value == x9C_8,
		 "Rotr of 0x72 by 2 should be 0x9C.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x73_8> :: value == xDC_8,
		 "Rotr of 0x73 by 2 should be 0xDC.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x74_8> :: value == x1D_8,
		 "Rotr of 0x74 by 2 should be 0x1D.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x75_8> :: value == x5D_8,
		 "Rotr of 0x75 by 2 should be 0x5D.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x76_8> :: value == x9D_8,
		 "Rotr of 0x76 by 2 should be 0x9D.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x77_8> :: value == xDD_8,
		 "Rotr of 0x77 by 2 should be 0xDD.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x78_8> :: value == x1E_8,
		 "Rotr of 0x78 by 2 should be 0x1E.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x79_8> :: value == x5E_8,
		 "Rotr of 0x79 by 2 should be 0x5E.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x7A_8> :: value == x9E_8,
		 "Rotr of 0x7A by 2 should be 0x9E.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x7B_8> :: value == xDE_8,
		 "Rotr of 0x7B by 2 should be 0xDE.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x7C_8> :: value == x1F_8,
		 "Rotr of 0x7C by 2 should be 0x1F.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x7D_8> :: value == x5F_8,
		 "Rotr of 0x7D by 2 should be 0x5F.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x7E_8> :: value == x9F_8,
		 "Rotr of 0x7E by 2 should be 0x9F.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x7F_8> :: value == xDF_8,
		 "Rotr of 0x7F by 2 should be 0xDF.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x80_8> :: value == x20_8,
		 "Rotr of 0x80 by 2 should be 0x20.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x81_8> :: value == x60_8,
		 "Rotr of 0x81 by 2 should be 0x60.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x82_8> :: value == xA0_8,
		 "Rotr of 0x82 by 2 should be 0xA0.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x83_8> :: value == xE0_8,
		 "Rotr of 0x83 by 2 should be 0xE0.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x84_8> :: value == x21_8,
		 "Rotr of 0x84 by 2 should be 0x21.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x85_8> :: value == x61_8,
		 "Rotr of 0x85 by 2 should be 0x61.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x86_8> :: value == xA1_8,
		 "Rotr of 0x86 by 2 should be 0xA1.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x87_8> :: value == xE1_8,
		 "Rotr of 0x87 by 2 should be 0xE1.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x88_8> :: value == x22_8,
		 "Rotr of 0x88 by 2 should be 0x22.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x89_8> :: value == x62_8,
		 "Rotr of 0x89 by 2 should be 0x62.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x8A_8> :: value == xA2_8,
		 "Rotr of 0x8A by 2 should be 0xA2.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x8B_8> :: value == xE2_8,
		 "Rotr of 0x8B by 2 should be 0xE2.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x8C_8> :: value == x23_8,
		 "Rotr of 0x8C by 2 should be 0x23.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x8D_8> :: value == x63_8,
		 "Rotr of 0x8D by 2 should be 0x63.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x8E_8> :: value == xA3_8,
		 "Rotr of 0x8E by 2 should be 0xA3.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x8F_8> :: value == xE3_8,
		 "Rotr of 0x8F by 2 should be 0xE3.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x90_8> :: value == x24_8,
		 "Rotr of 0x90 by 2 should be 0x24.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x91_8> :: value == x64_8,
		 "Rotr of 0x91 by 2 should be 0x64.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x92_8> :: value == xA4_8,
		 "Rotr of 0x92 by 2 should be 0xA4.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x93_8> :: value == xE4_8,
		 "Rotr of 0x93 by 2 should be 0xE4.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x94_8> :: value == x25_8,
		 "Rotr of 0x94 by 2 should be 0x25.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x95_8> :: value == x65_8,
		 "Rotr of 0x95 by 2 should be 0x65.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x96_8> :: value == xA5_8,
		 "Rotr of 0x96 by 2 should be 0xA5.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x97_8> :: value == xE5_8,
		 "Rotr of 0x97 by 2 should be 0xE5.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x98_8> :: value == x26_8,
		 "Rotr of 0x98 by 2 should be 0x26.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x99_8> :: value == x66_8,
		 "Rotr of 0x99 by 2 should be 0x66.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x9A_8> :: value == xA6_8,
		 "Rotr of 0x9A by 2 should be 0xA6.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x9B_8> :: value == xE6_8,
		 "Rotr of 0x9B by 2 should be 0xE6.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x9C_8> :: value == x27_8,
		 "Rotr of 0x9C by 2 should be 0x27.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x9D_8> :: value == x67_8,
		 "Rotr of 0x9D by 2 should be 0x67.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x9E_8> :: value == xA7_8,
		 "Rotr of 0x9E by 2 should be 0xA7.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, x9F_8> :: value == xE7_8,
		 "Rotr of 0x9F by 2 should be 0xE7.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xA0_8> :: value == x28_8,
		 "Rotr of 0xA0 by 2 should be 0x28.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xA1_8> :: value == x68_8,
		 "Rotr of 0xA1 by 2 should be 0x68.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xA2_8> :: value == xA8_8,
		 "Rotr of 0xA2 by 2 should be 0xA8.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xA3_8> :: value == xE8_8,
		 "Rotr of 0xA3 by 2 should be 0xE8.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xA4_8> :: value == x29_8,
		 "Rotr of 0xA4 by 2 should be 0x29.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xA5_8> :: value == x69_8,
		 "Rotr of 0xA5 by 2 should be 0x69.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xA6_8> :: value == xA9_8,
		 "Rotr of 0xA6 by 2 should be 0xA9.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xA7_8> :: value == xE9_8,
		 "Rotr of 0xA7 by 2 should be 0xE9.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xA8_8> :: value == x2A_8,
		 "Rotr of 0xA8 by 2 should be 0x2A.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xA9_8> :: value == x6A_8,
		 "Rotr of 0xA9 by 2 should be 0x6A.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xAA_8> :: value == xAA_8,
		 "Rotr of 0xAA by 2 should be 0xAA.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xAB_8> :: value == xEA_8,
		 "Rotr of 0xAB by 2 should be 0xEA.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xAC_8> :: value == x2B_8,
		 "Rotr of 0xAC by 2 should be 0x2B.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xAD_8> :: value == x6B_8,
		 "Rotr of 0xAD by 2 should be 0x6B.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xAE_8> :: value == xAB_8,
		 "Rotr of 0xAE by 2 should be 0xAB.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xAF_8> :: value == xEB_8,
		 "Rotr of 0xAF by 2 should be 0xEB.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xB0_8> :: value == x2C_8,
		 "Rotr of 0xB0 by 2 should be 0x2C.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xB1_8> :: value == x6C_8,
		 "Rotr of 0xB1 by 2 should be 0x6C.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xB2_8> :: value == xAC_8,
		 "Rotr of 0xB2 by 2 should be 0xAC.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xB3_8> :: value == xEC_8,
		 "Rotr of 0xB3 by 2 should be 0xEC.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xB4_8> :: value == x2D_8,
		 "Rotr of 0xB4 by 2 should be 0x2D.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xB5_8> :: value == x6D_8,
		 "Rotr of 0xB5 by 2 should be 0x6D.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xB6_8> :: value == xAD_8,
		 "Rotr of 0xB6 by 2 should be 0xAD.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xB7_8> :: value == xED_8,
		 "Rotr of 0xB7 by 2 should be 0xED.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xB8_8> :: value == x2E_8,
		 "Rotr of 0xB8 by 2 should be 0x2E.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xB9_8> :: value == x6E_8,
		 "Rotr of 0xB9 by 2 should be 0x6E.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xBA_8> :: value == xAE_8,
		 "Rotr of 0xBA by 2 should be 0xAE.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xBB_8> :: value == xEE_8,
		 "Rotr of 0xBB by 2 should be 0xEE.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xBC_8> :: value == x2F_8,
		 "Rotr of 0xBC by 2 should be 0x2F.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xBD_8> :: value == x6F_8,
		 "Rotr of 0xBD by 2 should be 0x6F.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xBE_8> :: value == xAF_8,
		 "Rotr of 0xBE by 2 should be 0xAF.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xBF_8> :: value == xEF_8,
		 "Rotr of 0xBF by 2 should be 0xEF.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xC0_8> :: value == x30_8,
		 "Rotr of 0xC0 by 2 should be 0x30.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xC1_8> :: value == x70_8,
		 "Rotr of 0xC1 by 2 should be 0x70.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xC2_8> :: value == xB0_8,
		 "Rotr of 0xC2 by 2 should be 0xB0.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xC3_8> :: value == xF0_8,
		 "Rotr of 0xC3 by 2 should be 0xF0.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xC4_8> :: value == x31_8,
		 "Rotr of 0xC4 by 2 should be 0x31.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xC5_8> :: value == x71_8,
		 "Rotr of 0xC5 by 2 should be 0x71.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xC6_8> :: value == xB1_8,
		 "Rotr of 0xC6 by 2 should be 0xB1.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xC7_8> :: value == xF1_8,
		 "Rotr of 0xC7 by 2 should be 0xF1.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xC8_8> :: value == x32_8,
		 "Rotr of 0xC8 by 2 should be 0x32.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xC9_8> :: value == x72_8,
		 "Rotr of 0xC9 by 2 should be 0x72.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xCA_8> :: value == xB2_8,
		 "Rotr of 0xCA by 2 should be 0xB2.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xCB_8> :: value == xF2_8,
		 "Rotr of 0xCB by 2 should be 0xF2.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xCC_8> :: value == x33_8,
		 "Rotr of 0xCC by 2 should be 0x33.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xCD_8> :: value == x73_8,
		 "Rotr of 0xCD by 2 should be 0x73.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xCE_8> :: value == xB3_8,
		 "Rotr of 0xCE by 2 should be 0xB3.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xCF_8> :: value == xF3_8,
		 "Rotr of 0xCF by 2 should be 0xF3.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xD0_8> :: value == x34_8,
		 "Rotr of 0xD0 by 2 should be 0x34.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xD1_8> :: value == x74_8,
		 "Rotr of 0xD1 by 2 should be 0x74.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xD2_8> :: value == xB4_8,
		 "Rotr of 0xD2 by 2 should be 0xB4.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xD3_8> :: value == xF4_8,
		 "Rotr of 0xD3 by 2 should be 0xF4.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xD4_8> :: value == x35_8,
		 "Rotr of 0xD4 by 2 should be 0x35.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xD5_8> :: value == x75_8,
		 "Rotr of 0xD5 by 2 should be 0x75.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xD6_8> :: value == xB5_8,
		 "Rotr of 0xD6 by 2 should be 0xB5.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xD7_8> :: value == xF5_8,
		 "Rotr of 0xD7 by 2 should be 0xF5.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xD8_8> :: value == x36_8,
		 "Rotr of 0xD8 by 2 should be 0x36.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xD9_8> :: value == x76_8,
		 "Rotr of 0xD9 by 2 should be 0x76.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xDA_8> :: value == xB6_8,
		 "Rotr of 0xDA by 2 should be 0xB6.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xDB_8> :: value == xF6_8,
		 "Rotr of 0xDB by 2 should be 0xF6.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xDC_8> :: value == x37_8,
		 "Rotr of 0xDC by 2 should be 0x37.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xDD_8> :: value == x77_8,
		 "Rotr of 0xDD by 2 should be 0x77.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xDE_8> :: value == xB7_8,
		 "Rotr of 0xDE by 2 should be 0xB7.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xDF_8> :: value == xF7_8,
		 "Rotr of 0xDF by 2 should be 0xF7.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xE0_8> :: value == x38_8,
		 "Rotr of 0xE0 by 2 should be 0x38.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xE1_8> :: value == x78_8,
		 "Rotr of 0xE1 by 2 should be 0x78.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xE2_8> :: value == xB8_8,
		 "Rotr of 0xE2 by 2 should be 0xB8.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xE3_8> :: value == xF8_8,
		 "Rotr of 0xE3 by 2 should be 0xF8.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xE4_8> :: value == x39_8,
		 "Rotr of 0xE4 by 2 should be 0x39.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xE5_8> :: value == x79_8,
		 "Rotr of 0xE5 by 2 should be 0x79.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xE6_8> :: value == xB9_8,
		 "Rotr of 0xE6 by 2 should be 0xB9.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xE7_8> :: value == xF9_8,
		 "Rotr of 0xE7 by 2 should be 0xF9.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xE8_8> :: value == x3A_8,
		 "Rotr of 0xE8 by 2 should be 0x3A.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xE9_8> :: value == x7A_8,
		 "Rotr of 0xE9 by 2 should be 0x7A.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xEA_8> :: value == xBA_8,
		 "Rotr of 0xEA by 2 should be 0xBA.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xEB_8> :: value == xFA_8,
		 "Rotr of 0xEB by 2 should be 0xFA.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xEC_8> :: value == x3B_8,
		 "Rotr of 0xEC by 2 should be 0x3B.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xED_8> :: value == x7B_8,
		 "Rotr of 0xED by 2 should be 0x7B.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xEE_8> :: value == xBB_8,
		 "Rotr of 0xEE by 2 should be 0xBB.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xEF_8> :: value == xFB_8,
		 "Rotr of 0xEF by 2 should be 0FB.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xF0_8> :: value == x3C_8,
		 "Rotr of 0xF0 by 2 should be 0x3C.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xF1_8> :: value == x7C_8,
		 "Rotr of 0xF1 by 2 should be 0x7C.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xF2_8> :: value == xBC_8,
		 "Rotr of 0xF2 by 2 should be 0xBC.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xF3_8> :: value == xFC_8,
		 "Rotr of 0xF3 by 2 should be 0xFC.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xF4_8> :: value == x3D_8,
		 "Rotr of 0xF4 by 2 should be 0x3D.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xF5_8> :: value == x7D_8,
		 "Rotr of 0xF5 by 2 should be 0x7D.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xF6_8> :: value == xBD_8,
		 "Rotr of 0xF6 by 2 should be 0xBD.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xF7_8> :: value == xFD_8,
		 "Rotr of 0xF7 by 2 should be 0xFD.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xF8_8> :: value == x3E_8,
		 "Rotr of 0xF8 by 2 should be 0x3E.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xF9_8> :: value == x7E_8,
		 "Rotr of 0xF9 by 2 should be 0x7E.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xFA_8> :: value == xBE_8,
		 "Rotr of 0xFA by 2 should be 0xBE.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xFB_8> :: value == xFE_8,
		 "Rotr of 0xFB by 2 should be 0xFE.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xFC_8> :: value == x3F_8,
		 "Rotr of 0xFC by 2 should be 0x3F.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xFD_8> :: value == x7F_8,
		 "Rotr of 0xFD by 2 should be 0x7F.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xFE_8> :: value == xBF_8,
		 "Rotr of 0xFE by 2 should be 0xBF.");
 static_assert(crap :: rotrValue <2u, std :: uint8_t, xFF_8> :: value == xFF_8,
		 "Rotr of 0xFF by 2 should be 0xFF.");

 //shift by 3
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x00_8> :: value == x00_8,
		 "Rotr of 0x00 by 3 should be 0x00.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x01_8> :: value == x20_8,
		 "Rotr of 0x01 by 3 should be 0x20.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x02_8> :: value == x40_8,
		 "Rotr of 0x02 by 3 should be 0x40.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x03_8> :: value == x60_8,
		 "Rotr of 0x03 by 3 should be 0x60.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x04_8> :: value == x80_8,
		 "Rotr of 0x04 by 3 should be 0x80.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x05_8> :: value == xA0_8,
		 "Rotr of 0x05 by 3 should be 0xA0.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x06_8> :: value == xC0_8,
		 "Rotr of 0x06 by 3 should be 0xC0.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x07_8> :: value == xE0_8,
		 "Rotr of 0x07 by 3 should be 0xE0.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x08_8> :: value == x01_8,
		 "Rotr of 0x08 by 3 should be 0x01.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x09_8> :: value == x21_8,
		 "Rotr of 0x09 by 3 should be 0x21.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x0A_8> :: value == x41_8,
		 "Rotr of 0x0A by 3 should be 0x41.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x0B_8> :: value == x61_8,
		 "Rotr of 0x0B by 3 should be 0x61.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x0C_8> :: value == x81_8,
		 "Rotr of 0x0C by 3 should be 0x81.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x0D_8> :: value == xA1_8,
		 "Rotr of 0x0D by 3 should be 0xA1.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x0E_8> :: value == xC1_8,
		 "Rotr of 0x0E by 3 should be 0xC1.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x0F_8> :: value == xE1_8,
		 "Rotr of 0x0F by 3 should be 0xE1.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x10_8> :: value == x02_8,
		 "Rotr of 0x10 by 3 should be 0x02.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x11_8> :: value == x22_8,
		 "Rotr of 0x11 by 3 should be 0x22.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x12_8> :: value == x42_8,
		 "Rotr of 0x12 by 3 should be 0x42.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x13_8> :: value == x62_8,
		 "Rotr of 0x13 by 3 should be 0x62.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x14_8> :: value == x82_8,
		 "Rotr of 0x14 by 3 should be 0x82.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x15_8> :: value == xA2_8,
		 "Rotr of 0x15 by 3 should be 0xA2.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x16_8> :: value == xC2_8,
		 "Rotr of 0x16 by 3 should be 0xC2.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x17_8> :: value == xE2_8,
		 "Rotr of 0x17 by 3 should be 0xE2.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x18_8> :: value == x03_8,
		 "Rotr of 0x18 by 3 should be 0x03.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x19_8> :: value == x23_8,
		 "Rotr of 0x19 by 3 should be 0x23.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x1A_8> :: value == x43_8,
		 "Rotr of 0x1A by 3 should be 0x43.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x1B_8> :: value == x63_8,
		 "Rotr of 0x1B by 3 should be 0x63.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x1C_8> :: value == x83_8,
		 "Rotr of 0x1C by 3 should be 0x83.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x1D_8> :: value == xA3_8,
		 "Rotr of 0x1D by 3 should be 0xA3.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x1E_8> :: value == xC3_8,
		 "Rotr of 0x1E by 3 should be 0xC3.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x1F_8> :: value == xE3_8,
		 "Rotr of 0x1F by 3 should be 0xE3.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x20_8> :: value == x04_8,
		 "Rotr of 0x20 by 3 should be 0x04.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x21_8> :: value == x24_8,
		 "Rotr of 0x21 by 3 should be 0x24.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x22_8> :: value == x44_8,
		 "Rotr of 0x22 by 3 should be 0x44.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x23_8> :: value == x64_8,
		 "Rotr of 0x23 by 3 should be 0x64.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x24_8> :: value == x84_8,
		 "Rotr of 0x24 by 3 should be 0x84.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x25_8> :: value == xA4_8,
		 "Rotr of 0x25 by 3 should be 0xA4.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x26_8> :: value == xC4_8,
		 "Rotr of 0x26 by 3 should be 0xC4.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x27_8> :: value == xE4_8,
		 "Rotr of 0x27 by 3 should be 0xE4.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x28_8> :: value == x05_8,
		 "Rotr of 0x28 by 3 should be 0x05.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x29_8> :: value == x25_8,
		 "Rotr of 0x29 by 3 should be 0x25.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x2A_8> :: value == x45_8,
		 "Rotr of 0x2A by 3 should be 0x45.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x2B_8> :: value == x65_8,
		 "Rotr of 0x2B by 3 should be 0x65.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x2C_8> :: value == x85_8,
		 "Rotr of 0x2C by 3 should be 0x85.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x2D_8> :: value == xA5_8,
		 "Rotr of 0x2D by 3 should be 0xA5.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x2E_8> :: value == xC5_8,
		 "Rotr of 0x2E by 3 should be 0xC5.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x2F_8> :: value == xE5_8,
		 "Rotr of 0x2F by 3 should be 0xE5.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x30_8> :: value == x06_8,
		 "Rotr of 0x30 by 3 should be 0x06.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x31_8> :: value == x26_8,
		 "Rotr of 0x31 by 3 should be 0x26.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x32_8> :: value == x46_8,
		 "Rotr of 0x32 by 3 should be 0x46.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x33_8> :: value == x66_8,
		 "Rotr of 0x33 by 3 should be 0x66.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x34_8> :: value == x86_8,
		 "Rotr of 0x34 by 3 should be 0x86.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x35_8> :: value == xA6_8,
		 "Rotr of 0x35 by 3 should be 0xA6.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x36_8> :: value == xC6_8,
		 "Rotr of 0x36 by 3 should be 0xC6.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x37_8> :: value == xE6_8,
		 "Rotr of 0x37 by 3 should be 0xE6.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x38_8> :: value == x07_8,
		 "Rotr of 0x38 by 3 should be 0x07.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x39_8> :: value == x27_8,
		 "Rotr of 0x39 by 3 should be 0x27.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x3A_8> :: value == x47_8,
		 "Rotr of 0x3A by 3 should be 0x47.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x3B_8> :: value == x67_8,
		 "Rotr of 0x3B by 3 should be 0x67.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x3C_8> :: value == x87_8,
		 "Rotr of 0x3C by 3 should be 0x87.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x3D_8> :: value == xA7_8,
		 "Rotr of 0x3D by 3 should be 0xA7.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x3E_8> :: value == xC7_8,
		 "Rotr of 0x3E by 3 should be 0xC7.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x3F_8> :: value == xE7_8,
		 "Rotr of 0x3F by 3 should be 0xE7.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x40_8> :: value == x08_8,
		 "Rotr of 0x40 by 3 should be 0x08.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x41_8> :: value == x28_8,
		 "Rotr of 0x41 by 3 should be 0x28.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x42_8> :: value == x48_8,
		 "Rotr of 0x42 by 3 should be 0x48.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x43_8> :: value == x68_8,
		 "Rotr of 0x43 by 3 should be 0x68.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x44_8> :: value == x88_8,
		 "Rotr of 0x44 by 3 should be 0x88.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x45_8> :: value == xA8_8,
		 "Rotr of 0x45 by 3 should be 0xA8.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x46_8> :: value == xC8_8,
		 "Rotr of 0x46 by 3 should be 0xD8.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x47_8> :: value == xE8_8,
		 "Rotr of 0x47 by 3 should be 0xE8.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x48_8> :: value == x09_8,
		 "Rotr of 0x48 by 3 should be 0x09.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x49_8> :: value == x29_8,
		 "Rotr of 0x49 by 3 should be 0x29.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x4A_8> :: value == x49_8,
		 "Rotr of 0x4A by 3 should be 0x49.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x4B_8> :: value == x69_8,
		 "Rotr of 0x4B by 3 should be 0x69.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x4C_8> :: value == x89_8,
		 "Rotr of 0x4C by 3 should be 0x89.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x4D_8> :: value == xA9_8,
		 "Rotr of 0x4D by 3 should be 0xA9.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x4E_8> :: value == xC9_8,
		 "Rotr of 0x4E by 3 should be 0xC9.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x4F_8> :: value == xE9_8,
		 "Rotr of 0x4F by 3 should be 0xE9.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x50_8> :: value == x0A_8,
		 "Rotr of 0x50 by 3 should be 0x0A.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x51_8> :: value == x2A_8,
		 "Rotr of 0x51 by 3 should be 0x2A.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x52_8> :: value == x4A_8,
		 "Rotr of 0x52 by 3 should be 0x4A.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x53_8> :: value == x6A_8,
		 "Rotr of 0x53 by 3 should be 0x6A.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x54_8> :: value == x8A_8,
		 "Rotr of 0x54 by 3 should be 0x8A.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x55_8> :: value == xAA_8,
		 "Rotr of 0x55 by 3 should be 0xAA.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x56_8> :: value == xCA_8,
		 "Rotr of 0x56 by 3 should be 0xCA.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x57_8> :: value == xEA_8,
		 "Rotr of 0x57 by 3 should be 0xEA.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x58_8> :: value == x0B_8,
		 "Rotr of 0x58 by 3 should be 0x0B.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x59_8> :: value == x2B_8,
		 "Rotr of 0x59 by 3 should be 0x2B.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x5A_8> :: value == x4B_8,
		 "Rotr of 0x5A by 3 should be 0x4B.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x5B_8> :: value == x6B_8,
		 "Rotr of 0x5B by 3 should be 0x6B.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x5C_8> :: value == x8B_8,
		 "Rotr of 0x5C by 3 should be 0x8B.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x5D_8> :: value == xAB_8,
		 "Rotr of 0x5D by 3 should be 0xAB.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x5E_8> :: value == xCB_8,
		 "Rotr of 0x5E by 3 should be 0xCB.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x5F_8> :: value == xEB_8,
		 "Rotr of 0x5F by 3 should be 0xEB.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x60_8> :: value == x0C_8,
		 "Rotr of 0x60 by 3 should be 0x0C.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x61_8> :: value == x2C_8,
		 "Rotr of 0x61 by 3 should be 0x2C.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x62_8> :: value == x4C_8,
		 "Rotr of 0x62 by 3 should be 0x4C.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x63_8> :: value == x6C_8,
		 "Rotr of 0x63 by 3 should be 0x6C.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x64_8> :: value == x8C_8,
		 "Rotr of 0x64 by 3 should be 0x8C.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x65_8> :: value == xAC_8,
		 "Rotr of 0x65 by 3 should be 0xAC.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x66_8> :: value == xCC_8,
		 "Rotr of 0x66 by 3 should be 0xCC.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x67_8> :: value == xEC_8,
		 "Rotr of 0x67 by 3 should be 0xFC.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x68_8> :: value == x0D_8,
		 "Rotr of 0x68 by 3 should be 0x0D.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x69_8> :: value == x2D_8,
		 "Rotr of 0x69 by 3 should be 0x2D.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x6A_8> :: value == x4D_8,
		 "Rotr of 0x6A by 3 should be 0x4D.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x6B_8> :: value == x6D_8,
		 "Rotr of 0x6B by 3 should be 0x6D.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x6C_8> :: value == x8D_8,
		 "Rotr of 0x6C by 3 should be 0x8D.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x6D_8> :: value == xAD_8,
		 "Rotr of 0x6D by 3 should be 0xAD.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x6E_8> :: value == xCD_8,
		 "Rotr of 0x6E by 3 should be 0xCD.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x6F_8> :: value == xED_8,
		 "Rotr of 0x6F by 3 should be 0xED.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x70_8> :: value == x0E_8,
		 "Rotr of 0x70 by 3 should be 0x0E.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x71_8> :: value == x2E_8,
		 "Rotr of 0x71 by 3 should be 0x2E.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x72_8> :: value == x4E_8,
		 "Rotr of 0x72 by 3 should be 0x4E.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x73_8> :: value == x6E_8,
		 "Rotr of 0x73 by 3 should be 0x6E.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x74_8> :: value == x8E_8,
		 "Rotr of 0x74 by 3 should be 0x8E.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x75_8> :: value == xAE_8,
		 "Rotr of 0x75 by 3 should be 0xAE.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x76_8> :: value == xCE_8,
		 "Rotr of 0x76 by 3 should be 0xCE.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x77_8> :: value == xEE_8,
		 "Rotr of 0x77 by 3 should be 0xEE.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x78_8> :: value == x0F_8,
		 "Rotr of 0x78 by 3 should be 0x0F.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x79_8> :: value == x2F_8,
		 "Rotr of 0x79 by 3 should be 0x2F.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x7A_8> :: value == x4F_8,
		 "Rotr of 0x7A by 3 should be 0x4F.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x7B_8> :: value == x6F_8,
		 "Rotr of 0x7B by 3 should be 0x6F.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x7C_8> :: value == x8F_8,
		 "Rotr of 0x7C by 3 should be 0x8F.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x7D_8> :: value == xAF_8,
		 "Rotr of 0x7D by 3 should be 0xAF.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x7E_8> :: value == xCF_8,
		 "Rotr of 0x7E by 3 should be 0xCF.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x7F_8> :: value == xEF_8,
		 "Rotr of 0x7F by 3 should be 0xEF.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x80_8> :: value == x10_8,
		 "Rotr of 0x80 by 3 should be 0x10.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x81_8> :: value == x30_8,
		 "Rotr of 0x81 by 3 should be 0x30.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x82_8> :: value == x50_8,
		 "Rotr of 0x82 by 3 should be 0x50.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x83_8> :: value == x70_8,
		 "Rotr of 0x83 by 3 should be 0x70.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x84_8> :: value == x90_8,
		 "Rotr of 0x84 by 3 should be 0x90.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x85_8> :: value == xB0_8,
		 "Rotr of 0x85 by 3 should be 0xB0.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x86_8> :: value == xD0_8,
		 "Rotr of 0x86 by 3 should be 0xD0.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x87_8> :: value == xF0_8,
		 "Rotr of 0x87 by 3 should be 0xF0.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x88_8> :: value == x11_8,
		 "Rotr of 0x88 by 3 should be 0x11.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x89_8> :: value == x31_8,
		 "Rotr of 0x89 by 3 should be 0x31.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x8A_8> :: value == x51_8,
		 "Rotr of 0x8A by 3 should be 0x51.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x8B_8> :: value == x71_8,
		 "Rotr of 0x8B by 3 should be 0x71.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x8C_8> :: value == x91_8,
		 "Rotr of 0x8C by 3 should be 0x91.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x8D_8> :: value == xB1_8,
		 "Rotr of 0x8D by 3 should be 0xB1.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x8E_8> :: value == xD1_8,
		 "Rotr of 0x8E by 3 should be 0xD1.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x8F_8> :: value == xF1_8,
		 "Rotr of 0x8F by 3 should be 0xF1.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x90_8> :: value == x12_8,
		 "Rotr of 0x90 by 3 should be 0x12.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x91_8> :: value == x32_8,
		 "Rotr of 0x91 by 3 should be 0x32.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x92_8> :: value == x52_8,
		 "Rotr of 0x92 by 3 should be 0x52.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x93_8> :: value == x72_8,
		 "Rotr of 0x93 by 3 should be 0x72.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x94_8> :: value == x92_8,
		 "Rotr of 0x94 by 3 should be 0x92.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x95_8> :: value == xB2_8,
		 "Rotr of 0x95 by 3 should be 0xB2.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x96_8> :: value == xD2_8,
		 "Rotr of 0x96 by 3 should be 0xD2.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x97_8> :: value == xF2_8,
		 "Rotr of 0x97 by 3 should be 0xF2.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x98_8> :: value == x13_8,
		 "Rotr of 0x98 by 3 should be 0x13.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x99_8> :: value == x33_8,
		 "Rotr of 0x99 by 3 should be 0x33.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x9A_8> :: value == x53_8,
		 "Rotr of 0x9A by 3 should be 0x53.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x9B_8> :: value == x73_8,
		 "Rotr of 0x9B by 3 should be 0x73.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x9C_8> :: value == x93_8,
		 "Rotr of 0x9C by 3 should be 0x93.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x9D_8> :: value == xB3_8,
		 "Rotr of 0x9D by 3 should be 0xB3.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x9E_8> :: value == xD3_8,
		 "Rotr of 0x9E by 3 should be 0xD3.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, x9F_8> :: value == xF3_8,
		 "Rotr of 0x9F by 3 should be 0xF3.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xA0_8> :: value == x14_8,
		 "Rotr of 0xA0 by 3 should be 0x14.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xA1_8> :: value == x34_8,
		 "Rotr of 0xA1 by 3 should be 0x34.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xA2_8> :: value == x54_8,
		 "Rotr of 0xA2 by 3 should be 0x54.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xA3_8> :: value == x74_8,
		 "Rotr of 0xA3 by 3 should be 0x74.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xA4_8> :: value == x94_8,
		 "Rotr of 0xA4 by 3 should be 0x94.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xA5_8> :: value == xB4_8,
		 "Rotr of 0xA5 by 3 should be 0xB4.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xA6_8> :: value == xD4_8,
		 "Rotr of 0xA6 by 3 should be 0xD4.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xA7_8> :: value == xF4_8,
		 "Rotr of 0xA7 by 3 should be 0xF4.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xA8_8> :: value == x15_8,
		 "Rotr of 0xA8 by 3 should be 0x15.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xA9_8> :: value == x35_8,
		 "Rotr of 0xA9 by 3 should be 0x35.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xAA_8> :: value == x55_8,
		 "Rotr of 0xAA by 3 should be 0x55.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xAB_8> :: value == x75_8,
		 "Rotr of 0xAB by 3 should be 0x75.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xAC_8> :: value == x95_8,
		 "Rotr of 0xAC by 3 should be 0x95.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xAD_8> :: value == xB5_8,
		 "Rotr of 0xAD by 3 should be 0xB5.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xAE_8> :: value == xD5_8,
		 "Rotr of 0xAE by 3 should be 0xD5.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xAF_8> :: value == xF5_8,
		 "Rotr of 0xAF by 3 should be 0xF5.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xB0_8> :: value == x16_8,
		 "Rotr of 0xB0 by 3 should be 0x16.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xB1_8> :: value == x36_8,
		 "Rotr of 0xB1 by 3 should be 0x36.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xB2_8> :: value == x56_8,
		 "Rotr of 0xB2 by 3 should be 0x56.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xB3_8> :: value == x76_8,
		 "Rotr of 0xB3 by 3 should be 0x76.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xB4_8> :: value == x96_8,
		 "Rotr of 0xB4 by 3 should be 0x96.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xB5_8> :: value == xB6_8,
		 "Rotr of 0xB5 by 3 should be 0xB6.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xB6_8> :: value == xD6_8,
		 "Rotr of 0xB6 by 3 should be 0xD6.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xB7_8> :: value == xF6_8,
		 "Rotr of 0xB7 by 3 should be 0xF6.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xB8_8> :: value == x17_8,
		 "Rotr of 0xB8 by 3 should be 0x17.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xB9_8> :: value == x37_8,
		 "Rotr of 0xB9 by 3 should be 0x37.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xBA_8> :: value == x57_8,
		 "Rotr of 0xBA by 3 should be 0x57.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xBB_8> :: value == x77_8,
		 "Rotr of 0xBB by 3 should be 0x77.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xBC_8> :: value == x97_8,
		 "Rotr of 0xBC by 3 should be 0x97.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xBD_8> :: value == xB7_8,
		 "Rotr of 0xBD by 3 should be 0xB7.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xBE_8> :: value == xD7_8,
		 "Rotr of 0xBE by 3 should be 0xD7.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xBF_8> :: value == xF7_8,
		 "Rotr of 0xBF by 3 should be 0xF7.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xC0_8> :: value == x18_8,
		 "Rotr of 0xC0 by 3 should be 0x18.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xC1_8> :: value == x38_8,
		 "Rotr of 0xC1 by 3 should be 0x38.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xC2_8> :: value == x58_8,
		 "Rotr of 0xC2 by 3 should be 0x58.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xC3_8> :: value == x78_8,
		 "Rotr of 0xC3 by 3 should be 0x78.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xC4_8> :: value == x98_8,
		 "Rotr of 0xC4 by 3 should be 0x98.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xC5_8> :: value == xB8_8,
		 "Rotr of 0xC5 by 3 should be 0xB8.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xC6_8> :: value == xD8_8,
		 "Rotr of 0xC6 by 3 should be 0xD8.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xC7_8> :: value == xF8_8,
		 "Rotr of 0xC7 by 3 should be 0xF8.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xC8_8> :: value == x19_8,
		 "Rotr of 0xC8 by 3 should be 0x19.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xC9_8> :: value == x39_8,
		 "Rotr of 0xC9 by 3 should be 0x39.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xCA_8> :: value == x59_8,
		 "Rotr of 0xCA by 3 should be 0x59.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xCB_8> :: value == x79_8,
		 "Rotr of 0xCB by 3 should be 0x79.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xCC_8> :: value == x99_8,
		 "Rotr of 0xCC by 3 should be 0x99.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xCD_8> :: value == xB9_8,
		 "Rotr of 0xCD by 3 should be 0xB9.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xCE_8> :: value == xD9_8,
		 "Rotr of 0xCE by 3 should be 0xD9.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xCF_8> :: value == xF9_8,
		 "Rotr of 0xCF by 3 should be 0xF9.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xD0_8> :: value == x1A_8,
		 "Rotr of 0xD0 by 3 should be 0x1A.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xD1_8> :: value == x3A_8,
		 "Rotr of 0xD1 by 3 should be 0x3A.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xD2_8> :: value == x5A_8,
		 "Rotr of 0xD2 by 3 should be 0x5A.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xD3_8> :: value == x7A_8,
		 "Rotr of 0xD3 by 3 should be 0x7A.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xD4_8> :: value == x9A_8,
		 "Rotr of 0xD4 by 3 should be 0x9A.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xD5_8> :: value == xBA_8,
		 "Rotr of 0xD5 by 3 should be 0xBA.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xD6_8> :: value == xDA_8,
		 "Rotr of 0xD6 by 3 should be 0xDA.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xD7_8> :: value == xFA_8,
		 "Rotr of 0xD7 by 3 should be 0xFA.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xD8_8> :: value == x1B_8,
		 "Rotr of 0xD8 by 3 should be 0x1B.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xD9_8> :: value == x3B_8,
		 "Rotr of 0xD9 by 3 should be 0x3B.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xDA_8> :: value == x5B_8,
		 "Rotr of 0xDA by 3 should be 0x5B.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xDB_8> :: value == x7B_8,
		 "Rotr of 0xDB by 3 should be 0x7B.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xDC_8> :: value == x9B_8,
		 "Rotr of 0xDC by 3 should be 0x9B.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xDD_8> :: value == xBB_8,
		 "Rotr of 0xDD by 3 should be 0xBB.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xDE_8> :: value == xDB_8,
		 "Rotr of 0xDE by 3 should be 0xDB.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xDF_8> :: value == xFB_8,
		 "Rotr of 0xDF by 3 should be 0xFB.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xE0_8> :: value == x1C_8,
		 "Rotr of 0xE0 by 3 should be 0x1C.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xE1_8> :: value == x3C_8,
		 "Rotr of 0xE1 by 3 should be 0x3C.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xE2_8> :: value == x5C_8,
		 "Rotr of 0xE2 by 3 should be 0x5C.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xE3_8> :: value == x7C_8,
		 "Rotr of 0xE3 by 3 should be 0x7C.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xE4_8> :: value == x9C_8,
		 "Rotr of 0xE4 by 3 should be 0x9C.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xE5_8> :: value == xBC_8,
		 "Rotr of 0xE5 by 3 should be 0xBC.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xE6_8> :: value == xDC_8,
		 "Rotr of 0xE6 by 3 should be 0xDC.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xE7_8> :: value == xFC_8,
		 "Rotr of 0xE7 by 3 should be 0xFC.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xE8_8> :: value == x1D_8,
		 "Rotr of 0xE8 by 3 should be 0x1D.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xE9_8> :: value == x3D_8,
		 "Rotr of 0xE9 by 3 should be 0x3D.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xEA_8> :: value == x5D_8,
		 "Rotr of 0xEA by 3 should be 0x5D.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xEB_8> :: value == x7D_8,
		 "Rotr of 0xEB by 3 should be 0x7D.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xEC_8> :: value == x9D_8,
		 "Rotr of 0xEC by 3 should be 0x9D.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xED_8> :: value == xBD_8,
		 "Rotr of 0xED by 3 should be 0xBD.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xEE_8> :: value == xDD_8,
		 "Rotr of 0xEE by 3 should be 0xDD.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xEF_8> :: value == xFD_8,
		 "Rotr of 0xEF by 3 should be 0xFD.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xF0_8> :: value == x1E_8,
		 "Rotr of 0xF0 by 3 should be 0x1E.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xF1_8> :: value == x3E_8,
		 "Rotr of 0xF1 by 3 should be 0x3E.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xF2_8> :: value == x5E_8,
		 "Rotr of 0xF2 by 3 should be 0x5E.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xF3_8> :: value == x7E_8,
		 "Rotr of 0xF3 by 3 should be 0x7E.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xF4_8> :: value == x9E_8,
		 "Rotr of 0xF4 by 3 should be 0x9E.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xF5_8> :: value == xBE_8,
		 "Rotr of 0xF5 by 3 should be 0xBE.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xF6_8> :: value == xDE_8,
		 "Rotr of 0xF6 by 3 should be 0xDE.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xF7_8> :: value == xFE_8,
		 "Rotr of 0xF7 by 3 should be 0xFE.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xF8_8> :: value == x1F_8,
		 "Rotr of 0xF8 by 3 should be 0x1F.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xF9_8> :: value == x3F_8,
		 "Rotr of 0xF9 by 3 should be 0x3F.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xFA_8> :: value == x5F_8,
		 "Rotr of 0xFA by 3 should be 0x5F.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xFB_8> :: value == x7F_8,
		 "Rotr of 0xFB by 3 should be 0x7F.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xFC_8> :: value == x9F_8,
		 "Rotr of 0xFC by 3 should be 0x9F.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xFD_8> :: value == xBF_8,
		 "Rotr of 0xFD by 3 should be 0xBF.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xFE_8> :: value == xDF_8,
		 "Rotr of 0xFE by 3 should be 0xDF.");
 static_assert(crap :: rotrValue <3u, std :: uint8_t, xFF_8> :: value == xFF_8,
		 "Rotr of 0xFF by 3 should be 0xFF.");

 //shift by 3
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x00_8> :: value == x00_8,
		 "Rotr of 0x00 by 4 should be 0x00.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x01_8> :: value == x20_8,
		 "Rotr of 0x01 by 4 should be 0x20.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x02_8> :: value == x40_8,
		 "Rotr of 0x02 by 4 should be 0x40.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x03_8> :: value == x60_8,
		 "Rotr of 0x03 by 4 should be 0x60.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x04_8> :: value == x80_8,
		 "Rotr of 0x04 by 4 should be 0x80.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x05_8> :: value == xA0_8,
		 "Rotr of 0x05 by 4 should be 0xA0.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x06_8> :: value == xC0_8,
		 "Rotr of 0x06 by 4 should be 0xC0.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x07_8> :: value == xE0_8,
		 "Rotr of 0x07 by 4 should be 0xE0.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x08_8> :: value == x01_8,
		 "Rotr of 0x08 by 4 should be 0x01.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x09_8> :: value == x21_8,
		 "Rotr of 0x09 by 4 should be 0x21.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x0A_8> :: value == x41_8,
		 "Rotr of 0x0A by 4 should be 0x41.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x0B_8> :: value == x61_8,
		 "Rotr of 0x0B by 4 should be 0x61.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x0C_8> :: value == x81_8,
		 "Rotr of 0x0C by 4 should be 0x81.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x0D_8> :: value == xA1_8,
		 "Rotr of 0x0D by 4 should be 0xA1.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x0E_8> :: value == xC1_8,
		 "Rotr of 0x0E by 4 should be 0xC1.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x0F_8> :: value == xE1_8,
		 "Rotr of 0x0F by 4 should be 0xE1.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x10_8> :: value == x01_8,
		 "Rotr of 0x10 by 4 should be 0x01.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x11_8> :: value == x11_8,
		 "Rotr of 0x11 by 4 should be 0x11.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x12_8> :: value == x21_8,
		 "Rotr of 0x12 by 4 should be 0x21.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x13_8> :: value == x31_8,
		 "Rotr of 0x13 by 4 should be 0x31.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x14_8> :: value == x41_8,
		 "Rotr of 0x14 by 4 should be 0x41.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x15_8> :: value == x51_8,
		 "Rotr of 0x15 by 4 should be 0x51.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x16_8> :: value == x61_8,
		 "Rotr of 0x16 by 4 should be 0x61.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x17_8> :: value == x71_8,
		 "Rotr of 0x17 by 4 should be 0x71.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x18_8> :: value == x81_8,
		 "Rotr of 0x18 by 4 should be 0x81.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x19_8> :: value == x91_8,
		 "Rotr of 0x19 by 4 should be 0x91.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x1A_8> :: value == xA1_8,
		 "Rotr of 0x1A by 4 should be 0xA1.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x1B_8> :: value == xB1_8,
		 "Rotr of 0x1B by 4 should be 0xB1.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x1C_8> :: value == xC1_8,
		 "Rotr of 0x1C by 4 should be 0xC1.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x1D_8> :: value == xD1_8,
		 "Rotr of 0x1D by 4 should be 0xD1.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x1E_8> :: value == xE1_8,
		 "Rotr of 0x1E by 4 should be 0xE1.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x1F_8> :: value == xF1_8,
		 "Rotr of 0x1F by 4 should be 0xF1.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x20_8> :: value == x02_8,
		 "Rotr of 0x20 by 4 should be 0x02.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x21_8> :: value == x12_8,
		 "Rotr of 0x21 by 4 should be 0x12.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x22_8> :: value == x22_8,
		 "Rotr of 0x22 by 4 should be 0x22.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x23_8> :: value == x32_8,
		 "Rotr of 0x23 by 4 should be 0x32.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x24_8> :: value == x42_8,
		 "Rotr of 0x24 by 4 should be 0x42.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x25_8> :: value == x52_8,
		 "Rotr of 0x25 by 4 should be 0x52.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x26_8> :: value == x62_8,
		 "Rotr of 0x26 by 4 should be 0x62.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x27_8> :: value == x72_8,
		 "Rotr of 0x27 by 4 should be 0x72.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x28_8> :: value == x82_8,
		 "Rotr of 0x28 by 4 should be 0x82.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x29_8> :: value == x92_8,
		 "Rotr of 0x29 by 4 should be 0x92.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x2A_8> :: value == xA2_8,
		 "Rotr of 0x2A by 4 should be 0xA2.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x2B_8> :: value == xB2_8,
		 "Rotr of 0x2B by 4 should be 0xB2.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x2C_8> :: value == xC2_8,
		 "Rotr of 0x2C by 4 should be 0xC2.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x2D_8> :: value == xD2_8,
		 "Rotr of 0x2D by 4 should be 0xD2.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x2E_8> :: value == xE2_8,
		 "Rotr of 0x2E by 4 should be 0xE2.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x2F_8> :: value == xF2_8,
		 "Rotr of 0x2F by 4 should be 0xF2.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x30_8> :: value == x03_8,
		 "Rotr of 0x30 by 4 should be 0x03.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x31_8> :: value == x13_8,
		 "Rotr of 0x31 by 4 should be 0x13.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x32_8> :: value == x23_8,
		 "Rotr of 0x32 by 4 should be 0x23.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x33_8> :: value == x33_8,
		 "Rotr of 0x33 by 4 should be 0x33.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x34_8> :: value == x43_8,
		 "Rotr of 0x34 by 4 should be 0x43.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x35_8> :: value == x53_8,
		 "Rotr of 0x35 by 4 should be 0x53.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x36_8> :: value == x63_8,
		 "Rotr of 0x36 by 4 should be 0x63.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x37_8> :: value == x73_8,
		 "Rotr of 0x37 by 4 should be 0x73.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x38_8> :: value == x83_8,
		 "Rotr of 0x38 by 4 should be 0x83.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x39_8> :: value == x93_8,
		 "Rotr of 0x39 by 4 should be 0x93.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x3A_8> :: value == xA3_8,
		 "Rotr of 0x3A by 4 should be 0xA3.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x3B_8> :: value == xB3_8,
		 "Rotr of 0x3B by 4 should be 0xB3.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x3C_8> :: value == xC3_8,
		 "Rotr of 0x3C by 4 should be 0xC3.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x3D_8> :: value == xD3_8,
		 "Rotr of 0x3D by 4 should be 0xD3.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x3E_8> :: value == xE3_8,
		 "Rotr of 0x3E by 4 should be 0xE3.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x3F_8> :: value == xF3_8,
		 "Rotr of 0x3F by 4 should be 0xF3.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x40_8> :: value == x04_8,
		 "Rotr of 0x40 by 4 should be 0x04.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x41_8> :: value == x14_8,
		 "Rotr of 0x41 by 4 should be 0x14.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x42_8> :: value == x24_8,
		 "Rotr of 0x42 by 4 should be 0x24.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x43_8> :: value == x34_8,
		 "Rotr of 0x43 by 4 should be 0x34.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x44_8> :: value == x44_8,
		 "Rotr of 0x44 by 4 should be 0x44.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x45_8> :: value == x54_8,
		 "Rotr of 0x45 by 4 should be 0x54.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x46_8> :: value == x64_8,
		 "Rotr of 0x46 by 4 should be 0x64.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x47_8> :: value == x74_8,
		 "Rotr of 0x47 by 4 should be 0x74.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x48_8> :: value == x84_8,
		 "Rotr of 0x48 by 4 should be 0x84.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x49_8> :: value == x94_8,
		 "Rotr of 0x49 by 4 should be 0x94.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x4A_8> :: value == xA4_8,
		 "Rotr of 0x4A by 4 should be 0xA4.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x4B_8> :: value == xB4_8,
		 "Rotr of 0x4B by 4 should be 0xB4.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x4C_8> :: value == xC4_8,
		 "Rotr of 0x4C by 4 should be 0xC4.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x4D_8> :: value == xD4_8,
		 "Rotr of 0x4D by 4 should be 0xD4.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x4E_8> :: value == xE4_8,
		 "Rotr of 0x4E by 4 should be 0xE4.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x4F_8> :: value == xF4_8,
		 "Rotr of 0x4F by 4 should be 0xF4.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x50_8> :: value == x05_8,
		 "Rotr of 0x50 by 4 should be 0x05.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x51_8> :: value == x15_8,
		 "Rotr of 0x51 by 4 should be 0x15.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x52_8> :: value == x25_8,
		 "Rotr of 0x52 by 4 should be 0x25.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x53_8> :: value == x35_8,
		 "Rotr of 0x53 by 4 should be 0x35.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x54_8> :: value == x45_8,
		 "Rotr of 0x54 by 4 should be 0x45.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x55_8> :: value == x55_8,
		 "Rotr of 0x55 by 4 should be 0x55.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x56_8> :: value == x65_8,
		 "Rotr of 0x56 by 4 should be 0x65.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x57_8> :: value == x75_8,
		 "Rotr of 0x57 by 4 should be 0x75.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x58_8> :: value == x85_8,
		 "Rotr of 0x58 by 4 should be 0x85.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x59_8> :: value == x95_8,
		 "Rotr of 0x59 by 4 should be 0x95.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x5A_8> :: value == xA5_8,
		 "Rotr of 0x5A by 4 should be 0xA5.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x5B_8> :: value == xB5_8,
		 "Rotr of 0x5B by 4 should be 0xB5.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x5C_8> :: value == xC5_8,
		 "Rotr of 0x5C by 4 should be 0xC5.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x5D_8> :: value == xD5_8,
		 "Rotr of 0x5D by 4 should be 0xD5.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x5E_8> :: value == xE5_8,
		 "Rotr of 0x5E by 4 should be 0xE5.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x5F_8> :: value == xF5_8,
		 "Rotr of 0x5F by 4 should be 0xF5.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x60_8> :: value == x06_8,
		 "Rotr of 0x60 by 4 should be 0x06.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x61_8> :: value == x16_8,
		 "Rotr of 0x61 by 4 should be 0x16.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x62_8> :: value == x26_8,
		 "Rotr of 0x62 by 4 should be 0x26.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x63_8> :: value == x36_8,
		 "Rotr of 0x63 by 4 should be 0x36.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x64_8> :: value == x46_8,
		 "Rotr of 0x64 by 4 should be 0x46.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x65_8> :: value == x56_8,
		 "Rotr of 0x65 by 4 should be 0x56.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x66_8> :: value == x66_8,
		 "Rotr of 0x66 by 4 should be 0x66.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x67_8> :: value == x76_8,
		 "Rotr of 0x67 by 4 should be 0x76.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x68_8> :: value == x86_8,
		 "Rotr of 0x68 by 4 should be 0x86.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x69_8> :: value == x96_8,
		 "Rotr of 0x69 by 4 should be 0x96.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x6A_8> :: value == xA6_8,
		 "Rotr of 0x6A by 4 should be 0xA6.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x6B_8> :: value == xB6_8,
		 "Rotr of 0x6B by 4 should be 0xB6.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x6C_8> :: value == xC6_8,
		 "Rotr of 0x6C by 4 should be 0xC6.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x6D_8> :: value == xD6_8,
		 "Rotr of 0x6D by 4 should be 0xD6.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x6E_8> :: value == xE6_8,
		 "Rotr of 0x6E by 4 should be 0xE6.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x6F_8> :: value == xF6_8,
		 "Rotr of 0x6F by 4 should be 0xF6.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x70_8> :: value == x07_8,
		 "Rotr of 0x70 by 4 should be 0x07.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x71_8> :: value == x17_8,
		 "Rotr of 0x71 by 4 should be 0x17.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x72_8> :: value == x27_8,
		 "Rotr of 0x72 by 4 should be 0x27.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x73_8> :: value == x37_8,
		 "Rotr of 0x73 by 4 should be 0x37.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x74_8> :: value == x47_8,
		 "Rotr of 0x74 by 4 should be 0x47.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x75_8> :: value == x57_8,
		 "Rotr of 0x75 by 4 should be 0x57.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x76_8> :: value == x67_8,
		 "Rotr of 0x76 by 4 should be 0x67.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x77_8> :: value == x77_8,
		 "Rotr of 0x77 by 4 should be 0x77.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x78_8> :: value == x87_8,
		 "Rotr of 0x78 by 4 should be 0x87.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x79_8> :: value == x97_8,
		 "Rotr of 0x79 by 4 should be 0x97.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x7A_8> :: value == xA7_8,
		 "Rotr of 0x7A by 4 should be 0xA7.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x7B_8> :: value == xB7_8,
		 "Rotr of 0x7B by 4 should be 0xB7.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x7C_8> :: value == xC7_8,
		 "Rotr of 0x7C by 4 should be 0xC7.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x7D_8> :: value == xD7_8,
		 "Rotr of 0x7D by 4 should be 0xD7.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x7E_8> :: value == xE7_8,
		 "Rotr of 0x7E by 4 should be 0xE7.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x7F_8> :: value == xF7_8,
		 "Rotr of 0x7F by 4 should be 0xF7.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x80_8> :: value == x08_8,
		 "Rotr of 0x80 by 4 should be 0x08.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x81_8> :: value == x18_8,
		 "Rotr of 0x81 by 4 should be 0x30.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x82_8> :: value == x28_8,
		 "Rotr of 0x82 by 4 should be 0x18.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x83_8> :: value == x38_8,
		 "Rotr of 0x83 by 4 should be 0x38.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x84_8> :: value == x48_8,
		 "Rotr of 0x84 by 4 should be 0x48.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x85_8> :: value == x58_8,
		 "Rotr of 0x85 by 4 should be 0x58.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x86_8> :: value == x68_8,
		 "Rotr of 0x86 by 4 should be 0x68.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x87_8> :: value == x78_8,
		 "Rotr of 0x87 by 4 should be 0x78.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x88_8> :: value == x88_8,
		 "Rotr of 0x88 by 4 should be 0x88.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x89_8> :: value == x98_8,
		 "Rotr of 0x89 by 4 should be 0x98.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x8A_8> :: value == xA8_8,
		 "Rotr of 0x8A by 4 should be 0xA8.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x8B_8> :: value == xB8_8,
		 "Rotr of 0x8B by 4 should be 0xB8.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x8C_8> :: value == xC8_8,
		 "Rotr of 0x8C by 4 should be 0xC8.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x8D_8> :: value == xD8_8,
		 "Rotr of 0x8D by 4 should be 0xD8.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x8E_8> :: value == xE8_8,
		 "Rotr of 0x8E by 4 should be 0xE8.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x8F_8> :: value == xF8_8,
		 "Rotr of 0x8F by 4 should be 0xF8.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x90_8> :: value == x09_8,
		 "Rotr of 0x90 by 4 should be 0x09.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x91_8> :: value == x19_8,
		 "Rotr of 0x91 by 4 should be 0x19.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x92_8> :: value == x29_8,
		 "Rotr of 0x92 by 4 should be 0x29.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x93_8> :: value == x39_8,
		 "Rotr of 0x93 by 4 should be 0x39.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x94_8> :: value == x49_8,
		 "Rotr of 0x94 by 4 should be 0x49.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x95_8> :: value == x59_8,
		 "Rotr of 0x95 by 4 should be 0x59.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x96_8> :: value == x69_8,
		 "Rotr of 0x96 by 4 should be 0x69.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x97_8> :: value == x79_8,
		 "Rotr of 0x97 by 4 should be 0x79.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x98_8> :: value == x89_8,
		 "Rotr of 0x98 by 4 should be 0x89.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x99_8> :: value == x99_8,
		 "Rotr of 0x99 by 4 should be 0x99.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x9A_8> :: value == xA9_8,
		 "Rotr of 0x9A by 4 should be 0xA9.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x9B_8> :: value == xB9_8,
		 "Rotr of 0x9B by 4 should be 0xB9.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x9C_8> :: value == xC9_8,
		 "Rotr of 0x9C by 4 should be 0xC9.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x9D_8> :: value == xD9_8,
		 "Rotr of 0x9D by 4 should be 0xD9.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x9E_8> :: value == xE9_8,
		 "Rotr of 0x9E by 4 should be 0xE9.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, x9F_8> :: value == xF9_8,
		 "Rotr of 0x9F by 4 should be 0xF9.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xA0_8> :: value == x0A_8,
		 "Rotr of 0xA0 by 4 should be 0x0A.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xA1_8> :: value == x1A_8,
		 "Rotr of 0xA1 by 4 should be 0x1A.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xA2_8> :: value == x2A_8,
		 "Rotr of 0xA2 by 4 should be 0x2A.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xA3_8> :: value == x3A_8,
		 "Rotr of 0xA3 by 4 should be 0x3A.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xA4_8> :: value == x4A_8,
		 "Rotr of 0xA4 by 4 should be 0x4A.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xA5_8> :: value == x5A_8,
		 "Rotr of 0xA5 by 4 should be 0x5A.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xA6_8> :: value == x6A_8,
		 "Rotr of 0xA6 by 4 should be 0x6A.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xA7_8> :: value == x7A_8,
		 "Rotr of 0xA7 by 4 should be 0x7A.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xA8_8> :: value == x8A_8,
		 "Rotr of 0xA8 by 4 should be 0x8A.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xA9_8> :: value == x9A_8,
		 "Rotr of 0xA9 by 4 should be 0x9A.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xAA_8> :: value == xAA_8,
		 "Rotr of 0xAA by 4 should be 0xAA.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xAB_8> :: value == xBA_8,
		 "Rotr of 0xAB by 4 should be 0xBA.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xAC_8> :: value == xCA_8,
		 "Rotr of 0xAC by 4 should be 0xCA.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xAD_8> :: value == xDA_8,
		 "Rotr of 0xAD by 4 should be 0xDA.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xAE_8> :: value == xEA_8,
		 "Rotr of 0xAE by 4 should be 0xEA.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xAF_8> :: value == xFA_8,
		 "Rotr of 0xAF by 4 should be 0xFA.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xB0_8> :: value == x0B_8,
		 "Rotr of 0xB0 by 4 should be 0x0B.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xB1_8> :: value == x1B_8,
		 "Rotr of 0xB1 by 4 should be 0x1B.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xB2_8> :: value == x2B_8,
		 "Rotr of 0xB2 by 4 should be 0x2B.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xB3_8> :: value == x3B_8,
		 "Rotr of 0xB3 by 4 should be 0x3B.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xB4_8> :: value == x4B_8,
		 "Rotr of 0xB4 by 4 should be 0x4B.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xB5_8> :: value == x5B_8,
		 "Rotr of 0xB5 by 4 should be 0x5B.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xB6_8> :: value == x6B_8,
		 "Rotr of 0xB6 by 4 should be 0x6B.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xB7_8> :: value == x7B_8,
		 "Rotr of 0xB7 by 4 should be 0x7B.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xB8_8> :: value == x8B_8,
		 "Rotr of 0xB8 by 4 should be 0x8B.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xB9_8> :: value == x9B_8,
		 "Rotr of 0xB9 by 4 should be 0x9B.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xBA_8> :: value == xAB_8,
		 "Rotr of 0xBA by 4 should be 0xAB.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xBB_8> :: value == xBB_8,
		 "Rotr of 0xBB by 4 should be 0xBB.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xBC_8> :: value == xCB_8,
		 "Rotr of 0xBC by 4 should be 0xCB.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xBD_8> :: value == xDB_8,
		 "Rotr of 0xBD by 4 should be 0xDB.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xBE_8> :: value == xEB_8,
		 "Rotr of 0xBE by 4 should be 0xEB.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xBF_8> :: value == xFB_8,
		 "Rotr of 0xBF by 4 should be 0xFB.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xC0_8> :: value == x0C_8,
		 "Rotr of 0xC0 by 4 should be 0x0C.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xC1_8> :: value == x1C_8,
		 "Rotr of 0xC1 by 4 should be 0x1C.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xC2_8> :: value == x2C_8,
		 "Rotr of 0xC2 by 4 should be 0x2C.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xC3_8> :: value == x3C_8,
		 "Rotr of 0xC3 by 4 should be 0x3C.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xC4_8> :: value == x4C_8,
		 "Rotr of 0xC4 by 4 should be 0x4C.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xC5_8> :: value == x5C_8,
		 "Rotr of 0xC5 by 4 should be 0x5C.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xC6_8> :: value == x6C_8,
		 "Rotr of 0xC6 by 4 should be 0x6C.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xC7_8> :: value == x7C_8,
		 "Rotr of 0xC7 by 4 should be 0x7C.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xC8_8> :: value == x8C_8,
		 "Rotr of 0xC8 by 4 should be 0x8C.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xC9_8> :: value == x9C_8,
		 "Rotr of 0xC9 by 4 should be 0x9C.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xCA_8> :: value == xAC_8,
		 "Rotr of 0xCA by 4 should be 0xAC.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xCB_8> :: value == xBC_8,
		 "Rotr of 0xCB by 4 should be 0xBC.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xCC_8> :: value == xCC_8,
		 "Rotr of 0xCC by 4 should be 0xCC.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xCD_8> :: value == xDC_8,
		 "Rotr of 0xCD by 4 should be 0xDC.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xCE_8> :: value == xEC_8,
		 "Rotr of 0xCE by 4 should be 0xEC.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xCF_8> :: value == xFC_8,
		 "Rotr of 0xCF by 4 should be 0xFC.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xD0_8> :: value == x0D_8,
		 "Rotr of 0xD0 by 4 should be 0x0D.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xD1_8> :: value == x1D_8,
		 "Rotr of 0xD1 by 4 should be 0x1D.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xD2_8> :: value == x2D_8,
		 "Rotr of 0xD2 by 4 should be 0x2D.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xD3_8> :: value == x3D_8,
		 "Rotr of 0xD3 by 4 should be 0x3D.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xD4_8> :: value == x4D_8,
		 "Rotr of 0xD4 by 4 should be 0x4D.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xD5_8> :: value == x5D_8,
		 "Rotr of 0xD5 by 4 should be 0x5D.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xD6_8> :: value == x6D_8,
		 "Rotr of 0xD6 by 4 should be 0x6D.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xD7_8> :: value == x7D_8,
		 "Rotr of 0xD7 by 4 should be 0x7D.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xD8_8> :: value == x8D_8,
		 "Rotr of 0xD8 by 4 should be 0x8D.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xD9_8> :: value == x9D_8,
		 "Rotr of 0xD9 by 4 should be 0x9D.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xDA_8> :: value == xAD_8,
		 "Rotr of 0xDA by 4 should be 0xAD.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xDB_8> :: value == xBD_8,
		 "Rotr of 0xDB by 4 should be 0xBD.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xDC_8> :: value == xCD_8,
		 "Rotr of 0xDC by 4 should be 0xCE.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xDD_8> :: value == xDD_8,
		 "Rotr of 0xDD by 4 should be 0xDD.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xDE_8> :: value == xED_8,
		 "Rotr of 0xDE by 4 should be 0xED.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xDF_8> :: value == xFD_8,
		 "Rotr of 0xDF by 4 should be 0xFD.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xE0_8> :: value == x0E_8,
		 "Rotr of 0xE0 by 4 should be 0x0E.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xE1_8> :: value == x1E_8,
		 "Rotr of 0xE1 by 4 should be 0x1E.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xE2_8> :: value == x2E_8,
		 "Rotr of 0xE2 by 4 should be 0x2E.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xE3_8> :: value == x3E_8,
		 "Rotr of 0xE3 by 4 should be 0x3E.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xE4_8> :: value == x4E_8,
		 "Rotr of 0xE4 by 4 should be 0x4E.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xE5_8> :: value == x5E_8,
		 "Rotr of 0xE5 by 4 should be 0x5E.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xE6_8> :: value == x6E_8,
		 "Rotr of 0xE6 by 4 should be 0x6E.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xE7_8> :: value == x7E_8,
		 "Rotr of 0xE7 by 4 should be 0x7E.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xE8_8> :: value == x8E_8,
		 "Rotr of 0xE8 by 4 should be 0x8E.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xE9_8> :: value == x9E_8,
		 "Rotr of 0xE9 by 4 should be 0x9E.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xEA_8> :: value == xAE_8,
		 "Rotr of 0xEA by 4 should be 0xAE.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xEB_8> :: value == xBE_8,
		 "Rotr of 0xEB by 4 should be 0xBE.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xEC_8> :: value == xCE_8,
		 "Rotr of 0xEC by 4 should be 0xCE.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xED_8> :: value == xDE_8,
		 "Rotr of 0xED by 4 should be 0xDE.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xEE_8> :: value == xEE_8,
		 "Rotr of 0xEE by 4 should be 0xEE.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xEF_8> :: value == xFE_8,
		 "Rotr of 0xEF by 4 should be 0xFE.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xF0_8> :: value == x0F_8,
		 "Rotr of 0xF0 by 4 should be 0x0F.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xF1_8> :: value == x1F_8,
		 "Rotr of 0xF1 by 4 should be 0x1F.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xF2_8> :: value == x2F_8,
		 "Rotr of 0xF2 by 4 should be 0x2F.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xF3_8> :: value == x3F_8,
		 "Rotr of 0xF3 by 4 should be 0x3F.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xF4_8> :: value == x4F_8,
		 "Rotr of 0xF4 by 4 should be 0x4F.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xF5_8> :: value == x5F_8,
		 "Rotr of 0xF5 by 4 should be 0x5F.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xF6_8> :: value == x6F_8,
		 "Rotr of 0xF6 by 4 should be 0x6F.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xF7_8> :: value == x7F_8,
		 "Rotr of 0xF7 by 4 should be 0x7F.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xF8_8> :: value == x8F_8,
		 "Rotr of 0xF8 by 4 should be 0x8F.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xF9_8> :: value == x9F_8,
		 "Rotr of 0xF9 by 4 should be 0x9F.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xFA_8> :: value == xAF_8,
		 "Rotr of 0xFA by 4 should be 0xAF.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xFB_8> :: value == xBF_8,
		 "Rotr of 0xFB by 4 should be 0xBF.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xFC_8> :: value == xCF_8,
		 "Rotr of 0xFC by 4 should be 0xCF.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xFD_8> :: value == xDF_8,
		 "Rotr of 0xFD by 4 should be 0xDF.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xFE_8> :: value == xEF_8,
		 "Rotr of 0xFE by 4 should be 0xEF.");
 static_assert(crap :: rotrValue <4u, std :: uint8_t, xFF_8> :: value == xFF_8,
		 "Rotr of 0xFF by 4 should be 0xFF.");

}

int main()
{
 test_uint8_t();
 return EXIT_SUCCESS;
}
