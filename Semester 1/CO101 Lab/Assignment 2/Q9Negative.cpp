#include <stdio.h>

int main()
{
	int n;
	printf("Enter a number: ");
	scanf_s("%d", &n);
	if (n < 0)
		printf("%d is negative", n);
	return 0;
}