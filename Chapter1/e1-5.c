/* Exercise 1-5. Modify the temperature conversion program to print
   the table in reverse order, that is, from 300 degrees to 0 */
#include <stdio.h>

#define LOWER 0		/* lower limit of the temperature */
#define UPPER 300	/* upper limit of the temperature */
#define STEP 20		/* step size */

int main(void)
{
	float fahr;

	printf("Fahrenheit to Celsius convert table\n");
	for (fahr = UPPER; fahr >= LOWER; fahr -= STEP)
		printf("%3.0f %8.1f\n", fahr, (5.0/9.0)*(fahr - 32.0));
	return 0;
}