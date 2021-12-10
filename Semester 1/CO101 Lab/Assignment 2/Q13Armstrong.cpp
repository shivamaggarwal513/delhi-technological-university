#include <stdio.h>

int main()
{
	int n, sum = 0;
	printf("Enter a 3 digit number: ");
	scanf_s("%d", &n);
	int num = n;

	while (num > 0)
	{
		sum += (num % 10) * (num % 10) * (num % 10);
		num /= 10;
	}
	if (sum == n)
		printf("Entered number is an Armstrong Number.");
	else
		printf("Entered number is not an Armstrong Number.");
	return 0;
}