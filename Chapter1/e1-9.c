/* Exercise 1-9. Write a program to copy its input to its output,
   replacing each string of one or more blanks by a single blank.
*/
#include <stdio.h>

int main(void)
{
	long c;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t') {
			while ((c = getchar()) == ' ' || c == '\t')
				;
			printf(" %c", (char)c);
		} else {
			putchar(c);
		}
	}
	return 0;
}