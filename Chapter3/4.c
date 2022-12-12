/* Exercise 3-4. In a two's complement number representation,
   our version of itoa doesn't handle the largest negative
   number, that is, the value of n equal to -(2^wordsize-1).
   Explain why not. Modify it to print that value correctly,
   regardless of the machine on which it runs.
*/

/* Explain: because in two's complement number representation,
   we need the MSB to be the signed bit, so the range which n bits
   can represent is -(2^n-1) -> 2^(n-1) - 1.
   To make it simplifier, just think the int data type can not store
   number equal to -(2^wordsize-1). So the solution is change the data
   type of n(int -> long or long long).
*/

#include <stdio.h>
#include <string.h>
#include <math.h>


void reverse(char s[])
{
	int i, j, tmp;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}

void lda_itoa(long long n, char s[])
{
	int i;
	long sign;

	if ((sign = n) < 0)	/* record sign */
		n = -n;		/* make n positive */
	i = 0;
	do {			/* generate digits in reverse order */
		s[i++] = n % 10 + '0';	/* get next digit */
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	reverse(s);
}

int main(void)
{
	char s[100];
	long long largest_negative_number = -1 * ((long long)pow(2, __WORDSIZE) - 1);

	lda_itoa(largest_negative_number, s);
	printf("number is: %s\n", s);
	return 0;
}