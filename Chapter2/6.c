/* Exercise 2-6. Write a function setbits(x, p, n, y) that returns
   x which the n bits that begin at position p set to the rightmost
   n bits of y, leaving the other bits unchanged.
*/

#include <stdio.h>

unsigned int setbits(unsigned int x, int p, int n, unsigned int y);
unsigned int getbits(unsigned int x, int p, int n);

int main(void)
{
	printf("%u\n", setbits(218, 3, 3, 170));
	return 0;
}

/* getbits: get n bits from position p */
unsigned int getbits(unsigned int x, int p, int n)
{
	return (x >> (p + 1 - n)) & ~(~0U << n);
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
	unsigned int mask = ~(~0U << n);

	y &= mask;
	x &= ~(mask << (p + 1 - n));
	return x | y;
}