/* Exercise 1-16. Revise the main routine of the longest-line program
   so it will correctly print the length of arbitrary long input lines,
   and as much as possible of the text.
*/
#include <stdio.h>
#define MAXLINE 1000	/* maximum input line length */

int lda_getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main(void)
{
	int len;	/* current line length */
	int max;	/* maximum length seen so far */
	char line[MAXLINE];	/* current input line */
	char longest[MAXLINE];	/* longest line saved here */

	max = 0;
	while ((len = lda_getline(line, MAXLINE)) > 0) {
		printf("%d %s", len - 1, line);
	}
	return 0;
}

/* getline: read a line into s, return length */
int lda_getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c =='\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		i++;
}