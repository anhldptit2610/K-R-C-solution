/* Exercise 2-5. Write the function any(s1, s2), which returns the
   first location in a string s1 where any character from the string
   s2 occurs, or -1 if s1 contains no characters from s2. (The standard
   library function strpbrk does the same job but returns a pointer to the
   location
*/
#include <stdio.h>
#include <stdlib.h>

int any(char *s1, char *s2);

int main(int argc, char **argv)
{
	char *s1 = argv[1], *s2 = argv[2];

	printf("The first string: %s\n", s1);
	printf("The second string: %s\n", s2);
	if (any != -1) {
		printf("The first location in %s which has a character of s2 is: %d.\n", s1, any(s1, s2));
		printf("That character is %c\n", s1[any(s1, s2)]);
	} else {
		printf("No character from s2 appears in s1\n");
	}
	return 0;
}

int any(char *s1, char *s2)
{
	int pos = -1, i, j;

	i = 0;
	for (; s2[i] != '\0' && pos == -1; i++) {
		for (j = 0; s1[j] != '\0' && s2[i] != s1[j]; j++)
			;
		if (s2[i] == s1[j])
			pos = j;
	}
	return pos;
}