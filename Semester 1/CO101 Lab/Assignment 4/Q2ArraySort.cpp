#include <stdio.h>

int main()
{
	int arr[1000], n, temp;
	printf("Enter size of array: ");
	scanf_s("%d", &n);

	printf("Enter %d elements: ", n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &arr[i]);

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printf("Ascending order: ");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\nDescending order: ");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[n - i - 1]);
	return 0;
}