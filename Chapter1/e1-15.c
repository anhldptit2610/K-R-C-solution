/* Exercise 1-15. Rewrite the temperature conversion program
   of Section 1.2 to use a function for conversion.
*/
#include <stdio.h>

#define UPPER 300	/* upper limit of temperature */
#define LOWER 0		/* lower limit of temperature */
#define STEP 20		/* step size */

/* print Fahrenheit-Celsius table for
   fahr = 0, 20, ..., 300 */

float fahr_to_celsius(float);

int main(void)
{
	for (int i = LOWER; i < UPPER; i += STEP)
		printf("%6d %6.2f\n", i, fahr_to_celsius(i));
	return 0;
}

float fahr_to_celsius(float fahr)
{
	return (5.0/9.0)*(fahr - 32.0);
}