/* Exercise 1-14. Write a program to print a histogram of the
   frequencies of different characters in its input
*/
#include <stdio.h>
#include <ctype.h>

#define ALPHABET 26

int main(void)
{
	int freq[26] = {0};
	long c;

	while ((c = getchar()) != EOF) {
		if (c >= 'a' && c <= 'z')
			++freq[c - 'a'];
		else if (c >= 'A' && c <= 'Z')
			++freq[c - 'A'];	/* A is the same as a */
	}
	for (int i = 0; i < ALPHABET; i++)
		printf("%d ", freq[i]);
	printf("\n");
	return 0;
} 