/* Exercise 1-19. Write a function reverse(s) that reverses the
   character string s. Use it to write a program that reverses
   its input a line at a time.
*/
#include <stdio.h>

void reverse(char s[]);

int main(void)
{
	char str[11] = "demoninlove";

	printf("The original string: %s\n", str);
	reverse(str);
	printf("The string after reversed: %s\n", str);
	return 0;
}

void reverse(char s[])
{
	int len = 0, i, j, tmp;

	while (s[len] != '\0')
		++len;
	for (i = 0, j = len - 1; i <= len/2; i++, j--) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}