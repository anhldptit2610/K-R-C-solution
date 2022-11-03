/* Exercise 3-3. Write a function expand(s1, s2) that expands
   shorthand notations like a-z in the string s1 into the equivalent
   complete list abc...xyz in s2. ALlow for letters of either case and
   digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z.
   Arrange that a leading or trailing - is taken literally.
*/

/* Note: in this exercise I will only use string.h header to have strcat, in
   order to do tests.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_STR_LEN	1000

/* expand(s1, s2): expands shorthand notations
   like a-z in s1 into the equivalent compelete
   list abc...xyz in s2.
*/
void expand(char *s1, char *s2);

int main(int argc, char **argv)
{
	char s1[MAX_STR_LEN];
	char s2[MAX_STR_LEN];
	int i;

	/* test code */
	memset(s1, 0, MAX_STR_LEN);
	memset(s2, 0, MAX_STR_LEN);
	for (i = 1; i < argc; i++) {
		strcat(s1, argv[i]);
		strcat(s1, " ");
	}
	printf("Input: %s\n", s1);
	expand(s1, s2);
	printf("Output: %s\n", s2);
	
	return 0;
}

void expand(char *s1, char *s2)
{
	int i, j, s1_len, s2_idx, first_char, last_char;

	for (s1_len = 0; s1[s1_len] != '\0'; s1_len++)
		;
	--s1_len;

	for (i = 0, s2_idx = 0; i <= s1_len; i++) {
		if (isalnum(s1[i]) && s1[i + 1] == '-') {
			first_char = i;
			last_char = (s1[i + 3] == '-') ? i + 4 : i + 2;
			for (j = s1[first_char]; j <= s1[last_char]; j++)
				s2[s2_idx++] = j;
			i += last_char - first_char;
		} else {
			s2[s2_idx++] = s1[i];
		}
	}
	s2[s2_idx] = '\0';
}