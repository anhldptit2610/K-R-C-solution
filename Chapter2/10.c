/* Exercise 2-10. Rewrite the function lower, which converts
   upper case letters to lower case, with a conditional expression
   instead of if-else.
*/

/* Note: the original version of lower.
   
   int lower(int c)
   {
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A;
	else
		return c;
   }
*/

#include <stdio.h>
#include <ctype.h>

/* lda_lower: convert c to lower case; ASCII only. */
int lda_lower(int c);

int main(void)
{
	long c;

	while ((c = getchar()) != EOF)
		if (isalpha(c))
			printf("Convert %c to lower: %c\n",
			 (char)c, (char)lda_lower(c));
	return 0;
}

int lda_lower(int c)
{
	return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}