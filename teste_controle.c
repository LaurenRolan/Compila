#include <stdio.h>
#include <stdlib.h>

long a = 2, b = 123, c = 456;

int main()
{
  if(a > b) a = a * 2;
  else a = a / 2;
  
  if (c > b) a = a * 3;
  
  while (a > 0)
    a = a - 1;
  
}
