/* Exercise 1-19. Write a program to remove trailing blanks and tabs
   from each line of input, and to delete entirely blank lines.
*/
#include <stdio.h>
#define MAXLINE 1000	/* maximum input line length */


int lda_getline(char line[], int lim);

int main(void)
{
	char line[MAXLINE], len;

	while ((len = lda_getline(line, MAXLINE)) > 0) {
		printf("%s\n", line);
	}
	return 0;
}

int lda_getline(char line[], int lim)
{
	int i, c, j;

	for (i = 0; i < lim - 1 && (c = getchar()) != '\n'; i++) {
		if (c == '\t') {
			--i;
			continue;
		}
		line[i] = c;
	}
	if (c == '\n')
		line[i] = '\0';

	/* remove trailing blanks */
	j = i - 1;
	while (line[j] == ' ')
		j--;
	line[j + 1] = '\0';
	return j;
}