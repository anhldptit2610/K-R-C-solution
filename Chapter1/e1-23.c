/* Exercise 1-23. Write a program to remove all comments from a C program.
   Don't forget to handle quoted strings and character constants properly.
   C comments don't nest.
*/

/* Note: Because in this Chapter, we aren't introduced file I/O, so I won't use
   that. 
*/

#include <stdio.h>

int main(void)
{
	long c;

	while ((c = getchar()) != EOF) {
		if (c == '/') {
			c = getchar();
			switch (c) {
			case '/':
				while ((c = getchar()) != '\n')
					;
				break;
			case '*':
				while (c) {
					if (c == '*' && (c = getchar()) == '/')
						break;
					else
						c = getchar();
				}
				break;
			default:
				break;
			}
		} else {
			putchar(c);
		}
	}
	return 0;
}