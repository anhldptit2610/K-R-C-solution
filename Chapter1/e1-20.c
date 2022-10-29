/* Exercise 1-20. Write a program "detab" that replaces tabs in the input
   with the proper number of blanks to space to the next tab stop. Assume
   a fixed set of tab stops, say every n columns. Should n be a variable 
   or a symboloc parameter?
*/

/* Note: first we need to understand how tab key works. Don't just replace
   a '\t' with a fixed number of spaces, e.g. 8 or 4.
*/

#include <stdio.h>

#define TABSIZE	8

int main(void)
{
	long c, count;

	count = 0;	/* use this count to track tab stops */
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			for (int i = 0; i < TABSIZE - count; i++)
				putchar(' ');
			count = 0;
		} else if (c == '\n') {
			putchar(c);
			count = 0;
		} else {
			putchar(c);
			count = (count + 1) % TABSIZE;
		}
	}
	return 0;
}