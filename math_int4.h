#pragma once

#include "math_basic_macros.h"

#define INT4_EQUAL         16
#define INT4_ALL_NOT_EQUAL  0
#define INT4_PURE_PREFIX  SSE_PURE_PREFIX inline int4
#define INT4_CONST_PREFIX SSE_CONST_PREFIX inline int4
#define INT4_DEFAULT_EPSILON 1.e-8f

inline uint32_t uint_pack4_ubytes(uint8_t c[4])
{ return *((uint32_t*)c); }

inline void uint_unpack4_ubytes(uint32_t i,uint8_t out_c[4])
{ 
    out_c[0] = (uint8_t)((i >>  0));
    out_c[1] = (uint8_t)((i >>  8));
    out_c[2] = (uint8_t)((i >> 16));
    out_c[3] = (uint8_t)((i >> 24));
}

//4xint
typedef __m128i int4;

//Need to use () into the SHUFFLE_MASK
#define int4_permute(a,SHUFFLE_MASK) _mm_permute_epi32(a, _MM_SHUFFLE SHUFFLE_MASK );

attribute((__always_inline__,__const__))
#define int4_element(a,i) _mm_extract_epi32(a,i)

#define int4_set(x,y,z,w)   _mm_set_epi32(w,z,y,x)
#define uint4_set(x,y,z,w)  _mm_set_u32(w,z,y,x)
#define int4_set0()         _mm_set1_epi32(0)
#define int4_set1(x)        _mm_set1_epi32(x)
#define int4_seta(a)        _mm_load_epi32(a)
#define int4_store(f,v)     _mm_store_epi32(f,v)

//by using const we are cheating but still
attribute((__always_inline__,__const__))
inline int32_t int4_cmp (const int4 a, const int4 b)
{
    const __m128i cmp = _mm_cmpeq_epi32(a,b);
    return _mm_popcnt_u32((int)_mm_movemask_epi8(cmp) );
}

/*A+B*/\
#define int4_add(a,b) _mm_add_epi32(a,b)
/*A-B*/
#define int4_sub(a,b) _mm_sub_epi32(a,b)
/*AB*/
#define int4_mul(a,b) _mm_mul_epi32(a,b)
#define int4_mul1(a,b) _mm_mul_epi32(a,_mm_set1_epi32(b))
/*A/B*/
#define int4_div(a,b) _mm_div_epi32(a,b)
/*(AB)+C*/
#define int4_fmadd(a,b,c) _mm_fmadd_epi32(a,b,c)
/*(AB)-C*/
#define int4_fmsub(a,b,c) _mm_fmsub_epi32(a,b,c)

INT4_PURE_PREFIX
int4_pack16_ubytes(uint8_t c[16])
{ return int4_seta((int*)c); }

INT4_PURE_PREFIX
int4_pack16_bytes(int8_t c[16]) 
{ return int4_seta((int*)c); }

__attribute__((__always_inline__, __target__("sse"))) inline void
int4_unpack16_ubytes(int4 a,uint8_t out_c[16]) 
{ int4_store((int*)out_c,a); }

__attribute__((__always_inline__, __target__("sse"))) inline void
int4_unpack16_bytes(int4 a,int8_t out_c[16]) 
{ int4_store((int*)out_c,a); }


#define int4_print(a)   printf("x:%i,y:%i,z:%i,w:%i",a[0],a[1],a[2],a[3]);
#define int4_println(a) printf("x:%i,y:%i,z:%i,w:%i\n",a[0],a[1],a[2],a[3]);