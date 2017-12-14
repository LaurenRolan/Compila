#include <stdio.h>
#include <stdlib.h>

long a, b, c;
double x, y, z;

int main()
{
  a = 5;
  b = 3;
  c = a + b;
  b = a - c;
  b = a * c;
  b = a / c;
  x = 1.2 * 3.5;
  y = x / 3.0;
  if(a >= y) z = y * x;
  if(a <= y) z = y * x;
  if(a > y) z = y * x;
  if(a < y) z = y * x;
  if(a == y) z = y * x;
  if (a && b) z = y * x;
  if(a || b) z = y * x;
}
