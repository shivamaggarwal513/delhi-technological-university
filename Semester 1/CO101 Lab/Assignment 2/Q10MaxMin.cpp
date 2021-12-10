#include <stdio.h>

int main()
{
	int a, b, c, max, min;
	printf("Enter 3 numbers: ");
	scanf_s("%d %d %d", &a, &b, &c);
	max = ((a > b ? a : b) > c) ? (a > b ? a : b) : c;
	min = ((a < b ? a : b) < c) ? (a < b ? a : b) : c;
	printf("Maximum among 3 numbers is %d and minimum is %d", max, min);
	return 0;
}