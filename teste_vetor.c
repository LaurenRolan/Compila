#include <stdio.h>
#include <stdlib.h>

long a[5];
long epsilon[9];
long b = 6;
long c[3] = {555, 444, 333};

int main()
{
	a[3] = b;
	b = a[0];
}
