// #include "math_matrix.h"
#include "./math_float4.h"
#include "./math_int4.h"
#include "./math_mat4.h"
#include <stdio.h>


int main()
{
  // mat4 a;
  // mat4 b;
  // a = mat4_diagonal();
  // // mat4_line1(a.m,1,2,3,4);
  // // mat4_line2(a.m,1,2,3,4);
  // // mat4_line3(a.m,5,6,7,8);
  // // mat4_line4(a.m,1,2,3,4);
  // b = mat4_diagonal();
  // a = mat4_mult_simd(&a, &b);

  // for(int i = 0 ; i < 16; i+=4)
  // {
  //   printf("[%f , %f , %f , %f]\n",a.m[0+i],a.m[1+i],a.m[2+i],a.m[3+i]);
  // }

  // float const_arrray[4]  = {1.f,0.f,3.f,4.f};
  // float const_arrray2[4] = {1.0f,0.f,3.f,4.f};
  
  // unsigned char* c = (unsigned char*)calloc(5,sizeof(unsigned char)); 
  // printf("%i\n",FLOAT4_ALL_EQUAL);
  // printf("%i\n",FLOAT4_013_NOT_EQUAL);
  // c[0] = 1;
  // c[1] = 2;
  // c[2] = 3;
  // c[3] = 4;

  // uint32_t p = uint_pack4_ubytes(c);
  // printf("PACKED INT: %u\n",p);
  // c[0] = 0; c[1] = 0; c[2] = 0; c[3] = 0;
  // printf("UNPACKED INT: %u,%u,%u,%u\n",c[0],c[1],c[2],c[3]);
  // uint_unpack4_ubytes(p, c);
  // printf("UNPACKED INT: %u,%u,%u,%u\n",c[0],c[1],c[2],c[3]);

  // float4 x = float4_seta(const_arrray);
  // float4 z = float4_seta(const_arrray2);

  // float4 r = float4_add(x, z);

  // printf("%i\n",float4_cmp(x,z,FLOAT4_DEFAULT_EPSILON));
  // float4_println(x);

  float4 a = float4_set(0.1560f  ,0.9460f ,0.52060f ,0.6130f);
  float4 b = float4_set(0.020f   ,0.290f  ,0.540f   ,0.5930f);
  float4 c = float4_set(0.10560f ,0.4560f ,0.2560f  ,0.360f);
  float4 d = float4_set(0.10f    ,0.60f   ,0.260f   ,0.3f);

  float4_println(a);
  float4_println(b);
  float4_println(c);
  float4_println(d);

  a = float4_norm(a);
  b = float4_norm(b);
  c = float4_norm(c);
  d = float4_norm(d);
  
  putchar('\n');
  float4_println(a);
  float4_println(b);
  float4_println(c);
  float4_println(d);
  putchar('\n'); putchar('\n');
  
  mat4 t = mat4_setf4(a,b,c,d);
  mat4_printf(&t);
  printf("DET:%f\n",mat4_det(&t));


  return 0;
}
