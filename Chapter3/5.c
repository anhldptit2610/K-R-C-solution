/* Exercise 3-5. Write teh function itob(n, s, b) that converts
   the integer n into a base b character representation in the
   string s. In particular, itob(n,s,16) formats s as a hexadecimal
   integer in s.
*/

char int_to_hex(int num)
{
	return (num < 10) ? num + '0' : num - 10 + 'A';
}

void reverse(char s[])
{
	int i, j, tmp;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}

void itob(long long n, char s[], int base)
{
	long long sign;
	int i;

	i = 0;
	if ((sign = n) < 0)
		n = -n;

	do {
		s[i++] = (base == 16) ? int_to_hex(n % base) : n % base + '0';
	} while ((n /= base) > 0);
	if (sign < 0)
		s[i++] = '-';
	if (base == 16) {
		s[i++] = 'x';
		s[i++] = '0';
	}
	reverse(s);
}

int main(void)
{
	long long n = 670;
	char s[100];
	int base = 2;

	itob(n, s, base);
	printf("the decimal number %lld is %s in base %d.\n", n, s, base);
	return 0;
}

