/* Exercise 1-12. Write a program that prints its input
   one word per line
*/
#include <stdio.h>
#include <ctype.h>

#define IN 1	/* inside a word */
#define OUT 0	/* outside a word */

int main(void)
{
	long c, status, nw = 0;

	status = OUT;
	
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t') {
			status = OUT;
			continue;
		}
		if (isalpha(c) && status == OUT) {
			status = IN;
			if (nw > 0) 	
				printf("\n%c", (char)c);
			else 
				printf("%c", (char)c);
			nw++;
		} else {
			printf("%c", (char)c);
		}
	}
	return 0;
}