#pragma once

#include "math_basic_macros.h"

#include "./math_float4.h"
#include <math.h>

#include <stdio.h>

#define MAT4_TRUE  0
#define MAT4_FALSE 1
#define MAT4_EQUAL MAT4_TRUE
#define MAT4_NOT_EQUAL MAT4_FALSE
#define MAT4_PURE_PREFIX  SSE_PURE_PREFIX inline mat4
#define MAT4_CONST_PREFIX SSE_CONST_PREFIX inline mat4


union _mat4
{
  float m[16];
  float4 v[4];
}alignas(64);

typedef union _mat4 mat4;

FLOAT4_PURE_PREFIX
mat4_get_row(const mat4* const A,const int index)
{ return A->v[index]; }

FLOAT4_PURE_PREFIX
mat4_get_collum(const mat4* const A,const int index)
{ return float4_set(A->v[0][index], A->v[1][index], A->v[2][index], A->v[3][index]); }

MAT4_PURE_PREFIX
mat4_tran(const mat4* const A)
{
    mat4 r = *A;
    _MM_TRANSPOSE4_PS(r.v[0],r.v[1],r.v[2],r.v[3]);
    return r;
}


MAT4_CONST_PREFIX
mat4_set(
  const float a0 ,const float a1 ,const float a2 ,const float a3
 ,const float a4 ,const float a5 ,const float a6 ,const float a7
 ,const float a8 ,const float a9 ,const float a10,const float a11
 ,const float a12,const float a13,const float a14,const float a15)
{
    mat4 r;
    r.v[0] = float4_set(a0 ,a1 ,a2 ,a3);
    r.v[1] = float4_set(a4 ,a5 ,a6 ,a7);
    r.v[2] = float4_set(a8 ,a9 ,a10,a11);
    r.v[3] = float4_set(a12,a13,a14,a15);
    return r;
}

MAT4_CONST_PREFIX
mat4_setf4(
const float4 a0_3  ,
const float4 a4_7  ,
const float4 a8_11 ,
const float4 a12_15)
{
    mat4 r;
    r.v[0] = a0_3  ;
    r.v[1] = a4_7  ;
    r.v[2] = a8_11 ;
    r.v[3] = a12_15;
    return r;
}


MAT4_CONST_PREFIX
mat4_set1(const float x)
{
    mat4 r;
    r.v[0] = float4_set1(x);
    r.v[1] = float4_set1(x);
    r.v[2] = float4_set1(x);
    r.v[3] = float4_set1(x);
    return r;
}

MAT4_CONST_PREFIX
mat4_setone()
{
    mat4 r;
    r.v[0] = float4_set1(1);
    r.v[1] = float4_set1(1);
    r.v[2] = float4_set1(1);
    r.v[3] = float4_set1(1);
    return r;
}

MAT4_CONST_PREFIX
mat4_set0()
{
    mat4 r;
    r.v[0] = float4_setzero();
    r.v[1] = float4_setzero();
    r.v[2] = float4_setzero();
    r.v[3] = float4_setzero();
    return r;
}

MAT4_PURE_PREFIX
mat4_seta(const float a[static 16])
{
    mat4 r;
    r.v[0] = float4_seta(a+0);
    r.v[1] = float4_seta(a+4);
    r.v[2] = float4_seta(a+8);
    r.v[3] = float4_seta(a+12);
    return r;
}

MAT4_CONST_PREFIX
mat4_diagonal()
{
    mat4 r;
    r.v[0] = float4_set(1,0,0,0);
    r.v[1] = float4_set(0,1,0,0);
    r.v[2] = float4_set(0,0,1,0);
    r.v[3] = float4_set(0,0,0,1);
    return r;
}

MAT4_CONST_PREFIX
mat4_upper()
{
    mat4 r;
    r.v[0] = float4_set(1,1,1,1);
    r.v[1] = float4_set(0,1,1,1);
    r.v[2] = float4_set(0,0,1,1);
    r.v[3] = float4_set(0,0,0,1);
    return r;
}

MAT4_CONST_PREFIX
mat4_lower()
{
    mat4 r;
    r.v[0] = float4_set(1,0,0,0);
    r.v[1] = float4_set(1,1,0,0);
    r.v[2] = float4_set(1,1,1,0);
    r.v[3] = float4_set(1,1,1,1);
    return r;
}

MAT4_CONST_PREFIX
mat4_scale(const float x,const float y,const float z)
{
    mat4 r;
    r.v[0] = float4_set(x, 0, 0, 0);
    r.v[1] = float4_set(0, y, 0, 0);
    r.v[2] = float4_set(0, 0, z, 0);
    r.v[3] = float4_set(0, 0, 0, 1);
    return r;
}

MAT4_CONST_PREFIX
mat4_translate(const float x,const float y,const float z)
{
    mat4 r;
    r.v[0] = float4_set(1, 0, 0, x);
    r.v[1] = float4_set(0, 1, 0, y);
    r.v[2] = float4_set(0, 0, 1, z);
    r.v[3] = float4_set(0, 0, 0, 1);
    return r;
}

MAT4_CONST_PREFIX
mat4_rotationX(const float angle)
{
    mat4 r;
    const float s = (float)sin(angle);
    const float c = (float)cos(angle);

    r.v[0] = float4_set(1, 0, 0,  0);
    r.v[1] = float4_set(0, c, -s, 0);
    r.v[2] = float4_set(0, s, c,  0);
    r.v[3] = float4_set(0, 0, 0,  1);

    return r;
}

MAT4_CONST_PREFIX
mat4_rotationY(const float angle)
{
    mat4 r;
    const float s = (float)sin(angle);
    const float c = (float)cos(angle);

    r.v[0] = float4_set(c, 0, -s, 0);
    r.v[1] = float4_set(0, 1, 0,  0);
    r.v[2] = float4_set(s, 0, c,  0);
    r.v[3] = float4_set(0, 0, 0,  1);
    return r;
}

MAT4_CONST_PREFIX
mat4_rotationZ(const float angle)
{
    mat4 r;
    const float s = (float)sin(angle);
    const float c = (float)cos(angle);

    r.v[0] = float4_set(c, -s,0,   0);
    r.v[1] = float4_set(s, c, 0,   0);
    r.v[2] = float4_set(0, 0, 1,   0);
    r.v[3] = float4_set(0, 0, 0, 1);
    return r;
}

MAT4_CONST_PREFIX
mat4_rotationXYZ(const float angleX,const float angleY,const float angleZ)
{

    mat4 r;
    const float sX = (float)sin(angleX); //α
    const float cX = (float)cos(angleX);
    
    const float sY = (float)sin(angleY); //β
    const float cY = (float)cos(angleY);

    const float sZ = (float)sin(angleZ); //γ
    const float cZ = (float)cos(angleZ);

    r.v[0] = float4_set(cY*cZ ,sX*sY*cZ - cX*sZ ,cX*sY*cZ + sX*sZ   ,0);
    r.v[1] = float4_set(cY*sZ ,sX*sY*sZ + cX*cZ ,cX*sY*sZ - sX*cZ   ,0);
    r.v[2] = float4_set(-sY   ,sX*cY            ,cX*cY              ,0);
    r.v[3] = float4_set(0     ,0                ,0                  ,1);

    return r;
}

MAT4_PURE_PREFIX
mat4_add(const mat4* const A, const mat4* const B)
{
    mat4 r;
    r.v[0] = float4_add(A->v[0],B->v[0]);
    r.v[1] = float4_add(A->v[1],B->v[1]);
    r.v[2] = float4_add(A->v[2],B->v[2]);
    r.v[3] = float4_add(A->v[3],B->v[3]);
    return r;
}


MAT4_PURE_PREFIX
mat4_mul(const mat4* const A, const mat4* const B)
{
    const mat4 b = mat4_tran(B);
    mat4 r;
    r.v[0] = float4_set(
     _mm_cvtss_f32(float4_dp(A->v[0],b.v[0]))
    ,_mm_cvtss_f32(float4_dp(A->v[0],b.v[1]))
    ,_mm_cvtss_f32(float4_dp(A->v[0],b.v[2]))
    ,_mm_cvtss_f32(float4_dp(A->v[0],b.v[3])) );

    r.v[1] = float4_set(
     _mm_cvtss_f32(float4_dp(A->v[1],b.v[0]))
    ,_mm_cvtss_f32(float4_dp(A->v[1],b.v[1]))
    ,_mm_cvtss_f32(float4_dp(A->v[1],b.v[2]))
    ,_mm_cvtss_f32(float4_dp(A->v[1],b.v[3])) );

    r.v[2] = float4_set(
     _mm_cvtss_f32(float4_dp(A->v[2],b.v[0]))
    ,_mm_cvtss_f32(float4_dp(A->v[2],b.v[1]))
    ,_mm_cvtss_f32(float4_dp(A->v[2],b.v[2]))
    ,_mm_cvtss_f32(float4_dp(A->v[2],b.v[3])) );

    r.v[3] = float4_set(
     _mm_cvtss_f32(float4_dp(A->v[3],b.v[0]))
    ,_mm_cvtss_f32(float4_dp(A->v[3],b.v[1]))
    ,_mm_cvtss_f32(float4_dp(A->v[3],b.v[2]))
    ,_mm_cvtss_f32(float4_dp(A->v[3],b.v[3])) );

    return r;
}

FLOAT4_CONST_PREFIX
mat4_mul_float4(const mat4* const A, const float4 V)
{
    float4 r = float4_set
    (_mm_cvtss_f32(float4_dp( A->v[0] , V) ),
     _mm_cvtss_f32(float4_dp( A->v[1] , V) ),
     _mm_cvtss_f32(float4_dp( A->v[2] , V) ),
     _mm_cvtss_f32(float4_dp( A->v[3] , V) )
    );

    return r;
}


MAT4_CONST_PREFIX
mat4_mul1(const mat4* const A,const float x)
{
    mat4 r;
    r.v[0] = float4_mul1(A->v[0],x);
    r.v[1] = float4_mul1(A->v[1],x);
    r.v[2] = float4_mul1(A->v[2],x);
    r.v[3] = float4_mul1(A->v[3],x);
    return r;
}

int8_t mat4_is_zero(const mat4* const A)
{
    float4 zero = float4_setzero();
    if(
        float4_cmp(A->v[0], zero, FLOAT4_DEFAULT_EPSILON) == FLOAT4_0123_NOT_EQUAL &&
        float4_cmp(A->v[1], zero, FLOAT4_DEFAULT_EPSILON) == FLOAT4_0123_NOT_EQUAL &&
        float4_cmp(A->v[2], zero, FLOAT4_DEFAULT_EPSILON) == FLOAT4_0123_NOT_EQUAL &&
        float4_cmp(A->v[3], zero, FLOAT4_DEFAULT_EPSILON) == FLOAT4_0123_NOT_EQUAL
    ) return MAT4_FALSE;

    return MAT4_TRUE;
}

int8_t mat4_is_unit(const mat4* const A)
{
    float4 one = float4_setone();
    if(
        float4_cmp(A->v[0], one, FLOAT4_DEFAULT_EPSILON) == FLOAT4_0123_NOT_EQUAL &&
        float4_cmp(A->v[1], one, FLOAT4_DEFAULT_EPSILON) == FLOAT4_0123_NOT_EQUAL &&
        float4_cmp(A->v[2], one, FLOAT4_DEFAULT_EPSILON) == FLOAT4_0123_NOT_EQUAL &&
        float4_cmp(A->v[3], one, FLOAT4_DEFAULT_EPSILON) == FLOAT4_0123_NOT_EQUAL
    ) return MAT4_FALSE;

    return MAT4_TRUE;
}

int8_t mat4_is_diagonal(const mat4* const A)
{
    float4 zero = float4_setzero();
    if(
        float4_cmp(A->v[0], zero, FLOAT4_DEFAULT_EPSILON) == FLOAT4_123_NOT_EQUAL &&
        float4_cmp(A->v[1], zero, FLOAT4_DEFAULT_EPSILON) == FLOAT4_023_NOT_EQUAL &&
        float4_cmp(A->v[2], zero, FLOAT4_DEFAULT_EPSILON) == FLOAT4_013_NOT_EQUAL &&
        float4_cmp(A->v[3], zero, FLOAT4_DEFAULT_EPSILON) == FLOAT4_012_NOT_EQUAL
    ) return MAT4_FALSE;

    return MAT4_TRUE;
}

int8_t mat4_is_upper(const mat4* const A)
{
    float4 zero = float4_setzero();
    if(
        float4_cmp(A->v[1], zero, FLOAT4_DEFAULT_EPSILON) == FLOAT4_0_NOT_EQUAL     &&
        float4_cmp(A->v[2], zero, FLOAT4_DEFAULT_EPSILON) == FLOAT4_01_NOT_EQUAL    &&
        float4_cmp(A->v[3], zero, FLOAT4_DEFAULT_EPSILON) == FLOAT4_012_NOT_EQUAL
    ) return MAT4_FALSE;

    return MAT4_TRUE;
}

int8_t mat4_is_lower(const mat4* const A)
{
    float4 zero = float4_setzero();
    if(
        float4_cmp(A->v[0], zero, FLOAT4_DEFAULT_EPSILON) == FLOAT4_123_NOT_EQUAL &&
        float4_cmp(A->v[1], zero, FLOAT4_DEFAULT_EPSILON) == FLOAT4_23_NOT_EQUAL  &&
        float4_cmp(A->v[2], zero, FLOAT4_DEFAULT_EPSILON) == FLOAT4_3_NOT_EQUAL
    ) return MAT4_FALSE;

    return MAT4_TRUE;
}

//
SSE_PURE_PREFIX inline float
mat4_det(const mat4* const A)
{
    const float4 p0 = float4_permute(A->v[1], (0, 3,2,1));
    const float4 p1 = float4_permute(A->v[1], (0, 3,2,0));
    const float4 p2 = float4_permute(A->v[1], (0, 3,1,0));
    const float4 p3 = A->v[1];

    const float4 mabc0 = float4_mul(float4_permute(A->v[2],(0,1,1,2)),float4_permute(A->v[3],(0,2,3,3)) );
    const float4 mabc1 = float4_mul(float4_permute(A->v[2],(0,2,3,3)),float4_permute(A->v[3],(0,1,1,2)) );
    const float4 mabc  = float4_sub(mabc0,mabc1);
    
    const float4 mdef0 = float4_mul(float4_set1(A->v[2][0]),float4_permute(A->v[3],(0,1,2,3)) );
    const float4 mdef1 = float4_mul(float4_set1(A->v[3][0]),float4_permute(A->v[2],(0,1,2,3)) );
    const float4 mdef  = float4_sub(mdef0,mdef1);
    
    const float4 zero_mask3 = float4_set(1.0f,-1.0f,1.0f,0.0f);
    float4 m0123 = float4_set(
    float4_hsum(float4_mul( float4_mul(p0,mabc),zero_mask3 ) ),
    float4_hsum(float4_mul( float4_mul(p1,float4_set(mabc[0],mdef[0],mdef[1],0)),zero_mask3 )  ),
    float4_hsum(float4_mul( float4_mul(p2,float4_set(mabc[1],mdef[0],mdef[2],0)),zero_mask3 )  ),
    float4_hsum(float4_mul( float4_mul(p3,float4_set(mabc[2],mdef[1],mdef[2],0)),zero_mask3 )  )
    );
    
    return float4_hsum( float4_mul(float4_mul(A->v[0], m0123),float4_set(1.0f,-1.0f,1.0f,-1.0f)) );
}


void mat4_printf(const mat4* const m)
{
    printf("Matrix:\n");
    float4_println(m->v[0]);
    float4_println(m->v[1]);
    float4_println(m->v[2]);
    float4_println(m->v[3]);
}
