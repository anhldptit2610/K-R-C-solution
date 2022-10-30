/* Exercise 2-2. Write a loop equivalent to the "for" loop
   above without using && or ||
*/

/* Note: without using && or || ???
        Can it be understood like: use && or ||,
	but not both of them? xDD
	No.
*/

#include <stdio.h>

/* The original for loop */
for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
	s[i] = c;

/* My 1st attemp loop. Quite ugly */
for (i = 0; i < lim - 1; i++) {
	if ((c = getchar()) != '\n')
		if (c != EOF)
			s[i] = c;
}

/* Still for loop */
for (i = 0; i < lim - 1; i++) {
	if ((c = getchar()) == '\n')
		break;
	else if (c == EOF)
		break;
	s[i] = c;
}
	
/* Using while loop */
i = 0;
while (i < lim - 1) {
	if ((c = getchar()) != '\n')
		if (c != EOF)
			s[i++] = c;
}