#include <stdio.h>

int main()
{
	int arr[1000], n, sum = 0;
	printf("Enter size of array: ");
	scanf_s("%d", &n);

	printf("Enter %d elements: ", n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &arr[i]);
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
			sum += arr[i];
	}
	printf("Sum of even numbers in array: %d", sum);
	return 0;
}