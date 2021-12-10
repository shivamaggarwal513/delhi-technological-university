#include <stdio.h>

int main()
{
	int arr[1000], n, min, max, avg = 0;
	printf("Enter size of array: ");
	scanf_s("%d", &n);

	printf("Enter %d elements: ", n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &arr[i]);

	max = min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
		avg += arr[i];
	}
	avg /= n;
	printf("Maximum value: %d\nMinimum value: %d\nAverage value: %d", max, min, avg);
	return 0;
}