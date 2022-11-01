/* Exercise 2-9. In a two's complement number system, x &= (x-1)
   delete the rightmost 1-bit in x. Explain why. Use this observation
   to write a faster version of bitcount.
*/

/* Note: original version of bitcount.
int bitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;
}
*/

/* Explain: x &= (x - 1) deletes the rightmost 1-bit in x because in
   two's complement number system, when we decrement a number by 1, 
   the rightmost 1-bit will always become 0.
   And we knew if 0 AND 1, the result will be 0.
*/

#include <stdio.h>

/* still bitcount, but faster version */
int bitcount(unsigned x);

int main(void)
{
}

int bitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x &= (x - 1))
		b++;
	return b;
}