#include <stdio.h>
#include<stdlib.h>

long a=2, b=2, c=2, d=3;

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
	
	b = a *c;
	b = a * 3;
	b = 6 * a;
	b = 6 * 3;

	b = a / d;
	b = a /3;
	b = 6 /d;
	b = 6/3;
}
