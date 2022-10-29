/* Exercise 1-24. Write a program to check a C program for rudimentary
   syntax errors like unmatched parentheses, brackets and braces. Don't
   forget about quotes, both single and double, escape sequences, and
   comments. (This program is hard if you do it in full generality).
*/

/* Note: ye sure, this will be hard if we want to do it full generality.
   The idea here is to use a stack to store parentheses, brackets, braces.
*/

#include <stdio.h>

#define NUM_OF_BRACKETS 1000

void print_error(int line);
int check_str(long c);
int check_comment(long c);

int line_tracking; 	/* Tracking which line we are in */

int main(void)
{
	char stack[NUM_OF_BRACKETS];
	int index;
	long c;

	index = 0;
	line_tracking = 1;	/* start at line 1 */
	while ((c = getchar()) != EOF) {
		if (c == '(' || c == '{' || c == '[') {
			stack[index] = c;
			++index;
		} else if (c == ')' || c == '}' || c == ']') {
			switch (c) {
			case ')':
				if (stack[index - 1] != '(') {
					print_error(line_tracking);
					--index;
				} else {
					--index;
				}
				break;
			case '}':
				if (stack[index - 1] != '{') {
					print_error(line_tracking);
					--index;
				} else {
					--index;
				}
				break;
			case ']':
				if (stack[index - 1] != '[') {
					print_error(line_tracking);
					--index;
				} else {
					--index;
				}	
				break;
			default:
				break;
			}
		} else if (c == 34 || c == 39) {	/* 34 is ", 39 is ' in ASCII */
			if (check_str(c))
				print_error(line_tracking);
		} else if (c == '\n') {
			++line_tracking;
		} else if (c == '/') {
			if ((c = getchar()) == '*' || c == '/')
				if (check_comment(c))
					print_error(line_tracking);
		}
	}
	return 0;
}

int check_comment(long c) {
	int ret;

	switch (c) {
	case '*':
		while (c) {
			if (c == '*' && (c = getchar()) == '/')
				break;
			else if (c == '\n')
				++line_tracking;
			c = getchar();
		}
		if (c != '/')
			ret = 1;
		else 
			ret = 0;
		break;
	default:
		break;
	}
	return ret;
}

int check_str(long c) {
	long tmp = c, flag = 1;

	while ((c = getchar()) != EOF) {
		if (c == tmp) {
			flag = 0;
			break;
		}
	}
	return flag;
}

void print_error(int line) {
	printf("Syntax error at line %d\n", line);
}