#include <stdio.h>

int main()
{
	int num, rev = 0, a;
	printf("Enter a number: ");
	scanf_s("%d", &num);
	a = num;

	while (a != 0)
	{
		rev = rev * 10 + a % 10;
		a /= 10;
	}

	printf("Reverse of %d is %d", num, rev);
	return 0;
}