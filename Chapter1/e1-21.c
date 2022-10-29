/* Exercise 1-21. Write a program "entab" that replaces strings of blanks
   by the minimum number of tabs and blanks to achieve the same spacing.
   Use the same tab stops as for "detab". When either a tab or a single
   blank would suffice to reach a tab stop, which should be giben preference?
*/
#include <stdio.h>

#define MAXLINE	1000	/* maximum input line length */
#define TABSTOP 8
#define IN	1	/* this means we are in blank space */
#define OUT	0	

int lda_getline(char line[], int lim);
void entab(char line[], int len);

int main(void)
{
	int len;
	char line[MAXLINE];

	while ((len = lda_getline(line, MAXLINE)) > 0)
		entab(line, len);
	return 0;

}

void entab(char line[], int len)
{
	int i, count = 0, blank_len = 0, tab_num, space_num, first_blank = 0, status = OUT;

	for (i = 0; i <= len; i++) {
		if ((line[i] == '\t' || line[i] == ' ')) {
			switch (line[i]) {
			case '\t':
				if (status == OUT)	/* not in blank space */
					first_blank = TABSTOP - count;
				blank_len += TABSTOP - count;
				count = 0;
				break;
			case ' ':
				++blank_len;
				count = (count + 1) % TABSTOP;
				break;
			default:
				break;
			}
			status = IN;
		} else {
			if (status == IN) {		/* in blank space */
				if (blank_len <= TABSTOP)
					tab_num = blank_len / TABSTOP;
				else {
					blank_len -= first_blank;
					tab_num = blank_len / TABSTOP + 1;
				}
				space_num = blank_len % TABSTOP;
				blank_len = 0;
				while (tab_num-- > 0)
					putchar('\t');
				while (space_num-- > 0)
					putchar(' ');
				status = OUT;
			}
			putchar(line[i]);
			count = (count + 1) % TABSTOP;
		}
	}
	putchar('\n');
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