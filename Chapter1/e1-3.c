#include <stdio.h>

/* print Fahrenheit-Celsius table for 
   fahr = 0, 20, ..., 300; floating-point version */
int main(void)
{
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;	/* lower limit of temperature scale */
	upper = 300;	/* upper limit of temperature scale */
	step = 20;	/* step size */

	printf("Fahr to Celsius convert table\n");

	fahr = lower;
	while (fahr <= upper) {
		celsius = (9.0/5.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	return 0;
}
	