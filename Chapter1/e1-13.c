/* Exercise 1-13. Write a program to print a histogram of the
   lengths of words in its input. It is easy to draw the histogram
   with the bars horizontal; a vertical orientation is more challenging.
*/

/* 29/10/22: It seems like I misunderstood what this exercise wants.
   Modified the code to make the histogram much like a histogram
*/


#include <stdio.h>
#include <ctype.h>

#define VERTICAL   1	/* 0 is equal horizontal, 1 is equal vertical */
#define OUT        0	/* it means we are not in a word */
#define IN         1
#define MAX_WORD_LEN  17 /* maximum limit of word length */

void draw_vertical_histogram(int freq[], int most);
void draw_horizontal_histogram(int freq[], int most);


int main(void)
{
	int freq[MAX_WORD_LEN] = {0}, word_len, status, most;
	long c;

	status = OUT;
	most = 0;	/* which length is the most */
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			++freq[word_len];
			status = OUT;
			word_len = 0;
		} else if (isalpha(c) && status == OUT) {
			++word_len;
			status = IN;
		} else {
			++word_len;
		}
	}
	for (int i = 0; i < MAX_WORD_LEN; i++)
		if (freq[i] > most)
			most = freq[i];
#if VERTICAL
	draw_vertical_histogram(freq, most);
#else
	draw_horizontal_histogram(freq, most);
#endif
	return 0;
}

void draw_vertical_histogram(int freq[], int most)
{
	for (int i = most; i >= 1; i--) {
		printf("%2d |", i);
		for (int j = 0; j < MAX_WORD_LEN; j++) {
			if (freq[j] >= i)
				printf("  *");
			else
				printf("   ");
		}
		printf("\n");
	}
	printf("    ");
	for (int i = 0; i < MAX_WORD_LEN; i++)
		printf("___");
	printf("\n    ");
	for (int i = 0; i < MAX_WORD_LEN; i++)
		printf("%3d", i);
	printf("\n");
}

void draw_horizontal_histogram(int freq[], int most)
{
	printf(">15 |\n");
	for (int i = MAX_WORD_LEN - 1; i >= 0; i--) {
		printf("%2d  |", i);
		for (int j = 0; j < freq[i]; j++)
			printf("   *");
		printf("\n");
	}
	printf("     ");
	for (int i = 0; i < 2*most; i++)
		printf("__");
	printf("\n     ");
	for (int i = 1; i <= most; i++)
		printf("%4d", i);
	printf("\n");
}