/* Exercise 1-22. Write a program to "fold" long input lines into
   two or more shorter lines after the last non-blank character that
   occurs before the n-th column of input. Make sure your program does
   something intelligent with very long lines, and if there are no blanks
   or tabs before the specified column.
*/
#include <stdio.h>
#include <ctype.h>

#define LINE_LENGTH	20	/* the limit of line length */
#define MAXLINE		1000	/* maximum input line length */

int lda_getline(char line[], int lim);
void fold(char line[], int len);

int main(void)
{
	int len;
	char line[MAXLINE];

	while ((len = lda_getline(line, MAXLINE)) > 0) {
		fold(line, len);
	}
	return 0;
}

void fold(char line[], int len)
{
	int i, head, last_line_len;

	i = head = 0;
	while (i <= len) {
		if (i + LINE_LENGTH <= len) {
			i += LINE_LENGTH;
			while (isblank(line[i]))
				--i;
			for (int j = head; j <= i; j++)
				putchar(line[j]);
			putchar('\n');
			head = i + 1;
		} else {
			for (int j = head; j <= len; j++)
				putchar(line[j]);
			putchar('\n');
			break;
		}
	}	
}

int lda_getline(char line[], int lim)
{
	int i;
	long c;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		line[i] = c;
	if (c == '\n')
		line[i] = '\0';
	return i - 1;
}
