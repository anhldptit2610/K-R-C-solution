/* Exercise 3-2. Write a function escape(s,t) that converts characters
   like newline and tab into visible escape sequences like \n and \t as
   it copies the string t to s. Use a switch. Write a function for the 
   other direction as well, converting escape sequences into the real 
   characters.
*/
#include <stdio.h>

#define MAX_LEN	2000	/* max convert string length */

/* escape(s, t): converts characters like newline
   and tab into visible escape sequences like \n
   and \t as it copies the string t to s.
*/
void escape(char *s, char *t);

/* invert_escape(s, t): escape but converts \n or \t
   into the real characters
*/
void invert_escape(char *s, char *t);

int main(void)
{
	char res[MAX_LEN], *src = "I\\tlove you so\\tmuch\\n";

	printf("The source string:\n %s\n", src);
	invert_escape(res, src);
	printf("The result of escape:\n %s\n", res);
	return 0;
}

void invert_escape(char *s, char *t)
{
	int i, idx;

	idx = 0;
	for (i = 0; t[i] !='\0'; i++) {
		switch (t[i])
		{
		case '\\':
		 	if (t[i + 1] == 'n') {
				s[idx++] = '\n';
				++i;
			} else if (t[i + 1] == 't') {
				s[idx++] = '\t';
				++i;
			} else {
				s[idx++] = '\\';
			}		
			break;
		default:
			s[idx++] = t[i];
			break;
		}
	}
}

void escape(char *s, char *t)
{
	int i, idx;

	idx = 0;
	for (i = 0; t[i] != '\0'; i++) {
		switch (t[i]) {
		case '\t':
			s[idx++] = '\\';
			s[idx++] = 't';
			break;
		case '\n':
			s[idx++] = '\\';
			s[idx++] = 'n';
			break;
		default:
			s[idx++] = t[i];
			break;
		}
	}
}