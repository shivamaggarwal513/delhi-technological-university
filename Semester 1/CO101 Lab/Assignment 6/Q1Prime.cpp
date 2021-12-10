#include <stdio.h>

int prime(int n, int i)
{
	if (i == 1)
		return 1;
	else
	{
		if (n % i == 0)
			return 0;
		else
			prime(n, i - 1);
	}
}

int main()
{
	int n, ans;
	printf("Enter a number: ");
	scanf_s("%d", &n);
	ans = prime(n, n / 2);
	if (ans == 1)
		printf("%d is prime", n);
	else
		printf("%d is not prime", n);
	return 0;
}