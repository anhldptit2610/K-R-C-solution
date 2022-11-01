/* Exercise 2-4. Write an alternative version of squeeze(s1, s2)
   that deletes each character in s1 that matches any characters
   in the string s2.
*/

/* Note: I use main arguments to input s1 and s2.
*/

#include <stdio.h>
#include <stdlib.h>

/* squeeze_v1(s1, s2): delete each character in s1 that matches any
   characters in the string s2.
   This version does not affect the original string.
*/
char *squeeze_v1(char *s1, char *s2);

/* squeeze_v2(s1, s2): delete each character in s1 that matches any
   characters in the string s2.
   This version affects the original string.
*/
void squeeze_v2(char *s1, char *s2);

int main(int argc, char **argv)
{
	char *s1 = argv[1], *s2 = argv[2];

	printf("The first string: %s\n", s1);
	printf("The second string: %s\n", s2);
	printf("The first string after applied squeeze v1: %s\n", squeeze_v1(s1, s2));
	squeeze_v2(s1, s2);
	printf("The first string after applied squeeze v2: %s\n", s1);
	return 0;
}

char *squeeze_v1(char *s1, char *s2)
{
	int i, j, s1_len, s2_len;

	s1_len = s2_len = 0;
	while (s1[s1_len] != '\0')
		++s1_len;
	--s1_len;
	while (s2[s2_len] != '\0')
		++s2_len;
	--s2_len;

	char *res = malloc(s1_len);
	int idx = 0;
	for (i = 0; i <= s1_len; i++) {
		j = 0;
		while (s2[j] != '\0') {
			if (s1[i] == s2[j])
				break;
			j++;
		}
		if (j <= s2_len)
			continue;
		else
			res[idx++] = s1[i];	
	}	
	res[idx] = '\0';
	return res;
}

void squeeze_v2(char *s1, char *s2)
{
	int i, j, s1_len, s2_len, idx;

	s1_len = s2_len = 0;
	while (s1[s1_len] != '\0')
		s1_len++;
	--s1_len;
	while (s2[s2_len] != '\0')
		s2_len++;
	--s2_len;

	i = idx = 0;
	for (; s1[i] != '\0'; i++) {
		j = 0;
		while (s2[j] != '\0') {
			if (s1[i] == s2[j])
				break;
			j++;
		}
		if (j <= s2_len)
			continue;
		else
			s1[idx++] = s1[i];
	}
	s1[idx] = '\0';
}