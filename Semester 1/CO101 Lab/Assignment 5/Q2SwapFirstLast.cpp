#include <stdio.h>

int main()
{
	int n, first, last, temp, count = 1;
	printf("Enter a number: ");
	scanf_s("%d", &n);
	temp = n;
	last = n % 10;
	while (temp)
	{
		count *= 10;
		first = temp;
		temp /= 10;
	}
	count /= 10;
	temp = n - last - (count * first) + first + (count * last);
	printf("%d after swaping first and last digit is %d", n, temp);
	return 0;
}