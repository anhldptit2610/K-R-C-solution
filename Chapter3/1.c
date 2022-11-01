/* Exercise 3-1. Our binary search makes two tests inside the loop,
   when one would suffice (at the price of more tests outside). Write
   a version with only one test inside the loop and measure the difference
   in run-time.
*/

/* Note: I used the benchmark part made by Paul Griffiths(mail@paulgriffths.net)
   in clc-wiki.net. Shoutout to Paul!
   Guess I need to learn how to do a benchmark...
*/

#include <stdio.h>
#include <time.h>

#define MAX_TEST_ELEM	20000

/* Note: The original version of binsearch */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high)/2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else	/* found match */
			return mid;
	}
	return -1;	/* no match */
}

/* Still binsearch, but less test inside loop version */
int lda_binsearch(int x, int v[], int n);

/* Search for -1, to test running time in the worst case */

int main(void)
{
	int test[MAX_TEST_ELEM];
	int index;	/* Index of found element in test data */
	int n = -1;	/* Element we want to search */
	int i;
	clock_t time_taken;
	
	/* Initialize test data */
	for (i = 0; i < MAX_TEST_ELEM; i++)
		test[i] = i;
	
	/* output approximation of time taken for 
	   100000 iterations */

	for (i = 0, time_taken = clock(); i < 100000; i++)
		index = binsearch(n, test, MAX_TEST_ELEM);
	time_taken = clock() - time_taken;
	printf("binsearch takes %lu clocks a.k.a %lu seconds\n", time_taken, time_taken/CLOCKS_PER_SEC);

	for (i = 0, time_taken = clock(); i < 100000; i++)
		index = lda_binsearch(n, test, MAX_TEST_ELEM);
	time_taken = clock() - time_taken;
	printf("lda_binsearch takes %lu clocks a.k.a %lu seconds\n", time_taken, time_taken/CLOCKS_PER_SEC);

	return 0;
}

int lda_binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	mid = (low + high)/2;
	while (low <= high && x != v[mid]) {
		mid = (low + high)/2;
		if (x > v[mid])
			low = mid + 1;
		else	/* found match */
			high = mid - 1; 
	}
	if (x == v[mid])
		return mid;
	return -1;
}

