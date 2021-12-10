#include <stdio.h>

int main()
{
	int arr[10][2];
	printf("Enter 10 elements: ");
	for (int i = 0; i < 10; i++)
	{
		scanf_s("%d", &arr[i][0]);
		arr[i][1] = 0;
	}

	printf("Number  | Occurence\n-------------------\n");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j][0] == arr[i][0])
				goto repeat;
		}
		for (int j = i; j < 10; j++)
		{
			if (arr[j][0] == arr[i][0])
				arr[i][1]++;
		}
		printf("%d\t|  %d\n", arr[i][0], arr[i][1]);
	repeat:;
	}
	return 0;
}