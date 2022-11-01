/* Exercise 2-8. Write a function rightrot(x, n) that returns
   the value the integer x rotated to the right by n positions
*/

/* Note: CHAR_BIT is defined in limits.h, it is the number of bits
   in char type
*/

#include <stdio.h>
#include <limits.h>

/* rightrot(x, n): returns x rotaed to the right by
   n positions
*/
unsigned rightrot(unsigned x, int n);

int main(void)
{

}

unsigned rightrot(unsigned x, int n)
{
	if (!n && n == sizeof(unsigned)*CHAR_BIT)
		return x;
	int move = (sizeof(unsigned)*CHAR_BIT - n);
	return (x >> n) | (x << move);
}