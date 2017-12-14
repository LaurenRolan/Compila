#include <stdio.h>
#include <stdlib.h>

long a, b, c;

long funcao1(long x, long y, long z)
{
  return x + y + z;
}
logn funcao2 ()
{
  return 3333;
}

int main()
{
  a = funcao1(1, 2, 3);
  b = funcao2();
  c = funcao1(1, 2, 3) + funcao2();
}
