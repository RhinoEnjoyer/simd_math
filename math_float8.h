#pragma once
#include "./math_basic_macros.h"
#include "./math_float4.h"

//INT8                              //76543210
#define FLOAT8_ALL_EQUAL            Ob11111111
#define FLOAT8_76543210_NOT_EQUAL   Ob00000000
#define FLOAT8_7654321_NOT_EQUAL    Ob00000001
#define FLOAT8_7654320_NOT_EQUAL    Ob00000010
#define FLOAT8_765432_NOT_EQUAL     Ob00000011
#define FLOAT8_7654310_NOT_EQUAL    Ob00000100
#define FLOAT8_765431_NOT_EQUAL     Ob00000101
#define FLOAT8_765430_NOT_EQUAL     Ob00000110
#define FLOAT8_76543_NOT_EQUAL      Ob00000111
#define FLOAT8_7654210_NOT_EQUAL    Ob00001000
#define FLOAT8_765421_NOT_EQUAL     Ob00001001
#define FLOAT8_765420_NOT_EQUAL     Ob00001010
#define FLOAT8_76542_NOT_EQUAL      Ob00001011
#define FLOAT8_765410_NOT_EQUAL     Ob00001100
#define FLOAT8_76541_NOT_EQUAL      Ob00001101
#define FLOAT8_76540_NOT_EQUAL      Ob00001110
#define FLOAT8_7654_NOT_EQUAL       Ob00001111
#define FLOAT8_7653210_NOT_EQUAL    Ob00010000
#define FLOAT8_765321_NOT_EQUAL     Ob00010001
#define FLOAT8_765320_NOT_EQUAL     Ob00010010
#define FLOAT8_76532_NOT_EQUAL      Ob00010011
#define FLOAT8_765310_NOT_EQUAL     Ob00010100
#define FLOAT8_76531_NOT_EQUAL      Ob00010101
#define FLOAT8_76530_NOT_EQUAL      Ob00010110
#define FLOAT8_7653_NOT_EQUAL       Ob00010111
#define FLOAT8_765210_NOT_EQUAL     Ob00011000
#define FLOAT8_76521_NOT_EQUAL      Ob00011001
#define FLOAT8_76520_NOT_EQUAL      Ob00011010
#define FLOAT8_7652_NOT_EQUAL       Ob00011011
#define FLOAT8_76510_NOT_EQUAL      Ob00011100
#define FLOAT8_7651_NOT_EQUAL       Ob00011101
#define FLOAT8_7650_NOT_EQUAL       Ob00011110
#define FLOAT8_765_NOT_EQUAL        Ob00011111
#define FLOAT8_7643210_NOT_EQUAL    Ob00100000
#define FLOAT8_764321_NOT_EQUAL     Ob00100001
#define FLOAT8_764320_NOT_EQUAL     Ob00100010
#define FLOAT8_76432_NOT_EQUAL      Ob00100011
#define FLOAT8_764310_NOT_EQUAL     Ob00100100
#define FLOAT8_76431_NOT_EQUAL      Ob00100101
#define FLOAT8_76430_NOT_EQUAL      Ob00100110
#define FLOAT8_7643_NOT_EQUAL       Ob00100111
#define FLOAT8_764210_NOT_EQUAL     Ob00101000
#define FLOAT8_76421_NOT_EQUAL      Ob00101001
#define FLOAT8_76420_NOT_EQUAL      Ob00101010
#define FLOAT8_7642_NOT_EQUAL       Ob00101011
#define FLOAT8_76410_NOT_EQUAL      Ob00101100
#define FLOAT8_7641_NOT_EQUAL       Ob00101101
#define FLOAT8_7640_NOT_EQUAL       Ob00101110
#define FLOAT8_764_NOT_EQUAL        Ob00101111
#define FLOAT8_763210_NOT_EQUAL     Ob00110000
#define FLOAT8_76321_NOT_EQUAL      Ob00110001
#define FLOAT8_76320_NOT_EQUAL      Ob00110010
#define FLOAT8_7632_NOT_EQUAL       Ob00110011
#define FLOAT8_76310_NOT_EQUAL      Ob00110100
#define FLOAT8_7631_NOT_EQUAL       Ob00110101
#define FLOAT8_7630_NOT_EQUAL       Ob00110110
#define FLOAT8_763_NOT_EQUAL        Ob00110111
#define FLOAT8_76210_NOT_EQUAL      Ob00111000
#define FLOAT8_7621_NOT_EQUAL       Ob00111001
#define FLOAT8_7620_NOT_EQUAL       Ob00111010
#define FLOAT8_762_NOT_EQUAL        Ob00111011
#define FLOAT8_7610_NOT_EQUAL       Ob00111100
#define FLOAT8_761_NOT_EQUAL        Ob00111101
#define FLOAT8_760_NOT_EQUAL        Ob00111110
#define FLOAT8_76_NOT_EQUAL         Ob00111111
#define FLOAT8_7543210_NOT_EQUAL    Ob01000000
#define FLOAT8_754321_NOT_EQUAL     Ob01000001
#define FLOAT8_754320_NOT_EQUAL     Ob01000010
#define FLOAT8_75432_NOT_EQUAL      Ob01000011
#define FLOAT8_754310_NOT_EQUAL     Ob01000100
#define FLOAT8_75431_NOT_EQUAL      Ob01000101
#define FLOAT8_75430_NOT_EQUAL      Ob01000110
#define FLOAT8_7543_NOT_EQUAL       Ob01000111
#define FLOAT8_754210_NOT_EQUAL     Ob01001000
#define FLOAT8_75421_NOT_EQUAL      Ob01001001
#define FLOAT8_75420_NOT_EQUAL      Ob01001010
#define FLOAT8_7542_NOT_EQUAL       Ob01001011
#define FLOAT8_75410_NOT_EQUAL      Ob01001100
#define FLOAT8_7541_NOT_EQUAL       Ob01001101
#define FLOAT8_7540_NOT_EQUAL       Ob01001110
#define FLOAT8_754_NOT_EQUAL        Ob01001111
#define FLOAT8_753210_NOT_EQUAL     Ob01010000
#define FLOAT8_75321_NOT_EQUAL      Ob01010001
#define FLOAT8_75320_NOT_EQUAL      Ob01010010
#define FLOAT8_7532_NOT_EQUAL       Ob01010011
#define FLOAT8_75310_NOT_EQUAL      Ob01010100
#define FLOAT8_7531_NOT_EQUAL       Ob01010101
#define FLOAT8_7530_NOT_EQUAL       Ob01010110
#define FLOAT8_753_NOT_EQUAL        Ob01010111
#define FLOAT8_75210_NOT_EQUAL      Ob01011000
#define FLOAT8_7521_NOT_EQUAL       Ob01011001
#define FLOAT8_7520_NOT_EQUAL       Ob01011010
#define FLOAT8_752_NOT_EQUAL        Ob01011011
#define FLOAT8_7510_NOT_EQUAL       Ob01011100
#define FLOAT8_751_NOT_EQUAL        Ob01011101
#define FLOAT8_750_NOT_EQUAL        Ob01011110
#define FLOAT8_75_NOT_EQUAL         Ob01011111
#define FLOAT8_743210_NOT_EQUAL     Ob01100000
#define FLOAT8_74321_NOT_EQUAL      Ob01100001
#define FLOAT8_74320_NOT_EQUAL      Ob01100010
#define FLOAT8_7432_NOT_EQUAL       Ob01100011
#define FLOAT8_74310_NOT_EQUAL      Ob01100100
#define FLOAT8_7431_NOT_EQUAL       Ob01100101
#define FLOAT8_7430_NOT_EQUAL       Ob01100110
#define FLOAT8_743_NOT_EQUAL        Ob01100111
#define FLOAT8_74210_NOT_EQUAL      Ob01101000
#define FLOAT8_7421_NOT_EQUAL       Ob01101001
#define FLOAT8_7420_NOT_EQUAL       Ob01101010
#define FLOAT8_742_NOT_EQUAL        Ob01101011
#define FLOAT8_7410_NOT_EQUAL       Ob01101100
#define FLOAT8_741_NOT_EQUAL        Ob01101101
#define FLOAT8_740_NOT_EQUAL        Ob01101110
#define FLOAT8_74_NOT_EQUAL         Ob01101111
#define FLOAT8_73210_NOT_EQUAL      Ob01110000
#define FLOAT8_7321_NOT_EQUAL       Ob01110001
#define FLOAT8_7320_NOT_EQUAL       Ob01110010
#define FLOAT8_732_NOT_EQUAL        Ob01110011
#define FLOAT8_7310_NOT_EQUAL       Ob01110100
#define FLOAT8_731_NOT_EQUAL        Ob01110101
#define FLOAT8_730_NOT_EQUAL        Ob01110110
#define FLOAT8_73_NOT_EQUAL         Ob01110111
#define FLOAT8_7210_NOT_EQUAL       Ob01111000
#define FLOAT8_721_NOT_EQUAL        Ob01111001
#define FLOAT8_720_NOT_EQUAL        Ob01111010
#define FLOAT8_72_NOT_EQUAL         Ob01111011
#define FLOAT8_710_NOT_EQUAL        Ob01111100
#define FLOAT8_71_NOT_EQUAL         Ob01111101
#define FLOAT8_70_NOT_EQUAL         Ob01111110
#define FLOAT8_7_NOT_EQUAL          Ob01111111
#define FLOAT8_6543210_NOT_EQUAL    Ob10000000
#define FLOAT8_654321_NOT_EQUAL     Ob10000001
#define FLOAT8_654320_NOT_EQUAL     Ob10000010
#define FLOAT8_65432_NOT_EQUAL      Ob10000011
#define FLOAT8_654310_NOT_EQUAL     Ob10000100
#define FLOAT8_65431_NOT_EQUAL      Ob10000101
#define FLOAT8_65430_NOT_EQUAL      Ob10000110
#define FLOAT8_6543_NOT_EQUAL       Ob10000111
#define FLOAT8_654210_NOT_EQUAL     Ob10001000
#define FLOAT8_65421_NOT_EQUAL      Ob10001001
#define FLOAT8_65420_NOT_EQUAL      Ob10001010
#define FLOAT8_6542_NOT_EQUAL       Ob10001011
#define FLOAT8_65410_NOT_EQUAL      Ob10001100
#define FLOAT8_6541_NOT_EQUAL       Ob10001101
#define FLOAT8_6540_NOT_EQUAL       Ob10001110
#define FLOAT8_654_NOT_EQUAL        Ob10001111
#define FLOAT8_653210_NOT_EQUAL     Ob10010000
#define FLOAT8_65321_NOT_EQUAL      Ob10010001
#define FLOAT8_65320_NOT_EQUAL      Ob10010010
#define FLOAT8_6532_NOT_EQUAL       Ob10010011
#define FLOAT8_65310_NOT_EQUAL      Ob10010100
#define FLOAT8_6531_NOT_EQUAL       Ob10010101
#define FLOAT8_6530_NOT_EQUAL       Ob10010110
#define FLOAT8_653_NOT_EQUAL        Ob10010111
#define FLOAT8_65210_NOT_EQUAL      Ob10011000
#define FLOAT8_6521_NOT_EQUAL       Ob10011001
#define FLOAT8_6520_NOT_EQUAL       Ob10011010
#define FLOAT8_652_NOT_EQUAL        Ob10011011
#define FLOAT8_6510_NOT_EQUAL       Ob10011100
#define FLOAT8_651_NOT_EQUAL        Ob10011101
#define FLOAT8_650_NOT_EQUAL        Ob10011110
#define FLOAT8_65_NOT_EQUAL         Ob10011111
#define FLOAT8_643210_NOT_EQUAL     Ob10100000
#define FLOAT8_64321_NOT_EQUAL      Ob10100001
#define FLOAT8_64320_NOT_EQUAL      Ob10100010
#define FLOAT8_6432_NOT_EQUAL       Ob10100011
#define FLOAT8_64310_NOT_EQUAL      Ob10100100
#define FLOAT8_6431_NOT_EQUAL       Ob10100101
#define FLOAT8_6430_NOT_EQUAL       Ob10100110
#define FLOAT8_643_NOT_EQUAL        Ob10100111
#define FLOAT8_64210_NOT_EQUAL      Ob10101000
#define FLOAT8_6421_NOT_EQUAL       Ob10101001
#define FLOAT8_6420_NOT_EQUAL       Ob10101010
#define FLOAT8_642_NOT_EQUAL        Ob10101011
#define FLOAT8_6410_NOT_EQUAL       Ob10101100
#define FLOAT8_641_NOT_EQUAL        Ob10101101
#define FLOAT8_640_NOT_EQUAL        Ob10101110
#define FLOAT8_64_NOT_EQUAL         Ob10101111
#define FLOAT8_63210_NOT_EQUAL      Ob10110000
#define FLOAT8_6321_NOT_EQUAL       Ob10110001
#define FLOAT8_6320_NOT_EQUAL       Ob10110010
#define FLOAT8_632_NOT_EQUAL        Ob10110011
#define FLOAT8_6310_NOT_EQUAL       Ob10110100
#define FLOAT8_631_NOT_EQUAL        Ob10110101
#define FLOAT8_630_NOT_EQUAL        Ob10110110
#define FLOAT8_63_NOT_EQUAL         Ob10110111
#define FLOAT8_6210_NOT_EQUAL       Ob10111000
#define FLOAT8_621_NOT_EQUAL        Ob10111001
#define FLOAT8_620_NOT_EQUAL        Ob10111010
#define FLOAT8_62_NOT_EQUAL         Ob10111011
#define FLOAT8_610_NOT_EQUAL        Ob10111100
#define FLOAT8_61_NOT_EQUAL         Ob10111101
#define FLOAT8_60_NOT_EQUAL         Ob10111110
#define FLOAT8_6_NOT_EQUAL          Ob10111111
#define FLOAT8_543210_NOT_EQUAL     Ob11000000
#define FLOAT8_54321_NOT_EQUAL      Ob11000001
#define FLOAT8_54320_NOT_EQUAL      Ob11000010
#define FLOAT8_5432_NOT_EQUAL       Ob11000011
#define FLOAT8_54310_NOT_EQUAL      Ob11000100
#define FLOAT8_5431_NOT_EQUAL       Ob11000101
#define FLOAT8_5430_NOT_EQUAL       Ob11000110
#define FLOAT8_543_NOT_EQUAL        Ob11000111
#define FLOAT8_54210_NOT_EQUAL      Ob11001000
#define FLOAT8_5421_NOT_EQUAL       Ob11001001
#define FLOAT8_5420_NOT_EQUAL       Ob11001010
#define FLOAT8_542_NOT_EQUAL        Ob11001011
#define FLOAT8_5410_NOT_EQUAL       Ob11001100
#define FLOAT8_541_NOT_EQUAL        Ob11001101
#define FLOAT8_540_NOT_EQUAL        Ob11001110
#define FLOAT8_54_NOT_EQUAL         Ob11001111
#define FLOAT8_53210_NOT_EQUAL      Ob11010000
#define FLOAT8_5321_NOT_EQUAL       Ob11010001
#define FLOAT8_5320_NOT_EQUAL       Ob11010010
#define FLOAT8_532_NOT_EQUAL        Ob11010011
#define FLOAT8_5310_NOT_EQUAL       Ob11010100
#define FLOAT8_531_NOT_EQUAL        Ob11010101
#define FLOAT8_530_NOT_EQUAL        Ob11010110
#define FLOAT8_53_NOT_EQUAL         Ob11010111
#define FLOAT8_5210_NOT_EQUAL       Ob11011000
#define FLOAT8_521_NOT_EQUAL        Ob11011001
#define FLOAT8_520_NOT_EQUAL        Ob11011010
#define FLOAT8_52_NOT_EQUAL         Ob11011011
#define FLOAT8_510_NOT_EQUAL        Ob11011100
#define FLOAT8_51_NOT_EQUAL         Ob11011101
#define FLOAT8_50_NOT_EQUAL         Ob11011110
#define FLOAT8_5_NOT_EQUAL          Ob11011111
#define FLOAT8_43210_NOT_EQUAL      Ob11100000
#define FLOAT8_4321_NOT_EQUAL       Ob11100001
#define FLOAT8_4320_NOT_EQUAL       Ob11100010
#define FLOAT8_432_NOT_EQUAL        Ob11100011
#define FLOAT8_4310_NOT_EQUAL       Ob11100100
#define FLOAT8_431_NOT_EQUAL        Ob11100101
#define FLOAT8_430_NOT_EQUAL        Ob11100110
#define FLOAT8_43_NOT_EQUAL         Ob11100111
#define FLOAT8_4210_NOT_EQUAL       Ob11101000
#define FLOAT8_421_NOT_EQUAL        Ob11101001
#define FLOAT8_420_NOT_EQUAL        Ob11101010
#define FLOAT8_42_NOT_EQUAL         Ob11101011
#define FLOAT8_410_NOT_EQUAL        Ob11101100
#define FLOAT8_41_NOT_EQUAL         Ob11101101
#define FLOAT8_40_NOT_EQUAL         Ob11101110
#define FLOAT8_4_NOT_EQUAL          Ob11101111
#define FLOAT8_3210_NOT_EQUAL       Ob11110000
#define FLOAT8_321_NOT_EQUAL        Ob11110001
#define FLOAT8_320_NOT_EQUAL        Ob11110010
#define FLOAT8_32_NOT_EQUAL         Ob11110011
#define FLOAT8_310_NOT_EQUAL        Ob11110100
#define FLOAT8_31_NOT_EQUAL         Ob11110101
#define FLOAT8_30_NOT_EQUAL         Ob11110110
#define FLOAT8_3_NOT_EQUAL          Ob11110111
#define FLOAT8_210_NOT_EQUAL        Ob11111000
#define FLOAT8_21_NOT_EQUAL         Ob11111001
#define FLOAT8_20_NOT_EQUAL         Ob11111010
#define FLOAT8_2_NOT_EQUAL          Ob11111011
#define FLOAT8_10_NOT_EQUAL         Ob11111100
#define FLOAT8_1_NOT_EQUAL          Ob11111101
#define FLOAT8_0_NOT_EQUAL          Ob11111110

typedef __m256 float8;

attribute((__always_inline__))
inline float float8_element(const float4 a,short i)
{ return a[i]; }

#define float8_set(x,y,z,w)             _mm256_set_ps(w,z,y,x)
#define float8_setzero()                _mm256_setzero_ps()
#define float8_setone(x)                _mm256_set1_ps(1)
#define float8_set1(x)                  _mm256_set1_ps(x)
#define float8_seta(a)                  _mm256_loadu_ps(a)
#define float8_store(f,v)               _mm256_storeu_ps(f,v)
#define float8_and(f,m)                 _mm256_and_ps(f,m)
#define float8_permute(a,SHUFFLE_MASK)  _mm256_permute_ps(a, _MM_SHUFFLE SHUFFLE_MASK )
#define float8_broadcast1(f)            _mm256_broadcast_ps(f)
