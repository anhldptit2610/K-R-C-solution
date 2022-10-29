/* Exercise 1-13. Write a program to print a histogram of the
   lengths of words in its input. It is easy to draw the histogram
   with the bars horizontal; a vertical orientation is more challenging.
*/

/* This code is a very basic solution, without table aligning... */

#include <stdio.h>
#include <ctype.h>

#define VERTICAL   1	/* 0 is equal horizontal, 1 is equal vertical */
#define OUT        0
#define IN         1
#define MAX_WORDS  1000	/* maximum limit of words which we can type in */

int main(void)
{
	int status, length, index, histogram[MAX_WORDS] = {0};
	long c;

	status = OUT;

	/* read the first character */
	c = getchar();
	if (isalpha(c)) {
		status = IN;
		printf("%c", (char)c);
#if VERTICAL
		length = 1;
#else
		index = 0;
		++histogram[index];
#endif
	}

#if VERTICAL
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t') {
			status = OUT;
			continue;
		} else if (isalpha(c) && status == OUT) {
			if (length > 0)
				printf("%10d\n%c", length, (char)c);
			else 
				printf("%c", (char)c);
			length = 1;
			status = IN;
		} else if (c == '\n') {
			printf("%10d\n", length);
			length = 0;
			status = OUT;
		} else {
			++length;
			printf("%c", (char)c);
		}
	}
#else
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t') {
			status = OUT;
			continue;
		} else if (isalpha(c) && status == OUT) {
			printf(" %c", (char)c);
			++index;
			histogram[index] = 1;
			status = IN;
		} else if (c == '\n') {
			printf("\n");
			for (int i = 0; i <= index; i++) {
				printf("%7d ", histogram[i]);
				histogram[i] = 0;
			}
			printf("\n");
			index = 0;
		} else {
			printf("%c", (char)c);
			++histogram[index];
		}
	}
#endif
	return 0;
}