#include <stdio.h>
#include <stdlib.h>

long a=111, b=222, c=333, d=19999, e = 10000, f = 2000, g = 5000;

int main()
{
  printf("Nao\n");
  printf("a = %ld e b = %ld\n", a, b);
  printf("%ld %ld %ld %ld %ld %ld %ld\n", a, b, c, d, e, f, g);
  scanf("%ld", &a);
}
