#include <stdio.h>

int main()
{
	int n, rev = 0;
	printf("Enter your number: ");
	scanf_s("%d", &n);
	int num = n;
	while (num > 0)
	{
		rev = rev * 10 + num % 10;
		num /= 10;
	}
	if (rev == n)
		printf("Entered number is a palindrome.");
	else
		printf("Entered number is not a palindrome.");
	return 0;
}