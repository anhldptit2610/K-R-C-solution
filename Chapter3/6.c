/* Exercise 3-6. Write a version of itoa that accepts three arguments
   instead of two. The third argument is a minimum field width; the 
   converted number must be padded with blanks on the left if necessary
   to make it wide enough.
*/

#include <stdio.h>
#include <string.h>

void reverse(char s[])
{
	int i, j, tmp;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}

void lda_itoa(long long n, char s[], int width)
{
	int i, space;
	long sign;

	if ((sign = n) < 0)	/* record sign */
		n = -n;		/* make n positive */
	i = 0;
	do {			/* generate digits in reverse order */
		s[i++] = n % 10 + '0';	/* get next digit */
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	space = width - i;
	while (space-- > 0)
		s[i++] = ' ';	
	reverse(s);
}

int main(void)
{
	long long num = 1234;
	char s[100];

	lda_itoa(num, s, 8);
	printf("the number is:%s\n", s);
	return 0;
}