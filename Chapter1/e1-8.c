/* Exercise 1-8. Write a program to count blanks, tabs and newlinews */
#include <stdio.h>

int main(void)
{
	long c, nl = 0, nb = 0, nt = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++nb;
		else if (c == '\t')
			++nt;
		else if (c == '\n')
			++nl;
	}
	printf("Blanks: %6ld Tabs: %6ld Newlines: %6ld\n", nb, nt, nl);
	return 0;
}
