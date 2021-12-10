#include <stdio.h>

int main()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j > i; j--)
		{
			printf("  ");
		}
		for (int k = i + 1; k > 0; k--)
		{
			printf("%d ", k - 1);
		}
		for (int l = 0; l < i; l++)
		{
			printf("%d ", l + 1);
		}
		printf("\n");
	}
	return 0;
}