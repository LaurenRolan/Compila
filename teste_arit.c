#include <stdio.h>
#include <stdlib.h>

long a, b, c, d='c';
//double x, y, z;

int main()
{
  a = 6;
  b = 3;
  c = a;

  c = a + b;
  a = a + 3;
  a = 6 + a;
  a = 6 + 3;

  b = c - a;
  a = b - 3;
  a = 3 - b;
  a = 6 - 3;

  b = a * c;
  b = a * 3;
  b = 6 * a;
  b = 6 * 3;

  b = a / d;
  b = a / 3;
  b = 6 / d;
  b = 6 / 3;
  printf("%ld", d);
/*
  x = 1.2 * 3.5;
  y = x / 3.0;
*/
//Muita loucura
/*
  if(a >= y) z = y * x;
  if(a <= y) z = y * x;
  if(a > y) z = y * x;
  if(a < y) z = y * x;
  if(a == y) z = y * x;
*/

  if(a >= b || a < b) c = a / b;
  if(a <= b) c = a / b;
  if(a > b) c = a / b;
  if(a < b) c = a /b;
  if(a == b) c = a / b;
  if (a && b) c = a / b;
  if(a || b) c = a / b;
}
