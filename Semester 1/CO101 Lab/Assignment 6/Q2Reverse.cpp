#include <stdio.h>

int reverse(int n)
{
	static int sum = 0;
	if (n)
	{
		sum = sum * 10 + n % 10;
		reverse(n / 10);
	}
	else
		return sum;
}

int main()
{
	int num, rev;
	printf("Enter a number: ");
	scanf_s("%d", &num);
	rev = reverse(num);
	printf("Reverse of %d is %d", num, rev);
	return 0;
}