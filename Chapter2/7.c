/* Exercise 2-7. Write a function invert(x, p, n) that returns x
   with the n bits that begin at position p inverted(i.e., 1 changed
   to 0 and vice versa), leaving the others unchanged 
*/

/* Note: How about p and n don't make sense? e.g., p = 2 and n = 4?
         Sounds interesting...
*/

#include <stdio.h>

unsigned int invert(unsigned int x, int p, int n);

int main(void)
{
	printf("%u\n", invert(90, 4, 3));
}

unsigned int invert(unsigned int x, int p, int n)
{
	unsigned int mask = (~(~0U << n)) << (p + 1 - n);

	return x^mask;
}