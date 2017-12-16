#include <stdio.h>
#include <stdlib.h>

long a[5], b = 6;

int main()
{
	a[3] = b;
	b = a[0];

}
