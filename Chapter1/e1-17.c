/* Exercise 1-17. Write a program to print all input lines 
   that are longer than 80 characters
*/
#include <stdio.h>
#define MAXLINE 1000	/* maximum input line length */
#define LENGTH 80	/* we will print anyline whose length exceeds LENGTH */

int lda_getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main(void)
{
	int len;	/* current line length */
	char line[MAXLINE];	/* current input line */

	while ((len = lda_getline(line, MAXLINE)) > 0) {
		if (len > LENGTH) {
			printf("%s", line);
		}
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