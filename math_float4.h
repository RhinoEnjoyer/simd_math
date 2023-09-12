#pragma once

#include "math_basic_macros.h"
#include <stdio.h>

#define FLOAT4_TRUE  0
#define FLOAT4_FALSE 1

//INT8                          //DEAD3210
#define FLOAT4_EQUAL            0b00001111 //15
#define FLOAT4_0_NOT_EQUAL      0b00001110 //14
#define FLOAT4_01_NOT_EQUAL     0b00001100 //12
#define FLOAT4_012_NOT_EQUAL    0b00001000 //8
#define FLOAT4_0123_NOT_EQUAL   0b00000000 //0
#define FLOAT4_013_NOT_EQUAL    0b00000100 //4
#define FLOAT4_02_NOT_EQUAL     0b00001010 //10
#define FLOAT4_03_NOT_EQUAL     0b00000110 //6
#define FLOAT4_023_NOT_EQUAL    0b00000010 //2
#define FLOAT4_1_NOT_EQUAL      0b00001101 //13
#define FLOAT4_12_NOT_EQUAL     0b00001001 //9
#define FLOAT4_13_NOT_EQUAL     0b00000101 //5
#define FLOAT4_123_NOT_EQUAL    0b00000001 //1
#define FLOAT4_2_NOT_EQUAL      0b00001011 //11
#define FLOAT4_23_NOT_EQUAL     0b00000011 //3
#define FLOAT4_3_NOT_EQUAL      0b00000111 //7
#define FLOAT4_ALL_NOT_EQUAL    FLOAT4_0123_NOT_EQUAL


#define FLOAT4_PURE_PREFIX  SSE_PURE_PREFIX inline float4
#define FLOAT4_CONST_PREFIX SSE_CONST_PREFIX inline float4

#define FLOAT4_DEFAULT_EPSILON 1.e-8f

typedef __m128 float4;
typedef __m128 float3;
typedef __m128 float2;

//Need to use () into the SHUFFLE_MASK

attribute((__always_inline__))
inline float float4_element(const float4 a,short i)
{ return a[i]; }

#define float4_set(x,y,z,w) _mm_set_ps(w,z,y,x)
#define float3_set(x,y,z)   _mm_set_ps(0.0f,z,y,x)
#define float2_set(x,y)     _mm_set_ps(0.0f,0.0f,y,x)

#define float4_setzero()    _mm_setzero_ps()
#define float3_setzero()    _mm_setzero_ps()
#define float2_setzero()    _mm_setzero_ps()

#define float4_setone()    _mm_set1_ps(1)
#define float3_setone()    _mm_set1_ps(1)
#define float2_setone()    _mm_set1_ps(1)

#define float4_set1(x)      _mm_set1_ps(x)
#define float3_set1(x)      _mm_set1_ps(x)
#define float2_set1(x)      _mm_set1_ps(x)

#define float4_seta(a)      _mm_loadu_ps(a)
#define float3_seta(a)      float3_set(a[0],a[1],a[2])
#define float2_seta(a)      float2_set(a[0],a[1])

#define float4_store(f,v)   _mm_storeu_ps(f,v)
#define float4_and(f,m)     _mm_and_ps(f,m)
#define float4_permute(a,SHUFFLE_MASK) _mm_permute_ps(a, _MM_SHUFFLE SHUFFLE_MASK )
#define float4_broadcast1(f) _mm_broadcast_ps(f)
// // //SEE: https://stackoverflow.com/questions/6042399/how-to-compare-m128-types
//by using const we are cheating but still
attribute((__always_inline__,__const__))
inline int8_t float4_cmp (const float4 a, const float4 b, float e)
{
    const __m128 abs_diff = _mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_sub_ps(a, b));
    return (int8_t)_mm_movemask_ps(_mm_cmplt_ps(abs_diff, _mm_set1_ps(e)));
}

#define FLOAT_MASK(x,y,z,w) 0b1111##w##z##y##x
#define FLOAT4_MASK FLOAT_MASK(1,1,1,1)
#define FLOAT3_MASK FLOAT_MASK(1,1,1,0)
#define FLOAT2_MASK FLOAT_MASK(1,1,0,0)

/*Get the lower 32bits of a A*/
#define float4_get0f(a) _mm_cvtss_f32(a)
#define float3_get0f(a) _mm_cvtss_f32(a)
#define float2_get0f(a) _mm_cvtss_f32(a)

/*A+B*/
#define float4_add(a,b) _mm_add_ps(a,b)
#define float3_add(a,b) float4_add(a,b)
#define float2_add(a,b) float4_add(a,b)

/*A-B*/
#define float4_sub(a,b) _mm_sub_ps(a,b)
#define float3_sub(a,b) float4_sub(a,b)
#define float2_sub(a,b) float4_sub(a,b)

/*AB*/
#define float4_mul(a,b) _mm_mul_ps(a,b)
#define float3_mul(a,b) float4_mul(a,b)
#define float2_mul(a,b) float4_mul(a,b)

/*A*c*/
#define float4_mul1(a,b)  _mm_mul_ps(a,_mm_set1_ps(b))
#define float3_mul1(a,b)  float4_mul1(a,b)
#define float2_mul1(a,b)  float4_mul1(a,b)

/*sqrt A*/
#define float4_sqrt(a)  _mm_sqrt_ps(a)
#define float3_sqrt(a)  _mm_sqrt_ps(a)
#define float2_sqrt(a)  _mm_sqrt_ps(a)

/*A/B*/
#define float4_div(a,b) _mm_div_ps(a,b)
#define float3_div(a,b) float4_div(a,b)
#define float2_div(a,b) float4_div(a,b)

/*(AB)+C*/
#define float4_fmadd(a,b,c) _mm_fmadd_ps(a,b,c)
#define float3_fmadd(a,b,c) float4_fmadd(a,b,c)
#define float2_fmadd(a,b,c) float4_fmadd(a,b,c)

/*(AB)-C*/
#define float4_fmsub(a,b,c) _mm_fmsub_ps(a,b,c)
#define float3_fmsub(a,b,c) float4_fmsub(a,b,c)
#define float2_fmsub(a,b,c) float4_fmsub(a,b,c)

/*A.B*/
#define float4_dp_mask(a,b,mask)  _mm_dp_ps(a,b,mask)
#define float3_dp_mask(a,b,mask)  float4_dp_mask(a,b,mask)
#define float2_dp_mask(a,b,mask)  float4_dp_mask(a,b,mask)

#define float4_dp(a,b)  float4_dp_mask(a,b,FLOAT4_MASK)
#define float3_dp(a,b)  float4_dp_mask(a,b,FLOAT3_MASK)
#define float2_dp(a,b)  float4_dp_mask(a,b,FLOAT2_MASK)

#define f32_float4_dp_mask(a,b,mask)  float4_get0f(float4_dp_mask(a,b,mask))
#define f32_float3_dp_mask(a,b,mask)  float3_get0f(float3_dp_mask(a,b,mask))
#define f32_float2_dp_mask(a,b,mask)  float2_get0f(float2_dp_mask(a,b,mask))

#define f32_float4_dp(a,b)  float4_get0f(float4_dp(a,b))
#define f32_float3_dp(a,b)  float3_get0f(float3_dp(a,b))
#define f32_float2_dp(a,b)  float2_get0f(float2_dp(a,b))

/*A distance from B*/
#define float4_dist(a,b)  float4_sqrt(float4_dp(a,b))
#define float3_dist(a,b)  float3_sqrt(float3_dp(a,b))
#define float2_dist(a,b)  float2_sqrt(float2_dp(a,b))

#define f32_float4_dist(a,b)  float4_get0f(float4_sqrt( _mm_dp_ps(a,b,0xFF) ))
#define f32_float3_dist(a,b)  float4_get0f(float3_sqrt( _mm_dp_ps(a,b,0xFF) ))
#define f32_float2_dist(a,b)  float4_get0f(float2_sqrt( _mm_dp_ps(a,b,0xFF) ))


/*||A||**2*/
#define float4_sqlen(a) float4_dp(a,a)
#define float3_sqlen(a) float3_dp(a,a)
#define float2_sqlen(a) float2_dp(a,a)

#define f32_float4_sqlen(a) float4_get0f(float4_sqlen(a))
#define f32_float3_sqlen(a) float4_get0f(float3_sqlen(a))
#define f32_float2_sqlen(a) float4_get0f(float2_sqlen(a))

/*||A||*/
#define float4_len(a) float4_sqrt(float4_sqlen(a))
#define float3_len(a) float3_sqrt(float3_sqlen(a))
#define float2_len(a) float2_sqrt(float2_sqlen(a))

#define f32_float4_len(a) float4_get0f(float4_sqrt( float4_sqlen(a) ))
#define f32_float3_len(a) float3_get0f(float3_sqrt( float3_sqlen(a) ))
#define f32_float2_len(a) float2_get0f(float2_sqrt( float2_sqlen(a) ))

/*A h+ B*/
#define float4_hadd(a,b)  _mm_hadd_ps(a,b)
#define float3_hadd(a,b)  float4_hadd(a,b)
#define float2_hadd(a,b)  float4_hadd(a,b)

#define float4_hsum_mask(a,m) float4_dp_mask(a,float4_set1(1.0f),m)
#define float4_hsum(a)  float4_dp(a,float4_set1(1.0f))
#define float3_hsum(a)  float3_dp(a,float4_set1(1.0f))
#define float2_hsum(a)  float2_dp(a,float4_set1(1.0f))

#define f32_float4_hsum_mask(a,m)   float4_get0f(float4_dp_mask(a,float4_set1(1.0f),m))
#define f32_float4_hsum(a)          float4_get0f(float4_dp(a,float4_set1(1.0f)))
#define f32_float3_hsum(a)          float4_get0f(float3_dp(a,float4_set1(1.0f)))
#define f32_float2_hsum(a)          float4_get0f(float2_dp(a,float4_set1(1.0f)))

// Normalize A
FLOAT4_PURE_PREFIX
float4_norm(const float4 a)
{
  const float4 len = float4_len(a);
  const float4 one = float4_set1(1.0f);
  if( float4_cmp(len,one,FLOAT4_DEFAULT_EPSILON) == FLOAT4_EQUAL ) return a;

  return float4_div(a, len);
}

//AxB
FLOAT4_PURE_PREFIX
float3_cross(const float4 a,const float4 b)
{
  //γ´ = α0*β1 - β0*α1
  //α´ = α1*β2 - β1*α2
  //β´ = α2*β0 - β2*α0

  //Shuffle to match the above
  const float4 sa = float4_permute(a,(3,0,2,1));
  const float4 sb = float4_permute(b,(3,0,2,1));

  const float4 rs = float4_mul(a,sb);
  const float4 ls = float4_mul(b,sa);

  //Shuffle back into place α=1 ,β=2 ,γ=0
  return float4_permute(float4_sub(rs,ls),(3,0,2,1));
}


#define float4_print(a) printf("x:%3.5f,y:%3.5f,z:%3.5f,w:%3.5f",a[0],a[1],a[2],a[3])
#define float3_print(a) printf("x:%3.5f,y:%3.5f,z:%3.5f",a[0],a[1],a[2])
#define float2_print(a) printf("x:%3.5f,y:%3.5f",a[0],a[1])

#define float4_println(a) printf("x:%3.5f,y:%3.5f,z:%3.5f,w:%3.5f\n",a[0],a[1],a[2],a[3])
#define float3_println(a) printf("x:%3.5f,y:%3.5f,z:%3.5f\n",a[0],a[1],a[2])
#define float2_println(a) printf("x:%3.5f,y:%3.5f\n",a[0],a[1])
