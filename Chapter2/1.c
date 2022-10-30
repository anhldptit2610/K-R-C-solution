/* Exercise 2-1. Write a program to determine the ranges of char,
   short, int, and long variables, both signed and unsigned, by
   printing appropriate values from standard headers and by direct
   computation. Harder if you compute them; determine the ranges
   of the various floating-point types
*/

/* In C, there are two floating-point data type: float(single precision)
   and double(double precision). I spent some times trying to under-
   stand the concept of IEEE-754 standard. Useful link:

   https://en.wikipedia.org/wiki/Single-precision_floating-point_format
   https://en.wikipedia.org/wiki/Double-precision_floating-point_format#C_and_C++

   Why we need to understand these? If you want to compute range of float and double,
   not using values defines in headers, you need to understand these.
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdint.h>

float get_float(uint32_t sign, uint32_t exponent, uint32_t fraction)
{
	uint32_t res = 0;

	res |= sign;
	res <<= 8;
	res |= exponent;
	res <<= 23;
	res |= fraction;
	return *(float *)&res;
}

double get_double(uint32_t sign, uint32_t exponent, uint64_t fraction)
{
	unsigned long long res = 0;

	res |= sign;
	res <<= 11;
	res |= exponent;
	res <<= 52;
	res |= fraction;
	return *(double *)&res;
}

int main(void)
{
	/* This is determine by printing appropriate values from headers */
	printf("RANGES OF VARIABLE TYPES\n");
	printf("The range of signed char: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("The range of unsigned char: 0 to %d\n", UCHAR_MAX);
	printf("The range of signed int: %d to %d\n", INT_MIN, INT_MAX);
	printf("The range of unsigned int: 0 to %u\n", UINT_MAX);
	printf("The range of long: %ld to %ld\n", LONG_MIN, LONG_MAX);
	printf("The range of unsigned long: 0 to %ld\n", ULONG_MAX);
	printf("The range of short: %hi to %hi\n", SHRT_MIN, SHRT_MAX);
	printf("The range of unsigned short: 0 to %hu\n", USHRT_MAX);
	printf("The range of float using header value: %e to %e\n", FLT_MIN, FLT_MAX);
	printf("The range of double using header value: %e to %e\n", DBL_MIN, DBL_MAX);


	/* Determine the ranges of float and double types by calculating */
	printf("The range of float: %e to %e\n", get_float(1, 0, 0x7FFFFF), get_float(0, 0xFE, 0x7FFFFF));
	printf("The range of double: %e to %e\n", get_double(1, 0, 0xFFFFFFFFFFFFF), get_double(0, 0x7FE, 0xFFFFFFFFFFFFF));
	return 0;
}