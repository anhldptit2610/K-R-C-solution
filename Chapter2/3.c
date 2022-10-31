/* Exercise 2-3. Write a function htoi(s), which converts a string
   of hexadecimal digits(including an optional 0x or 0X) into its
   equivalent integer value. The allowable digits are 0 through 9,
   a through f, and A through F.
*/

/* Note: although the concept of main function arguments is not 
   yet introduced in this chapter, I still want to use argc and argv.
   This program will take the first argument as hexa input value.
*/

#include <stdio.h>
#include <ctype.h>

int htoi(char *hex);
int lda_pow(int base, int exponent);

int main(int argc, char **argv)
{
	int res = htoi(argv[1]);

	if (res == -1)
		printf("The input value was invalid\n");
	else
		printf("The integer value of %s is: %d\n", argv[1], res);
	return 0;
}

int lda_pow(int base, int exponent)
{
	int res = 1;

	while (exponent--)
		res = res*base;
	return res;
}

int hex_to_dec(char c)
{
	if (isdigit(c))
		return c - '0';
	else {
		if (c >= 'a' && c <= 'f')
			return c - 'a' + 10;
		else if (c >= 'A' && c <= 'F')
			return c - 'A' + 10;
	}
	return -1;	/* for invalid value */
}

int htoi(char *hex)
{
	int res, index, exponent;

	res = index = 0;
	
	/* reach to the end of the string */
	while (hex[index] != '\0')
		++index;
	index--;	
	/* then traverse back and compute */
	exponent = 0;
	while (index > 1) {
		int val = hex_to_dec(hex[index]);
		if (val == -1)
			return -1;
		else {
			res = res + val*lda_pow(16, exponent);
			++exponent;
			--index;
		}
	}
	return res;
}