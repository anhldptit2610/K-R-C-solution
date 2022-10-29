/* Exercise 1-10. Write a program to copy its input to its output,
   replacing each tab by \t, each backspace by \b, and each backslash
   by \\. This make tabs and backspaces visible in an unambiguous way.
*/
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

void enableRawMode(void)
{
	struct termios raw;

	tcgetattr(STDIN_FILENO, &raw);
	raw.c_lflag &= ~(ECHO);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}
int main(void)
{
	long c;

	enableRawMode();

	while ((c = getchar()) != EOF) {
		if (c == '\t')
			printf("\\t");
		else if (c == 8)
			printf("\\b");
		else if (c == '\\')
			printf("\\\\");
		else
			putchar(c);
	}
	return 0;
}