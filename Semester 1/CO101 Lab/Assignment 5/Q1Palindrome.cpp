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
		printf("Entered number %d is a palindrome.", n);
	else
		printf("Entered number %d is not a palindrome.", n);
	return 0;
}