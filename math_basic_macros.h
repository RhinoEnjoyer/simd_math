#pragma once
#include <stdint.h>
#include <immintrin.h>

#define alignas(x) __attribute__((aligned(x)))
#define attribute(x) __attribute__(x)
#define SSE_CONST_PREFIX attribute(( __always_inline__,__target__("sse"),pure))
#define SSE_PURE_PREFIX attribute(( __always_inline__,__target__("sse"),__const__))

#define AVX_CONST_PREFIX attribute(( __always_inline__,__target__("avx"),pure))
#define AVX_PURE_PREFIX attribute(( __always_inline__,__target__("avx"),__const__))


typedef int8_t  byte;
typedef uint8_t ubyte;