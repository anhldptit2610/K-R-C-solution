#include <stdio.h>

/* print Celsius-Fahrenheit table for 
   celsius = 0, 20, ..., 300; floating-point version */
int main(void)
{
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;	/* lower limit of temperature scale */
	upper = 300;	/* upper limit of temperature scale */
	step = 20;	/* step size */

	printf("Celsius to Fahrenheit convert table\n");

	celsius = lower;
	while (celsius <= upper) {
		fahr = (9.0/5.0)*celsius + 32.0;
		printf("%6.0f %3.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
	return 0;
}