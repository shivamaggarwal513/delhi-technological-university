#include <stdio.h>

int main()
{
	int n;
	printf("Enter an integer: ");
	scanf_s("%d", &n);
	if (n % 2 == 0)
		printf("Entered integer is even");
	else
		printf("Entered integer is odd");
	return 0;
}